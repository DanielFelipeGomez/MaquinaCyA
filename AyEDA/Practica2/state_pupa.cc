/**
 * @file state_pupa.cc
 * @author Daniel Felipe Gomez Aristizabal (alu0101438139@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2022-03-07
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "state_pupa.h"

/**
 * @brief Constructor de la clase StatePupa, inicializa su identificador char
 * con su inicial en mayuscula
 *
 */
StatePupa::StatePupa() { state_ = 'P'; }

/**
 * @brief Calcula el número de vecinos que tiene en la vecindad, se fija solo en
 * los tipos necesarios para saber su siguiente estado
 *
 * @param board
 * @param i
 * @param j
 * @return int
 */
void StatePupa::Neighbors(const Grid& board, int i, int j) {
  if (board.GetCell(i - 1, j - 1).GetState() == 'E') {
    num_egg_ += 1;
  } else if (board.GetCell(i - 1, j - 1).GetState() == 'D') {
    num_died_ += 1;
  } else if (board.GetCell(i - 1, j - 1).GetState() == 'A') {
    num_adult_ += 1;
  } else if (board.GetCell(i - 1, j - 1).GetState() == 'L') {
    num_larva_ += 1;
  } else if (board.GetCell(i - 1, j - 1).GetState() == 'P') {
    num_pupa_ += 1;
  }

  if (board.GetCell(i - 1, j).GetState() == 'E') {
    num_egg_ += 1;
  } else if (board.GetCell(i - 1, j).GetState() == 'D') {
    num_died_ += 1;
  } else if (board.GetCell(i - 1, j).GetState() == 'A') {
    num_adult_ += 1;
  } else if (board.GetCell(i - 1, j).GetState() == 'L') {
    num_larva_ += 1;
  } else if (board.GetCell(i - 1, j).GetState() == 'P') {
    num_pupa_ += 1;
  }

  if (board.GetCell(i - 1, j + 1).GetState() == 'E') {
    num_egg_ += 1;
  } else if (board.GetCell(i - 1, j + 1).GetState() == 'D') {
    num_died_ += 1;
  } else if (board.GetCell(i - 1, j + 1).GetState() == 'A') {
    num_adult_ += 1;
  } else if (board.GetCell(i - 1, j + 1).GetState() == 'L') {
    num_larva_ += 1;
  } else if (board.GetCell(i - 1, j + 1).GetState() == 'P') {
    num_pupa_ += 1;
  }

  if (board.GetCell(i, j - 1).GetState() == 'E') {
    num_egg_ += 1;
  } else if (board.GetCell(i, j - 1).GetState() == 'D') {
    num_died_ += 1;
  } else if (board.GetCell(i, j - 1).GetState() == 'A') {
    num_adult_ += 1;
  } else if (board.GetCell(i, j - 1).GetState() == 'L') {
    num_larva_ += 1;
  } else if (board.GetCell(i, j - 1).GetState() == 'P') {
    num_pupa_ += 1;
  }

  if (board.GetCell(i, j + 1).GetState() == 'E') {
    num_egg_ += 1;
  } else if (board.GetCell(i, j + 1).GetState() == 'D') {
    num_died_ += 1;
  } else if (board.GetCell(i, j + 1).GetState() == 'A') {
    num_adult_ += 1;
  } else if (board.GetCell(i, j + 1).GetState() == 'L') {
    num_larva_ += 1;
  } else if (board.GetCell(i , j + 1).GetState() == 'P') {
    num_pupa_ += 1;
  }

  if (board.GetCell(i + 1, j - 1).GetState() == 'E') {
    num_egg_ += 1;
  } else if (board.GetCell(i + 1, j - 1).GetState() == 'D') {
    num_died_ += 1;
  } else if (board.GetCell(i + 1, j - 1).GetState() == 'A') {
    num_adult_ += 1;
  } else if (board.GetCell(i + 1, j - 1).GetState() == 'L') {
    num_larva_ += 1;
  } else if (board.GetCell(i + 1, j - 1).GetState() == 'P') {
    num_pupa_ += 1;
  }

  if (board.GetCell(i + 1, j).GetState() == 'E') {
    num_egg_ += 1;
  } else if (board.GetCell(i + 1, j).GetState() == 'D') {
    num_died_ += 1;
  } else if (board.GetCell(i + 1, j).GetState() == 'A') {
    num_adult_ += 1;
  } else if (board.GetCell(i + 1, j).GetState() == 'L') {
    num_larva_ += 1;
  } else if (board.GetCell(i + 1, j).GetState() == 'P') {
    num_pupa_ += 1;
  }

  if (board.GetCell(i + 1, j + 1).GetState() == 'E') {
    num_egg_ += 1;
  } else if (board.GetCell(i + 1, j + 1).GetState() == 'D') {
    num_died_ += 1;
  } else if (board.GetCell(i + 1, j + 1).GetState() == 'A') {
    num_adult_ += 1;
  } else if (board.GetCell(i + 1, j + 1).GetState() == 'L') {
    num_larva_ += 1;
  } else if (board.GetCell(i + 1, j + 1).GetState() == 'P') {
    num_pupa_ += 1;
  }
  
}

/**
 * @brief Se encarga de realizar la comparación necesaria para determianr el
 * siguiente estado, esto lo hace a partir de las reglas, retornando al final un
 * State* con el nuevo estado
 *
 * @return State*
 */
State* StatePupa::NextState() {
  State* new_state;
  if (num_larva_ > 4) {
    new_state = new StateDead;
  } else {
    new_state = new StateAdult;
  }
  return new_state;
}

/**
 * @brief Se encarga de retornar el valor del atributo state_, este es un
 * atributo heredado de la clase abstracta
 *
 * @return char
 */
char StatePupa::GetState() const {
  return state_;
}