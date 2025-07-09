/*
** EPITECH PROJECT, 2025
** B-NWP-400-NAN-4-1-jetpack-romain.berard
** File description:
** Graphics
*/

#include "Graphics.hpp"
#include "Client.hpp"

namespace JetPack {
Graphics::Graphics() {
  window_.create(sf::VideoMode(1920, 1080), "JetPack");
  if (!window_.isOpen())
    throw std::runtime_error("Failed to create window");
  window_.setFramerateLimit(60);
  fonts_ = sf::Font();
  if (!fonts_.loadFromFile("assets/jetpack_font.ttf"))
    throw std::runtime_error("Failed to load font");
  loadMenu();
  loadGame();
  loadEnd();
}

Graphics::~Graphics() {
  buttons_.clear();
  sprites_.clear();
  textures_.clear();
  texts_.clear();
  players_.clear();
  for (auto &sound_s : sounds_) {
    if (sound_s.sound.getStatus() == sf::Sound::Playing)
      sound_s.sound.stop();
  }
  sounds_.clear();
  players_score_.clear();
  entities_.clear();
  temp_entity_.clear();
  if (window_.isOpen())
    window_.close();
}

void Graphics::display() {
  window_.clear(sf::Color::Black);
  drawSprite();
  window_.display();
}

void Graphics::drawSprite() {
  if (game_started_ == GAME_T) {
    float yOffset = 10.0f;
    window_.draw(sprites_[sprite_id_t::GAME]);
    if (sounds_[sound_id_t::SOUNDMENU].sound.getStatus() == sf::Sound::Playing)
      sounds_[sound_id_t::SOUNDMENU].sound.stop();
    for (auto &entity : entities_) {
      window_.draw(entity.sprite);
    }
    for (auto &player : players_score_) {
      player.second.setPosition(sf::Vector2f(10.0f, yOffset));
      window_.draw(player.second);
      yOffset += 60.0f;
    }
    for (const auto &player : players_)
      window_.draw(player.second);
    updateGameMap();
  }
  if (game_started_ == MENU_T) {
    window_.draw(sprites_[sprite_id_t::MENU]);
    window_.draw(buttons_[button_id_t::START]);
    window_.draw(texts_[button_id_t::START]);
  }
  if (game_started_ == END_T) {
    window_.draw(sprites_[sprite_id_t::MENU_END]);
    window_.draw(buttons_[button_id_t::STATUS]);
    window_.draw(texts_[button_id_t::STATUS]);
    window_.draw(buttons_[button_id_t::END]);
    window_.draw(texts_[button_id_t::END]);
  }
}

void Graphics::updatePlayerScore(size_t playerId, int score) {
  if (players_score_.find(playerId) == players_score_.end()) {
    players_score_[playerId] = sf::Text();
    players_score_[playerId].setFont(fonts_);
    players_score_[playerId].setCharacterSize(50);
  }
  if ((int)playerId == client_id_) {
    players_score_[playerId].setFillColor(sf::Color::White);
    players_score_[playerId].setString("ME. " + std::to_string(score) + " pts");
  } else {
    players_score_[playerId].setFillColor(sf::Color::Red);
    players_score_[playerId].setString("OTHER. " + std::to_string(score) +
                                       " pts");
  }
}

void Graphics::updatePlayerAnimation(size_t playerId) {
  if (players_.find(playerId) == players_.end())
    return;
  if (players_state_.find(playerId) == players_state_.end())
    return;
  auto &anim = players_state_[playerId];
  const int frame_width = 134;
  const int frame_height = 134;
  const int num_frames = 3;
  if (anim.clock.getElapsedTime().asMilliseconds() > 100) {
    anim.frame = (anim.frame + 1) % num_frames;
    anim.clock.restart();
  }
  int row = 0;
  if (anim.state == AnimState::UP)
    row = 1;
  else if (anim.state == AnimState::DOWN)
    row = 1;
  else
    row = 0;
  sf::IntRect rect(anim.frame * frame_width, row * frame_height, frame_width,
                   frame_height);
  players_[playerId].setTextureRect(rect);
}

void Graphics::setPlayerPosition(size_t playerId, float x, float y) {
  if (players_.find(playerId) == players_.end()) {
    if (sprites_.find(sprite_id_t::PLAYER) == sprites_.end())
      createSprite(sprite_id_t::PLAYER, "assets/player.png", sf::Vector2f(x, y),
                   sf::IntRect(0, 0, 134, 134));
    players_[playerId] = sprites_[sprite_id_t::PLAYER];
    players_[playerId].setScale(sf::Vector2f(0.8, 0.8));
    if ((int)playerId == client_id_)
      players_[playerId].setColor(sf::Color(255, 255, 255, 255));
    else
      players_[playerId].setColor(sf::Color(255, 255, 255, 128));
    players_[playerId].setPosition(x, y);
    players_state_[playerId] = PlayerAnim();
  } else {
    sf::Vector2f currentPos = players_[playerId].getPosition();
    sf::Vector2f targetPos(x, y);
    float lerpFactor = 0.2f;
    sf::Vector2f newPos = currentPos + (targetPos - currentPos) * lerpFactor;
    players_[playerId].setPosition(newPos);
    float deltaY = targetPos.y - currentPos.y;
    if (deltaY < -1.0f)
      players_state_[playerId].state = AnimState::UP;
    else if (deltaY > 1.0f)
      players_state_[playerId].state = AnimState::DOWN;
    else
      players_state_[playerId].state = AnimState::Idle;
  }
  updatePlayerAnimation(playerId);
}

void Graphics::handleEvent(Client &client, std::atomic<bool> &running) {
  while (window_.pollEvent(event_)) {
    if (event_.type == sf::Event::Closed)
      running = false;
    if (event_.type == sf::Event::KeyPressed) {
      if (event_.key.code == sf::Keyboard::Escape)
        running = false;
      if (event_.key.code == sf::Keyboard::Space && players_.size() > 1)
        client.sendMessage("200 UP\r\n");
    }
    if (game_started_ == MENU_T && nb_players_ > 1) {
      if (event_.type == sf::Event::MouseButtonPressed &&
          event_.mouseButton.button == sf::Mouse::Left) {
        auto mousePos = sf::Mouse::getPosition(window_);
        if (buttons_[button_id_t::START].getGlobalBounds().contains(mousePos.x,
                                                                    mousePos.y))
          client.sendMessage("600 START\r\n");
      }
    }
    if (game_started_ == END_T && nb_players_ > 1) {
      if (event_.type == sf::Event::MouseButtonPressed &&
          event_.mouseButton.button == sf::Mouse::Left) {
        auto mousePos = sf::Mouse::getPosition(window_);
        if (buttons_[button_id_t::END].getGlobalBounds().contains(mousePos.x,
                                                                  mousePos.y))
          client.sendMessage("600 START\r\n");
      }
    }
  }
  if (game_started_ == MENU_T)
    updateMenu();
  if (game_started_ == END_T)
    updateEnd();
}

bool Graphics::isOpen() const { return window_.isOpen(); }

float Graphics::getElapsedTime() const {
  return clock_.getElapsedTime().asSeconds();
}

void Graphics::resetClock() { clock_.restart(); }

int Graphics::getClientId() const { return client_id_; }

void Graphics::setClientId(int id) { client_id_ = id; }

Graphics::game_state_t Graphics::isGameStarted() const { return game_started_; }

void Graphics::setGameStarted(Graphics::game_state_t started) {
  game_started_ = started;
}

void Graphics::setNbPlayers(size_t nbPlayers) { this->nb_players_ = nbPlayers; }

size_t Graphics::getNbPlayers() const { return nb_players_; }

void Graphics::createText(size_t index, std::string text, float charSize,
                          sf::Vector2f pos) {
  if (texts_.find(index) == texts_.end())
    texts_[index] = sf::Text();
  if (texts_[index].getFont() != &fonts_)
    texts_[index].setFont(fonts_);
  if (texts_[index].getString() != text)
    texts_[index].setString(text);
  texts_[index].setCharacterSize(charSize);
  texts_[index].setFillColor(sf::Color::Black);
  texts_[index].setOrigin(texts_[index].getGlobalBounds().width / 2,
                          texts_[index].getGlobalBounds().height / 2);
  texts_[index].setPosition(pos);
}

void Graphics::createSound(size_t index, std::string path, size_t volume,
                           bool play) {
  sounds_.push_back(sounds_t());
  sounds_[index].sound = sf::Sound();
  sounds_[index].soundBuffer = sf::SoundBuffer();
  if (!sounds_[index].soundBuffer.loadFromFile(path))
    throw std::runtime_error("Failed to load sound");
  sounds_[index].sound.setBuffer(sounds_[index].soundBuffer);
  sounds_[index].sound.setLoop(true);
  sounds_[index].sound.setVolume(volume);
  if (play)
    sounds_[index].sound.play();
}

void Graphics::createSprite(size_t index, std::string path, sf::Vector2f pos,
                            sf::IntRect rect) {
  sprites_[index] = sf::Sprite();
  sprites_[index].setPosition(pos.x, pos.y);
  if (!textures_[index].loadFromFile(path))
    throw std::runtime_error("Failed to load texture : " + path);
  sprites_[index].setTexture(textures_[index]);
  sprites_[index].setTextureRect(rect);
}

void Graphics::loadMenu() {
  createSprite(sprite_id_t::MENU, "assets/menu.jpg", (sf::Vector2f){0, 0});

  buttons_[button_id_t::START] = sf::RectangleShape(sf::Vector2f(600, 100));
  auto sizeButton = buttons_[button_id_t::START].getSize();
  buttons_[button_id_t::START].setOrigin(sizeButton.x / 2, sizeButton.y / 2);
  buttons_[button_id_t::START].setFillColor(sf::Color::White);
  auto sizeWindow = window_.getSize();
  buttons_[button_id_t::START].setPosition(sizeWindow.x / 2.0,
                                           sizeWindow.y / 2.0);
  buttons_[button_id_t::START].setOutlineThickness(2);
  buttons_[button_id_t::START].setOutlineColor(sf::Color::Black);

  createSound(sound_id_t::SOUNDMENU, "assets/theme.ogg", 50, true);
}

void Graphics::loadEnd() {
  createSprite(sprite_id_t::MENU_END, "assets/menu.jpg", (sf::Vector2f){0, 0});
  buttons_[button_id_t::STATUS] = sf::RectangleShape(sf::Vector2f(600, 100));
  buttons_[button_id_t::END] = sf::RectangleShape(sf::Vector2f(600, 100));
  auto sizeButton = buttons_[button_id_t::STATUS].getSize();
  buttons_[button_id_t::STATUS].setOrigin(sizeButton.x / 2, sizeButton.y / 2);
  buttons_[button_id_t::END].setOrigin(sizeButton.x / 2, sizeButton.y / 2);
  buttons_[button_id_t::STATUS].setFillColor(sf::Color::White);
  buttons_[button_id_t::END].setFillColor(sf::Color::White);
  auto sizeWindow = window_.getSize();
  float centerY = sizeWindow.y / 2.0f;
  float spacing = 200.0f;
  buttons_[button_id_t::STATUS].setPosition(sizeWindow.x / 2.0f,
                                            centerY - spacing / 2.0f);
  buttons_[button_id_t::END].setPosition(sizeWindow.x / 2.0f,
                                         centerY + spacing / 2.0f);
  buttons_[button_id_t::STATUS].setOutlineThickness(2);
  buttons_[button_id_t::STATUS].setOutlineColor(sf::Color::Black);
  buttons_[button_id_t::END].setOutlineThickness(2);
  buttons_[button_id_t::END].setOutlineColor(sf::Color::Black);
  createSound(sound_id_t::SOUNDMENU, "assets/theme.ogg", 50, true);
}

void Graphics::updateMenu() {
  auto windowSize = window_.getSize();
  windowSize.x /= 2;
  windowSize.y /= 2;
  auto posCenter =
      (sf::Vector2f){(float)(windowSize.x), (float)(windowSize.y - 10)};
  buttons_[button_id_t::START].setPosition(windowSize.x, windowSize.y);
  if (getNbPlayers() > 1)
    createText(button_id_t::START, "Press to play", 50, posCenter);
  else
    createText(button_id_t::START, "Waiting for other players", 50, posCenter);
}

void Graphics::updateEnd() {
  auto posCenter = buttons_[button_id_t::END].getPosition();
  posCenter.y -= 10;
  if (getNbPlayers() > 1)
    createText(button_id_t::END, "Press to play", 50, posCenter);
  else
    createText(button_id_t::END, "Waiting for other players", 50, posCenter);
  posCenter = buttons_[button_id_t::STATUS].getPosition();
  posCenter.y -= 10;
  if (isWin())
    createText(button_id_t::STATUS, "You won", 50, posCenter);
  else
    createText(button_id_t::STATUS, "You lost", 50, posCenter);
}

void Graphics::loadGame() {
  createSprite(sprite_id_t::GAME, "assets/og_back.png", (sf::Vector2f){0, 0});
  if (!textures_[sprite_id_t::COIN].loadFromFile("assets/coin.png"))
    throw std::runtime_error("Failed to load texture : assets/coin.png");
  if (!textures_[sprite_id_t::ZAPPY].loadFromFile("assets/zappy.png"))
    throw std::runtime_error("Failed to load texture : assets/zappy.png");
}

void Graphics::updateGameMap() {
  sf::IntRect pos1 = sprites_[sprite_id_t::GAME].getTextureRect();

  if (pos1.left >= 4418)
    pos1.left = 0;
  else
    pos1.left += 10;
  sprites_[sprite_id_t::GAME].setTextureRect(pos1);
}

void Graphics::addEntity(std::string name_entity, float x, float y) {
  Entity entity;
  entity.name = name_entity;
  entity.x = x;
  entity.y = y;

  if (name_entity == "COIN") {
    entity.sprite.setTexture(textures_[sprite_id_t::COIN]);
    sf::Vector2u size = textures_[sprite_id_t::COIN].getSize();
    entity.sprite.setScale(50.f / size.x, 50.f / size.y);
  } else if (name_entity == "ZAPPY") {
    entity.sprite.setTexture(textures_[sprite_id_t::ZAPPY]);
    sf::Vector2u size = textures_[sprite_id_t::ZAPPY].getSize();
    entity.sprite.setScale(50.f / size.x, 90.f / size.y);
  }
  entity.sprite.setPosition(x, y);
  temp_entity_.push_back(entity);
}

} // namespace JetPack
