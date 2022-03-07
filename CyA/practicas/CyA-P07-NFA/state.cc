/**
 * @file estado.cc
 * @author Daniel Felipe Gomez Aristizabal (alu0101438139@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2021-11-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "state.h"

/**
 * @brief Setter del map traanstitions_
 * 
 * @param symbol 
 * @param element 
 */
void State::SetTransition(char symbol, int element) {
  transitions_[symbol].push_back(element);
}

/**
 * @brief Se encarga de imprimir información relacionada al NFA
 * 
 */
void State::PrintState() {
  std::map<char, std::vector<int>>::iterator i;
  for (i = transitions_.begin(); i != transitions_.end(); ++i) {
    std::cout << name_ << "  " << accept_ << "  " << i->first;
    for (int j = 0; j < i->second.size(); ++j) {
      std::cout << " " << i->second[j] << std::endl;
    }
  }
}

/**
 * @brief Retorna la transición que tiene un estado
 * 
 * @param symbol 
 * @return std::vector<int> 
 */
std::vector<int> State::GetTransition(char symbol) {
  return transitions_[symbol];
}

/**
 * @brief Retornar si un estado es aceptado o no
 * 
 * @return true 
 * @return false 
 */
bool State::IsAccepted() { return accept_; }

/**
 * @brief Devuleve el nombre o id de un estado
 * 
 * @return int 
 */
int State::GetName() { return name_; }

/**
 * @brief Imrprime el nombre del estado y si es de aceptación o no
 *
 */
void State::Onlystates() { std::cout << name_ << "  " << accept_ << std::endl; }