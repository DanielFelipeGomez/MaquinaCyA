/**
 * @file nfa.h
 * @author Daniel Felipe Gomez Aristizabal (alu0101438139@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2021-11-14
 *
 * @copyright Copyright (c) 2021
 *
 */


#pragma once
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <fstream>
#include <vector>
#include "state.h"

class Nfa {
 public:
  Nfa(const std::string& file_name, const std::string& file_name_strings, const std::string& file_name_out);
  void ReadStrings(const std::string& file_name_strings);
  void PrintDepurate();
  void AcceptStrings();
  void GetAcceptStates();
  void RemoveDuplicateElements(std::vector<int> vector);
  void TransitionFunction(std::vector<int>& important_states, char& string);
  void EClosure(std::vector<int>& important_states);
  void PrintT(std::vector<int> a) { 
    for (int i = 0; i < a.size(); ++i) {
      std::cout << a[i] << std::endl;
    }
  }

 private:
  std::vector<State> state_set_;
  std::vector<int> dfa_information_;
  std::vector<std::string> symbol_in_;
  std::vector<int> destination_state_;
  std::vector<int> transition_table_;
  std::vector<std::pair<std::string, bool>> strings_to_analyze_;
  std::vector<State> states_;
  std::vector<int> name_accepted_states_;
  int start_state_;
  int number_states_;
  int number_transitions_{0};
};