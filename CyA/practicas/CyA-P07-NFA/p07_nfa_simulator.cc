/**
 * @file p07_nfa_simulator.cc
 * @author Daniel Felipe Gómez Aristizabal (alu0101438139@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2021-11-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "funciones.h"
#include "nfa.h"

int main(int argc, char* argv[]) {
  CheckParameter(argc, argv);
  Nfa my_nfa(argv[1], argv[2], argv[3]);
  
  return 0;
}