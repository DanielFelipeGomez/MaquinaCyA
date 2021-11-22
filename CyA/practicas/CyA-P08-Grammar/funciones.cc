/**
 * @file funciones.cc
 * @author Daniel Felipe Gómez Aristizabal (alu0101438139@ull.edu.es)
 * @brief Funciones de utilería apra el programa 
 * @version 0.1
 * @date 2021-11-20
 * 
 * @copyright Copyright (c) 2021
 * 
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
    std::cout << "El programa se encarga de mostrar paso a paso las\n"
                 "derivaciones realziadas con una determinada gramática\n"
                 "configurada por los parámetros dados en un fichero .cfg y\n"
                 "realizando las producciones indicadas en otro fichero .drv\n"
                 "./p08_grammar_arithmetic input.cfg input.drv\n";
    exit(1);
  } else if (argc != 4) {
    std::cout
        << "Error en el número de parámetros. Para saber más de como funciona\n"
        << "Modo de empleo: ./p08_grammar_arithmetic input.cfg input.drv "
           "output.txt\n "
        << "Pruebe ’./p08_grammar_arithmetic --help’ para más información "
        << std::endl;
    exit(1);
  }
}

/**
 * @brief Abre e incerta los resultados en un fichero de salida 
 * 
 * @param name_out_file 
 * @param results 
 */
void PrintResult(const std::string& name_out_file,
                 const std::vector<std::string>& results) {
  std::ofstream out_file;
  out_file.open(name_out_file);
  int i = 0;
  out_file << "--- Derivaciones ---\n";
  for (i; i < results.size() - 1; ++i) {
    out_file << results[i] << " => ";
    if (i % 4 == 0  && i != 0) {
      out_file << "\n";
    }
  }
  out_file << results[i];
  out_file.close();
}