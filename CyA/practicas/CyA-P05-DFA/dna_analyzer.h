// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 5: DFA, análisis de ADN
// Autor: Daniel Felipe Gomez Aristizabal
// Correo: alu0101438139@ull.es
// Fecha: 30/10/2021
// Archivo dna_analyzer.h
// Contiene la declaración de la clase DnaAnalyzer junto con sus métodos y
// atributos 
// Referencias: Enlaces de interés Historial de revisiones 29/10/2021
// - Creación (primera versión) del código

#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include "dfa.h"


class DnaAnalyzer {
 public:
  DnaAnalyzer(std::string string);
  void RemoveDuplicateElements(Dfa dfa);
  void SubStrings(std::string string);
  void RecognizedStrings(Dfa dfa);
  void PrintFile(std::string file_out);
  
 private:
  std::vector<std::string> dna_strings_;
  std::vector<std::string> accepted_strings_;
};