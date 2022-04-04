/**
 * @file block.h
 * @author Daniel Felipe Gomez Aristizabal (alu0101438139@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-04-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef __BLOCK__
#define __BLOCK__

#include "sequence.h"
#include <iostream>


template<class Key>
class Block: public Sequence<Key>{
 public:
  Block();
  Block(int block_size);
  bool Search(const Key& key) const;
  bool Insert(const Key& key);
  bool IsFull() const;
  void Print() {
    for (int i = 0; i < block_size_; ++i) {
      if (synonyms_[i] == NULL) {
        continue;
      }
      std::cout << "[" << synonyms_[i] << "] "; 
    }
  }
 private:
  Key* synonyms_;
  int block_size_;
};

/**
 * @brief Construtor por defecto de la clase Block
 * 
 * @tparam Key 
 */
template<class Key>
Block<Key>::Block(){

}

/**
 * @brief Constructor que recibe el tamaño del Block
 * 
 * @tparam Key 
 * @param block_size 
 */
template<class Key>
Block<Key>::Block(int block_size) {
  block_size_ = block_size;
  synonyms_ = new Key[block_size_];
}

/**
 * @brief Método de busqueda que retorna el valor booleano
 * true si el valor k del tipo Key está guardado en la secuencia. 
 * En otro caso retorna el valor false
 * 
 * @tparam Key 
 * @param key 
 * @return true 
 * @return false 
 */
template<class Key>
bool Block<Key>::Search(const Key& key) const {
  for (int i = 0; i < block_size_; ++i) {
    if (synonyms_[i] == key) {
      return true;
    }
  }
  return false;
}

template<class Key>
bool Block<Key>::Insert(const Key& key) {
  if (!Search(key)) {
    for (int i = 0; i < block_size_; ++i) {
      if (synonyms_[i] == NULL) {
        synonyms_[i] = key;
        return true;
      }
    }
  }
  return false;
}


template<class Key>
bool Block<Key>::IsFull() const {
  for (int i = 0; i < block_size_; ++i) {
    if (synonyms_[i] == NULL) {
      return false;
    } 
  }
  return true;
}

#endif