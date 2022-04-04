/**
 * @file fe_ double_scatter.h
 * @author Daniel Felipe Gomez Aristizabal (alu0101438139@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-04-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __FE_DOUBLE_SCATTER__
#define __FE_DOUBLE_SCATTER__

#include "exploration_function.h"
#include "dispersion_function.h"

template<class Key>
class feDoubleScatter: public ExplorationFunction<Key> {
 public:
  feDoubleScatter(){}
  feDoubleScatter(DispersionFunction<Key>* disp_fucn): disp_fucn_(disp_fucn) {}
  unsigned operator()(const Key& key, unsigned i) const {
    return (i * (disp_fucn_->operator()(key)));
  }
 private:
  DispersionFunction<Key>* disp_fucn_;
};

#endif