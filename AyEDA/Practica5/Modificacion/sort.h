/**
 * @file sort.h
 * @author Daniel Felipe Gómez Aristizabal (alu0101438139@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-04-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#pragma once

#include <vector>
#include "sort.h"

template<class Key>
class SortClass {
 public:
  /**
   * @brief Método virtual de la clase abstracta, que se implementa 
   * en las clases herederas
   * 
   */
  virtual void Sort() = 0;

};

