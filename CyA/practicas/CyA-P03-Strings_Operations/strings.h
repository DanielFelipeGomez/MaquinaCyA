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

#include <cassert>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "alphabet.h"
#include "symbol.h"


class String {
 public:
  String() : string_() {}
  String(std::string string);
  String(std::string string, Alphabet alphabet);
  friend std::ostream& operator<<(std::ostream& out, String string);
  friend std::istream& operator>>(std::istream&, const String&);
  int GetSize();
  int LengthWord();
  std::string ReverseWord();
  std::string GetString();
  std::string PrefixesWords();
  std::string SuffixesWords();
  std::string SubStrings();
  std::string StringComparison(String string2);
  std::string ConcatenateString(std::string string2);
  std::string PowerString(int n);
  bool IsSubString(std::string string, std::string string2);
  friend bool FindSubString(Symbol symbol, String string);
  friend bool operator<(String string, String string2);
  //friend bool operator>(String string, String string2);
  friend bool operator==(String string, String string2);
  friend bool operator!=(String string, String string2);
  std::string operator+(std::string string2);
  friend std::string operator+(std::string string, String string2);
  std::string operator^(int n);

 private:
  std::vector<Symbol> string_;
};