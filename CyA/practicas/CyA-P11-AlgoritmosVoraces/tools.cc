#include "tools.h"

void Usage() {
  std::cout
      << "El programa tiene dos modos de uso:\nPuede usar 4 argumentos "
         "para soluciones con objetos enteros:\n./ProblemaMochila -u"
         "<peso_máximo_P> <fichero_configuración>\nTambién puede usar solo 3 "
         "argumentos para obtener una solución con objetos fraccionados y un "
         "máximo de una unidad por objeto:\n./ProblemaMochila <peso_máximo_P> "
         "<fichero_configuración>"
      << std::endl;
}

void CheckParameters(int argc, char* argv[]) {
  if (argc == 3) {
    if (std::string(argv[1]) == "-u"){
      std::cout << "Faltan parámetros:\n";
      Usage();
      exit(1);
    }
  } else if (argc == 4) {
    if (std::string(argv[1]) != "-u") {
      Usage();
      exit(1);
    }
  } else {
    Usage();
    exit(1);
  }
}