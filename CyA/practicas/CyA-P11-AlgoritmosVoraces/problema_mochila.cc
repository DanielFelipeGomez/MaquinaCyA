#include "tools.h"
#include "mochila.h"


int main(int argc, char* argv[]) {
  CheckParameters(argc, argv);
  if (std::string(argv[1]) == "-u") {
    std::string hola = std::string(argv[3]);
    double peso_max = std::stoi(argv[2]);
    Mochila mochila(hola, peso_max);
    mochila.Unbounded();
    mochila.PrintUnboundedResult();
  } else {
    std::string hola = std::string(argv[2]);
    double peso_max = std::stoi(argv[1]);
    Mochila mochila(hola, peso_max);
    mochila.Bounded();
    mochila.PrintBoundedResult();
  }
  // mochila.PrintMochila();
}