/**
 * @file productions.h
 * @author Daniel Felipe Gómez Aristizabal (alu0101438139@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2021-11-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once
#include <map>
#include <string>
#include <vector>

class Productions {
 public:
  std::vector<std::string> GetProducciones(const char& symbol);
  void SetProductions(const char& symbol, const std::string& string);

 private:
  std::map<char, std::vector<std::string>> productions_;
};
