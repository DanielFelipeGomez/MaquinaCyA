/**
 * @file socket.cc
 * @author Daniel Felipe Gómez Arisitizabal (alu0101438139@ull.edu.es)
 * @brief Definiciones de la clase Socket
 * @version 0.1
 * @date 2021-12-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "socket.h"

/**
 * @brief Constructor de la clase Socket, crea el descriptor del socket con sus
 * respectivos parámetros para los protocolos con los que trabajaremos, y se
 * llama a 'bind' para asignar una dirección al socket
 *
 * @param address
 */
Socket::Socket(const sockaddr_in& address) {
  fd_ = socket(AF_INET, SOCK_DGRAM, 0);
  if (fd_ < 0 ) {
    throw std::system_error(errno, std::system_category(), "ViewNet: No se pudo crear el socket");
  }
  int result = bind(fd_, reinterpret_cast<const sockaddr*>(&address),
                          sizeof(address));
  if (result < 0) {
    throw std::system_error(errno, std::system_category(), "ViewNet: Falló llamada a bind");
  }
  
}

/**
 * @brief Destructor de la clase Socket, se cierra el descriptor del socket
 * 
 */
Socket::~Socket(){
  close(fd_);
}

/**
 * @brief Se encarga de enviar el mensaje al socket que nos interesa
 * 
 * @param message 
 * @param address 
 */
void Socket::SendTo(const Message& message, const sockaddr_in& address) {
  int result = sendto(fd_, &message, sizeof(message), 0,
        reinterpret_cast<const sockaddr*>(&address), sizeof(address));
  if (result < 0) {
    throw std::system_error(
        errno, std::system_category(),
        "ViewNet: No se pudo enviar el mensaje correctamente");
  }
}

/**
 * @brief Se encarga de recibir el mensaje
 * 
 * @param message 
 * @param address 
 */
void Socket::ReceiveFrom(Message& message, sockaddr_in& address) {
  socklen_t src_len = sizeof(address);
  int result = recvfrom(fd_, &message, sizeof(message), 0,
        reinterpret_cast<sockaddr*>(&address), &src_len);
  if (result < 0) {
    throw std::system_error(
        errno, std::system_category(),
        "ViewNet: No se pudo recibir el mensaje correctamente");
  }
}
