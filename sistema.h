#ifndef SISTEMA_H
#define SISTEMA_H
#include <iostream>
#include <string>
#include <vector>
#include "Servidor.h"
#include "Usuario.h"

using namespace std;

/** Classe responsável pelo Sistema
* Assinatura dos métodos utilizados no arquivo .cpp 
* @author Herlmanoel Fernandes Barbosa
* @version 1.0
* @param vector<Servidor> servidores - coleção de servidores
* @param vector<Usuario> usuarios - coleção de usuários
* @param int usuarioLogadoId - se 0: não logado, caso contrário guarda o id do usuário logado
* @param string nomeServidorConectado
* @param string nomeCanalConectado
**/

// Sistema deve concentrar todas as operações do Concordo
class Sistema {
   private:
    vector<Servidor> servidores;
    vector<Usuario> usuarios;
    int usuarioLogadoId;
    string nomeServidorConectado;
    string nomeCanalConectado;

   public:
    string quit();
    string create_user(const string email, const string senha, const string nome);
    string login(const string email, const string senha);
    string disconnect();
    string create_server(const string nome);
    string set_server_desc(const string nome, const string descricao);
    string set_server_invite_code(const string nome, const string codigo);
    string list_servers();
    string remove_server(const string nome);
    string enter_server(const string nome, const string codigo);
    string leave_server();
    string list_participants();
    string list_channels();
    string create_channel(const string nome, const string tipo);
    string enter_channel(const string nome);
    string leave_channel();
    string send_message(const string mensagem);
    string list_messages();

    Usuario* getLastUser();
    bool existEmail(string email);
    void incrementId(Usuario& user);
    Usuario* findUser(string email, string senha);
    Sistema();
    Servidor* findServer(string nome);
    bool existServer(string nome);
    int positionServer(string nome);
    Usuario* findUserById(int id);
};

#endif