/**
 * @file state_dead.h
 * @author Daniel Felipe Gomez Aristizabal (alu0101438139@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2022-03-07
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef __STATE_DEAD__
#define __STATE_DEAD__

#include "grid.h"
#include "state.h"
#include "state_alive.h"

class State;

class Grid;

class StateDead : public State {
 public:
  StateDead();
  void Neighbors(const Grid&, int i, int j) override;
  State* NextState() override;
  char GetState() const override;

 private:
  int num_alive_ = 0;
};

#endif