/**
 * @file state_pupa.h
 * @author Daniel Felipe Gomez Aristizabal (alu0101438139@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2022-03-07
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef __STATE_PUPA__
#define __STATE_PUPA__

#include "state.h"
#include "state_dead.h"
#include "state_adult.h"

class State;

class Grid;

class StatePupa : public State {
 public:
  StatePupa();
  void Neighbors(const Grid&, int i, int j) override;
  State* NextState() override;
  char GetState() const override;

 private:
  int num_egg_ = 0;
  int num_died_ = 0;
  int num_adult_ = 0;
  int num_larva_ = 0;
  int num_pupa_ = 0;
};

#endif