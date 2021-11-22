/**
 * @file productions.cc
 * @author Daniel Felipe Gómez Aristizabal (alu0101438139@ull.edu.es)
 * @brief Clase Productions, se marcan las reglas de una gramática determinada
 * @version 0.1
 * @date 2021-11-20
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "productions.h"

/**
 * @brief Retonar un vector de stirngs, con las producciones de determinado
 * simbolo
 *
 * @param symbol
 * @return std::vector<std::string>
 */
std::vector<std::string> Productions::GetProducciones(const char& symbol) {
  return productions_[symbol];
}

/**
 * @brief Rellena el vector de un determiando simbolo
 * 
 * @param symbol 
 * @param string 
 */
void Productions::SetProductions(const char& symbol, const std::string& string) {
  productions_[symbol].push_back(string);
}