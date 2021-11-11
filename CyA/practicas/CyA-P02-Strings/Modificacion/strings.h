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


class String {
 public:
  String(std::string string, Alphabet alphabet);
  int GetSize();
  void PrintElement();
  void LengthWord(std::ofstream &fileout);
  void ReverseWord(std::ofstream &fileout);
  std::string GetString();
  void PrefixesWords(std::ofstream &fileout);
  void SuffixesWords(std::ofstream &fileout);
  void SubStrings(std::ofstream &fileout);
//Modificacion
  void LengthWordModify(std::ofstream &fileout);


 private:
  std::vector<std::string> string_;
};