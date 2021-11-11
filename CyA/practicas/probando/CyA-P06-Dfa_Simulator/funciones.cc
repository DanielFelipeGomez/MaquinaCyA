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

void ReadAllInformation(const std::string& file_name, Dfa& my_dfa,
                        const std::string& file_name_strings) {
  std::ifstream file_in;
  std::string line;
  bool first_line{true}, second_line{true};
  file_in.open(file_name);
  while (!file_in.eof()) {
    getline(file_in, line);
    if (first_line) {
      std::stringstream container(line);
      int num;
      container >> num;
      my_dfa.SetNumberStates(num);
      first_line = false;
      continue;
    }else if (second_line) {
      std::stringstream container(line);
      int num;
      container >> num;
      my_dfa.SetStartState(num);
      second_line = false;
      continue;
    }
    int i = 0, count = 0;
    for (i; count < 2; ++i) {
      if (line[i] != ' ') {
        std::string aux(1, line[i]);
        std::stringstream container(aux);
        int num;
        container >> num;
        my_dfa.SetDfaInformation(num);
      } else {
        count++;
      }
    }
    i += 2;
    bool change = true;
    for (i; i < line.length(); ++i) {
      if (line[i] != ' ') {
        if (change) {
          my_dfa.SetSymbolIn(std::string(1, line[i]));
          change = false;
        } else {
          std::string aux = std::string(1, line[i]);
          std::stringstream container(aux);
          int num;
          container >> num;
          my_dfa.SetDestinationState(num);
          change = true;
        }
      } else {
        continue;
      }
    }
  }
  file_in.close();
  ReadStrings(file_name_strings, my_dfa);
  for (int i = 1; i < my_dfa.GetSizeDfaInformation(); i += 2) {
    my_dfa.SetStates(my_dfa.GetDfaInformation(i));
  }
  my_dfa.PrintDepurate();
}

void ReadStrings(const std::string& file_name_strings, Dfa& my_dfa) {
  std::ifstream file_in;
  std::string line;
  file_in.open(file_name_strings);
  while (!file_in.eof()) {
    getline(file_in, line);
    my_dfa.SetStringsToAnalyze(line);
  }
  file_in.close();
}