#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <string>
#include <vector>

#include "Canal.h"

using namespace std;

/** Classe responsável pelo Servidor
* Assinatura dos métodos utilizados no arquivo .cpp 
* @author Herlmanoel Fernandes Barbosa
* @version 1.0
* @param int usuarioDonoId - id do dono do servidor 
* @param string nome - nome do servidor
* @param string descricao 
* @param string codigoConvite - código necessário para se entrar no servidor
* @param vector<Canal> canais - vector de canais do servidor 
* @param  vector<int> participantesIDs - vector de usuários que participam do servidor
**/

class Servidor {
   public:
    int usuarioDonoId;
    string nome;
    string descricao;
    string codigoConvite;  // (código necessário para se entrar no servidor)
    vector<Canal> canais;
    vector<int> participantesIDs;  // (lista de IDs de usuários que já estão no servidor)

    Servidor(string nome, int usuarioDonoId);
    Canal* findCanal(string nome);
    bool existCanal(string nome);
    void listarCanais();
};

#endif