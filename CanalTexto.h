#ifndef CANALTEXTO_H
#define CANALTEXTO_H

#include <string>
#include <vector>

#include "Canal.h"
#include "Mensagem.h"

using namespace std;

class CanalTexto : public Canal {
   public:
    vector<Mensagem> mensagens;

    CanalTexto(string nome);
    string getTipo();
};

#endif