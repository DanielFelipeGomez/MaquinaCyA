// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 5: DFA, análisis de ADN
// Autor: Daniel Felipe Gomez Aristizabal
// Correo: alu0101438139@ull.es
// Fecha: 30/10/2021
// Archivo funciones.c
// Contiene las definciones de las funciones pertenecientes a funciones.h
// Referencias: Enlaces de interés Historial de revisiones
// 29/10/2021 - Creación (primera versión) del código

#pragma once
#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

class Dfa {
 public:
  void SetNumberStates(const int& number_states);
  void SetStartState(const int& start_state);
  void SetDfaInformation(const int& element);
  void SetDestinationState(const int& state);
  void SetSymbolIn(const std::string& symbol);
  void SetStringsToAnalyze(const std::string& string);
  void SetStates(const int& state);
  void RemoveDuplicateElements();
  int GetSizeDfaInformation();
  int GetDfaInformation(const int& i);
  void FillTransitionTable();
  void CheckAccepted();
  void PrintAll(const std::string& name_file_out);
  void PrintDepurate();

 private:
  std::vector<int> dfa_information_;
  std::vector<std::string> symbol_in_;
  std::vector<int> destination_state_;
  std::vector<int> transition_table_;
  std::vector<std::pair<std::string, bool>> strings_to_analyze_;
  // std::vector<std::string> strings_to_analyze_;
  // std::vector<bool> analyzed_strings_;
  std::vector<bool> states_;
  int start_state_;
  int number_states_;
};