/**
 * @file radix_sort.h
 * @author Daniel Felipe Gómez Aristizabal (alu0101438139@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-04-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include "sort.h"
#include "sort_func.h"





template<class Key>
class RadixSort : public SortClass<Key> {
 public:
  RadixSort();
  RadixSort(std::vector<Key> &vector, int size_vect);
  void Sort();
 private:
  std::vector<Key> vector_;
  int size_vect_;
};

template<class Key>
RadixSort<Key>::RadixSort() {

}

template<class Key>
RadixSort<Key>::RadixSort(std::vector<Key> &vector, int size_vect) {
  vector_ = vector;
  size_vect_ = size_vect;
}

template<class Key>
void RadixSort<Key>::Sort(){
  
  RadixSortFunct(vector_,size_vect_);
}

