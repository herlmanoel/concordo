#ifndef MENSAGEM_H
#define MENSAGEM_H
#include "sistema.h"
#include <istream>
#include <ostream>
#include <sstream>

using namespace std;

class Mensagem {
    private:
        string dataHora;
        int enviadaPor; //(guardar o ID do usuário que enviou a mensagem);
        string conteudo;
};

#endif