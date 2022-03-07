/**
 * @file tools.cc
 * @author Daniel Felipe Gómez Arisitizabal (alu0101438139@ull.edu.es)
 * @brief Definiciones de las funciones de tools.h
 * @version 0.1
 * @date 2021-12-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "tools.h"

/**
 * @brief Crea la dirección a partir de rellenar el struct 'socaddr_in'
 *
 * @param port
 * @param ip_address
 * @return sockaddr_in
 */
sockaddr_in MakeIpAddress(int port, const std::string& ip_address) {  
  // Dirección del socket local
  sockaddr_in new_addr{};        // Así se inicializa a 0, como se recomienda
  new_addr.sin_family = AF_INET;        // Pues el socket es de dominio AF_INET
  if (ip_address == "") {
    new_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    new_addr.sin_port = htons(port);
  } else {
    new_addr.sin_port = htons(port);
    inet_aton(ip_address.data(), &new_addr.sin_addr);
  }
  return new_addr;
}

/**
 * @brief Función main protegida de viewnetsend
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int ProtectedMainSend(int argc, char* argv[]) {
  const int port_local = 6000;
  const int port_remote = 6001;
  sockaddr_in local_address{};
  sockaddr_in remote_address{};
  local_address = MakeIpAddress(port_local, "127.0.0.1");
  Socket socket(local_address);

  remote_address = MakeIpAddress(port_remote, "127.0.0.1");
  Message message;
  File file("pruebas.txt");
  int bytes_enviados;

  do {
    bytes_enviados = read(file.GetFileDescriptor(), message.text.data(), 1024);
    message.bytes_enviados = bytes_enviados;
    socket.SendTo(message, remote_address);
  } while (message.bytes_enviados != 0);

  return 0;
}

/**
 * @brief Función main protegida de viewnetreceive
 *
 * @param argc
 * @param argv
 * @return int
 */
int ProtectedMainReceive(int argc, char* argv[]) {
  const int port_local = 6001;

  sockaddr_in local_address{};
  sockaddr_in remote_address{};

  local_address = MakeIpAddress(port_local, "127.0.0.1");
  Socket socket(local_address);

  Message message;
  do {
    socket.ReceiveFrom(message, remote_address);
    char* remote_ip = inet_ntoa(remote_address.sin_addr);
    int remote_port = ntohs(remote_address.sin_port);
    if (message.bytes_enviados == 0) {
      break;
    }
    std::string mensaje_string(message.text.data(), message.bytes_enviados);
    std::cout << "El sistema " << remote_ip << " : " << remote_port
              << std::endl;
    std::cout << "Envió\n" << mensaje_string << "'\n";
  } while (true);

  return 0;
}
