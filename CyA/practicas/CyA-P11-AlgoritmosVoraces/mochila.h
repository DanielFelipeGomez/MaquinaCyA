#pragma once
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "objeto.h"

class Mochila {
 public:
  Mochila(const std::string& name_file, double peso_max);
  void Bounded();
  void Unbounded();
  void SortUtility();
  void PrintMochila();
  void PrintMochilaOptima();
  void PrintBoundedResult();
  void PrintUnboundedResult();

 private:
  double beneficio_;
  double peso_max_;
  double peso_mochila_;
  std::vector<Objeto> objetos_;  // id del objeto y su cantidad
  std::vector<std::pair<Objeto, double>> mochila_optima_;
};
