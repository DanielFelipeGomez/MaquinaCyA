/**
 * @file fd_sum.h
 * @author Daniel Felipe Gomez Aristizabal (alu0101438139@ull.edu.es)
 * @brief Clase derivada que implemta la función des desipersión Basada en suma
 * @version 0.1
 * @date 2022-04-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __FD_SUM__
#define __FD_SUM__

#include "dispersion_function.h"


template<class Key>
class fdSum: public DispersionFunction<Key> {
 public:
  /**
  * @brief Constructor de la clase, que recibe por parámetro el tamaño de 
  * la tabla de hash
  * 
  * @param table_size 
  */
  fdSum(const unsigned table_size): table_size_(table_size){}
  /**
   * @brief Sobrecarga del operador función, en que se implementa el método 
   * para retornar la dirección
   * 
   * @param key 
   * @return unsigned 
   */
  unsigned operator()(const Key& key) const {
    int div_key = key, aux1 = 0, dir = 0 ;
    while (div_key > 0){ 
        aux1 = div_key % 10;
        dir = dir + aux1;
        div_key = div_key / 10;
    }
    return (dir % table_size_);
  }
 private:
  unsigned table_size_;
};

#endif