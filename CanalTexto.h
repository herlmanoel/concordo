#ifndef USUARIO_H
#define USUARIO_H
#include "sistema.h"
#include <istream>
#include <ostream>
#include <sstream>
#include "Mensagem.h"
#include "Canal.h"

using namespace std;

class CanalTexto {
    private:
        vector <Mensagem> mensagens;
};


#endif