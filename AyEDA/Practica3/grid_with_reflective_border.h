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

#ifndef __GRID_WITH__REFLECTIVE_BORDER__
#define __GRID_WITH__REFLECTIVE_BORDER__
#include "grid.h"
#include "cell.h"
#include <iostream>


class Grid;

class Cell;

class GridWithReflectiveBorder : public Grid {
 public:
  GridWithReflectiveBorder(int, int);
  Cell& GetCell(int, int) override;
  const Cell& GetCell(int, int) const override;
  ~GridWithReflectiveBorder() override;

 private:
};

#endif
