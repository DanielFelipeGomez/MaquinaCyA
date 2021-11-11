/**
 *Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 6: DFA
 * @file dfa.h
 * @author Daniel Felipe Gomez Aristizabal (alu0101438139@ull.es)
 * @brief Contiene las declaraciones de la clase Dfa
 * @version 0.1
 * @date 2021-11-09
 * @copyright Copyright (c) 2021
 *
 */

#pragma once
#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

class Dfa {
 public:
  /**
   * @brief Setter de nuestro atributo number_state_ el cual indica el número de
   * etados
   *
   * @param number_states
   */
  void SetNumberStates(const int& number_states);
  /**
   * @brief Setter de nuestro atributo start_state_ el cual indica estado
   * de arranque
   *
   * @param start_state
   */
  void SetStartState(const int& start_state);
  /**
   * @brief Setter de nuestro atributo start_state_ el cual indica el estado de
   * arranque
   *
   * @param element
   */
  void SetDfaInformation(const int& element);
  /**
   * @brief Setter encargado de rellenar el vector donde almacenamos el estad
   * estino de nuestro correspondiente símbolo
   *
   * @param state
   */
  void SetDestinationState(const int& state);
  /**
   * @brief Setter encargado de rellenar nuestro vector symbol_in_
   *
   * @param symbol
   */
  void SetSymbolIn(const std::string& symbol);
  /**
   * @brief Setter encargado de introducir nuestras cadenas a analizar, al
   * principio entiende todas las cadenas como "rejected"
   *
   * @param string
   */
  void SetStringsToAnalyze(const std::string& string);
  /**
   * @brief Setter de nuestro estado, donde si recibimos un "0" (el cual nos
   * indican en el fichero) determinamos que no es de aceptación, por el
   * contrario si tenemos un "1" indicamos que es un estado de ceptación
   *
   * @param state
   */
  void SetStates(const int& state);
  /**
   * @brief Setter encargado de rellenar nuestra variable number_transition_
   *
   * @param element
   */
  void SetNumberTransition(const int& element);
  /**
   * @brief Método encargado de eliminar elementos repetidos en nuestro alfabeto
   *
   */
  void RemoveDuplicateElements();
  /**
   * @brief Nos devuelve el tamaño del vector de información del DFA
   *
   * @return int
   */
  int GetSizeDfaInformation();
  /**
   * @brief Retorna el número de elementos que componen al alfabeto
   *
   * @return int
   */
  int GetSizeSymbol();
  /**
   * @brief Retorna el elemento ubicado en la i-esisma posicion del vector de
   * infromación
   *
   * @param i
   * @return int
   */
  int GetDfaInformation(const int& i);
  /**
   * @brief Devuelve el número de estados
   *
   * @return int
   */
  int GetNumberState();
  /**
   * @brief Se encarga de rellenar la tabla de transiciones de nuestro DFA
   *
   */
  void FillTransitionTable();
  /**
   * @brief Se encarga de verificar que el DFA esta capacitado para funcionar y
   * luego comienza a analizar cada una de las cadenas introducidas por el
   * usuario
   *
   */
  void CheckAccepted();
  /**
   * @brief Encargado de verificar que los simbolos que componen las cadenas a
   * analizar pertencen al alfabeto que pertenece al DFA
   *
   * @param string
   * @return true
   * @return false
   */
  bool CheckSymbol(const std::string& string);
  /**
   * @brief Se asegura que el número de trnasiciones del DFA corresponda con las
   * necesarias para un DFA según su definición
   *
   */
  void CheckNumberTransition();
  /**
   * @brief Se encarga de volcar la información a un fichero indicado por el
   * usuario
   *
   * @param name_file_out
   */
  void PrintAll(const std::string& name_file_out);
  void PrintDepurate();

 private:
  std::vector<int> dfa_information_;
  std::vector<std::string> symbol_in_;
  std::vector<int> destination_state_;
  std::vector<int> transition_table_;
  std::vector<std::pair<std::string, bool>> strings_to_analyze_;
  std::vector<bool> states_;
  int start_state_;
  int number_states_;
  int number_transitions_{0};
};