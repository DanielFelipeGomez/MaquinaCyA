/**
 * @file abe.h
 * @author Daniel Felipe Gómez Aristizabal alu0101438139@ull.edu.es
 * @brief 
 * @version 0.1
 * @date 2022-05-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __ABE_CLASS__
#define __ABE_CLASS__

#include <queue>
#include <iostream>
#include "ab.h"

template<class Key>
class ABE : public AB<Key> {
 public:
  ABE();
  const int Size();
  const int BranchSize(NodeB<Key>* node);
  NodeB<Key>* SearchBranch(NodeB<Key>* node, Key key);
  bool Insert(const Key& key);
  void InsertEquilibrate(NodeB<Key>* const node, Key const& key);
  bool Search(const Key& key);
  bool Erase(const Key& key);
  
 private:
};

/**
 * @brief Constructor por defecto de la clase ABE 
 * 
 * @tparam Key 
 */
template<class Key>
ABE<Key>::ABE() {

}

/**
 * @brief Método que se encarga de llamar a la función que revisa el tamaño de 
 * una rama, el nodo incicial de dicha rama se lo pasamos
 * 
 * @tparam Key 
 * @return const int 
 */
template<class Key>
const int ABE<Key>::Size() { 
  return BranchSize(this->GetRoot()); 
}

/**
 * @brief Método encargado de revisar el tamaño de una rama, Verificando si 
 * este está vacío o si cuenta con ramas izquierdas o derechas.
 * 
 * @tparam Key 
 * @param node 
 * @return const int 
 */
template<class Key>
const int ABE<Key>::BranchSize(NodeB<Key>* node) {
  if (node == nullptr) {
    return 0;
  }
  return (1 + BranchSize(node->GetLeft()) + BranchSize(node->GetRight()));
}

/**
 * @brief Método recursivo que se encarga de insertar equilibradamente 
 * elementos a el arbol binario equilibrado.
 * 
 * @tparam Key 
 * @param node 
 * @param key 
 */
template<class Key>
void ABE<Key>::InsertEquilibrate(NodeB<Key>* const node, Key const& key) {
  if(this->BranchSize(node->GetLeft()) <= this->BranchSize(node->GetRight())) {
    if (node->GetLeft() != NULL) {
      InsertEquilibrate(node->GetLeft(), key);
    } else {
      NodeB<Key>* aux = new NodeB<Key>(key);
      node->SetLeft(aux);
    }
  } else {
    if (node->GetRight() != nullptr) {
      InsertEquilibrate(node->GetRight(), key);
    } else {
      NodeB<Key>* aux = new NodeB<Key>(key);
      node->SetRight(aux);
    }
  }
}

/**
 * @brief Método que implementa el método virtual que hereda de la clase 
 * abtracta AB<Key>, se encarga de llamar al método recursivo que 
 * inserta equilibradamente.
 * 
 * @tparam Key 
 * @param key 
 * @return true 
 * @return false 
 */
template<class Key>
bool ABE<Key>::Insert(const Key& key) {
  if (Search(key)) {
    return false;
  }
  if (this->GetRoot() == nullptr) {
    NodeB<Key>* new_node = new NodeB<Key>(key);
    this->SetRoot(new_node);
  } else {
    InsertEquilibrate(this->GetRoot(), key);
  }
  return true;
}

template<class Key>
bool ABE<Key>::Erase(const Key& key) {
  return false;
}

/**
 * @brief Método que implementa el método de busqueda heredado de la clase 
 * abtracta AB<Key>, se encarga de llamar al método que impleemta la 
 *  busqueda por ramas.
 * 
 * @tparam Key 
 * @param key 
 * @return true 
 * @return false 
 */
template<class Key>
bool ABE<Key>::Search(const Key& key) {
  NodeB<Key>* node = this->GetRoot();
  if (node == nullptr) {
    return false;
  }
  if (key == node->GetInformation()) {
    return true;
  }
  if (SearchBranch(node->GetLeft(), key) || SearchBranch(node->GetRight(), key)) {
    return true;
  }
}

/**
 * @brief Método recursivo que se encarga de recorrer las ramas de un árbol 
 * binario
 * 
 * @tparam Key 
 * @param node 
 * @param key 
 * @return NodeB<Key>* 
 */
template<class Key>
NodeB<Key>* ABE<Key>::SearchBranch(NodeB<Key>* node, Key key) {
  if (node == nullptr) {
    return nullptr;
  }
  if (key == node->GetInformation()) {
    return node;
  }
  if (key < node->GetInformation()) {
    return SearchBranch(node->GetLeft(), key);
  }
  return SearchBranch(node->GetRight(), key);
}


#endif