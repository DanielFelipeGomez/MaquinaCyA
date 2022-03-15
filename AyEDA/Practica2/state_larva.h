/**
 * @file state_larva.h
 * @author Daniel Felipe Gomez Aristizabal (alu0101438139@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2022-03-07
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef __STATE_LARVA__
#define __STATE_LARVA__

#include "state.h"
#include "state_dead.h"
#include "state_pupa.h"

class State;

class Grid;

class StateLarva : public State{
 public:
  StateLarva();
  void Neighbors(const Grid&, int i, int j) override;
  State* NextState() override;
  char GetState() const override;

 private:
  int num_egg_ = 0;
  int num_pupa_ = 0;
  int num_adult_ = 0;
  int num_larva_ = 0;
};

#endif