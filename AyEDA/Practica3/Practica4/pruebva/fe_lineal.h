/**
 * @file fe_lineal.h
 * @author Daniel Felipe Gomez Aristizabal (alu0101438139@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-04-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __FE_LINEAL__
#define __FE_LINEAL__

#include "exploration_function.h"


template<class Key>
class feLineal: public ExplorationFunction<Key> {
 public:
  /**
   * @brief Constructor de la clase por defecto
   * 
   */
  feLineal(){}
  /**
   * @brief Sobrecarga del operador función en el que se implementa la 
   * operación para calcular el desplazamiento que se debe sumar a la 
   * dirección de la tabla. Simplemente retorna el indice dado.
   * 
   * @param key 
   * @param i 
   * @return unsigned 
   */
  unsigned operator()(const Key& key, unsigned indice) const {
    return indice;
  }
};

#endif