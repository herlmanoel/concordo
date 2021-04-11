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
    // Atributos públicos
    int usuarioDonoId;
    string nome;
    string descricao;
    string codigoConvite; // (código necessário para se entrar no servidor)
    vector<Canal *> canais; // Lista de canais
    vector<int> participantesIDs; // (lista de IDs de usuários que já estão no servidor)

    // Constructor. Adiciona nome e o id ao Servidor
    Servidor(string nome, int usuarioDonoId);
    // Método para pesquisar um canal na lista de canais do Servidor
    Canal* findCanal(string nome);
    // Método para verificar se existe um canal com este nome na lista de canais do Servidor
    bool existCanal(string nome);
    // Método para imprimir os elementos da lista de canais do Servidor
    void listarCanais();

};

#endif