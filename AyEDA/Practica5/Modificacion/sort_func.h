/**
 * @file sort_func.h
 * @author Daniel Felipe Gómez Aristizabal (alu0101438139@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-04-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

#define __COMMENTS__

#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <list>


/**
 * @brief Función auxiliar para la recursividad de la ordenación
 * HeapSort encargada de dividir los respectivos hijos de izquierda 
 * a derecha
 * 
 * @tparam Type 
 * @param vector 
 * @param size 
 * @param i 
 */
template <typename Type>
void Heapify(std::vector<Type> &vector, int size, int i) {
  int largest = i; 
  int l = 2 * i + 1; 
  int r = 2 * i + 2; 

  if (l < size && vector[l] > vector[largest]) {
    largest = l;
  }

  if (r < size && vector[r] > vector[largest]){
    largest = r;
  }
  if (largest != i) {
    std::swap(vector[i], vector[largest]);
    Heapify(vector, size, largest);
  }

}

/**
 * @brief Función encargada de imprimir por pantalla el vertor que se
 * pase por parámetros
 * 
 * @tparam Type 
 * @param vector 
 * @param size 
 */
template <typename Type>
void PrintVector(std::vector<Type> &vector, int size) {
  int i = 0;
  for (i; i < size-1; ++i) {
    std::cout << vector[i] << " , ";
  }
  std::cout << vector[i] << std::endl;
}

/**
 * @brief Función HeapSort, llama recursivamente a Heapify para resolver el 
 * árbol binario y ordenar un vector dado por parámetros
 * 
 * @tparam Type 
 * @param vector 
 * @param size 
 * @return std::vector<Type> 
 */
template <typename Type>
std::vector<Type> HeapSortFunct(std::vector<Type> &vector, int size) {
  for (int i = size / 2 - 1; i >= 0; i--) {
    Heapify(vector, size, i);
    #ifdef __COMMENTS__
    PrintVector(vector,size);
    #endif
  }
  
  for (int i = size - 1; i >= 0; --i) {
    std::swap(vector[0], vector[i]);
    Heapify(vector, i, 0);
    #ifdef __COMMENTS__
    PrintVector(vector,size);
    #endif
  }
  
  return vector;
}

/**
 * @brief Función que implementa el ordenamiento QuickSort llamandose 
 * rescursivamente, ordena un vector dado por parámetros
 * 
 * @tparam Type 
 * @param vector 
 * @param start 
 * @param end 
 * @return std::vector<Type> 
 */
template <typename Type>
std::vector<Type> QuickSortFunct(std::vector<Type> &vector, int start, int end) {
  int i = start ; int f = end ;
  int p = vector[(i+f)/2] ;
  while (i <= f){
    while (vector[i] < p) {
     i++ ;
    }
    while (vector[f] > p) {
      f-- ;
    }
    if (i <= f) {
      std::swap(vector[i],vector[f]) ;
      i++ ; 
      f-- ;
    #ifdef __COMMENTS__
    PrintVector(vector,vector.size());
    #endif
    }
  }
  if (start < f) {
    QuickSortFunct(vector, start, f) ; 
  }
  if (i < end) {
    QuickSortFunct(vector, i, end) ;
  }
  return vector;
}

/**
 * @brief Función que implementa la ordenación ShellSort, consigue ordenar 
 * un vector que se pasa por parámetros
 * 
 * @tparam Type 
 * @param delta 
 * @param vector 
 * @param size 
 * @return std::vector<Type> 
 */
template <typename Type>
std::vector<Type> ShellSortFunct(int delta, std::vector<Type> &vector, int size) {
  int x = 0, j = 0;
  for (int i = delta; i < size; ++i){
    x = vector[i] ;
    j = i ;
    while ((j >= delta) && (x < vector[j - delta])){
      vector[j] = vector[j - delta] ;
      j = j - delta ;
    } 
    vector[j] = x ;
  } 
  return vector;
}

/**
 * @brief Función que dado un vector por parámetros, lo reccore y retorna el 
 * mayor de los valores encontrados
 * 
 * @tparam Type 
 * @param vector 
 * @param size 
 * @return Type 
 */
template <typename Type>
Type GetMax(std::vector<Type> &vector, int size) {
  Type max = vector[0];
  for (int i = 1; i < size; ++i) {
    if (vector[i] > max){
      max = vector[i];
    }
  }
  return max;
}

/**
 * @brief Función auxiliar para el funcionamiento de la función de 
 * ordenación RadixSort
 * 
 * @tparam Type 
 * @param vector 
 * @param size 
 * @param exp 
 */
template <typename Type>
void CountSort(std::vector<Type> &vector, int size, int exp) {
  std::vector<Type> output; 
  output.resize(size);
  int i, count[10] = {0};
 
  for (i = 0; i < size; ++i){
    count[(vector[i] / exp) % 10]++;
  }

  for (i = 1; i < 10; ++i) {
    count[i] += count[i - 1];
  }

  for (i = size - 1; i >= 0; --i) {
    output[count[(vector[i] / exp) % 10] - 1] = vector[i];
    count[(vector[i] / exp) % 10]--;
  }
  
  for (i = 0; i < size; ++i){
    vector[i] = output[i];
  } 
}

/**
 * @brief Función que implementa el método de ordenamiento RadixSort, consigue 
 * ordenar un vector dado por parámetros
 * 
 * @tparam Type 
 * @param vector 
 * @param size 
 * @return std::vector<Type> 
 */
template <typename Type>
std::vector<Type> RadixSortFunct(std::vector<Type> &vector, int size) {
  int max = GetMax(vector, size);

  for (int exp = 1; max / exp > 0; exp *= 10){
    CountSort(vector, size, exp);
    #ifdef __COMMENTS__
    PrintVector(vector,size);
    #endif   
  }
   
  return vector;
}

/**
 * @brief Función que implementa el método de ordenamiento SelectionSort, 
 * consigue ordenar un vector que se pasa por parámetros
 * 
 * @tparam Type push_back(1000 + rand() % (10000 - 1))
 * @return std::vector<Type> 
 */
template <typename Type>
std::vector<Type> SelectionFunct(std::vector<Type> &vector, int size) {
  int min=0, x = 0;
  for (int i = 0; i < size; ++i) {
    for (int i = 0; i < size; ++i){
	    min = i ;
	    for (int j = i+1; j < size; ++j){
        if (vector[j] < vector[min]){
	        min = j ;
          #ifdef __COMMENTS__
          PrintVector(vector,size);
          #endif  
        }
      } 
	    x = vector[min] ;
	    vector[min] = vector[i] ;
	    vector[i] = x ;
	  }
  }
  #ifdef __COMMENTS__
  PrintVector(vector,size);
  #endif 
  return vector;
}

template <typename Type>
std::vector<Type> ModifyFunct(std::vector<Type> &vector, int size) {
  int i, key, j;
    for (i = 1; i < size; i++) {
        key = vector[i];
        j = i - 1;
        while (j >= 0 && vector[j] > key)
        {
            vector[j + 1] = vector[j];
            j = j - 1;
        }
        vector[j + 1] = key;
        PrintVector(vector,size);
    }
  return vector;
}