/**
 * @file funciones.h
 * @author Daniel Felipe Gómez Aristizabal (alu0101438139@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2021-11-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <string>


void CheckParameter(int argc, char* argv[]);
void PrintResult(const std::string& name_out_file,
                 const std::vector<std::string>& results);
