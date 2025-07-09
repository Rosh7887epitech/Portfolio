/*
** EPITECH PROJECT, 2025
** B-NWP-400-NAN-4-1-jetpack-romain.berard
** File description:
** Client
*
*/

#pragma once
#include <arpa/inet.h>
#include <atomic>
#include <iostream>
#include <list>
#include <mutex>
#include <stdexcept>
#include <string>
#include <sys/socket.h>
#include <unistd.h>

#include "Graphics.hpp"

namespace JetPack {
class Client {
public:
  Client() = default;
  Client(std::string ip, int port);
  ~Client();

  void readMessage(std::list<std::string> &messages, std::mutex &mutex);
  void sendMessage(std::string message);

  void clientLoop(std::atomic<bool> &running, std::list<std::string> &messages,
                  std::mutex &mutex);

  void setDebug(bool debug);

private:
  int _socket = -1;
  bool showDebug = false;
};
} // namespace JetPack
