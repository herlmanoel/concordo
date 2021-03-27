#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "sistema.h"
#include "executor.h"

using namespace std;

/** Método principal responsável por inicializar projeto.
* @author Herlmanoel Fernandes Barbosa
* @version 1.0
**/

// g++ concordo.cpp executor.cpp sistema.cpp Usuario.cpp Servidor.cpp  -Wall -o prog && prog
int main() {
  // inicialização do sistema
  Sistema sistema;
  Executor executor(sistema);

  // o executor recebe o cin e o cout. Ele irá os utilizar para ler as linhas
  // de comando, executar o método correto em "sistema" e exibir as mensagens
  executor.iniciar(cin, cout);

  return 0;
}