#ifndef MENSAGEM_H
#define MENSAGEM_H

#include <string>

using namespace std;

class Mensagem {
  

   public:
    Mensagem();
    Mensagem(int enviadaPor, string conteudo);
    string dataHora;
    int enviadaPor;
    string conteudo;
};

#endif