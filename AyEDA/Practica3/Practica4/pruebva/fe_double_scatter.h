/**
 * @file fe_ double_scatter.h
 * @author Daniel Felipe Gomez Aristizabal (alu0101438139@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-04-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __FE_DOUBLE_SCATTER__
#define __FE_DOUBLE_SCATTER__

#include "exploration_function.h"
#include "dispersion_function.h"

template<class Key>
class feDoubleScatter: public ExplorationFunction<Key> {
 public:
  /**
   * @brief Constructor de la clase por defecto
   * 
   */
  feDoubleScatter(){}
  /**
   * @brief Constructor de la clase, que recibe por parámetro un puntero de 
   * DispersionFunction para usar dicha función en el cálculo de la 
   * función de exploración
   * 
   * @param disp_fucn 
   */
  feDoubleScatter(DispersionFunction<Key>* disp_fucn): disp_fucn_(disp_fucn) {}
  /**
   * @brief Sobrecarga del operador función en el que se implementa la 
   * operación para calcular el desplazamiento que se debe sumar a la 
   * dirección de la tabla. Hace uso de una fucnión de dispersión 
   * pidiendo nuevamente una dir con la clave y multiplicandola 
   * al indice dado
   * 
   * @param key 
   * @param i 
   * @return unsigned 
   */
  unsigned operator()(const Key& key, unsigned i) const {
    return (i * (disp_fucn_->operator()(key)));
  }
 private:
  DispersionFunction<Key>* disp_fucn_;
};

#endif