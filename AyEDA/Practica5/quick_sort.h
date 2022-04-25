/**
 * @file quick_sort.h
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
class QuickSort : public SortClass<Key> {
 public:
  QuickSort();
  QuickSort(std::vector<Key> &vector, int start, int end);
  void Sort();
 private:
  std::vector<Key> vector_;
  int start_;
  int end_;
};

/**
 * @brief Constructor por defecto de la clase
 * 
 * @tparam Key 
 */
template<class Key>
QuickSort<Key>::QuickSort() {

}

/**
 * @brief Constructor que recibe el vector por referencia y su tamaño
 * 
 * @tparam Key 
 * @param vector 
 * @param size_vect 
 */
template<class Key>
QuickSort<Key>::QuickSort(std::vector<Key> &vector, int start, int end) {
  vector_ = vector;
  start_ = start;
  end_ = end;
}

/**
 * @brief Método para ordenar el vector, llama a su función de plantilla 
 * encargada de hacer la orddenación
 * 
 * @tparam Key 
 */
template<class Key>
void QuickSort<Key>::Sort(){
  QuickSortFunct(vector_, 0, vector_.size()-1);
}

