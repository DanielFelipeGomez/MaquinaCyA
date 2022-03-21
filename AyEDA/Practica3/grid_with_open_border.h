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

#ifndef __GRID_WITH_OPEN__BORDER__
#define __GRID_WITH_OPEN__BORDER__
#include "grid.h"
#include "cell.h"
#include <iostream>

class Grid;

class Cell;

class GridWithOpenBorder : public Grid {
 public:
  GridWithOpenBorder(int, int);
  Cell& GetCell(int, int) override;
  const Cell& GetCell(int, int) const override;
  ~GridWithOpenBorder() override;

 private:

};

#endif