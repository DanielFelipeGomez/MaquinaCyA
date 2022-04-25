/**
 * @file selection.h
 * @author Daniel Felipe Gómez Aristizabal (alu0101438139@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-04-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include "sort.h"
#include "sort_func.h"





template<class Key>
class Selection : public SortClass<Key> {
 public:
  Selection();
  Selection(std::vector<Key> &vector, int size_vect);
  void Sort();
 private:
  std::vector<Key> vector_;
  int size_vect_;
};

template<class Key>
Selection<Key>::Selection() {

}

template<class Key>
Selection<Key>::Selection(std::vector<Key> &vector, int size_vect) {
  vector_ = vector;
  size_vect_ = size_vect;
}

template<class Key>
void Selection<Key>::Sort(){
  SelectionFunct(vector_,size_vect_);
}