/*
** EPITECH PROJECT, 2025
** B-NWP-400-NAN-4-1-jetpack-romain.berard
** File description:
** Graphics
*/

#pragma once
#include <atomic>
#include <iostream>
#include <list>
#include <map>

#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

struct sounds_t {
  sf::Sound sound;
  sf::SoundBuffer soundBuffer;
};

namespace JetPack {
class Client;

class Graphics {
public:
  enum button_id_t {
    START = 0,
    STATUS = 1,
    END = 2,
  };

  enum sprite_id_t {
    MENU = 0,
    MENU_END = 1,
    GAME = 2,
    COIN = 3,
    ZAPPY = 4,
    PLAYER = 5,
  };

  enum game_state_t {
    MENU_T = 0,
    GAME_T = 1,
    END_T = 2,
  };

  enum sound_id_t {
    SOUNDMENU = 0,
  };

  enum class AnimState { Idle, UP, DOWN };

  struct PlayerAnim {
    AnimState state = AnimState::Idle;
    int frame = 0;
    sf::Clock clock;
  };

  struct Entity {
    std::string name;
    float x;
    float y;
    sf::Sprite sprite;
  };

  Graphics();
  ~Graphics();

  void display();
  void drawSprite();

  void handleEvent(Client &client, std::atomic<bool> &running);
  void resetClock();
  bool isOpen() const;

  void setClientId(int id);
  void setPlayerPosition(size_t playerId, float x, float y);

  float getElapsedTime() const;
  int getClientId() const;

  game_state_t isGameStarted() const;
  void setGameStarted(Graphics::game_state_t started);

  void setNbPlayers(size_t nb_players_);
  size_t getNbPlayers() const;
  void updatePlayerScore(size_t playerId, int score);
  void updatePlayerAnimation(size_t playerId);

  void createText(size_t index, std::string text, float charSize,
                  sf::Vector2f pos);
  void createSound(size_t index, std::string path, size_t volume, bool play);
  void createSprite(size_t index, std::string path, sf::Vector2f pos,
                    sf::IntRect rect = sf::IntRect(0, 0, 1920, 1080));

  void loadMenu();
  void updateMenu();

  void loadGame();
  void updateGameMap();

  void loadEnd();
  void updateEnd();

  std::vector<Entity> getEntities() const { return entities_; }
  std::vector<Entity> getTempEntities() const { return temp_entity_; }
  void addEntity(std::string name_entity, float x, float y);
  void setEntity(std::vector<Entity> entities) { entities_ = entities; }
  void resetEntity() { entities_.clear(); }
  void resetTempEntity() { temp_entity_.clear(); }
  void setWin(bool over) { winner_ = over; }
  bool isWin() const { return winner_; }

private:
  std::map<size_t, sf::RectangleShape> buttons_;
  std::map<size_t, sf::Text> texts_;
  sf::Font fonts_;
  std::map<size_t, sf::Sprite> sprites_;
  std::map<size_t, sf::Texture> textures_;
  std::vector<sounds_t> sounds_ = {};
  sf::Clock clock_;
  sf::RenderWindow window_;
  sf::Event event_;
  std::map<size_t, sf::Sprite> players_;
  std::map<size_t, sf::Text> players_score_;
  std::map<size_t, PlayerAnim> players_state_;
  int client_id_ = -1;
  size_t nb_players_ = 0;
  bool winner_ = false;
  game_state_t game_started_ = MENU_T;

  std::vector<Entity> entities_;
  std::vector<Entity> temp_entity_;
};
} // namespace JetPack
