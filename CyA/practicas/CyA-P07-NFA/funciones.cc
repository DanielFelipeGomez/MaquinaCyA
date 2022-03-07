/** Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 5: DFA, análisis de ADN
 * Autor: Daniel Felipe Gomez Aristizabal
 * Correo: alu0101438139@ull.es
 * Fecha: 30/10/2021
 * Archivo funciones.cc
 * Contiene las definicones de las funciones declaradas en funciones.h
 * Referencias: Enlaces de interés Historial de revisiones
 * 29/10/2021 - Creación (primera versión) del código
 */

#include "funciones.h"

/**
 * @brief Funcion encargada de asegurarse el buen paso de parámetros
 *
 * @param argc
 * @param argv
 */
void CheckParameter(int argc, char* argv[]) {
  if (argc == 2 && std::string(argv[1]) == "--help") {
    std::cout << "El programa se encarga de analizar una cadena introducida\n"
                 "por línea de comandos y devuelve en un fichero de salida\n"
                 "todas las subcadenas que reconozca un DFA implementado que\n"
                 "tambien es creado a partir de un fichero dado:\n"
                 "./dfa_simulation input.dfa input.txt output.txt\n";
    exit(1);
  } else if (argc != 4) {
    std::cout
        << "Error en el número de parámetros. Para saber más de como funciona\n"
        << "Modo de empleo: ./dfa_simulation input.dfa input.txt output.txt\n"
        << "Pruebe ’./dfa_simulator --help’ para más información " << std::endl;
    exit(1);
  }
}
