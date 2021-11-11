/**
 *Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 6: DFA
 * @file dfa.cc
 * @author Daniel Felipe Gomez Aristizabal (alu0101438139@ull.es)
 * @brief Contiene las definciones de las funciones pertenecientes a dfa.h
 * @version 0.1
 * @date 2021-11-09
 * @copyright Copyright (c) 2021
 *
 */

#include "dfa.h"

void Dfa::FillTransitionTable() { transition_table_ = {destination_state_}; }

void Dfa::CheckAccepted() {
  RemoveDuplicateElements();
  CheckNumberTransition();
  for (int k = 0; k < strings_to_analyze_.size(); ++k) {
    std::string string = strings_to_analyze_[k].first;
    int state = start_state_;
    for (int i = 0; i < string.length(); i++) {
      int col = -1;
      for (int j = 0; j < symbol_in_.size();++j) {   
        if (string[i] == char(symbol_in_[j][0])) {
          col = j;
        }
      }
      if (col == -1 ) {
        strings_to_analyze_[k].second = false;
        break;
      }
      state = transition_table_[(state)*(symbol_in_.size()) + col];
    }
    if (states_[state] && CheckSymbol(string)){
      strings_to_analyze_[k].second = true;
    } else {
      strings_to_analyze_[k].second = false;
    }
  }
}

void Dfa::PrintAll(const std::string& name_file_out) {
  std::ofstream file_out;
  file_out.open(name_file_out);
  for (int i = 0; i < strings_to_analyze_.size(); ++i) {
    file_out << strings_to_analyze_[i].first
             << (strings_to_analyze_[i].second ? " -- Accepted\n"
                                               : " -- Rejected\n");
  }
  file_out.close();
}

void Dfa::RemoveDuplicateElements() {
  auto end = symbol_in_.end();
  for (auto it = symbol_in_.begin(); it != end; ++it) {
    end = std::remove(it + 1, end, *it);
  }
  symbol_in_.erase(end, symbol_in_.end());
}

void Dfa::SetStates(const int& state) {
  if (state == 0) {
    states_.push_back(false);
  } else {
    states_.push_back(true);
  }
}

void Dfa::SetStringsToAnalyze(const std::string& string) {
  strings_to_analyze_.push_back(make_pair(string,false));
}

void Dfa::SetSymbolIn(const std::string& symbol) { symbol_in_.push_back(symbol); }

void Dfa::SetDestinationState(const int& state) {
  destination_state_.push_back(state);
}

void Dfa::SetDfaInformation(const int& element) {
  dfa_information_.push_back(element);
}
tar -czvf p06_nombre_apellidos.tgz p06_dfa_simulator

int Dfa::GetSizeDfaInformation() { return dfa_information_.size(); }

int Dfa::GetDfaInformation(const int& i) { return dfa_information_[i]; }

void Dfa::PrintDepurate() {
  std::cout << "dfa information" << std::endl;
  for (int i = 0; i < dfa_information_.size(); ++i){
    std::cout << dfa_information_[i]<< std::endl;
  }
  std::cout << "symbol_in" << std::endl;
  for (int i = 0; i < symbol_in_.size(); ++i) {
    std::cout << symbol_in_[i] << std::endl;
  }
  std::cout << "destination_state" << std::endl;
  for (int i = 0; i < destination_state_.size(); ++i) {
    std::cout << destination_state_[i] << std::endl;
  }
  std::cout << "trnasition table" << std::endl;
  for (int i = 0; i < transition_table_.size(); ++i) {
    std::cout << transition_table_[i] << std::endl;
  }
  std::cout << "string to analyze" << std::endl;
  for (int i = 0; i < strings_to_analyze_.size(); ++i) {
    std::cout << strings_to_analyze_[i].first << "  " << strings_to_analyze_[i].second << std::endl;
  }
  std::cout << "states" << std::endl;
  for (int i = 0; i < states_.size(); ++i) {
    std::cout << states_[i] << std::endl;
  }
  std::cout << "start state" << std::endl;
  std::cout << start_state_ << std::endl;
  std::cout << "number state" << std::endl;
  std::cout << number_states_ << std::endl;
}

bool Dfa::CheckSymbol(const std::string& string) {
  bool check = false;
  for (int i = 0; i < string.length(); ++i) {
    check = false;
    for (int j = 0; j < symbol_in_.size(); ++j) {
      if (string[i] == symbol_in_[j][0]){
        check = true;
      }
      if (check == false && j == symbol_in_.size()){
        return false;
      }
    }
    if(check == false) {
      return false;
    }
  }
  return check;
}

int Dfa::GetSizeSymbol() { 
  return symbol_in_.size(); 
}

int Dfa::GetNumberState() { return number_states_; }

void Dfa::SetNumberTransition(const int& element) {
  number_transitions_ = element;
}

void Dfa::CheckNumberTransition() {
  if (GetSizeSymbol() * GetNumberState() != number_transitions_) {
    std::cout << "Hay un error en el paso de datos, un DFA debe tener n*m\n"
                 "transiciones. Donde n es el número de estados y m el\n"
                 "número de simbolos.\n";
    exit(1);
  }
}