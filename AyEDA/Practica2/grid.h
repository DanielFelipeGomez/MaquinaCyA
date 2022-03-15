/**
 * @file grid.h
 * @author Daniel Felipe Gomez Aristizabal (alu0101438139@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2022-03-07
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef __GRID__
#define __GRID__
#include <iostream>
#include "cell.h"

class State;

class Cell;

class Grid {
 public:
  Grid(int num_rows, int num_columns);
  void GiveLife();
  const Cell& GetCell(int, int) const;
  void NextGeneration();
  int SelectAxisX();
  int SelectAxisY();

 private:
  int num_columns_;
  int num_rows_;
  Cell** array_pointer_;
  int turno_ = 0;
};

#endif