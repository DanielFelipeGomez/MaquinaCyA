// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Símbolos, alfabetos y cadenas
// Autor: Daniel Felipe Gomez Aristizabal
// Correo: alu0101438139@ull.es
// Fecha: 04/10/2021
// Archivo cya-P02-Strings.cc: programa cliente.
// Contiene la funci´on main del proyecto que usa las clases X e Y
// que realizan el trabajo de leer el fichero de entrada
// identificando patrones en el texto que dan lugar
// al fichero de salida.
// Referencias:
// Enlaces de interés
// Historial de revisiones
// 04/10/2021 - Creación (primera versión) del código

#include "funciones.h"

// Verifica que todos los parametros necesarios hallan sido ingresados, de lo
// contrario se encarga de explicar el funcionamiento del programa
void CheckParameter(int argc, char* argv[]) {
  std::string aux = argv[1];
  if (argc == 2 && aux == "--help") {
    std::cout << "Para ejecutar le programa debe ingresar: \n./p02_strings "
                 "filein.txt fileout.txt opcode \nfilein.txt -> fichero de "
                 "entrada de valores \nfileout.txt -> fichero de salida de "
                 "resultados \nopcode código de operacion donde: \n    1 = "
                 "Longitud de la cadena \n    2 = Inversa de la cadena \n    3 "
                 "= Prefijos de la cadena \n    4 = Sufijos de la cadena \n    "
                 "5 = Subcadenas de la cadena"
              << std::endl;
  } else if (argc =! 4) {
    std::cout << "Faltan parámetros, para saber más de como funcina el "
                 "programa: \n./p02_strings --help" << std::endl;
  }
}

// Retorna una cadena invertida
std::string Reverse(std::string string) {
  std::string new_string;
  for (int i = 0; i < string.length(); ++i) {
    new_string = string[i] + new_string;
  }
  return new_string;
}

// Se encarga de leer el fichero y llamar a los constructores Alphabet y String
// de sus respectivas clases, ademas de llamar a la funcion Menu
void ReadFile(std::string file, int opcode, std::string fileout) {
  std::ifstream file_in;
  std::string string2;
  int n_power;
  std::string line;
  std::ofstream file_out;
  file_in.open(file);
  file_out.open(fileout);
  if(opcode == 6 || opcode == 7) {
    std::cout << "Ingrese la otra cadena a utilizar: " << std::endl;
    std::cin >> string2;
  } else if (opcode == 8) {
    std::cout << "Ingrese el número n a elevar la cadena: " << std::endl;
    std::cin >> n_power;
  }
  while (!file_in.eof()) {
    std::string alphabet = "", string = "";
    getline(file_in, line);
    bool flag = false;
    for (int i = line.length() - 1; i >= 0; --i) {
      if (line[i] != ' ') {
        if (flag) {
          alphabet += line[i];
          if (line[i - 1] == ' ') {
            alphabet += ' ';
          }
        } else {
          string += line[i];
        }
      } else {
        flag = true;
      }
    }
    if (alphabet == "") {
      alphabet = string;
    }
    Alphabet alpha(Reverse(alphabet));
    String str(Reverse(string), alpha);
    Menu(opcode, alpha, str, file_out, string2, n_power);
  }
  file_in.close();
  file_out.close();
}

// Llama a la correspondiente función según el opcode pasado por línea de comandos
void Menu(int opcode, Alphabet alpha, String str, std::ofstream& fileout, 
          std::string string2, int n_power) {
  switch (opcode) {
    case 1:{
      fileout << str.LengthWord() << "\n";
      break;
    }case 2:{
      fileout << str.ReverseWord() << "\n";
      break;
    }case 3:{
      Language language(str.PrefixesWords());
      fileout << language << "\n";
      break;
    }case 4:{
      Language language(str.SuffixesWords());
      fileout << language << "\n";
      break;
    }case 5:{
      Language language(str.SubStrings());
      fileout << language << "\n";
      break;
    }case 6:{
      String aux(string2);
      fileout << str.StringComparison(aux) << "\n";
      break;
    }case 7:{
      fileout << str.ConcatenateString(string2) << "\n";
      break;
    }case 8:{
      fileout << str.PowerString(n_power) << "\n";
      break;
    }default:{
      std::cout << "Invalid opcode" << std::endl;
      exit(1);
      break;
    }
  }
}
