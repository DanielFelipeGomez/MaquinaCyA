/**
 * @file nodob.h
 * @author Daniel Felipe Gómez Aristizabal alu0101438139@ull.edu.es
 * @brief 
 * @version 0.1
 * @date 2022-05-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __NODOB_CLASS__
#define __NODOB_CLASS__

#include <iostream>

template <class Key> 
class NodeB {
 public:
  NodeB();
  NodeB(Key key);
  Key GetInformation();
  NodeB<Key>* GetLeft();
  NodeB<Key>* GetRight();
  void SetInformation(Key information) {
    information_ = information;
  }
  void SetLeft(NodeB<Key>* left) {
    left_ = left;
  }
  void SetRight(NodeB<Key>* right) {
    right_ = right;
  }
 private:
  Key information_;
  NodeB<Key>* left_ = nullptr;
  NodeB<Key>* right_ = nullptr;
};

/**
 * @brief Constructor por defecto de la clase
 * 
 * @tparam Key 
 */
template<class Key>
NodeB<Key>::NodeB(){
  right_ = nullptr;
  left_ = nullptr;
}

/**
 * @brief Constructor que recibe una clave por parámetros e incializa los 
 * atributos con la clave que se ha pasado y aputa a null cada uno de sus 
 * nodos hijos.
 * 
 * @tparam Key 
 * @param key 
 */
template<class Key>
NodeB<Key>::NodeB(Key key){
  information_ = key;
  right_ = nullptr;
  left_ = nullptr;
}

/**
 * @brief Getter del atributo information_
 * 
 * @tparam Key 
 * @return Key 
 */
template<class Key>
Key NodeB<Key>::GetInformation() {
  return information_;
}

/**
 * @brief Getter del atributo left_
 * 
 * @tparam Key 
 * @return NodeB<Key>* 
 */
template<class Key>
NodeB<Key>* NodeB<Key>::GetLeft() {
  return left_;
}

/**
 * @brief Getter del atributo right_
 * 
 * @tparam Key 
 * @return NodeB<Key>* 
 */
template<class Key>
NodeB<Key>* NodeB<Key>::GetRight() {
  return right_;
}

#endif