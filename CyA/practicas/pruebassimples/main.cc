// simples pruebas de como hacer un dfa con una matriz

#include <iostream>
#include <vector>

int main() {
  //                  0    1    2    3    4    5
  char DFA[6][6] = {{'i', 'a', 'i', 't', 'i', 'g'},   // 0
                    {'i', 't', 'a', 'i', 'i', 'i'},   // 1
                    {'i', 't', 'a', 'i', 'i', 'i'},   // 2
                    {'i', 'i', 'i', 'a', 't', 'i'},   // 3
                    {'i', 'i', 'i', 'a', 't', 'i'},   // 4
                    {'i', 'i', 'i', 'i', 'i', 'i'}};  // 5
  int estado=0;
  std::vector<std::string> cadenas =  {"tt", "aa", "ttt", "aaa", "tttt", "aaaa", "agta", "taaata"};
  std::string cadena = cadenas[7];
    for (int i = 0; i < cadena.length(); ++i) {
      std::cout << "soy i:" << i << std::endl;
      for (int j = 0; j < 5; ++j) {
        std::cout << std::endl << cadena[i] << " == " << DFA[estado][j];
        if (cadena[i] == DFA[estado][j]) {
          std::cout << std::endl<< DFA[estado][j] << " == " << 'i';
          if (DFA[estado][j] == 'i') {
            continue;
          } else {
            estado = j;
            std::cout << j << ' ';
            break;
          }
        }
      }
    }
  

  if (estado == 2 || estado == 4) {
    std::cout << "La cadena: " << cadena << " ha sido aceptada"
              << std::endl;
  }


  return 0;
}