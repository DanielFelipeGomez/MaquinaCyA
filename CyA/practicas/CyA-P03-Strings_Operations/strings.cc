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

// Constructor de String, sin un alfabeto asociado
String::String(std::string string) {
  for(int i{0}; i < string.length(); ++i) {
    Symbol aux(string[i]);
    string_.emplace_back(aux);
  }
}

// Constructor de la clase, recibe una string con la cadena y un objeto de 
// la clase Alphabet que es el alfabeto asociado a la cadena
String::String(std::string string, Alphabet alphabet) {
  std::string aux;
  for (int i = 0; i < string.length(); ++i) {
    for (int j = alphabet.GetSize() - 1; j >= 0; --j) {
      aux = string.substr(i, alphabet[j].length());
      if (aux == alphabet[j]) {
        string_.emplace_back(alphabet[j]);
      }
    }
  }
}

// Sobrecarga del operador de flujo de salida de la clase String
std::ostream& operator<<(std::ostream& out, String string) {
  out << string.GetString();
  return out;
}

// Sobrecarga del operador de flujo de entrada de la clase String
std::istream& operator>>(std::istream& in, const String& string) {
  std::string aux;
  in >> aux;
  return in;
}

// Devuelve el numero de elementos del vector string, que corresponde con el tamaño de la cadena
int String::GetSize() { 
  return string_.size(); 
}

// Método encargado de dar el tamaño de la cadena
int String::LengthWord() {
  return GetSize();
}

// Retorna encargado de dar la inversa de la
// cadena
std::string String::ReverseWord() {
  std::string reverse_word = "";
  for (int i = GetSize() - 1; i >= 0; --i) {
    reverse_word = reverse_word + string_[i];
  }
  return reverse_word;
}

// Devuelve la cadena almacenada en un vector<string> en una string
std::string String::GetString() {
  std::string string = "";
  for (int i = 0; i < GetSize(); ++i) {
    string = string + string_[i];
  }
  return string;
}

// Retorna todos los prefijos de un objeto
// de la clase string
std::string String::PrefixesWords() {
  std::string prefixes = "& ", aux = "";
  for (int i = 0; i < string_.size(); ++i) {
    aux = aux + string_[i];
    prefixes += aux + ' ';
  }
  return prefixes;
}

// Retorna todos los sufijos de un objeto de la clase string
std::string String::SuffixesWords() {
  std::string suffixes = "& ", aux = "";
  for (int i = string_.size() - 1; i >= 0; --i) {
    aux = string_[i] + aux;
    suffixes += aux + ' ';
  }
  return suffixes;
}

// Retorna todas las subcadenas de un objeto de la clase string
std::string String::SubStrings() {
  std::string subcadenas{"& "};
  int n = string_.size();
  for (int len = 1; len <= n; len++) {
    for (int i = 0; i <= n - len; i++) {
      int j = i + len - 1;
      for (int k = i; k <= j; k++) {
        subcadenas = subcadenas + string_[k];
      }
      subcadenas += ' ';
    }
  }
  return subcadenas;
}

// Compara una cadena dada por fichero con otra introducida por el usuario
std::string String::StringComparison(String string2) {
  std::string aux;
  if(this->GetSize() > string2.GetSize()) {
    aux = *this + " > " + string2;
  } else {
    aux = *this + " < " + string2;
  } 
  if(*this == string2) {
    aux = *this + " == " + string2;
    return aux;
  }
  if (*this < string2) {
    return aux;
  } else if ((string2 < *this)) {
    return aux;
  } else if (*this != string2) {
    aux = *this + " != " + string2;
  }
  return aux;
}

// Retorna una cadena resultante de la concatenación de dos String
std::string String::ConcatenateString(std::string string2) {
  std::string new_string;
  new_string = *this + string2;
  return new_string;
}

// Retorna la cadena resultante de elevar una String a un número n
std::string String::PowerString(int n) {
  std::string string;
  string = *this ^ n;
  return string;
}

bool FindSubString(Symbol symbol, String string) {
  for (int i = 0; i < string.GetSize(); ++i) {
    if(symbol == string.string_[i]) {
      return true;
    }
  }
  return false;
}

// Sobrecarga del operador <, que significa que una String A es subcadena de otra
// String B, donde A < B
bool operator<(String string, String string2) {
  for (int i = 0; i < string.GetSize(); ++i) {
    if (FindSubString(string.string_[i], string2)) {
      continue;
    } else {
      return false;
    }
  }
  return true;
}

// Sobrecarga del operador >, que significa que una String B es subcadena de una
// String A, donde A > B
/*bool operator>(String string, String string2) {
  for (int i = 0; i < string.GetSize(); ++i) {
    if (!FindSubString(string.string_[i], string2)) {
      return false;
    } else {
      continue;
    }
  }
  return true;
}*/

// Sobrecarga del operador ==, Compara si una String A es igual a una String B
bool operator==(String string, String string2) {
  if (string.LengthWord() != string2.LengthWord()) {
    return false;
  }
  bool aux{false};
  for (int i = 0; i < string.LengthWord(); ++i) {
    if (string.string_[i] == string2.string_[i]) {
      aux = true;
    } else {
      return false;
    }
  }
  return aux;
}

// Sobrecarga del operador !=, se encarga de indicar si una String A es distinta
// de una String B
bool operator!=(String string, String string2) { 
  return !(string == string2); 
}

// Sobrecarga dal operador +, Se encarga de la concatenacion de dos String
std::string String::operator+(std::string string2) {
  std::string aux = this->GetString() + string2;
  return aux;
}

// Sobrecarga dal operador +, Se encarga de la concatenacion de dos Strings
std::string operator+(std::string string, String string2) { 
  return (string + string2.GetString()); 
}

// Sobrearga del operador potencia de n, encargado de elevar una String a un
// valor n
std::string String::operator^(int n) {
  std::string string;
  for (int i = 0; i < n; ++i) {
    string += GetString();
  }
  return string;
}
