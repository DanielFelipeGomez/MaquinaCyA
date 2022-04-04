/**
 * @file fe_lineal.h
 * @author Daniel Felipe Gomez Aristizabal (alu0101438139@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-04-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __FE_LINEAL__
#define __FE_LINEAL__

#include "exploration_function.h"


template<class Key>
class feLineal: public ExplorationFunction<Key> {
 public:
  feLineal(){}
  unsigned operator()(const Key& key, unsigned indice) const {
    return indice;
  }
};

#endif