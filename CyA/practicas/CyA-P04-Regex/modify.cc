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

#include "modify.h"

// Se declara la expresión regular para buscar los int, si se encuetra 
// se llama al método para extrae la cadena 
bool Modify::SearchInclude(const std::string& line) {
  std::regex exp_regular("( )*(#include)(.)*");
  if (std::regex_match(line, exp_regular)) {
    include_ = TakeInclude(line);
    return true;
  }
  return false;
}

// Se declara la expresión regular para buscar el double, si se encuentra
// se llama al método para extraer la cadena
bool Modify::SearchReturn(const std::string& line) {
  std::regex exp_regular("( )*(return)(.)*");
  if (std::regex_match(line, exp_regular)) {
    return_ = TakeReturn(line);
    return true;
  }
  return false;
}

// Método encargado de extraer la cadena 
std::string Modify::TakeReturn(const std::string& line) {
  std::string my_var;
  size_t pos = 0;
  pos = line.find("return");
  my_var = line.substr(pos, line.length());
  return my_var;

}

// Método encargado de extraer la cadena
std::string Modify::TakeInclude(const std::string& line) {
  std::string my_var;
  size_t pos = 0;
  pos = line.find("include");
  my_var = line.substr(pos, line.length());
  return my_var;
}
