/**
 * @file fe_quadratic.h
 * @author Daniel Felipe Gomez Aristizabal (alu0101438139@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-04-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __FE_QUADRATIC__
#define __FE_QUADRATIC__

#include "exploration_function.h"


template<class Key>
class feQuadratic: public ExplorationFunction<Key> {
 public:
  feQuadratic(){}
  unsigned operator()(const Key& key, unsigned i) const {
    return (i*i);
  }
};

#endif