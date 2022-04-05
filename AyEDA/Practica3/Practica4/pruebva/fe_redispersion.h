/**
 * @file fe_redispersion.h
 * @author Daniel Felipe Gomez Aristizabal (alu0101438139@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-04-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */



#ifndef __FE_REDISPERSION__
#define __FE_REDISPERSION__

#include "exploration_function.h"
#include<stdlib.h>


template<class Key>
class feRedispersion: public ExplorationFunction<Key> {
 public:
  /**
   * @brief Constructor de la clase por defecto
   * 
   */
  feRedispersion(){}
  /**
   * @brief Sobrecarga del operador función en el que se implementa la 
   * operación para calcular el desplazamiento que se debe sumar a la 
   * dirección de la tabla. Usa de la función de pseudoaletoriedad 
   * para calcular el aux, además usamos el indice para calcular la 
   * i-esima respuesta del rand()
   * 
   * @param key 
   * @param i 
   * @return unsigned 
   */
  unsigned operator()(const Key& key, unsigned i) const {
    srand(key);
    int aux;
    for (int j = 0; j < i; ++j) {
      aux = rand();
    }
    return aux;
  }
 private:
};

#endif