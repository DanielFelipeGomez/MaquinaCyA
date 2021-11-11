// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 5: DFA, análisis de ADN
// Autor: Daniel Felipe Gomez Aristizabal
// Correo: alu0101438139@ull.es
// Fecha: 30/10/2021
// Archivo dfa.c
// Contiene las definiciones de las funciones de la clase DFA
// Referencias: Enlaces de interés Historial de revisiones
// 29/10/2021 - Creación (primera versión) del código

#include "dfa.h"

// Contructor de la clase Dfa, se encarga de:
//  -Crear estados, que su nombre coincide con su indexado y su valor será
//   "true" si es de aceptación a "false" si es un estado corriente
//  -El número de elemntos contenidos en Q_ corresponde con el número de
//   estados, por tanto es el numero de filas y columnas que construllen nuestra
//   matriz de transiciones que representa la función de transición
//  -Asignamos ahora los elementos al vector que corresponden con el
//   caracter que permite transitar a "x" estado Por último rellenamos nuestro
//   alfabeto que esta conformado por los caracteres con los que transitamos a
//   los estados
Dfa::Dfa() {
  Q_.push_back(false);  // Estado 0, no es de aceptación
  Q_.push_back(false);  // Estado 1
  Q_.push_back(true);   // Estado 2, de acpetación 
  Q_.push_back(false);  // Estado 3
  Q_.push_back(true);   // Estado 4, de aceptación
  Q_.push_back(false);  // Estado 5
  nrows = Q_.size(), ncols = Q_.size();
  transition_function_ =
      //    0    1    2    3    4    5
      {"I", "A",   "I", "T",   "I", "GC",     // 0
       "I", "GCT", "A", "I",   "I", "I",      // 1
       "I", "GCT", "A", "I",   "I", "I",      // 2
       "I", "I",   "I", "GCA", "T", "I",      // 3
       "I", "I",   "I", "GCA", "T", "I",      // 4
       "I", "I",   "I", "I",   "I", "GCTA"};  // 5
  alphabet_.FillAlphabet("ATGC");
}

// Retorna el tamaño de Q_ que corresponde con el número de estados existentes
int Dfa::GetNumerState() { return Q_.size(); }

// Retorna el elemento que se encuentra en la posición deseada de la matriz,
// recordar que la matriz está implementada en vector de vectores
std::string Dfa::GetTransition(int i, int j) {
  return transition_function_[i * ncols + j];
}

// Retorna el i-esimo estado del autómata
bool Dfa::GetQ(int i) { 
  return Q_[i]; 
}

// Se encarga de imprimir los estados que componen al DFA e indica si el estado
// es de aceptación
void Dfa::PrintState() {
  std::cout << "Número de estados del DFA: " << Q_.size() << std::endl;
  std::cout << "\nStates of DFA:\n";
  for (int i = 0; i < Q_.size(); ++i) {
    std::cout << "State " << i << (Q_[i] ? " acceptance state"
                                        : "") << std::endl;
    
  }
  std::cout << "Esatado de arranque es: " << Q_[0] << std::endl << std::endl;
}

// Imprimimos las tramnsiciones 
void Dfa::PrintTransition() {
  std::cout << "Transiciones del autómata finito" << std::endl;
  std::cout << "qi qd s" << std::endl;
  for (int i = 0; i < nrows; ++i) {
    for (int j = 0; j < nrows; ++j){
      if(GetTransition(i,j) != "I"){
        std::string auxiliar = GetTransition(i,j);
        for (int k = 0; k < auxiliar.length(); ++k) {
          std::cout << i << "  " << j << "  " << auxiliar[k] << std::endl; 
        }
      }
    }
    std::cout << "\n";
  }
}