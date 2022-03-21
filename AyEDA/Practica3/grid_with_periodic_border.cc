/**
 * @file grid.cc
 * @author Daniel Felipe Gomez Aristizabal (alu0101438139@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2022-03-07
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "grid_with_periodic_border.h"

/**
 * @brief Constructor de la clase Grid, recibe el número de filas y columnas y
 * crea dinámicamente una  matriz de objetos de la clase Cell, inicializandolos
 * muertos por defecto
 *
 * @param num_rows
 * @param num_columns
 */
GridWithPeriodicBorder::GridWithPeriodicBorder(int num_rows, int num_columns) {
  num_rows_ = num_rows + 2;
  num_columns_ = num_columns + 2;
  array_pointer_ = new Cell*[num_rows_];
  for (int i = 0; i < num_rows_ + 2; ++i) {
    array_pointer_[i] = new Cell[num_columns_];
  }
  for (int i = 0; i < num_rows_; ++i) {
    for (int j = 0; j < num_columns_; ++j) {
      Cell nueva(new StateDead, i, j);
      array_pointer_[i][j] = nueva;
    }
  }
}

/**
 * @brief Get the Cell object
 *
 * @return Cell&
 */
Cell& GridWithPeriodicBorder::GetCell(int axisX, int axisY) {
  if (axisX == 0) {
    axisX += num_rows_ - 2;
  }
  if (axisY == 0) {
    axisY += num_columns_ - 2;
  }
  if (axisX == num_rows_-1) {
    axisX = 1;
  }
  if (axisY == num_columns_-1) {
    axisY = 1;
  }

  return array_pointer_[axisX][axisY];
}

/**
 * @brief Getter de la Cell, devulve la célula que esté ubicada en la matriz en
 * las coordenadas dadas por parámetro
 *
 * @param axisX
 * @param axisY
 * @return const Cell&
 */
const Cell& GridWithPeriodicBorder::GetCell(int axisX, int axisY) const {
  if (axisX == 0) {
    axisX += num_rows_ - 2;
  }
  if (axisY == 0) {
    axisY += num_columns_ - 2;
  }
  if (axisX == num_rows_ - 1) {
    axisX = 1;
  }
  if (axisY == num_columns_ - 1) {
    axisY = 1;
  }
  return array_pointer_[axisX][axisY];
}

/**
 * @brief Destroy the Grid With Open Border:: Grid With Open Border object
 *
 */
GridWithPeriodicBorder::~GridWithPeriodicBorder() {
  for (int i = 0; i < num_rows_; ++i) {
    delete[] array_pointer_[i];
  }
  delete[] array_pointer_;
}
