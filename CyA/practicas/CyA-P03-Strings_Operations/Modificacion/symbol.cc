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

#include "symbol.h"

// Constructor de una String a partir de un char 
Symbol::Symbol(char symbol) { symbol_ = symbol; }

// Sobrecarga del operaodr de flujo de salida de la clase Symbol
std::ostream& operator<<(std::ostream& out, const Symbol& symbol) {
  out << symbol;
  return out;
}

// Sobrecarga del operador concatenar de la clase Symbol, que concatena una
// std::string con un Symbol
std::string operator+(const std::string& string, const Symbol& symbol) {
  return string + symbol.symbol_;
}

// Funcón encargada de devolver la longitud de un Symbol
int Length(Symbol symbol) { 
  return symbol.symbol_.length(); 
}

// Sobrecarga del operador concatenar para un Symbol con una std::string
std::string operator+(const Symbol& symbol, const std::string& string) {
  return symbol.symbol_ + string;
}

// Sobrecarga del operador menor que, utilizado para organizar la preferencia en
// el Set del Alphabet
bool operator<(const Symbol& symbol, const Symbol& symbol2) {
  if (Length(symbol) == Length(symbol2)) {
    return (symbol.symbol_ < symbol2.symbol_);
  }
  return Length(symbol) < Length(symbol2);
}

// Sobrecarga del operador de == encargada de comparar dos Symbol
bool operator==(const Symbol& symbol, const Symbol& symbol2) {
  return (symbol.symbol_ == symbol2.symbol_);
}

// Sobrecarga de flujo de entrada de la clase Symbol
std::istream& operator>>(std::istream& in, const Symbol& symbol) {
  in >> symbol.symbol_;
  return in;
}