/**
 * @file ABB.h
 * @author Daniel Felipe Gómez Aristizabal alu0101438139@ull.edu.es
 * @brief 
 * @version 0.1
 * @date 2022-05-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __ABB_CLASS__
#define __ABB_CLASS__

#include <queue>
#include <iostream>
#include "ab.h"

template<class Key>
class ABB : public AB<Key> {
 public:
  ABB();
  const int Size();
  const int BranchSize(NodeB<Key>* node);
  NodeB<Key>* SearchBranch(NodeB<Key>* node, Key key);
  void InsertABB(NodeB<Key>*& node, Key key);
  void TakeHisPlace(NodeB<Key>*& replacement_node, NodeB<Key>*& node_to_erase);
  bool EraseSubABB(NodeB<Key>*& node, Key key);
  bool Insert(const Key& key);
  bool Search(const Key& key);
  bool Erase(const Key& key);
  
 private:
};

/**
 * @brief Constructor por defecto de la clase ABB 
 * 
 * @tparam Key 
 */
template<class Key>
ABB<Key>::ABB() {

}

/**
 * @brief Método que se encarga de llamar a la función que revisa el tamaño de 
 * una rama, el nodo incicial de dicha rama se lo pasamos
 * 
 * @tparam Key 
 * @return const int 
 */
template<class Key>
const int ABB<Key>::Size() { 
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
const int ABB<Key>::BranchSize(NodeB<Key>* node) {
  if (node == nullptr) {
    return 0;
  }
  return (1 + BranchSize(node->GetLeft()) + BranchSize(node->GetRight()));
}

/**
 * @brief Método encargado de insertar de manera recursiva en el árbol los 
 * valores que se indiquen por parámetros, respetando si son mayores o 
 * menores que el nodo de arranque
 * 
 * @tparam Key 
 * @param node 
 * @param key 
 */
template<class Key>
void ABB<Key>::InsertABB(NodeB<Key>*& node, Key key) {
  
  if (node->GetInformation() > key) {
    if(node->GetLeftR() != nullptr) {
      InsertABB(node->GetLeftR(), key);
    } else {
      node->SetLeft(new NodeB<Key>(key));
      return;
    }
  } else {
    if (node->GetRightR() != nullptr) {
      InsertABB(node->GetRightR(), key);
    } else {
      node->SetRight(new NodeB<Key>(key));
      return;
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
bool ABB<Key>::Insert(const Key& key) {
  if (Search(key)) {
    return false;
  }
  if (this->GetRootR() == nullptr) {
    NodeB<Key>* new_node = new NodeB<Key>(key);
    this->SetRootR(new_node);
  } else {
    InsertABB(this->GetRootR(), key);
  }
  return true;
}

/**
 * @brief Método encargado de remplazar un nodo por otro, cuidando de mantener 
 * a sus nodos hijos
 * 
 * @tparam Key 
 * @param replacement_node 
 * @param node_to_erase 
 */
template<class Key>
void ABB<Key>::TakeHisPlace(NodeB<Key>*& replacement_node, NodeB<Key>*& node_to_erase) {
  if (replacement_node->GetRightR() != nullptr) {
    TakeHisPlace(replacement_node->GetRightR(), node_to_erase);
  } else {
    node_to_erase->SetInformation(replacement_node->GetInformation());
    node_to_erase = replacement_node;
    replacement_node = replacement_node->GetLeftR();
  }
}

/**
 * @brief Método encargado de eliminar de manera recursiva el nodo que le 
 * corresponda la clave dada por parámetros
 * 
 * @tparam Key 
 * @param node 
 * @param key 
 * @return true 
 * @return false 
 */
template<class Key>
bool ABB<Key>::EraseSubABB(NodeB<Key>*& node, Key key) {
  if (node == nullptr) {
    return false;
  }
  if(node->GetInformation() > key) {
    return EraseSubABB(node->GetLeftR(), key);
  } else if (node->GetInformation() < key) {
    return EraseSubABB(node->GetRightR(), key);
  } else {
    NodeB<Key>* node_to_erase = node;
    if (node->GetRightR() == nullptr) {
      node = node->GetLeftR();
    } else if (node->GetLeftR() == nullptr) {
      node = node->GetRightR();
    } else {
      TakeHisPlace(node->GetLeftR(), node_to_erase);
      //delete(node_to_erase);
    }
  }
  return true;
}

/**
 * @brief Método que permite la implementación del método de borrado definido 
 * en la clase abstracta
 * 
 * @tparam Key 
 * @param key 
 * @return true 
 * @return false 
 */
template<class Key>
bool ABB<Key>::Erase(const Key& key) {
  return (EraseSubABB(this->GetRootR(), key));
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
bool ABB<Key>::Search(const Key& key) {
  return SearchBranch(this->GetRoot(), key);
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
NodeB<Key>* ABB<Key>::SearchBranch(NodeB<Key>* node, Key key) {
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