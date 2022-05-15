/**
 * @file main.cc
 * @author Daniel Felipe Gómez Aristizabal alu0101438139@ull.edu.es
 * @brief 
 * @version 0.1
 * @date 2022-05-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include "nodob.h"
#include "abe.h"
#include "abb.h"

using Key = int;
int main() {
  short option;
  AB<Key>* Tree = new ABB<Key>;
  while (true) {
    Key clave = 0;
    std::cout << "[0] Salir\n[1] Insertar clave\n[2] Buscar clave\n[3] eliminar clave\n[4] Mostrar árbol inorden" << std::endl;
    std::cin >> option;
    switch (option) {
    case 0:
      std::cout << "Fin del programa" << std::endl;
      return 0;
      break;
    case 1:
      std::cout << "Ingrese la clave a insertar: " << std::endl;
      std::cin >> clave;
      Tree->Insert(clave);
      std::cout << Tree << std::endl;
      break;
    case 2:
      std::cout << "Ingrese la clave a buscar: " << std::endl;
      std::cin >> clave;
      if (Tree->Search(clave)) {
        std::cout << "Se encontró la clave" << std::endl;;
      } else {
        std::cout << "No se encontró la clave" << std::endl;;
      }
      break;
    case 3:
      std::cout << "Ingrese la clave a eliminar: " << std::endl;
      std::cin >> clave;
      if (Tree->Erase(clave)) {
        std::cout << "Se ha eliminado la clave" << std::endl;
      } else {
        std::cout << "No se ha eliminado la clave" << std::endl;
      }
      break;
    case 4:
      Tree->InOrden();
      std::cout << std::endl;
      break;
    
    default:
      break;
    }
  }

  return 0;
}