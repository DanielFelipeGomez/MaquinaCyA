// /**
//  * @file hash_table.h
//  * @author Daniel Felipe Gomez Aristizabal (alu0101438139@ull.edu.es)
//  * @brief 
//  * @version 0.1
//  * @date 2022-04-03
//  * 
//  * @copyright Copyright (c) 2022
//  * 
//  */

// #pragma once

#include <vector>
#include "dispersion_function.h"
#include "exploration_function.h"
#include "fe_double_scatter.h"
#include "fe_lineal.h"
#include "fe_quadratic.h"
#include "fe_redispersion.h"
#include "fd_module.h"
#include "fd_pseudorandom.h"
#include "fd_sum.h"
#include "list.h"
#include "block.h"
#include "sequence.h"


template<class Key>
class HashTable{
 public:
  HashTable(int table_size, DispersionFunction<Key>* fd, ExplorationFunction<Key>* fe = nullptr, int block_size = 0) {
    table_size_ = table_size;
    fe_ = fe; 
    fd_ = fd;
    table = new Sequence<Key>*[table_size_];
    if (fe_ == nullptr) {
      for (int i = 0; i < table_size_; ++i) {
        table[i] = new List<Key>;
      }
    } else {
      for (int i = 0; i < table_size_; ++i) {
        table[i] = new Block<Key>(block_size);
      }
    }
  }
  bool Search(const Key& key) const;
  bool Insert(const Key& key);
  void Print() {
    for (int i = 0; i < table_size_; ++i) {
      std::cout << i << ")";
      table[i]->Print();
      std::cout << "\n";
    }
  }
 private:
  int table_size_;  ///especificar en el costructor
  Sequence<Key> **table;   //// revisar, la idea seria qu fuera un vetor con punteros sequuence  y su tmasañlo dsea table size
  DispersionFunction<Key>* fd_; ///se especifica en el contructor de la tabla
  ExplorationFunction<Key>* fe_;  /// en abierta asignar valor nullptr;
  int block_size_ = 0;  /// en el construcvtor poner por defecto 0 si es abierta

};


template<class Key>
bool HashTable<Key>::Search(const Key& key) const {
  int dir = fd_(key);
  if (block_size_ != 0) {
    for (int i  = 0; i < table_size_; ++i) {
      for (int j = 0; j < block_size_; ++j) {
        if(table[i][j] == key){
          return true;
        }
      }
    }
  }
  for (int i = 0; i < table_size_; ++i) {
    if (table[dir] == key) {
      return true;
    } 
  }
  return false;
  
}


template<class Key>
bool HashTable<Key>::Insert(const Key& key) {
  int dir = fd_->operator()(key);
  for (int i = 0; i < table_size_; ++i) {
    if ((table[dir]->Search(key) == false) && (table[dir]->IsFull() == false)){
      table[dir]->Insert(key);
      return true;
    } else if (table[dir]->Search(key) == true) {
      return false;
    } else if (table[dir]->IsFull() == true) {
      int displacement = fe_->operator()(key,i);
      for (int j = 0; j < displacement; ++j) {
        ++dir;
        if (dir == table_size_) {
          dir = 0;
        }
      }
    }
  }
  return false;
}