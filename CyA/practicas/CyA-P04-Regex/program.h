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

#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include "comment.h"
#include "variable.h"
#include "statement.h"
#include "modify.h"

class Program {
 public:
  Program(const std::string& file, const std::string& outfile);
  void SearchVariables(const std::string& line, Variable variable,
                       int line_number);
  void SearchComments(const std::string& line, Comment comment,
                      int line_number, std::string& description);
  void SearchStatements(const std::string& line, Statement statement,
                      int line_number);
  void SearchInclude(const std::string& line, Modify modify,
                       int line_number);
  void SearchReturn(const std::string& line, Modify modify,
                       int line_number);
  void SearchMain(const std::string& line);
  void PrintAll(std::string file, std::string description, const std::string& outfile);


 private:
  int line_number_ = 0;
  bool main_ = false;
  std::vector<std::pair<int, std::string>> variables_;
  std::vector<std::pair <int, std::string>> comments_;
  std::vector<std::pair<int, std::string>> statements_;
};