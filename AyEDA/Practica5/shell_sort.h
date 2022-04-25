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

/**
 * @brief Constructor por defecto de la clase
 * 
 * @tparam Key 
 */
template<class Key>
ShellSort<Key>::ShellSort() {

}

/**
 * @brief Constructor que recibe el vector por referencia y su tamaño
 * 
 * @tparam Key 
 * @param vector 
 * @param size_vect 
 */
template<class Key>
ShellSort<Key>::ShellSort(std::vector<Key> &vector, int size_vect) {
  vector_ = vector;
  size_vect_ = size_vect;
}

/**
 * @brief Método para ordenar el vector, llama a su función de plantilla 
 * encargada de hacer la orddenación, además pide el parámetro alpha 
 * para variar el número de iteraciones
 * 
 * @tparam Key 
 */
template<class Key>
void ShellSort<Key>::Sort(){
  int delta = size_vect_;
  double alpha = 1;
  std::cout << "Dime un alpha entre [0 - 1]: " << std::endl;
  std::cin >> alpha;
  while (delta >= 1){
    delta = delta * alpha ;
    ShellSortFunct(delta,vector_, size_vect_) ;
    for (int i = 0; i < size_vect_; ++i) {
    std::cout << vector_[i] << " ";
    }
    std::cout << std::endl;
  }
  
}