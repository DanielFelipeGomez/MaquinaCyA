/**
 * @file grid.h
 * @author Daniel Felipe Gomez Aristizabal (alu0101438139@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2022-03-20
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
  virtual Cell& GetCell(int, int) = 0;
  virtual const Cell& GetCell(int, int) const = 0;
  void NextGeneration();
  int SelectAxisY(int num_columns_);
  int SelectAxisX(int num_rows_);
  void PrintAll();
  virtual ~Grid(){};

 protected:
  int num_columns_;
  int num_rows_;
  Cell** array_pointer_;
  int turno_ = 0;
};

#endif