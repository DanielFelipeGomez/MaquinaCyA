// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Símbolos, alfabetos y cadenas
// Autor: Daniel Felipe Gomez Aristizabal
// Correo: alu0101438139@ull.es
// Fecha: 23/10/2021
// Archivo program.h
// Contiene las declaraciones de las funciones utilizadas para la implementación
// de la clase Program
// Referencias: Enlaces de interés Historial de revisiones
// 23/10/2021 - Creación (primera versión) del código

#include "comment.h"

// Se definen las expresiones regulares, en caso de que alguna se cumpla se llaman 
// a los determianados métotodos para extraer el comentario y la línea.
bool Comment::SearchComment(const std::string& line, int line_number, 
                            std::string& description) {
  std::regex line_comment("[^*](.)*//(.)*");
  std::regex line_comment2("( )*//(.)*");
  std::regex block_comment("( )*/\\*(.)*");
  std::regex block_comment2("\\*(.)*");
  std::regex block_comment3("\\*/\\w");
  if (std::regex_match(line, line_comment) ||
      std::regex_match(line, line_comment2)) {
    comment_ = TakeLineComment(line);
    line_ = line_number;
    return true;
  } else if (std::regex_match(line, block_comment)) {
    comment_ = "DESCRIPTION";
    TakeBlockComment(line, description);
    return true;

  } else if (std::regex_match(line, block_comment2)
                 || std::regex_match(line, block_comment3)) {
    TakeBlockComment(line, description);
  }
  return false;
}

// Método encargado de extraer el comentario simple
std::string Comment::TakeLineComment(const std::string& line) {
  std::string my_var;
  size_t pos = 0;
  pos = line.find("//");
  my_var = line.substr(pos, line.length());
  return my_var;
}

// Método encargado de extraer el comentario en bloque
std::string Comment::TakeBlockComment(const std::string& line, std::string& description) {
  description += '\n' + line;
  return description;
}
