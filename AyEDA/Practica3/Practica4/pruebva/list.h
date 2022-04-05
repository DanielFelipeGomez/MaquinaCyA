/**
 * @file list.h
 * @author Daniel Felipe Gomez Aristizabal (alu0101438139@ull.edu.es)
 * @brief Clase derivada de Sequence, donde se implemeta la función de 
 * dispersión abierta
 * @version 0.1
 * @date 2022-04-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef __LIST__
#define __LIST__

#include <vector>
#include <iostream>
#include "sequence.h"



template<class Key>
class List: public Sequence<Key> {
 public:
  List();
  bool Search(const Key& key) const;
  bool Insert(const Key& key);
  bool IsFull() const;
  /**
   * @brief Método que va recorreidno el vector dinámico y lo va imprimiendo 
   * por pantalla
   * 
   */
  void Print() {
    for (int i = 0; i < tam; ++i) {
      std::cout << "[" << synonyms_[i] << "] "; 
    }
  }
 private: 
  Key* synonyms_;
  int tam = 0;

};

/**
 * @brief Construtor por defecto de la clase, reserva memoria según el tamaño
 * 
 * @tparam Key 
 */
template<class Key>
List<Key>::List() {
  synonyms_ = new Key[tam];
} 

/**
 * @brief Método de busqueda que retorna el valor booleano
 * true si el valor k del tipo Key está guardado en la secuencia. 
 * En otro caso retorna el valor false
 * 
 * @tparam Key 
 * @param key 
 * @return true 
 * @return false 
 */
template<class Key>
bool List<Key>::Search(const Key& key) const {
  for (int i = 0; i < tam; ++i) {
    if (synonyms_[i] == key) {
      return true;
    }
  }
  return false;
}

/**
 * @brief Método que comprueba no esté el valor previamente, si no está, lo inserta
 * 
 * @tparam Key 
 * @param key 
 * @return true 
 * @return false 
 */
template<class Key>
bool List<Key>::Insert(const Key& key) {
  if (!Search(key)) {
    /// tam++;
    /// std::cout << "para " << key << "es estos"<<tam << std::endl;
    /// synonyms_ = new Key[tam];   //// revisar func 
    /// //tam++;
    /// synonyms_[tam-1] = key;
    tam++;
    for (int i = 0; i < tam; ++i) {
      if (synonyms_[i] == NULL) {
        synonyms_[i] = key;
        return true;
      }
    }
    return true;
  }
  return false;
}


/**
 * @brief Método que se encarga de verificar que el bloque no esté lleno
 * 
 * @tparam Key 
 * @return true 
 * @return false 
 */
template<class Key>
bool List<Key>::IsFull() const {
  return false;
}


#endif