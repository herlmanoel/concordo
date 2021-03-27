#include "sistema.h"

#include <algorithm>
#include <iostream>
#include <sstream>

#include "Usuario.h"

using namespace std;

// Método para sair do Sistema
string Sistema::quit() {
    return "Saindo...";
}

/** Método para criar um usuário no Sistema
* @param email - string
* @param senha - string
* @param nome - string
* @return string
*/
string Sistema::create_user(const string email, const string senha, const string nome) {
    if (existEmail(email))
        return "Usuario ja existe";

    Usuario *user = new Usuario(email, senha, nome);
    incrementId(*(user));

    usuarios.push_back(*(user));

    return "Usuario criado";
}

/** Método para logar o usuário no Sistema
* @param email - string
* @param senha - string
* @return string
*/
string Sistema::login(const string email, const string senha) {
    Usuario *user = findUser(email, senha);
    if (user != NULL) {
        usuarioLogadoId = user->getId();
        return "Logado como " + user->getEmail();
    }

    return "Senha ou usuario invalidos!";
}

/** Método para desconectar do Sistema (deslogar)
* @return string
**/
string Sistema::disconnect() {
    if (this->usuarioLogadoId == 0)
        return "Nao está conectado";

    int id = this->usuarioLogadoId;
    this->usuarioLogadoId = 0;

    return "Desconectando usuario " + usuarios[id - 1].getEmail();
}

/** Método para criar um servior no Sistema
* @param nome - string
* @return string
*/
string Sistema::create_server(const string nome) {
    if (this->usuarioLogadoId == 0)
        return "Nao está conectado";
    if (existServer(nome))
        return "Servidor com esse nome ja existe";

    Servidor *server = new Servidor(nome, this->usuarioLogadoId);
    servidores.push_back(*(server));
    return "Servidor criado";
}

/** Método para setar a descrição de um servior no Sistema
* @param nome - string
* @param descricao - string
* @return string
*/
string Sistema::set_server_desc(const string nome, const string descricao) {
    if (this->usuarioLogadoId == 0)
        return "Nao está conectado";
    Servidor *server = findServer(nome);

    if (server == NULL)
        return "Servidor ‘" + nome + "’ não existe";
    if (server->usuarioDonoId != usuarioLogadoId)
        return "Voce nao pode alterar a descricao de um servidor que nao foi criado por voce";

    server->descricao = descricao;

    return "Descricao do servidor '" + nome + "' modificada!";
}

/** Método para setar um código de convite de um servior no Sistema
* @param nome - string
* @param codigo - string
* @return string
*/
string Sistema::set_server_invite_code(const string nome, const string codigo) {
    if (this->usuarioLogadoId == 0)
        return "Nao está conectado";

    Servidor *server = findServer(nome);

    if (server == NULL)
        return "Servidor ‘" + nome + "’ não existe";
    if (server->usuarioDonoId != usuarioLogadoId)
        return "Voce nao pode alterar o codigo de um servidor que nao foi criado por voce";
    if (codigo.compare("") == 0)
        return "Código de convite do servidor 'minha-casa' removido!";

    server->codigoConvite = codigo;

    return "Codigo de convite do servidor '" + nome + "' modificado!";
}

/** Método para listar os servidores do Sistema
* @return string
**/
string Sistema::list_servers() {
    if (this->usuarioLogadoId == 0)
        return "Nao está conectado";
    for (int i = 0; i < (int)servidores.size(); i++) {
        cout << "Nome: " << servidores[i].nome << (servidores[i].descricao.compare("") != 0 ? ". Descricao: " + servidores[i].descricao : "") << (servidores[i].codigoConvite.compare("") != 0 ? " Aberto. " : " Fechado") << endl;
    }
    return "Fim da lista.";
}

/** Método para remover um servior do Sistema
* @param nome - string
* @return string
*/
string Sistema::remove_server(const string nome) {
    if (this->usuarioLogadoId == 0)
        return "Nao está conectado";
    int position = positionServer(nome);
    Servidor server = servidores[position];
    if (position == -1) {
        return "Servidor '" + nome + "' não encontrado.";
    } else if (server.usuarioDonoId != usuarioLogadoId) {
        return "Você não é dono do Servidor " + nome;
    }
    servidores.erase(servidores.begin() + position);
    return "Servidor '" + nome + "' removido";
}

