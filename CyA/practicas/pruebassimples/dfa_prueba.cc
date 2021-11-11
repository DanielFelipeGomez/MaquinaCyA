#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>


int main(){
  std::string linea;
  std::vector<std::string> valores;
  std::vector<std::string> simbolo;
  std::vector<int> estado_trans;
  std::ifstream file_in;
  file_in.open("fichero.txt");
  while (!file_in.eof()) {
    getline(file_in, linea);
    int i = 0, count = 0;
    for (i; count < 3; ++i) {
      if (linea[i] != ' ') {
        std::string aux(1, linea[i]);
        std::cout << aux << std::endl;
        valores.push_back(aux);
      } else {
        count++;
      }
    }
    bool change = true;
    for (i; i < linea.length(); ++i) {
      if (linea[i] != ' ') {
        if (change) {
          simbolo.push_back(std::string(1, linea[i]));
          change = false;
        } else {
          std::string aux = std::string(1, linea[i]);
          std::stringstream container(aux);
          int num;
          container >> num;
          estado_trans.push_back(num);
          change = true;
        }
      } else {
        continue;
      }
    }
  }
  file_in.close();
  
  // 0 0 2 a 1 b 3
  // extrae transiciones
  
  std::vector<int> v1;
  // = {2, 1};
  std::vector<int> v2;
 // = {1, 1};
  std::vector<int> v3;
 // = {2, 2};

  // v1.push_back(estado_trans[0]);
  // v1.push_back(estado_trans[1]);
  // v2.push_back(estado_trans[2]);
  // v2.push_back(estado_trans[3]);
  // v3.push_back(estado_trans[4]);
  // v3.push_back(estado_trans[5]);

  std::vector<int> table = {estado_trans};
  std::string input;
  int state = 0;
  std::cout << "Program that accepts strings starting with 1:\nEnter String: ";
  std::cin >> input;
  std::cout << input << std::endl;
  std::cout << "Transitions: \n";
  for(int i = 0; i < input.length(); i++){
    std::cout << "(q" << state << ", " << input[i] << ") -> q";
    int col;
    if (input[i] == 'a') {
      col = 0;
    } else if (input[i] == 'b') {
      col = 1;
    } else {
      std::cout << "jueputa";
    }
    state = table[(state)*2 + col];  //// antes (input[i] - '0') era col
    std::cout << state << std::endl;
  } if(state == 1 || state == 2)
      std::cout << "\nString accepted!";
    else
      std::cout << "\nNot accepted!";
  return 0;
}