/**
 * @file grid.cc
 * @author Daniel Felipe Gomez Aristizabal (alu0101438139@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2022-03-07
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "grid.h"

/**
 * @brief Constructor de la clase Grid, recibe el número de filas y columnas y
 * crea dinámicamente una  matriz de objetos de la clase Cell, inicializandolos
 * muertos por defecto
 *
 * @param num_rows
 * @param num_columns
 */
Grid::Grid(int num_rows, int num_columns) {
  num_rows_ = num_rows + 2;
  num_columns_ = num_columns + 2;
  array_pointer_ = new Cell*[num_rows_];
  for (int i = 0; i < num_rows+2; ++i) {
    array_pointer_[i] = new Cell[num_columns_];
  } 
  for (int i = 0; i < num_rows_; ++i) {
    for (int j = 0; j < num_columns_; ++j) {
      Cell nueva(false, i, j, 0);
      array_pointer_[i][j] = nueva;
    }
  }
}

/**
 * @brief Método encargado de preguntar al usuario que células quiere vivas
 * entes de iniciar el juego
 *
 */
void Grid::GiveLife() {
  short option{0};
  int axisX, axisY;
  std::cout << "Seleccione las celulas que quiere vivan inicialmente.\n";
  for (int i = 1; i < num_rows_ - 1; ++i) {
    for (int j = 1; j < num_columns_ - 1; ++j) {
      std::cout << "[" << i << "," << j << "] ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
  do {
    option = 0;
    bool check_flag = true;
    std::cout
        << "Si quiere dar vida a una celula presione \"1\", sino \"2\" \n";
    std::cin >> option;
    if (option == 1) {
      do {
        std::cout << "Ingrese la coordenada x: \n";
        std::cin >> axisX;
        std::cout << "Ingrese la coordenada y: \n";
        std::cin >> axisY;
        if (axisX < 1 || axisY < 1 || axisX > (this->num_rows_ - 2) || axisY > (this->num_columns_ - 2)) {
          std::cout << "\nIngresaste coordenadas fuera de la matriz, vuelve a "
                       "intentarlo:\n\n";
          check_flag = false;
        } else {
          check_flag = true;
        }
      } while (!check_flag);
      State live;
      live.SetState(true);
      array_pointer_[axisX][axisY].SetState(live);
    } else {
      continue;
    }
  } while (option == 1);
  std::cout << "--- Turno 0 ---\n";
  for (int i = 0; i < num_rows_ ; ++i) {
    for (int j = 0; j < num_columns_ ; ++j) {
      if (i == 0 || j == 0 || i == num_rows_ - 1 || j == num_columns_ - 1) {
        std::cout << " * ";
      } else {
        std::cout << array_pointer_[i][j];
      }
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}

/**
 * @brief Getter de la Cell, devulve la célula que esté ubicada en la matriz en
 * las coordenadas dadas por parámetro
 *
 * @param axisX
 * @param axisY
 * @return const Cell&
 */
const Cell& Grid::GetCell(int axisX, int axisY) const {
  return array_pointer_[axisX][axisY];
}

/**
 * @brief Se encarga de ir incrementando el número de turnos, aademás de hacer
 * los 3 recorridos necesarios
 * - Uno para determinar el número de vecinos vivos de cada célula
 * - Otro para definir el estado nuevom de cada célula 
 * - Un último recorrido imprimiendo cada célula
 *
 */
void Grid::NextGeneration() {
  turno_ += 1;
  for (int i = 1; i < num_rows_-1; ++i) {
    for (int j = 1; j < num_columns_-1; ++j) {
      //std::cout << "Soy " << array_pointer_[i][j]
                //<< array_pointer_[i][j].Neighbors(*this);
      array_pointer_[i][j].SetLiveNeighborns((array_pointer_[i][j].Neighbors(*this)));
    }
  }
  for (int i = 1; i < num_rows_ - 1; ++i) {
    for (int j = 1; j < num_columns_ - 1; ++j) {
      array_pointer_[i][j].UpdateState();
    }
  }
  std::cout << "--- Turno " << turno_ << " ---\n";
  for (int i = 0; i < num_rows_; ++i) {
    for (int j = 0; j < num_columns_; ++j) {
      if (i == 0 || j == 0 || i == num_rows_ - 1 || j == num_columns_ - 1) {
        std::cout << " * ";
      } else {
        std::cout << array_pointer_[i][j];
      }
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}