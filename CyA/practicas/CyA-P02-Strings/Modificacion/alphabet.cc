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

#include "alphabet.h"

//Constructor de la clase, recibe una cadena que contiene el alfabeto separado por espacios
Alphabet::Alphabet(std::string alphabet) {
  //assert(alphabet != "");
  std::string aux, aux2 = " ";
  if (alphabet.find(aux2) > alphabet.length()) {
    for (int i = 0; i < alphabet.length(); ++i) {
      aux += alphabet[i];
      alphabet_.push_back(aux);
      aux = "";
    }
  } else {
    std::string aux;
    for (int i = 0; i < alphabet.length(); ++i) {
      if (alphabet[i] != ' ') {
        aux += alphabet[i];
      }
      if (alphabet[i + 1] == ' ' || i + 1 == alphabet.length()) {
        alphabet_.push_back(aux);
        aux = "";
      }
    }
  }
}

//Devuelve el número de elementos del alfabeto
int Alphabet::GetSize() { 
  return alphabet_.size(); 
}

//Devuelve el elemento i-esimo del alfabeto
std::string Alphabet::GetElementAlphabet(int i) { 
  return alphabet_[i]; 
}


void Alphabet::PrintElement() {
  std::cout << "{";
  for (int i = 0; i < GetSize(); ++i) {
    std::cout << alphabet_[i] << ",";
  }
  std::cout << "}";
}