/**
 * @file main.cc
 * @author Daniel Felipe Gómez Aristizabal (alu0101438139@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-04-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <iostream>
#include <vector>
#include "context.h"
#include "sort.h"

// void PrintVector(std::vector<int> vector) {
//   for (int i = 0; i < vector.size(); ++i) {
//     std::cout << vector[i] << " , ";
//   }
//   std::cout << std::endl;

// }

int main() {
  // std::vector<int> vector = {1,3,5,7,2,9,4,6,8};
  // std::vector<int> sort_vector = vector;
  // PrintVector(vector);
  // sort_vector = QuickSort(sort_vector, 0, vector.size()-1);
  // PrintVector(vector);
  // std::cout << "Vector ordenado" << std::endl;
  // PrintVector(sort_vector);
  short type_sort, random_option;
  int size_vect = 0;
  std::cout << "Digite el algoritmo que desea utilizar\n1. Selección\n2. " 
              "QuickSort\n3. ShellSort\n4. HeapSort\n5. RadixSort" << std::endl;
  std::cin >> type_sort;
  std::cout << "Dime el tamaño de la secuencia" << std::endl;
  std::cin >> size_vect;
  std::cout << "Desea que se elijan los números aleatoriamente?\n1. Si\n2. No" << std::endl;
  std::cin >> random_option;
  Context<int> SortVector(type_sort, size_vect, random_option);
  SortVector.SortVector();
  //SortVector.PrintVector();


/// no me imprime el vercor ordenado si uso el print, sno se si es que no se pasa bein por referencia (Selection)

  return 0;
}