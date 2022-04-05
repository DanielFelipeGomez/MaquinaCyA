/**
 * @file main.cc
 * @author Daniel Felipe Gomez Aristizabal (alu0101438139@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-04-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include "hash_table.h"
#include "dispersion_function.h"
#include "fd_module.h"
#include "fd_pseudorandom.h"
#include "fd_sum.h"
#include "exploration_function.h"
#include "fe_double_scatter.h"
#include "fe_lineal.h"
#include "fe_quadratic.h"
#include "fe_redispersion.h"

int main() {

  // Solicitamos los datos a l usuario
  int table_size = 0, type_dispersion = 0, type_dispersion_func = 0, block_size = 0, type_exploration = 0;
  std::cout << "Inserte el tamaño de la tabla: " << std::endl;
  std::cin >> table_size;
  std::cout << "Que función de dispersión desea usar:\n1. Módulo\n2. Basada en la suma\n3. Pseudoaleatoria" << std::endl;
  std::cin >> type_dispersion_func;
  std::cout << "Que dispersión desea usar:\n1. Abierta\n2. Cerrada" << std::endl;
  std::cin >> type_dispersion;


  // Creamos la función de dispersión que el usario haya elegido
  DispersionFunction<long>* ptfd;
  switch (type_dispersion_func) {
  case 1 : // module
    ptfd = new fdModule<long>(table_size);

    break;
  case 2 : //suma
    ptfd = new fdSum<long>(table_size);

    break;
  case 3 : // pseudoaleatoria
    ptfd = new fdPseudorandom<long>(table_size);
    break;
  default:
    break;
  }

  ExplorationFunction<long>* ptfe = nullptr;


  // Creamos la función de exploración que el usario haya elegido
  if (type_dispersion == 2) {
    std::cout << "Inserte el tamaño del bloque: " << std::endl;
    std::cin >> block_size;
    std::cout << "Elija la función de exploración:\n1. Exploración lineal\n2. Exploración cuadrática\n3. Doble dispersión\n4. Redispersión" << std::endl;
    std::cin >> type_exploration;
    
    switch (type_dispersion_func) {
    case 1 : // Exploración lineal
      ptfe = new feLineal<long>;
      break;
    case 2 : //Exploración cuadrática
      ptfe = new feQuadratic<long>;
      break;
    case 3 : // Doble dispersión
      ptfe = new feDoubleScatter<long>;
      break;
    case 4 : // Redispersión
      ptfe = new feRedispersion<long>;
      break;
    default:
      break;
    }
  }
  
  // Solicitamos valores a insertar en la tabla de hash
  HashTable<long> table(table_size, ptfd, ptfe, block_size);
  int num_insert = 0;
  std::cout << "Digite el número de valores que quiera insertar:" << std::endl;
  std::cin >> num_insert;
  for (int i = 0; i < num_insert; ++i) {
    int value = 0;
    std::cout << i+1 <<" valor: " << std::endl;
    std::cin >> value;
    table.Insert(value);
  }

  // Imprimimos la tabla
  table.Print();
}
