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
#include "state.h"
#include "grid.h"
class Grid;

class Cell {
 public:
  Cell();
  Cell(bool state, int axisX, int axisY, int life_neighborns);
  State GetState() const;
  void SetState(State);
  void UpdateState();
  int Neighbors(const Grid&);
  friend std::ostream& operator<<(std::ostream&, const Cell&);
  void SetLiveNeighborns(int live_neigh);

 private:
  State state_;
  State next_state_;
  int axisX_;
  int axisY_;
  int life_neighborns_{0};
};

#endif