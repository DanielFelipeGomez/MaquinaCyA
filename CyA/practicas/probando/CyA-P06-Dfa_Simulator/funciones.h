// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 5: DFA, análisis de ADN
// Autor: Daniel Felipe Gomez Aristizabal
// Correo: alu0101438139@ull.es
// Fecha: 30/10/2021
// Archivo funciones.h
// Contiene la declaración de la funcón para chequear el número de parámetros
// pasados por consola 
// Referencias: Enlaces de interés Historial de revisiones
// 29/10/2021 - Creación (primera versión) del código

#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "dfa.h"

void CheckParameter(int argc, char* argv[]);

void ReadAllInformation(const std::string& file_name, Dfa& my_dfa,
                        const std::string& file_name_strings);

void ReadStrings(const std::string& file_name_strings, Dfa& my_dfa);