/** Método para entrar em um servidor do Sistema
* @param nome - string
* @return string
*/
string Sistema::enter_server(const string nome, const string codigo) {
    if (this->usuarioLogadoId == 0) {
        return "Nao está conectado";
    }

    int position = positionServer(nome);

    Servidor *server = &servidores[position];
    if (server->usuarioDonoId == this->usuarioLogadoId) {
        server->participantesIDs.push_back(usuarioLogadoId);
        this->nomeServidorConectado = nome;

        return "Entrou no servidor com sucesso.";
    }

    if (server->codigoConvite.compare("") == 0) {
        server->participantesIDs.push_back(usuarioLogadoId);
        this->nomeServidorConectado = nome;

        return "Entrou no servidor com sucesso.";
    }

    if (server->codigoConvite.compare(codigo) == 0) {
        server->participantesIDs.push_back(usuarioLogadoId);
        this->nomeServidorConectado = nome;

        return "Entrou no servidor com sucesso.";
    }

    return "Erro ao entrar no servidor.";
}

// Método para sair do servidor
string Sistema::leave_server() {
    string nome = this->nomeServidorConectado;
    this->nomeServidorConectado = "";
    return "Saindo do servidor '" + nome + "'";
}

// Método para listar os participantes
string Sistema::list_participants() {
    if (this->nomeServidorConectado == "") {
        return "Você nao esta conectado em um servidor";
    }
    Servidor *server = findServer(this->nomeServidorConectado);
    vector<int> pid = server->participantesIDs;
    for (int id = 1; id < (int)pid.size(); id++) {
        Usuario *user = Sistema::findUserById(id);
        cout << user->getNome() << endl;
    }

    return "list_participants NÃO IMPLEMENTADO";
}

string Sistema::list_channels() {
    return "list_channels NÃO IMPLEMENTADO";
}

string Sistema::create_channel(const string nome, const string tipo) {
    return "create_channel NÃO IMPLEMENTADO";
}

string Sistema::enter_channel(const string nome) {
    return "enter_channel NÃO IMPLEMENTADO";
}

string Sistema::leave_channel() {
    return "leave_channel NÃO IMPLEMENTADO";
}

string Sistema::send_message(const string mensagem) {
    return "send_message NÃO IMPLEMENTADO";
}

string Sistema::list_messages() {
    return "list_messages NÃO IMPLEMENTADO";
}

// Método para acessar o último usuário
Usuario *Sistema::getLastUser() {
    int n = usuarios.size();
    if (n == 0)
        return NULL;

    return &usuarios[n - 1];
}

/** Método verificar a existência de um usuário 
* @param email - string
* @return bool
*/
bool Sistema::existEmail(string email) {
    for (int i = 0; i < (int)usuarios.size(); i++) {
        if (usuarios[i].getEmail() == email) {
            return true;
        }
    }
    return false;
}

/** Método encontrar um usuário pelo nome e email
* @param email - string
* @param nome - string
* @return Usuario*
*/
Usuario *Sistema::findUser(string email, string senha) {
    for (int i = 0; i < (int)usuarios.size(); i++) {
        bool userExist =
            usuarios[i].getEmail() == email &&
            usuarios[i].getSenha() == senha;
        if (userExist) {
            return &usuarios[i];
        }
    }
    return NULL;
}

/** Método encontrar um usuário pelo id
* @param id - int
* @return Usuario* 
*/
Usuario *Sistema::findUserById(int id) {
    for (int i = 0; i < (int)usuarios.size(); i++) {
        if (usuarios[i].getId() == id) {
            return &usuarios[i];
        }
    }
    return NULL;
}

/** Método para incrementar o id do usuário 
* @param &user - Usuario
*/
void Sistema::incrementId(Usuario &user) {
    Usuario *lastUser = getLastUser();
    if (lastUser == NULL) {
        user.setId(1);
    } else {
        int id_new = lastUser->getId() + 1;
        user.setId(id_new);
    }
}

// Método para inicializar um servidor
Sistema::Sistema() {
    this->usuarioLogadoId = 0;
}

/** Método encontrar um servidor pelo nome
* @param nome - string
* @return Servidor*
*/
Servidor *Sistema::findServer(string nome) {
    for (int i = 0; i < (int)servidores.size(); i++) {
        if (servidores[i].nome == nome) {
            return &servidores[i];
        }
    }
    return NULL;
}

/** Método para verificar a existência de um servidor pelo
* @param nome - string
* @return bool
*/
bool Sistema::existServer(string nome) {
    for (int i = 0; i < (int)servidores.size(); i++) {
        if (servidores[i].nome == nome) {
            return true;
        }
    }
    return false;
}

/** Método retornar a posição de um servidor
* @param nome - string
* @return int - id
*/
int Sistema::positionServer(string nome) {
    for (int i = 0; i < (int)servidores.size(); i++) {
        cout << servidores[i].nome << endl;
        cout << nome << endl;
        if (servidores[i].nome.compare(nome) == 0) {
            return i;
        }
    }
    return -1;
}