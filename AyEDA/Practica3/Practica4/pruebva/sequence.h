/**
 * @file sequence.h
 * @author Daniel Felipe Gomez Aristizabal (alu0101438139@ull.edu.es)
 * @brief Clase abtracta que se encarga de el almacenamiento individual 
 * de la tabla de hash
 * @version 0.1
 * @date 2022-04-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
 
#ifndef __SEQUENCE__
#define __SEQUENCE__

#include <vector>


template<class Key>
class Sequence {
 public:
  virtual bool Search(const Key& key) const = 0;
  virtual bool Insert(const Key& key) = 0;
  virtual bool IsFull() const = 0;
  virtual void Print() = 0;
 protected:
};

#endif