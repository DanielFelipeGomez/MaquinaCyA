/**
 * @file state.h
 * @author Daniel Felipe Gomez Aristizabal (alu0101438139@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2022-03-07
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef __STATE__
#define __STATE__

class State {
 public:
  State(): state_{false} {} ;
  bool GetState();
  void SetState(bool new_state);

 private:
  bool state_;
};


#endif