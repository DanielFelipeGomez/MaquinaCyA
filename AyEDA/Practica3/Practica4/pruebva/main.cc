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
  int table_size = 0, type_dispersion = 0, type_dispersion_func = 0, block_size = 0, type_exploration = 0;
  std::cout << "Inserte el tamaño de la tabla: " << std::endl;
  std::cin >> table_size;
  std::cout << "Que función de dispersión desea usar:\n1. Módulo\n2. Basada en la suma\n3. Pseudoaleatoria" << std::endl;
  std::cin >> type_dispersion_func;
  std::cout << "Que dispersión desea usar:\n1. Abierta\n2. Cerrada" << std::endl;
  std::cin >> type_dispersion;

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

  table.Insert(3);
  table.Insert(5);
  table.Insert(3);
  table.Insert(6);
  table.Insert(7);
  table.Insert(9);
  table.Insert(10);
  table.Insert(1111);
  table.Insert(222);
  table.Insert(5);
  table.Insert(12);
  table.Insert(2002);
  table.Print();
  //HashTable<int> an(table_size,type_dispersion_func);
  

  ///Crear objeto segun la fución  de dispersión elegida
     /// Puede que tambien se deba crear el objeto que imple,menta la función de exploración (CERRADA)
  ///Tabla hash con el tipo de Clvae=long y los parámetros especificados por el usario
  ///menú que permite insertasrt y buscar los valores de clave indicados por el usario, y muestra los resultados de la operación

}
