/*
** EPITECH PROJECT, 2025
** B-NWP-400-NAN-4-1-jetpack-romain.berard
** File description:
** Client
*/

#include "Client.hpp"

#include <algorithm>

#include "poll.h"

namespace JetPack {

Client::Client(std::string ip, int port) {
  sockaddr_in serverAddress;

  _socket = socket(AF_INET, SOCK_STREAM, 0);
  if (_socket == -1)
    throw std::runtime_error("Failed to create socket");
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_port = htons(port);
  if (inet_pton(AF_INET, ip.c_str(), &serverAddress.sin_addr) <= 0)
    throw std::runtime_error("Invalid IP address");
  if (connect(_socket, (struct sockaddr *)&serverAddress,
              sizeof(serverAddress)) < 0)
    throw std::runtime_error("Connection to server failed");
  std::cout << "Connected to server at " << ip << ":" << port << std::endl;
}

Client::~Client() {
  std::cout << "Client disconnected" << std::endl;
  while (read(_socket, nullptr, 0) > 0);
  close(_socket);
}

void Client::readMessage(std::list<std::string> &_messages, std::mutex &mutex) {
  char buffer = 0;
  std::string message = "";
  size_t bytesRead = 0;

  bytesRead = read(_socket, &buffer, 1);
  while (bytesRead > 0) {
    message += buffer;
    if (buffer == '\n') {
      break;
    }
    bytesRead = read(_socket, &buffer, 1);
  }
  if (bytesRead <= 0)
    throw std::runtime_error("Failed to read from socket");
  message.erase(std::remove(message.begin(), message.end(), '\r'),
                message.end());
  message.erase(std::remove(message.begin(), message.end(), '\n'),
                message.end());
  {
    std::lock_guard<std::mutex> lock(mutex);
    _messages.push_back(message);
  }
  if (showDebug)
    std::cout << "$> " << message << std::endl;
}

void Client::sendMessage(std::string message) {
  if (write(_socket, message.c_str(), message.size()) == -1) {
    throw std::runtime_error("Failed to send message to server");
  }
  if (showDebug) {
    message.erase(std::remove(message.begin(), message.end(), '\r'),
                  message.end());
    message.erase(std::remove(message.begin(), message.end(), '\n'),
                  message.end());
    std::cout << "<$ " << message << std::endl;
  }
}

void Client::clientLoop(std::atomic<bool> &running,
                        std::list<std::string> &message, std::mutex &mutex) {
  struct pollfd fds[1];
  fds[0].fd = _socket;
  fds[0].events = POLLIN;
  fds[0].revents = 0;

  while (running) {
    if (poll(fds, 1, 100) < 0)
      throw std::runtime_error("Poll failed");
    if (fds[0].revents & POLLIN) {
      readMessage(message, mutex);
    }
  }
}

void Client::setDebug(bool debug) { showDebug = debug; }

} // namespace JetPack
