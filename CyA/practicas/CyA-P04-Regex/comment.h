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

#pragma once

#include <iostream>
#include <regex>
#include <string>
#include <vector>

class Comment {
 public:
  Comment(std::string comment) : comment_(comment) {}
  bool SearchComment(const std::string& line, int line_number,
                     std::string& description);
  std::string TakeLineComment(const std::string& line);
  std::string TakeBlockComment(const std::string& line,
                               std::string& description);
  std::string GetComment() { return comment_; }

 private:
  std::string comment_;
  int line_;
};