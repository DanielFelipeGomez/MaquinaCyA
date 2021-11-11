// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 5: DFA, análisis de ADN
// Autor: Daniel Felipe Gomez Aristizabal
// Correo: alu0101438139@ull.es
// Fecha: 30/10/2021
// Archivo funciones.c
// Contiene las definciones de las funciones pertenecientes a funciones.h
// Referencias: Enlaces de interés Historial de revisiones
// 29/10/2021 - Creación (primera versión) del código

#include "dfa.h"

void Dfa::FillTransitionTable() { 
  transition_table_ = {destination_state_};
}

void Dfa::CheckAccepted() {
  RemoveDuplicateElements();
  for (int k = 0; k < strings_to_analyze_.size(); ++k) {
    std::string string = strings_to_analyze_[k].first;
    int state = start_state_;
    for (int i = 0; i < string.length(); i++) {
      int col = -1;
      // if (string[i] == '&') {
      //   break;
      // }
      for (int j = 0; j < symbol_in_.size();++j) {   
        if (string[i] == char(symbol_in_[j][0])) {
          col = j;
        }
      }
      if (col == -1 ) {
        strings_to_analyze_[k].second = false;
        break;
      }
        // if (string[i] == 'a') {
        //   col = 0;
        // } else if (string[i] == 'b') {
        //   col = 1;
        // } else {
        //   std::cout << "jueputa";
        // }
      state = transition_table_[(state)*(symbol_in_.size()) + col];  //// antes (string[i] - '0') era col
    }
    if (states_[state]){
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
             << (strings_to_analyze_[i].second ? " -- Accepted\n" : " -- Rejected\n");
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

void Dfa::SetStartState(const int& start_state) { start_state_ = start_state; }

void Dfa::SetNumberStates(const int& number_states) {
  number_states_ = number_states;
}

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
  // std::cout << "analized string" << std::endl;
  // for (int i = 0; i < analyzed_strings_.size(); ++i) {
  //   std::cout << analyzed_strings_[i] << std::endl;
  // }
  std::cout << "states" << std::endl;
  for (int i = 0; i < states_.size(); ++i) {
    std::cout << states_[i] << std::endl;
  }
  std::cout << "start state" << std::endl;
  std::cout << start_state_ << std::endl;
  std::cout << "number state" << std::endl;
  std::cout << number_states_ << std::endl;
}