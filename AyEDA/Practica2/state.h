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


class Grid;

class State {
 public:
  virtual void Neighbors(const Grid&, int i, int j) = 0;
  virtual State* NextState() = 0;
  virtual char GetState() const = 0;

 protected:
  char state_;
};

#endif