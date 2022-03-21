/**
 * @file tools.h
 * @author Daniel Felipe Gomez Aristizabal (alu0101438139@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2022-03-07
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>

#include "grid.h"
#include "grid_with_open_border.h"
#include "grid_with_reflective_border.h"
#include "grid_with_periodic_border.h"

/**
 * @brief Función de ayuda explicando como funciona el juego
 *
 */
void Usage() {
  std::cout << "El juego de la vida es un juego de cero jugadores, lo que \n"
               "quiere decir que su evolución está determinada por el estado \n"
               "inicial y no necesita ninguna entrada dedatos posterior.\n";
  std::cout
      << "Intrucciones de uso:\n ejecutar ./p01_game_of_life\n Se preguntará "
         "el numero de filas y columnas.\n También el número de turnos máximos.";
}

/**
 * @brief Se encarga de recbir los valores introducidos por el usuario para el
 * juego y asi asegurarse que están bien
 *
 * @param rows
 * @param columns
 * @param type_grid
 */
void CheckAll(const int& rows, const int& columns, const int& type_grid) {
  if (rows < 1) {
    Usage();
    exit(1);
  }
  if (columns < 1) {
    Usage();
    exit(1);
  }
  if (type_grid < 0 || type_grid > 3) {
    Usage();
    exit(1);
  }
}


/**
 * @brief Método encargado de preguntar al usuario que células quiere vivas
 * antes de iniciar el juego
 *
 */
void GiveLife(int num_rows_, int num_columns_, Grid* &board) {
  int axisX = 0, axisY = 0, option;
  std::cout << "Seleccione las celulas que quiere vivan inicialmente.\n";
  for (int i = 1; i < num_rows_ - 1; ++i) {
    for (int j = 1; j < num_columns_-1; ++j) {
      std::cout << "[" << i << "," << j << "] ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
  do {
    option = 0;
    std::cout
        << "Si quiere dar vida a una celula presione 1.\n ";
    std::cin >> option;
    if (option == 1 ) {
      while (true) {
        std::cout << "Digite X:" << std::endl;
        std::cin >> axisX;
        if(axisX > 0 && axisX < num_columns_-1) {
          break;
        }
      }
      while (true) {
        std::cout << "Digite Y:" << std::endl;
        std::cin >> axisY;
        if (axisY > 0 && axisY < num_rows_ - 1) {
          break;
        }
      }
      board->GetCell(axisX,axisY).SetState(new StateAlive);
      std::cout << "Soy:" << board->GetCell(axisX,axisY).GetState() << ":\n";
    } else {
      continue;
    }
  } while (option == 1);
  std::cout << "las coordenadas son:" << axisX << "," << axisY << std::endl;

  board->PrintAll();
  std::cout << "\n";
}