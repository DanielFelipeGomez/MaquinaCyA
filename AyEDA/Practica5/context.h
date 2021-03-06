/**
 * @file context.h
 * @author Daniel Felipe Gómez Aristizabal (alu0101438139@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-04-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef __SORT__
#define __SORT__

#include <vector>
#include <stdlib.h>
#include "sort.h"
#include "quick_sort.h"
#include "radix_sort.h"
#include "selection.h"
#include "shell_sort.h"
#include "heap_sort.h"
#include "sort_func.h"

template<class Key>
class Context {
 public:
  Context();
  Context(short type_func, int size_vect, short random_option);
  void SortVector();
  void PrintVector();

 private:
  SortClass<Key>* sort_pointer_;
  int size_vect_;
  std::vector<Key> vector_;
};

/**
 * @brief Constructor por defecto de la clase
 * 
 * @tparam Key 
 */
template<class Key>
Context<Key>::Context() {
}

/**
 * @brief Constructor de la clase, que crea el objetpo de la clase que 
 * corresponda según lo elegido por parámetros, además de rellenar 
 * el vector (de forma aleatoria o manual)
 * 
 * @tparam Key 
 * @param type_func 
 * @param size_vect 
 * @param random_option 
 */
template<class Key>
Context<Key>::Context(short type_func, int size_vect, short random_option) {
  size_vect_ = size_vect;
  if (random_option == 1){
    for (int i = 0; i < size_vect_; ++i) {
      srand(size_vect_*i);
      vector_.push_back(1000 + rand() % (10001 - 1000));
    }
  } else {
    std::cout << "Rellenar el vector manualmente" << std::endl;
    Key num;
    for (int i = 0; i < size_vect_; ++i) {
      std::cout << "Dame el valor " << i+1 << ":\n"; 
      std::cin >> num;
      vector_.push_back(num);
    }
  }
  std::cout << "LA SECUENCIA." << std::endl;
  int i = 0;
  for (i; i < size_vect_-1; ++i) {
    std::cout << vector_[i] << " , ";
  }
  std::cout << vector_[i] << std::endl;
  switch (type_func) {
    case 1 : 
      sort_pointer_ = new Selection<int>(vector_,size_vect_-1);
      break;
    case 2 : 
      sort_pointer_ = new QuickSort<int>(vector_, 0, size_vect_-1);
      break;
    case 3 : 
      sort_pointer_ = new ShellSort<int>(vector_,size_vect_-1);
      break;
    case 4: 
      sort_pointer_ = new HeapSort<int>(vector_,size_vect_-1);
      break;
    case 5 : 
      sort_pointer_ = new RadixSort<int>(vector_, size_vect_);
      break;
    default:
      break;
  }
}

/**
 * @brief Método encargado de llamar el método de ordenamiento que corresponda
 * 
 * @tparam Key 
 */
template<class Key>
void Context<Key>::SortVector() {
  sort_pointer_->Sort();
}


#endif