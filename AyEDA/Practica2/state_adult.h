/**
 * @file state_adult.h
 * @author Daniel Felipe Gomez Aristizabal (alu0101438139@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2022-03-07
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef __STATE_ADULT__
#define __STATE_ADULT__

#include "state.h"
#include "grid.h"
#include "state_egg.h"
#include "state_dead.h"

class State;

class Grid;

class StateAdult : public State {
 public:
  StateAdult();
  void Neighbors(const Grid&, int i, int j) override;
  State* NextState() override;
  char GetState() const override;

 private:
  int num_adult = 0;
};

#endif