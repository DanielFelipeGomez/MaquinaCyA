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

#include "funciones.h"
int main(int argc, char* argv[]) { 
  CheckParameter(argc, argv);
  Dfa my_dfa;
  ReadAllInformation(argv[1], my_dfa, argv[2]);
  my_dfa.FillTransitionTable();
  my_dfa.CheckAccepted();
  my_dfa.PrintAll(argv[3]);
  return 0;
}