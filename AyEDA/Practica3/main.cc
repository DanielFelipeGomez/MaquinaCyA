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
  int rows{0}, columns{0}, type_grid{0};
  std::cout << "\n\nDigite el número de filas: " << std::endl;
  std::cin >> rows;
  std::cout << "Digite el número de columnas: " << std::endl;
  std::cin >> columns;
  std::cout << "Digite el número de tipo de rejilla:\n  1. OpenBorder\n  2.PeriodicBorder\n  3.ReflectiveBorder" << std::endl;
  std::cin >> type_grid;
  CheckAll(rows, columns, type_grid);
  Grid* board;
  if (type_grid == 1) {
    board = new GridWithOpenBorder(rows,columns);
  } else if (type_grid == 2) {
    board = new GridWithPeriodicBorder(rows, columns);
  } else {
    board = new GridWithReflectiveBorder(rows, columns);
  }
  std::cout << ":"<< board->GetCell(0, 0) << ":"<< std::endl;
  GiveLife(rows + 2, columns + 2, board);

  char option = {'a'};
  do {
    board->NextGeneration();
    std::cout << "Enter para continuar, \'s\' para terminar\n";
    option = getchar();
  } while (option != 's');
  return 0;
}