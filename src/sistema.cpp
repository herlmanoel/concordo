#include "sistema.h"

#include <algorithm>
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Canal.h"
#include "CanalTexto.h"
#include "CanalVoz.h"
#include "Mensagem.h"
#include "Servidor.h"
#include "Usuario.h"

// g++ concordo.cpp executor.cpp sistema.cpp Usuario.cpp Servidor.cpp Canal.cpp CanalTexto.cpp CanalVoz.cpp -Wall -o prog && prog

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

    // salvando no arquivo de texto
    salvar();

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

    salvar();
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
    salvar();
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
    salvar();
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
    salvar();
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

    Servidor *server = findServer(nome);
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
    salvar();
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
    vector<int> partIDs = server->participantesIDs;
    vector<int>::iterator id;
    for (id = partIDs.begin(); id < partIDs.end(); id++) {
        Usuario *user = Sistema::findUserById(*(id));
        cout << user->getNome() << endl;
    }

    return "fim.";
}

string Sistema::list_channels() {
    if (this->nomeServidorConectado == "") {
        return "Você nao esta conectado em um servidor";
    }
    Servidor *server = findServer(this->nomeServidorConectado);
    cout << "Listando canais:" << endl;
    server->listarCanais();
    return "fim";
}

string Sistema::create_channel(const string nome, const string tipo) {
    if (this->nomeServidorConectado == "") {
        return "Você nao esta conectado em um servidor";
    }
    Servidor *server = findServer(this->nomeServidorConectado);
    cout << "Criando..." << endl;
    bool existCanal = server->existCanal(nome);

    if (existCanal) {
        return "O canal '" + nome + "' ja existe!";
    }

    if (tipo.compare("texto") == 0) {
        CanalTexto *canTxt = new CanalTexto(nome);

        server->canais.push_back(canTxt);
        salvar();
        return "Canal de texto '" + nome + "' criado!";
    } else if (tipo.compare("voz") == 0) {
        CanalVoz *canVoz = new CanalVoz(nome);
        server->canais.push_back(canVoz);
        salvar();
        return "Canal de voz '" + nome + "' criado!";
    }

    return "Erro no create_channel.";
}

string Sistema::enter_channel(const string nome) {
    if (this->nomeServidorConectado == "") {
        return "Você nao esta conectado em um servidor";
    }
    Servidor *server = findServer(this->nomeServidorConectado);
    Canal *canal = server->findCanal(nome);

    if (canal == NULL) {
        return "Canal nao encontrado no Servidor '" + server->nome + "'.";
    }

    this->nomeCanalConectado = nome;
    return "Entrou no canal " + nome;
}

string Sistema::leave_channel() {
    string nome = this->nomeCanalConectado;

    if (nome.compare("") == 0) {
        return "Voce nao esta dentro de um canal.";
    }

    this->nomeCanalConectado = "";
    return "Saindo do canal '" + nome + "'";
}

string Sistema::send_message(const string mensagem) {
    if (this->nomeServidorConectado == "") {
        return "Você nao esta conectado em um servidor";
    }

    Canal *canal = findServer(this->nomeServidorConectado)->findCanal(this->nomeCanalConectado);
    Mensagem m(this->usuarioLogadoId, mensagem);
    if (canal->getTipo().compare("texto") == 0) {
        CanalTexto *ct = (CanalTexto *)(canal);

        ct->mensagens.push_back(m);
        return "Mensagem enviada!";
    } else if (canal->getTipo().compare("voz") == 0) {
        CanalVoz *cv = (CanalVoz *)(canal);

        cv->ultimaMensagem = m;
        return "Mensagem enviada!";
    }

    return "send_message NÃO IMPLEMENTADO";
}

