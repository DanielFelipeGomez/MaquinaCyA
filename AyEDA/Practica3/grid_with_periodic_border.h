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

#ifndef __GRID_WITH__PERIODIC_BORDER__
#define __GRID_WITH__PERIODIC_BORDER__
#include <iostream>

#include "cell.h"
#include "grid.h"

class Grid;

class Cell;

class GridWithPeriodicBorder : public Grid {
 public:
  GridWithPeriodicBorder(int, int);
  Cell& GetCell(int, int) override;
  const Cell& GetCell(int, int) const override;
  ~GridWithPeriodicBorder() override;

 private:
};

#endif