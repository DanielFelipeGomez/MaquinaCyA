/**
 * @file exploration_function.h
 * @author Daniel Felipe Gomez Aristizabal (alu0101438139@ull.edu.es)
 * @brief Clase abstracta de la que derivan las diferentes funciones de exploración
 * @version 0.1
 * @date 2022-04-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __EXPLORATION_FUNCTION__
#define __EXPLORATION_FUNCTION__

template<class Key>
class ExplorationFunction {
 public:
  virtual unsigned operator()(const Key& k, unsigned i) const = 0;
};

#endif