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

#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <list>



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

template <typename Type>
std::vector<Type> HeapSortFunct(std::vector<Type> &vector, int size) {
  for (int i = size / 2 - 1; i >= 0; i--) {
    Heapify(vector, size, i);
    int j = 0;
    for (j; j < vector.size()-1; ++j) {
      std::cout << vector[j] << " , ";
    }
    std::cout << std::endl;
  }
  
  for (int i = size - 1; i >= 0; --i) {
    std::swap(vector[0], vector[i]);
    Heapify(vector, i, 0);
      int j = 0;
    for (j; j < vector.size()-1; ++j) {
    std::cout << vector[j] << " , ";
    }
    std::cout << std::endl;
  }
  
  return vector;
}

template <typename Type>
std::vector<Type> QuickSortFunct(std::vector<Type> &vector, int start, int end) {
  int j = 0;
  for (j; j < vector.size()-1; ++j) {
    std::cout << vector[j] << " , ";
  }
  std::cout << vector[j] << std::endl;
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
    }
    int j = 0;
    for (j; j < vector.size()-1; ++j) {
      std::cout << vector[j] << " , ";
    }
    std::cout << vector[j] << std::endl;
  }
  if (start < f) {
    QuickSortFunct(vector, start, f) ; 
  }
  if (i < end) {
    QuickSortFunct(vector, i, end) ;
  }
  return vector;
}

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

template <typename Type>
std::vector<Type> RadixSortFunct(std::vector<Type> &vector, int size) {
  int max = GetMax(vector, size);

  for (int exp = 1; max / exp > 0; exp *= 10){
    CountSort(vector, size, exp);
    int k = 0;
    for (k; k < size - 1; ++k) {
      std::cout << vector[k] << " , ";
    }
    std::cout << vector[k] << std::endl;
  }
   
  return vector;
}


template <typename Type>
std::vector<Type> SelectionFunct(std::vector<Type> &vector, int size) {
  int min=0, x = 0;
  for (int i = 0; i < size; ++i) {
  for (int i = 0; i < size; ++i){
	  min = i ;
	  for (int j = i+1; j < size; ++j){
      if (vector[j] < vector[min]){
	      min = j ;
      }
    } 
	  x = vector[min] ;
	  vector[min] = vector[i] ;
	  vector[i] = x ;
	}
  for(int i = 0; i < size; ++i) {
    std::cout << vector[i] << " " ;
  }
  std::cout << std::endl; 
  }
  return vector;
}

