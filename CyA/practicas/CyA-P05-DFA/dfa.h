// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 5: DFA, análisis de ADN
// Autor: Daniel Felipe Gomez Aristizabal
// Correo: alu0101438139@ull.es
// Fecha: 30/10/2021
// Archivo program.h
// Contiene la declaración de la clase DFA, junto con sus métodos y atributos
// Referencias: Enlaces de interés Historial de revisiones
// 29/10/2021 - Creación (primera versión) del código

#pragma once
#include <iostream>
#include <vector>
#include "alphabet.h"

class Dfa {
 public:
  Dfa();
  std::string GetTransition(int i, int j);
  int GetNumerState();
  bool GetQ(int i);
  void PrintState();
  void PrintTransition();

 private:
  int nrows,ncols;
  std::vector<bool> Q_;
  std::vector<std::string> transition_function_;
  Alphabet alphabet_;
};