/**
 * @file ab.h
 * @author Daniel Felipe Gómez Aristizabal alu0101438139@ull.edu.es
 * @brief 
 * @version 0.1
 * @date 2022-05-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __AB_CLASS__
#define __AB_CLASS__

#include "nodob.h"
#include <iostream>
#include <queue>
#include <utility>

template<class Key>
class AB {
 public:
  virtual bool Insert(const Key& key) = 0;
  virtual bool Search(const Key& key) = 0;
  void TravelInOrder(NodeB<Key>* node) const;
  void InOrden() const;
  friend std::ostream& operator<<(std::ostream& out, const AB<Key>* const node) {
    std::queue<std::pair<NodeB<Key>*,int>> queue; 
    int node_level, current_level = 0;
    std::pair<NodeB<Key>*,int> aux{node->GetRoot(), 0};
    queue.push(aux);
    out << "Nivel 0: ";
    while (!queue.empty()) {
      aux = queue.front(); 
      queue.pop();
      if (aux.second > current_level) {
        current_level = aux.second;
        out << std::endl << "Nivel " << current_level << ":";
      }
      if (aux.first != nullptr) { 
        out << " [" <<aux.first->GetInformation() << "]";
        std::pair<NodeB<Key>*,int> node_pair_level(aux.first->GetLeft(), aux.second + 1);
        queue.push(node_pair_level); 
        node_pair_level = {aux.first->GetRight(), aux.second + 1};
        queue.push(node_pair_level);
      } else {
        out << "[.]";
      }
    } 
    return out;
  }
 protected:
  NodeB<Key>* GetRoot() const;
  void SetRoot(NodeB<Key>* root);
 private:
  NodeB<Key>* root_;
};

/**
 * @brief Método encargado de recorrer InOrder el árbol binario y lo va 
 * imprimiendo por pantalla. Necesita un nodo por parámetro para inciar
 * el recorrido desde este.
 * 
 * @tparam Key 
 * @param node 
 */
template<class Key>
void AB<Key>::TravelInOrder(NodeB<Key>* node) const {
  if (node != nullptr) {
    TravelInOrder(node->GetLeft());
    std::cout << node->GetInformation() << " - ";
    TravelInOrder(node->GetRight());
  }
}

/**
 * @brief Método encargado de llamar al método que hace el recorrido InOrder, 
 * usa la raiz como parámetro
 * 
 * @tparam Key 
 */
template<class Key>
void AB<Key>::InOrden() const {
  TravelInOrder(root_);
}

/**
 * @brief Getter del atributo privado root_, buscamos que sea protected para 
 * permitir su uso en clases herederas.
 * 
 * @tparam Key 
 * @return NodeB<Key>* 
 */
template<class Key>
NodeB<Key>* AB<Key>::GetRoot() const {
  return root_;
}

/**
 * @brief Setter del atributo root_, buscamos que sea protected para 
 * permitir su uso en clases herederas.
 * 
 * @tparam Key 
 * @param root 
 */
template<class Key>
void AB<Key>::SetRoot(NodeB<Key>* root) {
  root_ = root;
}

#endif