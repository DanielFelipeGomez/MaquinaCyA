// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 5: DFA, análisis de ADN
// Autor: Daniel Felipe Gomez Aristizabal
// Correo: alu0101438139@ull.es
// Fecha: 30/10/2021
// Archivo dna_analyzer.cc
// Contiene las definiciones de la clase DnaAnalyzer 
// Referencias: Enlaces de interés Historial de revisiones
// 29/10/2021 - Creación (primera versión) del código

#include "dna_analyzer.h"

// Construcotor encargado de:
//  -Rellena el vector con las substrings de la cadena introducida por
//   parámetro;
//  -Crea un objeto Dfa y llama a nuestra función de reconociemiento de cadenas
//   de ADN
DnaAnalyzer::DnaAnalyzer(std::string string) {
  SubStrings(string);
  Dfa my_dfa;
  RecognizedStrings(my_dfa);
  my_dfa.PrintState();
  my_dfa.PrintTransition();
}

// Se encarga de rellenar el vector dna_strings_ con todas las subcadenas de la
// cadena original pasada por parámetros
void DnaAnalyzer::SubStrings(std::string string) {
  std::string subcadenas{""};
  const size_t ksize = string.size();
  for (int len = 1; len <= ksize; len++) {
    for (int i = 0; i <= ksize - len; i++) {
      int j = i + len - 1;
      for (int k = i; k <= j; k++) {
        subcadenas = subcadenas + string[k];
      }
      if(subcadenas.length() >= 2){
        dna_strings_.emplace_back(subcadenas);
      }
      subcadenas = "";
    }
  }
}

// Se encarga de recorrer nuestro DFA y en caso de que termine en un estado de
// aceptación se guarda dicha cadena en un vector con todas las cadenas
// aceptadas por el autómata. Por ultimo llama a un método que se encargará de
// eliminar cadenas diplicadas si existiera alguna
void DnaAnalyzer::RecognizedStrings(Dfa dfa) {
  int estado = 0;
  for (int l = 0; l < dna_strings_.size(); ++l) {
    estado = 0;
    std::string string = dna_strings_[l];
    for (int i = 0; i < string.length(); ++i) {
      for (int j = 0; j < dfa.GetNumerState(); ++j) {
        for (int k = 0; k < dfa.GetTransition(estado,j).length(); ++k) {
          if (string[i] == (dfa.GetTransition(estado,j)[k])) {
            if ((dfa.GetTransition(estado,j))[k] == 'I') {
              continue;
            } else {
              estado = j;
              break;
            }
          }
        }
      }
    }
    if (dfa.GetQ(estado)) {
      accepted_strings_.emplace_back(string);
    }
  }
  RemoveDuplicateElements(dfa);
}

// Método encargado de eliminar posibles cadenas duplicadas reconocidas por
// nuestro DFA
void DnaAnalyzer::RemoveDuplicateElements(Dfa dfa) {
  auto end = accepted_strings_.end();
  for (auto it = accepted_strings_.begin(); it != end; ++it) {
    end = std::remove(it + 1, end, *it);
  }
  accepted_strings_.erase(end, accepted_strings_.end());
}

// Se encarga de imprimir en un fichero pasado por parámetros
void DnaAnalyzer::PrintFile(std::string file_out) { 
  std::ofstream out_file;
  out_file.open(file_out);
  out_file << "The DFA has recognized the following strings\n";
  for (int i = 0; i < accepted_strings_.size(); ++i) {
    out_file << "\t" << accepted_strings_[i] << "\n";
  }
}
