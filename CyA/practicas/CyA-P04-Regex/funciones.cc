// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Símbolos, alfabetos y cadenas
// Autor: Daniel Felipe Gomez Aristizabal
// Correo: alu0101438139@ull.es
// Fecha: 23/10/2021
// Archivo funciones.cc
// Contiene las deficniones declaradas en el fichero funciones.h
// Referencias: Enlaces de interés Historial de revisiones
// 23/10/2021 - Creación (primera versión) del código

#include "funciones.h"

// Función encargada de verificar si los parámetos se han pasado correctamente.
// de lo contrario ofrece más infromación acerca del programa con "--help"
void CheckParameter(int argc, char* argv[]) {
  if (argc == 2 && std::string(argv[1]) == "--help") {
    std::cout
        << "El programa se encarga de analizar un programa .cc y "
           "devuelve:\n- Varibles inicializadas en una línea, su tipo y "
           "el número de línea.\n- Bucles, "
           "su tipo y el número de línea.\n- Si existe un int main en el "
           "fichero y el número de línea.\n- Comentarios "
           "simples y de bloque y el número de línea. donde se encuentran.\n"
           "Inserte los siguientes parámetros para ejcutar correctamente el "
           "programa:\n./p04_regular_expressions code.cc codescheme.txt\n";
    exit(1);
  } else if (argc != 3) {
    std::cout << "Error en el número de parámetros. Para saber más de como funcina el "
                 "programa: \n./p04_regular_expressions --help"
              << std::endl;
    exit(1);
  }
}
