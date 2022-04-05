/**
 * @file fe_quadratic.h
 * @author Daniel Felipe Gomez Aristizabal (alu0101438139@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-04-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __FE_QUADRATIC__
#define __FE_QUADRATIC__

#include "exploration_function.h"


template<class Key>
class feQuadratic: public ExplorationFunction<Key> {
 public:
  /**
   * @brief Constructor de la clase por defecto
   * 
   */
  feQuadratic(){}
  /**
   * @brief Sobrecarga del operador función en el que se implementa la 
   * operación para calcular el desplazamiento que se debe sumar a la 
   * dirección de la tabla. Simplemente retorna la multiplicación del 
   * indice por si mismo.
   * 
   * @param key 
   * @param i 
   * @return unsigned 
   */
  unsigned operator()(const Key& key, unsigned i) const {
    return (i*i);
  }
};

#endif