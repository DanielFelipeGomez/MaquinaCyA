/**
 * @file alphabet.h
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

class Alphabet {
 public:
  Alphabet();
  Alphabet(std::string line_alphabet);
  void Copy(Alphabet& alphabet2);
  int GetSize();
  std::string GetElement(const int& index);
  void PrintAlphabet();

 private:
  std::vector<std::string> alphabet_;
};