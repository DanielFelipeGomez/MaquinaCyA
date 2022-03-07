/**
 * @file tools.h
 * @author Daniel Felipe Gómez Arisitizabal (alu0101438139@ull.edu.es)
 * @brief Declaraciones de las funciones de utilería
 * @version 0.1
 * @date 2021-12-13
 *
 * @copyright Copyright (c) 2021
 *
 */
#pragma once
#include <iostream>
#include <string>
#include <errno.h>
#include <error.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <system_error>
#include <arpa/inet.h>
#include "file.h"
#include "socket.h"

sockaddr_in MakeIpAddress(int port, const std::string& ip_address );
int ProtectedMainSend(int argc, char* argv[]);
int ProtectedMainReceive(int argc, char* argv[]);
