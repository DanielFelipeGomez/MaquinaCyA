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
#include <set>
#include "symbol.h"


class Alphabet {
 public:
  Alphabet(std::string alphabet);
  int GetSize();
  const std::string& operator[](size_t index) const;
  friend std::ostream& operator<<(std::ostream&, const Alphabet&);
  friend std::istream& operator>>(std::istream&,const Alphabet&);

 private:
  std::set<std::string> alphabet_;
};
