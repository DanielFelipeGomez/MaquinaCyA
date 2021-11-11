// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Símbolos, alfabetos y cadenas
// Autor: Daniel Felipe Gomez Aristizabal
// Correo: alu0101438139@ull.es
// Fecha: 04/10/2021
// Archivo cya-P02-Strings.cc: programa cliente.
// Contiene la funci´on main del proyecto que usa las clases X e Y
// que realizan el trabajo de leer el fichero de entrada
// identificando patrones en el texto que dan lugar
// al fichero de salida.
// Referencias:
// Enlaces de interés
// Historial de revisiones
// 04/10/2021 - Creación (primera versión) del código

#include "strings.h"

// Constructor de la clase, recibe una string con la cadena y un objeto de 
// la clase Alphabet que es el alfabeto asociado a la cadena
String::String(std::string string, Alphabet alphabet) {
  std::string aux;
  for (int i = 0; i < string.length(); ++i) {
    for (int j = alphabet.GetSize() - 1; j >= 0; --j) {
      aux = string.substr(i, alphabet.GetElementAlphabet(j).length());
      if (aux == alphabet.GetElementAlphabet(j)) {
        string_.emplace_back(alphabet.GetElementAlphabet(j));
      }
    }
  }
}

// Devuelve el numero de elementos del vector string, que corresponde con el tamaño de la cadena
int String::GetSize() { 
  return string_.size(); 
}

void String::PrintElement() {
  for (int i = 0; i < GetSize(); ++i) {
    std::cout << string_[i] << ",";
  }
}

// Método encargado de dar el tamaño de la cadena
void String::LengthWord(std::ofstream &fileout) {
  fileout << GetSize() << "\n";
}

// Imprime en un fichero pasado por parámetros encargado de dar la inversa de la
// cadena
void String::ReverseWord(std::ofstream &fileout) {
  std::string reverse_word = "";
  for (int i = GetSize() - 1; i >= 0; --i) {
    reverse_word += string_[i];
  }
  fileout << reverse_word << "\n";
}

// Devuelve la cadena almacenada en un vector<string> en una string
std::string String::GetString() {
  std::string string = "";
  for (int i = 0; i < GetSize(); ++i) {
    string += string_[i];
  }
  return string;
}

// Imprime en un fichero pasado por parámetros todos los prefijos de un objeto
// de la clase string
void String::PrefixesWords(std::ofstream &fileout) {
  std::string prefixes = "& ", aux = "";
  for (int i = 0; i < string_.size(); ++i) {
    aux += string_[i];
    prefixes += aux + ' ';
  }
  fileout << prefixes << "\n";
}

// Imprime en un fichero pasado por parámetros todos los sufijos de un objeto de
// la clase string
void String::SuffixesWords(std::ofstream &fileout) {
  std::string suffixes = "& ", aux = "";
  for (int i = string_.size() - 1; i >= 0; --i) {
    aux = string_[i] + aux;
    suffixes += aux + ' ';
  }
  fileout << suffixes << "\n";
}

// Imprime en un fichero pasado por parámetros todas las subcadenas de un objeto de la clase string
void String::SubStrings(std::ofstream &fileout) {
  std::string aux, subcadenas;
  int n = string_.size();
  for (int len = 1; len <= n; len++) {
    for (int i = 0; i <= n - len; i++) {
      int j = i + len - 1;
      for (int k = i; k <= j; k++) {
        aux += string_[k];
      }
      aux += ' ';
    }
  }

  fileout << "& " << aux << "\n";
}

