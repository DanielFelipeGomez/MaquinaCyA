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

#include "variable.h"

// Se declara la expresión regular para buscar los int, si se encuetra 
// se llama al método para extrae la cadena 
bool Variable::SearchInt(const std::string& line) {
  std::regex exp_regular_int("( )*(int)(.)*(;|\\w)");
  if (std::regex_match(line, exp_regular_int)) {
    variable_ = TakeInt(line);
    return true;
  }
  return false;
}

// Se declara la expresión regular para buscar el double, si se encuentra
// se llama al método para extraer la cadena
bool Variable::SearchDouble(const std::string& line) {
  std::regex exp_regular_double("( )*(double)(.)*(;|\\w)");
  if (std::regex_match(line, exp_regular_double)) {
    variable_ = TakeDouble(line);
    return true;
  }
  return false;
}

// Métod encargado de extraer la cadena 
std::string Variable::TakeDouble(const std::string& line) {
  std::string my_var;
  size_t pos, pos_final, si;
  pos = line.find("double");
  pos_final = (line.find(";") - pos - 6);
  my_var = "DOUBLE: ";
  my_var += line.substr(pos + 6, pos_final);
  return my_var;
}

// Método encargado de extraer la cadena
std::string Variable::TakeInt(const std::string& line) {
  std::string my_var;
  size_t pos, pos_final;
  pos = line.find("int");
  pos_final = (line.find(";") - pos - 3);
  my_var = "INT: ";
  my_var += line.substr(pos + 3, pos_final);
  return my_var;
}
