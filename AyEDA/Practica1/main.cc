/**
 * @file main.cc
 * @author Daniel Felipe Gomez Aristizabal (alu0101438139@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2022-03-07
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "tools.h"

int main() {
  Usage();
  int rows{0}, columns{0}, turns{0};
  std::cout << "\n\nDigite el número de filas: " << std::endl;
  std::cin >> rows;
  std::cout << "Digite el número de columnas: " << std::endl;
  std::cin >> columns;
  std::cout << "Digite el número máximo de turnos: " << std::endl;
  std::cin >> turns;
  CheckAll(rows, columns, turns);
  Grid board(rows, columns);
  board.GiveLife();
  for (int i = 0; i < turns; ++i) {
    board.NextGeneration();
  }

  return 0;
}