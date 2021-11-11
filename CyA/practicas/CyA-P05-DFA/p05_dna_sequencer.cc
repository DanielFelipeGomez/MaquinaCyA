// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 5: DFA, análisis de ADN
// Autor: Daniel Felipe Gomez Aristizabal
// Correo: alu0101438139@ull.es
// Fecha: 30/10/2021
// Archivo p05_dna_sequencer.cc
// Contiene el main, se encarga de llamar a funciones de verificado y al
// constructor de la clase DnaAnalizer 
// Referencias: Enlaces de interés
// Historial de revisiones 29/10/2021 - Creación (primera versión) del código

#include "funciones.h"
#include "dna_analyzer.h"

int main(int argc, char* argv[]) {
  // Verificamos que todos los parámetros sean correctos
  CheckParameter(argc, argv);
  // Analizaremos la cadena ingresada por línea de comandos
  DnaAnalyzer analyzer(argv[1]);
  // Imprimimos las cadenas reconocidas por nuestor DFA
  analyzer.PrintFile(argv[2]);
  return 0;
}