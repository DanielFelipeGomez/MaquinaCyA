#include "mochila.h"

Mochila::Mochila(const std::string& name_file, double peso_max) {
  peso_max_ = peso_max;
  std::ifstream file(name_file);
  std::string line;
  double peso = 0, bondad = 0;
  int numero_objeto = 1;
  bool first_line = true;
  while (!file.eof()) {
    getline(file, line);
    std::string peso_string, bondad_string;
    if (!first_line) {
      int elementos = 0;
      for (auto& i : line) {
        if (i != ' ') {
          if (elementos == 0) {
            peso_string += i;
          } else if (elementos == 1) {
            bondad_string += i;
          } else {
            break;
          }
        } else {
          elementos++;
        }
      }
      std::stringstream aux, aux2;
      aux << peso_string;
      aux >> peso;
      aux2 << bondad_string;
      aux2 >> bondad;
      Objeto objeto(numero_objeto, peso, bondad);
      numero_objeto++;
      objetos_.push_back(objeto);
      //objeto.PrintObject();
    } else {
      std::string total_objects = "";
      for (auto& i : line) {
        if (i != ' ') {
          total_objects += i;
        } else {
          break;
        }
      }
      std::stringstream aux;
      int aux_num;
      aux << total_objects;
      aux >> aux_num;
      ///GetTotalNumElements(aux_num);
      first_line = false;
    }
  }
  SortUtility();
  file.close();
}

void Mochila::SortUtility() {
  sort(objetos_.begin(), objetos_.end());
}

void Mochila::PrintMochila() {
  for(int i = 0; i < objetos_.size(); ++i) {
    objetos_[i].PrintObject();
  }
}

void Mochila::Bounded() {
  double peso = 0;
  beneficio_ = 0; 
  for (int i = 0; i < objetos_.size() && peso <= peso_max_; ++i) {
    if ((peso + objetos_[i].GetPeso()) <= peso_max_) {
      const double kcompleto = 1;
      peso += objetos_[i].GetPeso();
      beneficio_ += objetos_[i].GetBondad() * kcompleto;
      mochila_optima_.push_back(std::make_pair(objetos_[i], kcompleto));
    } else {
      const double kcantidad = (peso_max_ - peso) / objetos_[i].GetPeso();
      beneficio_ += objetos_[i].GetBondad() * kcantidad;
      peso += peso_max_ - peso;
      mochila_optima_.push_back(std::make_pair(objetos_[i], kcantidad));
    }
    peso_mochila_ = peso;
  }
}

void Mochila::PrintMochilaOptima() {
  for (int i = 0; i < mochila_optima_.size(); ++i) {
    mochila_optima_[i].first.PrintObject();
    std::cout << "Cantidad del objeto = " << mochila_optima_[i].second
              << std::endl;
  }
}

void Mochila::PrintBoundedResult() {
  std::cout << "Beneficio: " << beneficio_ << std::endl;
  std::cout << "Peso: " << peso_mochila_ << std::endl;
  std::cout << "Solución: ";
  int i = 0;
  for (i; i < mochila_optima_.size() - 1; ++i) {
    std::cout << mochila_optima_[i].first.GetId() << ":"
              << mochila_optima_[i].second << ", ";
  }
  std::cout << mochila_optima_[i].first.GetId() << ":"
            << mochila_optima_[i].second << std::endl;
}

void Mochila::Unbounded() {
  double peso = 0;
  beneficio_ = 0;
  for (int i = 0; i < objetos_.size() && peso <= peso_max_; ++i) {
    double cantidad = 0; 
    while ((peso + objetos_[i].GetPeso()) <= peso_max_) {
      peso += objetos_[i].GetPeso();
      cantidad++;
    }
    beneficio_ += objetos_[i].GetBondad() * cantidad;
    mochila_optima_.push_back(std::make_pair(objetos_[i], cantidad));
    peso_mochila_ = peso;
  }
}

void Mochila::PrintUnboundedResult() {
  std::cout << "Beneficio: " << beneficio_ << std::endl;
  std::cout << "Peso: " << peso_mochila_ << std::endl;
  std::cout << "Solución: ";
  int i = 0;
  for (i; i < mochila_optima_.size() - 1; ++i) {
    std::cout << mochila_optima_[i].first.GetId() << ":"
              << mochila_optima_[i].second << ", ";
  }
  std::cout << mochila_optima_[i].first.GetId() << ":"
            << mochila_optima_[i].second << std::endl;
}