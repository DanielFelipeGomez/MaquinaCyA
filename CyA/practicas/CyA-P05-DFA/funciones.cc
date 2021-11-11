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

// Función encargada de verificar si los parámetos se han pasado correctamente.
// de lo contrario ofrece más infromación acerca del programa con "--help"
void CheckParameter(int argc, char* argv[]) {
  if (argc == 2 && std::string(argv[1]) == "--help") {
    std::cout << "El programa se encarga de analizar una cadena introducida "
                 "por línea de comandos y devuelve en un fichero de salida "
                 "todas las subcadenas que reconozca un DFA implementado que "
                 "acepta cadenas que empiezan y terminan por A o T:\n./ "
                 "p05_dna_sequencer TTTTAAAA dna_subsequences.out\n";
    exit(1);
  } else if (argc != 3) {
    std::cout << "Error en el número de parámetros. Para saber más de como "
                 "funciona el programa: \n./p05_dna_sequencer --help"
              << std::endl;
    exit(1);
  }
}
