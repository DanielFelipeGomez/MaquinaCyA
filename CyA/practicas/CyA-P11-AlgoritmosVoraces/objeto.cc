#include "objeto.h"

Objeto::Objeto(const int& id, const double& peso, const double& bondad) {
  id_ = id;
  peso_ = peso;
  bondad_ = bondad;
  utilidad_ = bondad / peso;
}

void Objeto::PrintObject() {
  std::cout << "-------- " << id_ << "-------- " << std::endl;
  std::cout << "Peso " << peso_ << std::endl;
  std::cout << "Bondad " << bondad_ << std::endl;
  std::cout << "Utilidad " << utilidad_ << std::endl;
}

int Objeto::GetId() { return id_; }
double Objeto::GetPeso() { return peso_; }
double Objeto::GetBondad() { return bondad_; }
double Objeto::GetUtilidad() { return utilidad_; }

bool operator<(Objeto& obj1, Objeto& obj2) {
  return (obj1.GetUtilidad() > obj2.GetUtilidad());
}