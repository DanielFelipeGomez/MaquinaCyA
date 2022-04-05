/**
 * @file dispersion_function.h
 * @author Daniel Felipe Gomez Aristizabal (alu0101438139@ull.edu.es)
 * @brief Clase abstracta de la que derivan las funciones de dispersión
 * @version 0.1
 * @date 2022-04-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __DISPERSION_FUNCTION__
#define __DISPERSION_FUNCTION__

template<class Key>
class DispersionFunction {
 public:
  virtual unsigned operator()(const Key& key) const = 0;
};

#endif