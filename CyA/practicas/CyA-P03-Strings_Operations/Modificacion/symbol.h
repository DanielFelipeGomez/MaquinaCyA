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

#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>


class Symbol {
 public:
  Symbol(char symbol);
  Symbol(std::string symbol) : symbol_(symbol) {}
  Symbol() : symbol_(""){}
  friend int Length(Symbol symbol);
  friend std::ostream& operator<<(std::ostream& out, const Symbol& symbol);
  friend std::istream& operator>>(std::istream&, const Symbol&);
  friend std::string operator+
      (const std::string& string, const Symbol& symbol);
  friend std::string operator+
      (const Symbol& symbol, const std::string& string);
  friend bool operator<(const Symbol& symbol, const Symbol& symbol2);
  friend bool operator==(const Symbol& symbol, const Symbol& symbol2);

 private:
  std::string symbol_;
};