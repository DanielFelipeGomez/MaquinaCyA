/**
 * @file grammar_arithmetic.cc
 * @author Daniel Felipe Gómez Aristizabal (alu0101438139@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2021-11-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "funciones.h"
#include "grammar.h"
#include "productions.h"
#include "alphabet.h"

int main(int argc, char* argv[]) {
  CheckParameter(argc, argv);
  Grammar gramatica(argv[1]);
  std::vector<std::string> results;
  results = gramatica.MakeDerivations(argv[2]);
  PrintResult(argv[3], results);
  return 0;
}