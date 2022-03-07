/**
 * @file cell.cc
 * @author Daniel Felipe Gomez Aristizabal (alu0101438139@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2022-03-07
 *
 * @copyright Copyright (c) 2022
 *
 */
 
#include "cell.h"

/**
 * @brief Constructor predeterminado de la clase Cell
 * 
 */
Cell::Cell() {
  
}

/**
 * @brief Constructor de la clase Cell
 * 
 * @param state 
 * @param axisX 
 * @param axisY 
 * @param life_neighborns 
 */
Cell::Cell(bool state, int axisX, int axisY, int life_neighborns) {
  state_.SetState(state);
  axisX_ = axisX;
  axisY_ = axisY;
  life_neighborns_ = life_neighborns;
}

/**
 * @brief Getter del atributo state_, devulve un State 
 * 
 * @return State 
 */
State Cell::GetState() const { 
  return state_; 
}

/**
 * @brief Setter de state_, permite modificar el estado por uno nuevo pasado por
 * parámetro
 *
 * @param new_state
 */
void Cell::SetState(State new_state) { state_ = new_state; }

/**
 * @brief Actualiza el estado de la celula dependiendo el número de vecinos
 * vivos que tenga en su vecindad
 *
 */
void Cell::UpdateState() {
  if (state_.GetState() == false && life_neighborns_ == 3){
    state_.SetState(true);
  } else if (state_.GetState() == true && (life_neighborns_ == 3 || life_neighborns_ == 2)) {
    state_.SetState(true);
  } else {
    state_.SetState(false);
  }
}

/**
 * @brief Retorna el número de vecinos vivos en la vecindad de la célula que lo
 * invoque
 *
 * @param board
 * @return int
 */
int Cell::Neighbors(const Grid& board) {
  int live_neighbors{0};
  for (int k = -1; k <= 1; ++k) {
    for (int l = -1; l <= 1; ++l) {
      if (!(k == 0 && l == 0)) {
        if (board.GetCell((axisX_ + k), (axisY_ + l)).GetState().GetState() ==
            true) {
          live_neighbors += 1;
        }
      }
    }
  }
  return live_neighbors;
}

/**
 * @brief Sobrecarga del operador de flujo de salida
 * 
 * @param out 
 * @param cell 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& out, const Cell& cell) {
  if (cell.GetState().GetState() == true){
    out << " X ";
  } else {
    out << "   ";
  }
  return out;
}

/**
 * @brief Setter del número de vecinos vivos
 * 
 * @param live_neigh 
 */
void Cell::SetLiveNeighborns(int live_neigh) { life_neighborns_ = live_neigh; }
