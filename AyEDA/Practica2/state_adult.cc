/**
 * @file state_adult.cc
 * @author Daniel Felipe Gomez Aristizabal (alu0101438139@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2022-03-07
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "state_adult.h"

/**
 * @brief Constructor de la clase StateAdult, inicializa su identificador char
 * con su inicial en mayuscula
 *
 */
StateAdult::StateAdult() { state_ = 'A'; }

/**
 * @brief Calcula el número de vecinos que tiene en la vecindad, se fija solo en
 * los tipos necesarios para saber su siguiente estado
 *
 * @param board
 * @param i
 * @param j
 * @return int
 */
void StateAdult::Neighbors(const Grid& board, int i, int j) {
  if (board.GetCell(i - 1, j - 1).GetState() == 'A') {
    num_adult += 1;
  } 

  if (board.GetCell(i - 1, j).GetState() == 'A') {
    num_adult += 1;
  }

  if (board.GetCell(i - 1, j + 1).GetState() == 'A') {
    num_adult += 1;
  } 

  if (board.GetCell(i, j - 1).GetState() == 'A') {
    num_adult += 1;
  } 

  if (board.GetCell(i, j + 1).GetState() == 'A') {
    num_adult += 1;
  } 

  if (board.GetCell(i + 1, j - 1).GetState() == 'A') {
    num_adult += 1;
  }

  if (board.GetCell(i + 1, j).GetState() == 'A') {
    num_adult += 1;
  } 

  if (board.GetCell(i + 1, j + 1).GetState() == 'A') {
    num_adult += 1;
  } 
}

/**
 * @brief Se encarga de realizar la comparación necesaria para determianr el
 * siguiente estado, esto lo hace a partir de las reglas, retornando al final un
 * State* con el nuevo estado
 *
 * @return State*
 */
State* StateAdult::NextState() {
  State* new_state;
  if (num_adult >= 1) {
    new_state = new StateEgg;
  } else {
    new_state = new StateDead;
  }
  return new_state;
}

/**
 * @brief Se encarga de retornar el valor del atributo state_, este es un
 * atributo heredado de la clase abstracta
 *
 * @return char
 */
char StateAdult::GetState() const {
  return state_;
}