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


#include "program.h"

// Constructor de la clase Program, se encarga de leer el fichero y va verificado
// línea a línea si se ha encontrado alguna expresión regular 
Program::Program(const std::string& file, const std::string& outfile) {
  std::string line, description;
  std::ifstream file_in;
  file_in.open(file);
  Variable variable("a");
  Comment comment("b");
  Statement statement("c");
  Modify modify("a");
  while (!file_in.eof()) {
    getline(file_in, line);
    ++line_number_;
    
    SearchVariables(line, variable, line_number_);
    SearchMain(line);
    SearchComments(line, comment, line_number_, description);
    SearchStatements(line, statement, line_number_);
    SearchInclude(line, modify, line_number_);
    SearchReturn(line, modify, line_number_);
    
  }
  PrintAll(file, description, outfile);
}

// Método encargado de llamar a los métodos de la clase Variable para saber si se encuentra
// alguna, en caso de que si la guarda en un vector de variables
void Program::SearchVariables(const std::string& line, Variable variable,
                              int line_number) {
  if (variable.SearchInt(line)) {
    variables_.emplace_back(line_number_, variable.GetVariable());
  } else if (variable.SearchDouble(line)) {
    variables_.emplace_back(line_number_, variable.GetVariable());
  }
}



// Método encargado de llamar a los métodos de la clase Comment para saber si se encuentra
// alguna, en caso de que si, la guarda en un vector de comments
void Program::SearchComments(const std::string& line, Comment comment, 
                             int line_number, std::string& description) {
  if (comment.SearchComment(line, line_number, description)) {
    comments_.emplace_back(line_number_, comment.GetComment());
  }
}

// Método encargado de llamar a los métodos de la clase Statement para saber si se encuentra
// alguna, en caso de que sí, la  guarda en un vector de statements
void Program::SearchStatements(const std::string& line, Statement statement,
                             int line_number) {
  if (statement.SearchFor(line)) {
    statements_.emplace_back(line_number_, statement.GetStatement());
  } else if (statement.SearchWhile(line)) {
    statements_.emplace_back(line_number_, statement.GetStatement());
  }
}

// Método encargado de imprimir todo con un estílo determinado en el fichero de salida
void Program::PrintAll(std::string file, std::string description,
                       const std::string& outfile) {
  std::ofstream file_out;
  file_out.open(outfile);
  file_out << "PROGRAM: " << file << std::endl;
  file_out << "DESCRIPTION:" << description;
  file_out << "\n\nVARIABLES:\n";
  for (int i = 0; i < variables_.size(); ++i) {
    file_out << "[Line " << variables_[i].first << "] " << variables_[i].second
             << std::endl;
  }
  file_out << "\n\nINCLUDE:\n";
  for (int i = 0; i < variables_.size(); ++i) {
    file_out << "[Line " << variables_[i].first << "] " << variables_[i].second
             << std::endl;
  }
  file_out << "\nSTATEMENTS\n";
  for (int i = 0; i < statements_.size(); ++i) {
    file_out << "[Line " << statements_[i].first << "] "
             << "LOOP: " << statements_[i].second << std::endl;
  }
  file_out << "\nMAIN:\n";
  if (main_) {
    file_out << "True\n";
  } else {
    file_out << "False";
  }
  file_out << "\nCOMMENTS:\n";
  for (int i = 0; i < comments_.size(); ++i) {
    file_out << "[Line " << comments_[i].first << "] " << comments_[i].second
             << std::endl;
  }
}



// Método encargado de verificar si se encuta un main dentro del fichero
// en caso de que si se pone a True el atributo main_
void Program::SearchMain(const std::string& line) {
  std::regex exp_regular("( )*int main(.)*");
  if (std::regex_match(line, exp_regular)) {
    main_ = true;
  }
}


// Modificacion palnteada en clase

// Método encargado de llamar a los métodos de la clase Modify para saber si se encuentra
// alguna, en caso de que si la guarda en un vector de include 
void Program::SearchInclude(const std::string& line, Modify modify,
                              int line_number) {
  if (modify.SearchInclude(line)) {
    variables_.emplace_back(line_number_, modify.GetInclude());
  } else if (modify.SearchInclude(line)) {
    variables_.emplace_back(line_number_, modify.GetInclude());
  }
}

// Método encargado de llamar a los métodos de la clase Modify para saber si se encuentra
// alguna, en caso de que si la guarda en un vector de include 
void Program::SearchReturn(const std::string& line, Modify modify,
                              int line_number) {
  if (modify.SearchReturn(line)) {
    variables_.emplace_back(line_number_, modify.GetReturn());
  } else if (modify.SearchReturn(line)) {
    variables_.emplace_back(line_number_, modify.GetReturn());
  }
}


