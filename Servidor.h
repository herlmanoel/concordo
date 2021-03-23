#ifndef SERVIDOR_H
#define SERVIDOR_H
#include "sistema.h"
#include <istream>
#include <ostream>
#include <sstream>
#include "Canal.h"

using namespace std;

class Servidor {
    public:
        int usuarioDonoId;
        string nome;
        string descricao;
        string codigoConvite; // (código necessário para se entrar no servidor)
        vector<Canal> canais;
        vector<int> participantesIDs; // (lista de IDs de usuários que já estão no servidor)
        
        Servidor(string nome, int usuarioDonoId);
};

#endif