string Sistema::list_messages() {
    Sistema::salvar();
    if (this->nomeServidorConectado == "") {
        return "Você nao esta conectado em um servidor";
    }
    if (this->nomeCanalConectado == "") {
        return "Você nao esta conectado em um Canal";
    }

    Canal *canal = findServer(this->nomeServidorConectado)->findCanal(this->nomeCanalConectado);
    if (canal->getTipo().compare("texto") == 0) {
        CanalTexto *ct = (CanalTexto *)(canal);
        if (ct->mensagens.size() == 0) {
            return "Sem mensagens para exibir";
        }

        ct->imprimirMensagens(this->usuarios);
        return " ";
    } else if (canal->getTipo().compare("voz") == 0) {
        CanalVoz *cv = (CanalVoz *)(canal);
        if (cv->ultimaMensagem.conteudo.compare("") == 0) {
            return "Sem mensagens para exibir";
        }
        cv->imprimirUltimaMensagem(this->usuarios);
        return " ";
    }
    return "list_messages NÃO IMPLEMENTADO";
}

// Método para salvar os usuários do sistema
void Sistema::salvarUsuarios() {
    ofstream arquivo;
    arquivo.open("usuarios.txt");

    vector<Usuario> usuariosList = this->usuarios;
    vector<Usuario>::iterator ptr;

    arquivo << this->usuarios.size() << endl;
    for (ptr = usuariosList.begin(); ptr < usuariosList.end(); ptr++) {
        arquivo << ptr->getId() << endl;
        arquivo << ptr->getNome() << endl;
        arquivo << ptr->getEmail() << endl;
        arquivo << ptr->getSenha() << endl;
    }

    arquivo.close();
}

// Método para salvar os servidores e seus dados do sistema
void Sistema::salvarServidores() {
    ofstream arquivo;
    arquivo.open("servidores.txt");
    vector<Servidor> servidoresList = this->servidores;
    vector<Servidor>::iterator ptr;
    arquivo << servidoresList.size() << endl;

    for (ptr = servidoresList.begin(); ptr < servidoresList.end(); ptr++) {
        arquivo << ptr->usuarioDonoId << endl;
        arquivo << ptr->nome << endl;
        arquivo << ptr->descricao << endl;
        arquivo << ptr->codigoConvite << endl;

        vector<int> partIDs = ptr->participantesIDs;
        arquivo << partIDs.size() << endl;

        vector<int>::iterator id;
        for (id = partIDs.begin(); id < partIDs.end(); id++) {
            arquivo << *id << endl;
        }

        arquivo << ptr->canais.size() << endl;
        vector<Canal *> canaisList = ptr->canais;
        arquivo << canaisList.size() << endl;

        vector<Canal *>::iterator ptrCanal;
        for (ptrCanal = canaisList.begin(); ptrCanal != canaisList.end(); ptrCanal++) {
            Canal *canal = *ptrCanal;
            arquivo << canal->getNome() << endl;
            arquivo << canal->getTipo() << endl;

            if (canal->getTipo().compare("texto") == 0) {
                CanalTexto *ct = (CanalTexto *)(canal);

                vector<Mensagem> mensagens = ct->mensagens;
                vector<Mensagem>::iterator ptrTxt;
                for (ptrTxt = mensagens.begin(); ptrTxt != mensagens.end(); ptrTxt++) {
                    Mensagem mensagem = *ptrTxt;
                    arquivo << mensagem.enviadaPor << endl;
                    arquivo << mensagem.dataHora << endl;
                    arquivo << mensagem.conteudo << endl;
                }
            } else if (canal->getTipo().compare("voz") == 0) {
                CanalVoz *cv = (CanalVoz *)(canal);
                Mensagem mensagem = cv->ultimaMensagem;
                arquivo << mensagem.enviadaPor << endl;
                arquivo << mensagem.dataHora << endl;
                arquivo << mensagem.conteudo << endl;
            }
        }
    }

    arquivo.close();
}

// Método para executar os métodos
void Sistema::salvar() {
    salvarUsuarios();
    salvarServidores();
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
