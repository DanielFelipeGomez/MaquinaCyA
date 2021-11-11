// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 5: DFA, análisis de ADN
// Autor: Daniel Felipe Gomez Aristizabal
// Correo: alu0101438139@ull.es
// Fecha: 30/10/2021
// Archivo alphabet.h
// Contiene la definiciones de la clase Alphabet
// Referencias: Enlaces de interés Historial de revisiones 29/10/2021
// - Creación (primera versión) del código

#pragma once
#include <iostream>
#include <vector>

class Alphabet {
 public:
  void FillAlphabet(std::string alphabet);
  void SetElement(char element);
  void Print();

 private:
  std::vector<char> alphabet_;
};