/**
 * @file viewnetsend.cc
 * @author Daniel Felipe Gómez Arisitizabal (alu0101438139@ull.edu.es)
 * @brief main de el programa encargado de enviar los mensaje
 * @version 0.1
 * @date 2021-12-13
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "tools.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cerrno>

int main(int argc, char* argv[]) {
  /// Manejo de errores
  try {
    return ProtectedMainSend(argc, argv);

  } catch(std::system_error& e) {
    std::cerr << "mitalk"
              << ": " << e.what() << '\n';
    return 2;
  }
  
  return 0;
}