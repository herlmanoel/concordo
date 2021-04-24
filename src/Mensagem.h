#ifndef MENSAGEM_H
#define MENSAGEM_H

#include <string>

using namespace std;

class Mensagem {
   public:
    // Atributos e métodos públicos
    string dataHora;
    int enviadaPor;
    string conteudo;

    // Constructor. Adiciona valores "nulos" a Mensagem
    Mensagem();
    // Constructor. Constrói uma Mensagem com os parametros passados e data e hora atual
    Mensagem(int enviadaPor, string conteudo);
    //  Constructor cópia. Recebe a referência de uma Mensagem e faz a cópia para outra Mensagem
    Mensagem(const Mensagem &m);
    // Add uma data a mensagem
    void setData(string dataHora);
};

#endif