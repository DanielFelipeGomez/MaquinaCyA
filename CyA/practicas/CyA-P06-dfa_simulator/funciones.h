/** Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 5: DFA, análisis de ADN
 * Autor: Daniel Felipe Gomez Aristizabal
 * Correo: alu0101438139@ull.es
 * Fecha: 30/10/2021
 * Archivo funciones.h
 * Contiene las declaraciones de funciones útiles en el programa
 * Referencias: Enlaces de interés Historial de revisiones
 * 29/10/2021 - Creación (primera versión) del código
 */

#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "dfa.h"

/**
 * @brief Función encargada de verificar si los parámetos se han pasado
 * correctamente.de lo contrario ofrece más infromación acerca del programa con
 * "--help"
 *
 * @param argc
 * @param argv
 */
void CheckParameter(int argc, char* argv[]);

/**
 * @brief Función encargada de leer el fichero y extraer los valores necesarios
 * para componer nuestro DFA
 *
 * @param file_name
 * @param my_dfa
 * @param file_name_strings
 */
void ReadAllInformation(const std::string& file_name, Dfa& my_dfa,
                        const std::string& file_name_strings);

/**
 * @brief Función auxiliar encargada de leer el fichero que contiene las cadenas
 * que nos interesan analizar
 *
 * @param file_name_strings
 * @param my_dfa
 */
void ReadStrings(const std::string& file_name_strings, Dfa& my_dfa);
