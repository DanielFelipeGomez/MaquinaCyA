/**
 * @file state_egg.h
 * @author Daniel Felipe Gomez Aristizabal (alu0101438139@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2022-03-07
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef __STATE_EGG__
#define __STATE_EGG__

#include "state.h"
#include "state_dead.h"
#include "state_larva.h"

class StateEgg : public State {
 public:
  StateEgg();
  void Neighbors(const Grid&, int i, int j) override;
  State* NextState() override;
  char GetState() const override;

 private:
  int num_larva_ = 0;
  int num_huevo_ = 0;
};

#endif