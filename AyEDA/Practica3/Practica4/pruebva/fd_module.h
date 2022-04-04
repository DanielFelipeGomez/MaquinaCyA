/**
 * @file fd_module.h
 * @author Daniel Felipe Gomez Aristizabal (alu0101438139@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-04-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __FD_MODULE__
#define __FD_MODULE__

#include "dispersion_function.h"

template<class Key>
class fdModule: public DispersionFunction<Key> {
 public:
  fdModule(const unsigned table_size): table_size_(table_size) {}
  unsigned operator()(const Key& key) const {
    return key % table_size_;
  }
 private:
  unsigned table_size_;
};


#endif