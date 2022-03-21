/**
 * @file cell.h
 * @author Daniel Felipe Gomez Aristizabal (alu0101438139@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-03-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
 
#ifndef __CELL__
#define __CELL__
#include "grid.h"
#include "state.h"
#include "state_dead.h"
#include <vector>
#include <utility>

class State;

class Grid;

class Cell {
 public:
  Cell();
  Cell(State* state, int axisX, int axisY);
  char GetState() const;
  void SetState(State*);
  void UpdateState();
  void Neighbors(const Grid&);
  friend std::ostream& operator<<(std::ostream&, const Cell&);

 private:
  State* state_;
  int axisX_;
  int axisY_;
};

#endif