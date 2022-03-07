/**
 * @file socket.h
 * @author Daniel Felipe Gómez Arisitizabal (alu0101438139@ull.edu.es)
 * @brief Declaraciones de la clase Socket
 * @version 0.1
 * @date 2021-12-13
 *
 * @copyright Copyright (c) 2021
 *
 */
#pragma once
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <system_error>
#include <errno.h>
#include <error.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <array>
#include "tools.h"

struct Message {
  std::array<char, 1024> text;
  int bytes_enviados;
};

class Socket {
 public:
  Socket(const sockaddr_in& address);
  ~Socket();
  void SendTo(const Message& message, const sockaddr_in& address);
  void ReceiveFrom(Message& message, sockaddr_in& address);
 private:
  int fd_;
};