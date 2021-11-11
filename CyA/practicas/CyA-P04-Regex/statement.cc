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

#include "statement.h"
// for (int i = 1; i <= number ; ++ i ) {
// Se definen las expresiones regulares y si se cumple se inidica el tipo conseguido
bool Statement::SearchFor(const std::string& line) {
  std::regex exp_regular("( )*(for)(.)*\\((.)*\\)(.)*");
  if (std::regex_match(line, exp_regular)) {
    statement_ = "for";
    return true;
  }
  return false;
}

// Se define las expresiones regualres y si se cumple se inidica que es de tipo while
bool Statement::SearchWhile(const std::string& line) {
  std::regex exp_regular("( )*(while)(.)*\\((.)*\\)(.)*");
  if (std::regex_match(line, exp_regular)) {
    statement_ = "while";
    return true;
  }
  return false;
}
