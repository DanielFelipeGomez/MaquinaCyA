/**
 * @file heap_sort.h
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
class HeapSort : public SortClass<Key> {
 public:
  HeapSort();
  HeapSort(std::vector<Key> &vector, int size_vect_);
  void Sort();
 private:
  std::vector<Key> vector_;
  int size_vect_;
};

template<class Key>
HeapSort<Key>::HeapSort() {

}

template<class Key>
HeapSort<Key>::HeapSort(std::vector<Key> &vector, int size_vect) {
  vector_ = vector;
  size_vect_ = size_vect;
}

template<class Key>
void HeapSort<Key>::Sort(){
  
  HeapSortFunct(vector_,size_vect_);
}