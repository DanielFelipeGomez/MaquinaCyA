/**
 * @file grammar.cc
 * @author Daniel Felipe Gómez Aristizabal (alu0101438139@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2021-11-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "grammar.h"

/**
 * @brief Constructor de la clase que construye a partir de un fichero una
 * gramática
 *
 * @param name_configuration
 */
Grammar::Grammar(const std::string& name_configuration) {
  ReadConfigurationFile(name_configuration);
}

/**
 * @brief Determina si deteminado caracter es No Terminal
 * 
 * @param symbol 
 * @return true 
 * @return false 
 */
bool Grammar::IsNoTerminal(const char& symbol) {
  for (int i = 0; i < non_terminals_.size(); ++i) {
    if (symbol == non_terminals_[i]) {
      return true;
    }
  }
  return false;
}

/**
 * @brief Abre y lee un ficheor dado, para configurar la gramática
 * 
 * @param name_configuration 
 */
void Grammar::ReadConfigurationFile(const std::string& name_configuration) {
  std::ifstream in_configuration;
  std::string line;
  int counter_line = 0;
  in_configuration.open(name_configuration);
  while (!in_configuration.eof()) {
    getline(in_configuration, line);
    if (counter_line == 0) {
      Alphabet alphabet(line);
      alphabet_.Copy(alphabet);
    }
    if (counter_line == 1) {
      for (auto& c : line) {
        if (c != ' ') {
          non_terminals_.push_back(c);
        }
      }
    }
    if (counter_line > 1) {
      for (int i = 0; i < non_terminals_.size(); ++i) {
        // std::cout << line << std::endl;
        if (non_terminals_[i] == line[0]) {
          productions_.SetProductions(non_terminals_[i], 
              line.substr(5, line.length() - 5));
        }
      }
    }
    ++counter_line;
  }
  in_configuration.close();
}

/**
 * @brief Abre y lee un fichero con las derivaciones indicadas y las almacena
 *
 * @param name_derivarion
 */
void Grammar::ReadDerivationFile(const std::string& name_derivarion) {
  std::ifstream in_derivation;
  in_derivation.open(name_derivarion);
  std::string line;
  while (!in_derivation.eof()) {
    getline(in_derivation, line);
    int num = line[4] - '0';
    char symbol = line[0];
    derivations_.push_back(std::make_pair(symbol, num));
  }
  in_derivation.close();
}

/**
 * @brief Devuelve las derivaciones indicadas según las producciones de la
 * gramática
 *
 * @param name_derivation
 * @return std::vector<std::string>&
 */
std::vector<std::string>& Grammar::MakeDerivations(
    const std::string& name_derivation) {
  ReadDerivationFile(name_derivation);
  std::string string = "E";
  std::string parte1 = "", parte2 = "";
  for (int j = 0; j < derivations_.size(); ++j) {
    for (int i = 0; i < string.size(); ++i) {
      if (IsNoTerminal(string[i])) {
        std::vector<std::string> auxiliar = productions_.GetProducciones(string[i]);
        parte1 = string.substr(0, i);
        parte2 = string.substr((i + 1), (string.length() - i));
        string = parte1 + auxiliar[(derivations_[j].second - 1)] + parte2;
        results.push_back(string);
        break;
      }
    }
  }
  return results;
}
