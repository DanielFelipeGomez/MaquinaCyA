/**
 * @file fd_pseudorandom.h
 * @author Daniel Felipe Gomez Aristizabal (alu0101438139@ull.edu.es)
 * @brief Clase derivada que implemta la función des desipersión Pseudorandom
 * @version 0.1
 * @date 2022-04-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __FD_PSEUDORANDOM__
#define __FD_PSEUDORANDOM__

#include "dispersion_function.h"
#include <stdlib.h>



template<class Key>
class fdPseudorandom: public DispersionFunction<Key> {
 public:
  /**
  * @brief Constructor de la clase, que recibe por parámetro el tamaño de 
  * la tabla de hash
  * 
  * @param table_size 
  */
  fdPseudorandom(const unsigned table_size): table_size_(table_size){}
  /**
   * @brief Sobrecarga del operador función, en que se implementa el método 
   * para retornar la dirección
   * 
   * @param key 
   * @return unsigned 
   */
  unsigned operator()(const Key& key) const {
    srand(key);
    return rand() % table_size_;
  }
 private:
  unsigned table_size_;
};

#endif