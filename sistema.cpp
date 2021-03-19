#include "sistema.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include "Usuario.h"

using namespace std;

/* COMANDOS */
string Sistema::quit()
{
  return "Saindo...";
}

string Sistema::create_user(const string email, const string senha, const string nome)
{

  if (existEmail(email))
    return "Usuario ja existe";

  Usuario *user = new Usuario(email, senha, nome);
  incrementId(*(user));

  usuarios.push_back(*(user));

  return "Usuario criado";
}

string Sistema::login(const string email, const string senha)
{
  Usuario *user = findUser(email, senha);
  if (user != NULL)
  {
    usuarioLogadoId = user->getId();
    return "Logado como " + user->getEmail();
  }

  return "Senha ou usuario invalidos!";
}

string Sistema::disconnect()
{
  if (this->usuarioLogadoId == 0)
    return "Nao está conectado";

  int id = this->usuarioLogadoId;
  this->usuarioLogadoId = 0;

  return "Desconectando usuario " + usuarios[id - 1].getEmail();
}

string Sistema::create_server(const string nome)
{
  if (this->usuarioLogadoId == 0)
    return "Nao está conectado";
  if (existServer(nome))
    return "Servidor com esse nome ja existe";

  Servidor *server = new Servidor(nome, this->usuarioLogadoId);
  servidores.push_back(*(server));
  return "Servidor criado";
}

string Sistema::set_server_desc(const string nome, const string descricao)
{
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

string Sistema::set_server_invite_code(const string nome, const string codigo)
{
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

string Sistema::list_servers()
{
  if (this->usuarioLogadoId == 0)
    return "Nao está conectado";
  for(int i = 0; i < (int) servidores.size(); i++) {
    cout << "Nome: " << servidores[i].nome << 
        (servidores[i].descricao.compare("") != 0 ? ". Descricao: "+ servidores[i].descricao : "") << 
        (servidores[i].codigoConvite.compare("") != 0 ? " Aberto. " : " Fechado") << endl;
  }
  return "Fim da lista.";
}

string Sistema::remove_server(const string nome)
{
  if (this->usuarioLogadoId == 0)
    return "Nao está conectado";
  int position = positionServer(nome);
  Servidor server = servidores[position];
  if(position == -1) {
    return "Servidor '"+nome+"' não encontrado.";
  } else if (server.usuarioDonoId != usuarioLogadoId) {
    return "Você não é dono do Servidor "+nome;
  }
  servidores.erase(servidores.begin() + position);
  return "Servidor '"+nome+"' removido";
}

string Sistema::enter_server(const string nome, const string codigo)
{
  if (this->usuarioLogadoId == 0)
    return "Nao está conectado";

  int position = positionServer(nome);
  Servidor* server = &servidores[position];
  if(server->usuarioDonoId == this->usuarioLogadoId) {
    server->participantesIDs.push_back(usuarioLogadoId);
    server->participantesIDsLogados.push_back(usuarioLogadoId);

    return "Entrou no servidor com sucesso.";
  }

  if(server->codigoConvite.compare("") == 0) {
    server->participantesIDs.push_back(usuarioLogadoId);
    server->participantesIDsLogados.push_back(usuarioLogadoId);

    return "Entrou no servidor com sucesso.";
  }

  if(server->codigoConvite.compare(codigo) == 0) {
    server->participantesIDs.push_back(usuarioLogadoId);
    server->participantesIDsLogados.push_back(usuarioLogadoId);

    return "Entrou no servidor com sucesso.";
  }

  return "Erro ao entrar no servidor.";
}

string Sistema::leave_server()
{
  return "leave_server NÃO IMPLEMENTADO";
}

string Sistema::list_participants()
{
  return "list_participants NÃO IMPLEMENTADO";
}

string Sistema::list_channels()
{
  return "list_channels NÃO IMPLEMENTADO";
}

string Sistema::create_channel(const string nome, const string tipo)
{
  return "create_channel NÃO IMPLEMENTADO";
}

string Sistema::enter_channel(const string nome)
{
  return "enter_channel NÃO IMPLEMENTADO";
}

string Sistema::leave_channel()
{
  return "leave_channel NÃO IMPLEMENTADO";
}

string Sistema::send_message(const string mensagem)
{
  return "send_message NÃO IMPLEMENTADO";
}

string Sistema::list_messages()
{
  return "list_messages NÃO IMPLEMENTADO";
}
// -----------------------------
Usuario *Sistema::getLastUser()
{
  int n = usuarios.size();
  if (n == 0)
    return NULL;

  return &usuarios[n - 1];
}

bool Sistema::existEmail(string email)
{
  for (int i = 0; i < (int)usuarios.size(); i++)
  {
    if (usuarios[i].getEmail() == email)
    {
      return true;
    }
  }
  return false;
}

Usuario *Sistema::findUser(string email, string senha)
{
  for (int i = 0; i < (int)usuarios.size(); i++)
  {
    bool userExist =
        usuarios[i].getEmail() == email &&
        usuarios[i].getSenha() == senha;
    if (userExist)
    {
      return &usuarios[i];
    }
  }
  return NULL;
}

void Sistema::incrementId(Usuario &user)
{
  Usuario *lastUser = getLastUser();
  if (lastUser == NULL)
  {
    user.setId(1);
  }
  else
  {
    int id_new = lastUser->getId() + 1;
    user.setId(id_new);
  }
}

Sistema::Sistema()
{
  this->usuarioLogadoId = 0;
}

Servidor *Sistema::findServer(string nome)
{
  for (int i = 0; i < (int)servidores.size(); i++)
  {
    if (servidores[i].nome == nome)
    {
      return &servidores[i];
    }
  }
  return NULL;
}

bool Sistema::existServer(string nome)
{
  for (int i = 0; i < (int)servidores.size(); i++)
  {
    if (servidores[i].nome == nome)
    {
      return true;
    }
  }
  return false;
}

int Sistema::positionServer(string nome) {
  for(int i = 0; i < (int) servidores.size(); i++) {
    cout << servidores[i].nome << endl;
    cout << nome << endl;
    if(servidores[i].nome.compare(nome) == 0) {
      return i;
    }
  }
  return -1;
}