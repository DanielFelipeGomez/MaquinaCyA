// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 5: DFA, análisis de ADN
// Autor: Daniel Felipe Gomez Aristizabal
// Correo: alu0101438139@ull.es
// Fecha: 30/10/2021
// Archivo alphabet.cc
// Contiene la declaración de la clase Alphabet junto con sus métodos y
// atributos
// Referencias: Enlaces de interés Historial de revisiones 29/10/2021
// - Creación (primera versión) del código


#include "alphabet.h"

// Se encarga de rellenar el alfabeto, recibe por parámetro una cadena la cual
// la parte en caracteres individuales
void Alphabet::FillAlphabet(std::string alphabet) {
  for (int i = 0; i < alphabet.length(); ++i) {
    SetElement(alphabet[i]);
  }
}

// Se encarga de hacer un push_back del elemento recibido por parámetros, de
// esta forma se va rellenando el alfabeto
void Alphabet::SetElement(char element) { alphabet_.push_back(element); }

// Se encarga de imprimir el alfabeto generado con un par de llaves
void Alphabet::Print() {
  std::cout << "{ ";
  for (int i = 0; i < alphabet_.size(); ++i) {
    std::cout << alphabet_[i] << " ";
  }
  std::cout << "}";
}