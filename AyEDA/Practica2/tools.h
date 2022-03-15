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
 * @param turns
 */
void CheckAll(const int& rows, const int& columns, const int& turns) {
  if (rows < 1) {
    Usage();
    exit(1);
  }
  if (columns < 1) {
    Usage();
    exit(1);
  }
  if (turns < 0) {
    Usage();
    exit(1);
  }
}