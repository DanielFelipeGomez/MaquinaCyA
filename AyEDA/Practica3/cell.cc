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
 * @brief Constructor de la clase Cell, asigna el estado con el que se crea la
 * celula y sus coordenadas
 *
 * @param state
 * @param axisX
 * @param axisY
 * @param life_neighborns
 */
Cell::Cell(State* state,int axisX, int axisY) {
  state_ = state;
  axisX_ = axisX;
  axisY_ = axisY;
}

/**
 * @brief Devuelve el caracter que representa el estado de la celula
 *
 * @return char
 */
char Cell::GetState() const {
  return state_->GetState();
}

/**
 * @brief Asigna un nuevo estado al atributo state_, apartir de un puntero de la
 * clase abstracta State
 *
 * @param new_state
 */
void Cell::SetState(State* new_state) { state_ = new_state; }

/**
 * @brief Actualiza el estado de la celula dependiendo el número de vecinos
 * vivos que tenga en su vecindad, esta responsabilidad la delega en la función
 * vitual NextState 
 *
 */
void Cell::UpdateState() {
  SetState(state_->NextState());
}

/**
 * @brief Llama a la fución encargada de determianr el número de vecinos y sus
 * estados según el interes de cada celula, dando como parámetro el tablero de
 * juego y las coordenadas de la celula interesada
 *
 * @param board
 * @return int
 */
void Cell::Neighbors(const Grid& board) {
  state_->Neighbors(board, axisX_, axisY_);
}

/**
 * @brief Sobrecarga del operador de flujo de salida de la clase Cell
 *
 * @param out
 * @param cell
 * @return std::ostream&
 */
std::ostream& operator<<(std::ostream& out, const Cell& cell) {
  char aux = cell.GetState();
  if (aux == ' ') {
    out << " ";
  } else {
    out << "X";
  }
  return out;
}

