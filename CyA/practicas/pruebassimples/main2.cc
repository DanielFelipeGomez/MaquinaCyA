// simples pruebas de como hacer un dfa con una matriz

#include <iostream>
#include <vector>

int main() {
  //                         0    1    2    3    4    5
  std::string DFA[6][6] = {{"i", "a", "i", "t", "i", "gc"},   // 0
                          {"i", "gct", "a", "i", "i", "i"},   // 1
                          {"i", "gct", "a", "i", "i", "i"},   // 2
                          {"i", "i", "i", "gca", "t", "i"},   // 3
                          {"i", "i", "i", "gca", "t", "i"},   // 4
                          {"i", "i", "i", "i", "i", "gcta"}};  // 5
  int estado = 0;
  std::string cadena = "agtacaa";
  for (int i = 0; i < cadena.length(); ++i) {
    // std::cout << "soy i:" << i << std::endl;
    for (int j = 0; j < 5; ++j) {
      // std::cout << std::endl << cadena[i] << " == " << DFA[estado][j];
      for (int k = 0; k < DFA[estado][j].length(); ++k) {
         if (cadena[i] == (DFA[estado][j])[k]) {
          // std::cout << std::endl << DFA[estado][j] << " == " << 'i';
          if ((DFA[estado][j])[k] == 'i') {
            continue;
          } else {
            estado = j;
            std::cout << j << ' ';
            break;
          }
        }
      }
       
    }
  }

  if (estado == 2 || estado == 4) {
    std::cout << "La cadena: " << cadena << " ha sido aceptada" << std::endl;
  }

  return 0;
}