// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Símbolos, alfabetos y cadenas
// Autor: Daniel Felipe Gomez Aristizabal
// Correo: alu0101438139@ull.es
// Fecha: 04/10/2021
// Archivo cya-P02-Strings.cc: programa cliente.
// Contiene la funci´on main del proyecto que usa las clases X e Y
// que realizan el trabajo de leer el fichero de entrada
// identificando patrones en el texto que dan lugar
// al fichero de salida.
// Referencias:
// Enlaces de interés
// Historial de revisiones
// 04/10/2021 - Creación (primera versión) del código

#include "language.h"

// Constructor de la clase Language
Language::Language(std::string language) {
  FillVector(language);
}

// Función encargada de rellenar el atributo std::vector<String> language_
void Language::FillVector(std::string language) {
  std::string aux;
  for (int i{0}; i < language.length(); ++i) {
    if (language[i] == ' ' || i == language.length() - 1) {
      String string(aux);
      language_.emplace_back(aux);
      aux = "";
    } else {
      aux += language[i];
    }
  }
}

// Getter del atrbuto, devuelve el elemento i-esimo de vector language_
String Language::GetElement(int i) { 
  return language_[i]; 
}

// Sobrecarga del operador de flujo de salida de la clase Language
std::ostream& operator<<(std::ostream& out, const Language& language) {
  out << "{ ";
  for (int i{0}; i < language.language_.size(); ++i) {
    if (i == language.language_.size()-1) {
      out << language.language_[i];
    } else {
      out << language.language_[i] << ", ";
    }
  }
  out << " }";
  return out;
}

// Sobrecarga del operador de flujo de entrada de la clase Language
std::istream& Language::operator>>(std::istream& in) {
  std::string aux;
  in >> aux;
  FillVector(aux);
  return in;
}
