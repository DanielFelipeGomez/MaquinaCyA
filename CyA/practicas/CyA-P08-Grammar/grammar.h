/**
 * @file grammar.h
 * @author Daniel Felipe Gómez Aristizabal (alu0101438139@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2021-11-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include "alphabet.h"
#include "productions.h"

class Grammar {
 public:
  Grammar(const std::string& in_configuration);
  void ReadConfigurationFile(const std::string& in_configuration);
  void ReadDerivationFile(const std::string& in_derivation);
  bool IsNoTerminal(const char& symbol);
  std::vector<std::string>& MakeDerivations(const std::string& name_derivation);
  std::vector<std::string> GetProducciones(const char& symbol);

 private:
  Alphabet alphabet_;
  Productions productions_;
  std::vector<std::pair<char, int>> derivations_;
  std::vector<char> non_terminals_;
  std::vector<std::string> results;
};
