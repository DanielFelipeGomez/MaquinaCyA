/**
 * @file shell_sort.h
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
class ShellSort : public SortClass<Key> {
 public:
  ShellSort();
  ShellSort(std::vector<Key> &vector, int size_vect);
  void Sort();
 private:
  std::vector<Key> vector_;
  int size_vect_;
};

template<class Key>
ShellSort<Key>::ShellSort() {

}

template<class Key>
ShellSort<Key>::ShellSort(std::vector<Key> &vector, int size_vect) {
  vector_ = vector;
  size_vect_ = size_vect;
}

template<class Key>
void ShellSort<Key>::Sort(){
  int delta = size_vect_ ;
  while (delta > 1){
    delta = delta / 2 ;
    ShellSortFunct(delta,vector_, size_vect_) ;
    for (int i = 0; i < size_vect_; ++i) {
    std::cout << vector_[i] << " ";
    }
    std::cout << std::endl;
  }
  
}