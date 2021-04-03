#ifndef CANALTEXTO_H
#define CANALTEXTO_H

#include <string>
#include <vector>

#include "Canal.h"
#include "Mensagem.h"
#include "sistema.h"

using namespace std;

class CanalTexto : public Canal {
   private:
    vector<Mensagem> mensagens;

   public:
    CanalTexto();
    CanalTexto(string nome);
};

#endif