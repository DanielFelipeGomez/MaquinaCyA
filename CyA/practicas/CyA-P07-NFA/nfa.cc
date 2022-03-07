/**
 * @file nfa.cc
 * @author Daniel Felipe Gomez Aristizabal (alu0101438139@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2021-11-14
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "nfa.h"

/**
 * @brief Constructor de la clase Nfa 
 * 
 * @param file_name 
 * @param file_name_strings 
 * @param file_name_out 
 */
Nfa::Nfa(const std::string& file_name, const std::string& file_name_strings,
         const std::string& file_name_out){
  std::ifstream file_in;
  std::string line;
  int number_transitions = 0;
  bool first_line{true}, second_line{true}, accept_state;
  file_in.open(file_name);
  int id;
  while (!file_in.eof()) {
    getline(file_in, line);
    if (first_line) {
      std::stringstream container(line);
      int num;
      container >> num;
      number_states_ = num;
      // SetNumberStates(num); 
      first_line = false;
      continue;
    } else if (second_line) {
      std::stringstream container(line);
      int num;
      container >> num;
      start_state_=num;
      second_line = false;
      id = 0;
      continue;
    }
    int i = 0, count = 0;
    std::string acept_or_not(1, line[2]);
    std::stringstream cambiar(acept_or_not);
    int num;
    cambiar >> num;
    accept_state = num;
    for (i; count < 2; ++i) {
      if (line[i] != ' ') {
        std::string aux(1, line[i]);
        std::stringstream container(aux);
        int num;
        container >> num;
        dfa_information_.push_back(num);
      } else {
        count++;
      }
    }
    std::string aux = std::string(1, line[i]);
    std::stringstream container(aux);
    int number_element;
    container >> number_element;
    number_transitions_ += number_element;
    i++;
    bool change = true;
    std::string valor_no_transita = std::string(1, line[4]);
    std::stringstream no_transita(valor_no_transita);
    int num_transitar;
    no_transita >> num_transitar;
    if (num_transitar == 0) {
      State state(id, accept_state);
      states_.push_back(state);
    }
    for (i; i < line.length(); ++i) {
      if (line[i] != ' ') {
        char symbol;
        if (change) {
          symbol = line[i];
          change = false;
        } else {
          std::string aux = std::string(1, line[i]);
          std::stringstream container(aux);
          int num;
          container >> num;
          State state(id, dfa_information_[1]);
          state.SetTransition(symbol,num);
          dfa_information_.clear();
          states_.push_back(state);
          change = true;
        }
      } else {
        continue;
      }
    }
    ++id;
    }
  file_in.close();
  ReadStrings(file_name_strings);
  GetAcceptStates();
  //PrintDepurate();
  AcceptStrings();
  std::ofstream file_out;
  file_out.open(file_name_out);
  for (int i = 0; i < strings_to_analyze_.size(); ++i) {
    file_out << strings_to_analyze_[i].first
             << ((strings_to_analyze_[i].second) ? " -- Accepted"
                                                 : " -- Rejected")
             << "\n";
  }
  file_out.close();
    
}

/**
 * @brief Se encarga de leer el fichero que contiene las strins a evaluar y las
 * introduce en un vector
 *
 * @param file_name_strings
 */
void Nfa::ReadStrings (const std::string& file_name_strings) {
  std::ifstream file_in;
  std::string line;
  file_in.open(file_name_strings);
  while (!file_in.eof()) {
    getline(file_in, line);
    strings_to_analyze_.push_back(make_pair(line, false));
  }
  file_in.close();

}

/**
 * @brief Se encarga de reevaluar la condicion de aceptación de una cadena
 *
 */
void Nfa::AcceptStrings() {
  std::vector<int> important_states;
  std::vector<int> new_vect;
  std::string string;
  for (int w = 0; w < strings_to_analyze_.size(); ++w) {
    string = strings_to_analyze_[w].first;
    important_states.push_back(start_state_);
    for (int j = 0; j < string.length(); ++j) {
      EClosure(important_states);
      TransitionFunction(important_states, string[j]);
    }
    for (int l = 0; l < important_states.size(); ++l) {
      for (int i = 0; i < name_accepted_states_.size(); ++i){
        if (important_states[l] == name_accepted_states_[i]) {
          strings_to_analyze_[w].second = true;
        }
      }
    }
  }
}

/**
 * @brief Rellena un vector con los id o nombres de los estados de aceptación
 * 
 */
void Nfa::GetAcceptStates() { 
  for (int i = 0; i < states_.size(); ++i) {
    if (states_[i].IsAccepted()) {
      name_accepted_states_.push_back(states_[i].GetName());
    }
  } 
}

/**
 * @brief Se encarga de rellenar un vector pasado por referencia con los estados
 * a los que pude trnasitar con determinado simbolo dado por parámetros
 *
 * @param important_states
 * @param string
 */
void Nfa::TransitionFunction(std::vector<int>& important_states, char& string) {
  std::vector<int> new_vect;
  for (int i = 0; i < important_states.size(); ++i) {
    for (int k = 0; k < states_.size(); ++k) {
      if (states_[k].GetName() == important_states[i]) {
        std::vector<int> aux = states_[k].GetTransition(string);
        for (int u = 0; u < aux.size(); ++u) {
          new_vect.push_back(aux[u]);
          RemoveDuplicateElements(new_vect);
        }
      }
    }
  }
  important_states = new_vect;
}

/**
 * @brief Realiza la E-Clausura de un conjunto de estados y los introuce en un
 * vector pasado por referencia
 *
 * @param important_states
 */
void Nfa::EClosure(std::vector<int>& important_states) {
  std::vector<int> new_vect;
  std::vector<int> aux = important_states;
  for (int i = 0; i < aux.size(); ++i) {
    new_vect.push_back(aux[i]);
  }
    for (int i = 0; i < important_states.size(); ++i) {
      // new_vect.push_back(important_states[i]);
      for (int k = 0; k < states_.size(); ++k) {
        if (states_[k].GetName() == important_states[i]) {
          std::vector<int> aux = states_[k].GetTransition('&');
          for (int u = 0; u < aux.size(); ++u) {
            new_vect.push_back(aux[u]);
          }
        }
      }
    }
  important_states = new_vect;
}

/**
 * @brief Se encarga de eliminar las posibles coincidencias de valores en el
 * vector que se indique por parámetros
 *
 * @param vector
 */
void Nfa::RemoveDuplicateElements(std::vector<int> vector) {
  auto end = vector.end();
  for (auto it = vector.begin(); it != end; ++it) {
    end = std::remove(it + 1, end, *it);
  }
  vector.erase(end, vector.end());
}