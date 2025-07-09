/*
** EPITECH PROJECT, 2025
** B-NWP-400-NAN-4-1-jetpack-romain.berard
** File description:
** Main
*/
#include <mutex>

#include <atomic>
#include <thread>

#include "Client.hpp"
#include "Graphics.hpp"

struct params_t {
  int port = -1;
  bool debug = false;
  std::string ip = "";
};

static void printHelp() {
  std::cout << "USAGE: ./jetpack_client -h <ip> -p <port> [-d]" << std::endl;
  std::cout << "  -h ip     IP address of the server" << std::endl;
  std::cout << "  -p port   Port number" << std::endl;
  std::cout << "  -d        Debug mode" << std::endl;
}

static void getIp(params_t &params, int *i, char **argv) {
  if (std::string(argv[*i]) == "-h") {
    if (argv[*i + 1] == NULL) {
      printHelp();
      exit(84);
    }
    params.ip = argv[*i + 1];
    *i += 1;
  }
}

static void getPort(params_t &params, int *i, char **argv) {
  if (std::string(argv[*i]) == "-p") {
    if (argv[*i + 1] == NULL) {
      printHelp();
      exit(84);
    }
    params.port = std::stoi(argv[*i + 1]);
    if (params.port < 1024 || params.port > 65535) {
      std::cerr << "Port must be between 1024 and 65535" << std::endl;
      exit(84);
    }
    *i += 1;
  }
}

static params_t getParams(int argc, char **argv) {
  params_t params;

  if (argc < 5) {
    printHelp();
    exit(84);
  }
  for (int i = 1; i < argc; i++) {
    if (std::string(argv[i]) != "-h" && std::string(argv[i]) != "-p" &&
        std::string(argv[i]) != "-d") {
      printHelp();
      exit(84);
    }
    getIp(params, &i, argv);
    getPort(params, &i, argv);
    if (std::string(argv[i]) == "-d")
      params.debug = true;
  }
  return params;
}

static void parseMessagePlayer(std::string message,
                               JetPack::Graphics &graphics) {
  if (message.rfind("801:", 0) == 0) {
    size_t id = std::stoi(message.substr(4, message.find(':', 4) - 4));
    int score = std::stoi(message.substr(message.find(' ', 5) + 1));
    graphics.updatePlayerScore(id, score);
  }
}

static void parseMessageGame(std::string message, JetPack::Graphics &graphics) {
  if (message.rfind("401:", 0) == 0) {
    size_t id = std::stoi(message.substr(4, message.find(':', 4) - 4));
    float x = std::stof(
        message.substr(message.find(':', 4) + 1, message.find(';', 4)));
    float y = std::stof(message.substr(message.find(';', 4) + 1));
    graphics.setPlayerPosition(id, x, y);
  }
  if (message.rfind("901:", 0) == 0) {
    int id = std::stoi(message.substr(5));
    if (id != -1)
      graphics.setGameStarted(JetPack::Graphics::END_T);
    if (id == 1)
      graphics.setWin(true);
    if (id == 0)
      graphics.setWin(false);
  }
  if (message.rfind("701:", 0) == 0) {
    if (message.find("COIN") != std::string::npos) {
      float x =
          std::stof(message.substr(message.find('(') + 1, message.find(';')));
      float y =
          std::stof(message.substr(message.find(';') + 1, message.find(')')));
      graphics.addEntity("COIN", x, y);
    }
    if (message.find("ZAPPY") != std::string::npos) {
      float x =
          std::stof(message.substr(message.find('(') + 1, message.find(';')));
      float y =
          std::stof(message.substr(message.find(';') + 1, message.find(')')));
      graphics.addEntity("ZAPPY", x, y);
    }
  }
  parseMessagePlayer(message, graphics);
}

static void parseMessageMenu(std::string message, JetPack::Graphics &graphics) {
  if (message.rfind("301:", 0) == 0)
    graphics.setClientId(std::stoi(message.substr(4)));
  if (message.rfind("501:", 0) == 0)
    graphics.setNbPlayers(std::stoi(message.substr(4)));
  if (message.rfind("601: START", 0) == 0) {
    graphics.setGameStarted(JetPack::Graphics::GAME_T);
    graphics.setWin(false);
  }
}

static void sendMessageEachFrame(JetPack::Graphics &graphics,
                                 JetPack::Client &client, float &elapsedTime) {
  auto graphicsElapsedTime = graphics.getElapsedTime();
  if (graphicsElapsedTime > 0.3 &&
      graphics.isGameStarted() != JetPack::Graphics::GAME_T) {
    client.sendMessage("500 NB_PLAYERS\r\n");
    graphics.resetClock();
  }
  elapsedTime += graphicsElapsedTime;
  if (graphicsElapsedTime > 0.03 &&
      graphics.isGameStarted() == JetPack::Graphics::GAME_T) {
    graphics.resetClock();
    client.sendMessage("400 POSITION\r\n");
    client.sendMessage("900 VICTORY\r\n");
    client.sendMessage("800 SCORE\r\n");
    client.sendMessage("700 ENTITY\r\n");
    graphics.resetEntity();
    graphics.setEntity(graphics.getTempEntities());
    graphics.resetTempEntity();
  }
}

void handleGraphicsMessages(std::list<std::string> &messages,
                            std::mutex &messages_mutex,
                            JetPack::Graphics &graphics) {
  while (true) {
    std::string message;
    {
      std::lock_guard<std::mutex> lock(messages_mutex);
      if (messages.empty())
        break;
      message = messages.front();
      messages.pop_front();
    }
    if (graphics.isGameStarted() == JetPack::Graphics::GAME_T)
      parseMessageGame(message, graphics);
    else
      parseMessageMenu(message, graphics);
  }
}

int main(int argc, char **argv) {
  params_t params = getParams(argc, argv);
  if (params.ip.empty() || params.port == -1) {
    printHelp();
    return 84;
  }
  try {
    float elapsedTime = 0.0f;
    JetPack::Client client(params.ip, params.port);
    JetPack::Graphics graphics;
    std::atomic<bool> running = true;
    client.setDebug(params.debug);
    std::mutex messages_mutex;
    std::list<std::string> messages;
    std::thread clientThread([&client, &running, &messages, &messages_mutex]() {
      try {
        client.clientLoop(running, messages, messages_mutex);
      } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        running = false;
      }
    });
    while (graphics.isOpen() && running) {
      if (graphics.getClientId() == -1)
        client.sendMessage("300 CONNECTED\r\n");
      else
        sendMessageEachFrame(graphics, client, elapsedTime);
      handleGraphicsMessages(messages, messages_mutex, graphics);
      graphics.handleEvent(client, running);
      graphics.display();
    }
    client.sendMessage("100 QUIT\r\n");
    running = false;
    clientThread.join();
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  return 0;
}
