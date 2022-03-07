/**
 * @file state.cc
 * @author Daniel Felipe Gomez Aristizabal (alu0101438139@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2022-03-07
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "state.h"

/**
 * @brief Getter del estado, en este caso el estado vivo se representa con true
 * y muerto con false
 *
 * @return true
 * @return false
 */
bool State::GetState() { return state_; }

/**
 * @brief Setter de state, recibe un booleano por parámetro y lo iguala a su
 * atributo
 *
 * @param new_state
 */
void State::SetState(bool new_state) { state_ = new_state; }