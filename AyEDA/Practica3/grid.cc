/**
 * @file grid.cc
 * @author Daniel Felipe Gomez Aristizabal (alu0101438139@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2022-03-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "grid.h"

/**
 * @brief Se encarga de ir incrementando el número de turnos, aademás de hacer
 * los 3 recorridos necesarios
 * - Uno para determinar el número de vecinos vivos de cada célula
 * - Otro para definir el estado nuevom de cada célula
 * - Un último recorrido imprimiendo cada célula
 *
 */
void Grid::NextGeneration() {

  turno_ += 1;
  for (int i = 1; i < num_rows_ - 1; ++i) {
    for (int j = 1; j < num_columns_ - 1; ++j) {
      GetCell(i,j).Neighbors(*this);
    }
  }

  for (int i = 1; i < num_rows_ - 1; ++i) {
    for (int j = 1; j < num_columns_ - 1; ++j) {
      GetCell(i,j).UpdateState();
    }
  }

  PrintAll();

  std::cout << "\n";
}


void Grid::PrintAll() {
  std::cout << "--- Turno " << turno_ << " ---\n";
  for (int i = 1; i < num_rows_ - 1; ++i) {
    std::cout << "|";
    for (int j = 1; j < num_columns_-1; ++j) {
      std::cout << array_pointer_[i][j];
    }
    std::cout << "|";
    std::cout << "\n";
  }
}