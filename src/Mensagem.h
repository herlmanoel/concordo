#ifndef MENSAGEM_H
#define MENSAGEM_H

#include <string>

using namespace std;

class Mensagem {
   public:
    string dataHora;
    int enviadaPor;
    string conteudo;
    Mensagem();
    Mensagem(int enviadaPor, string conteudo);
    Mensagem(const Mensagem &m);
};

#endif