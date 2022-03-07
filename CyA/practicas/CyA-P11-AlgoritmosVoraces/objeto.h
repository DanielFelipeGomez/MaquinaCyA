#pragma once
#include <string>
#include <fstream>
#include <iostream>

class Objeto {
 public:
  Objeto();
  Objeto(const int& id, const double& peso, const double& bondad);
  void PrintObject();
  int GetId();
  double GetPeso();
  double GetBondad();
  double GetUtilidad();
  friend bool operator<(Objeto& obj1, Objeto& obj2) ;

 private:
  int id_;
  double peso_;
  double bondad_;
  double utilidad_;
};
