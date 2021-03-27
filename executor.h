#ifndef EXECUTOR_H
#define EXECUTOR_H
#include "sistema.h"
#include <istream>
#include <ostream>
#include <sstream>

using namespace std;

/** Classe responsável por executar o sistema
* Assinatura dos métodos utilizados no arquivo .cpp 
* @author Herlmanoel Fernandes Barbosa
* @version 1.0
* @param Sistema* - sistema
* @param sair - sair
* @param stringstream - ss
**/

class Executor {
  private:
  Sistema* sistema;
  stringstream ss;
  bool sair = false;

  public:
  Executor(Sistema &sistema);

  void iniciar(istream &in, ostream &out);

  string processarLinha(string linha);
};

#endif