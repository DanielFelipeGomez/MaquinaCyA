/**
 * @file alphabet.cc
 * @author Daniel Felipe Gómez Aristizabal (alu0101438139@ull.edu.es)
 * @brief Clase que crea un alfabeto, conjunto de simbolos
 * @version 0.1
 * @date 2021-11-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "alphabet.h"

/**
 * @brief Constructor predeterminado de la clase alphabet
 * 
 */
Alphabet::Alphabet() {}

/**
 * @brief Constructor de la clasealphabet, dada una string la divide en simbolos
 * individuales
 *
 * @param line_alphabet
 */
Alphabet::Alphabet(std::string line_alphabet) {
  for (int i = 0; i < line_alphabet.length(); ++i) {
    if (line_alphabet[i] != ' ') {
      std::string symbol(1, line_alphabet[i]);
      alphabet_.push_back(symbol);
    }
  } 
}

/**
 * @brief Copia un alphabeto pasado por parámetros en otro que llama al método
 *
 * @param alphabet2
 */
void Alphabet::Copy(Alphabet& alphabet2) {
  for (int i = 0; i < alphabet2.GetSize(); ++i) {
    alphabet_.push_back(alphabet2.GetElement(i));
  }
}

/**
 * @brief Devuelve el tamaño del vector alphabet, que correspinde tambien con el
 * número de simbolos del alfabeto
 *
 * @return int
 */
int Alphabet::GetSize() { return alphabet_.size(); }

/**
 * @brief Retorna el elemento i-esimo del alfabeto
 * 
 * @param index
 * @return std::string 
 */
std::string Alphabet::GetElement(const int& index) { return alphabet_[index]; }

/**
 * @brief Imprime el alfabeto
 * 
 */
void Alphabet::PrintAlphabet() {
  std::cout << "Σ = { ";
  int i = 0;
  for (i; i < alphabet_.size() - 1; ++i) {
    std::cout << alphabet_[i] << " , ";
  }
  std::cout << alphabet_[i] << " }";
}