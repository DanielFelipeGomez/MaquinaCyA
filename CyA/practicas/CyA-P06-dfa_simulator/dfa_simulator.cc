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
  // Verificamos que todo se pase correctamente
  CheckParameter(argc, argv);
  // Creamos nuestro objeto dfa
  Dfa my_dfa;
  // Pasamos nombres de los ficheros con la información necesaria para construir
  // el DFA y las cadenas que deseamos analizar
  ReadAllInformation(argv[1], my_dfa, argv[2]);
  // Rellenamos nuestro DFA
  my_dfa.FillTransitionTable();
  // Verificamos las cadenas
  my_dfa.CheckAccepted();
  // Imprimimos los resultados en el fichero indicado
  my_dfa.PrintAll(argv[3]);
  return 0;
}