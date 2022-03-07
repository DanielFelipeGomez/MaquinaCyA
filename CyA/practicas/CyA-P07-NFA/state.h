/**
 * @file estado.h
 * @author Daniel Felipe Gomez Aristizabal (alu0101438139@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2021-11-14
 *
 * @copyright Copyright (c) 2021
 *
 */

#pragma once
#include <iostream>
#include <set>
#include <vector>
#include <map>

class State {
 public:
  State(int name, bool accept): name_(name), accept_(accept) {}
  void SetTransition(char symbol, int element);
  void PrintState();
  void Onlystates();
  int GetName();
  bool IsAccepted();
  std::vector<int> GetTransition(char symbol);

 private:
  int name_;
  bool accept_;
  std::map<char, std::vector<int>> transitions_;
};