#include "sistema.h"
#include <istream>
#include <ostream>
#include <sstream>
#include <string>
#include "Usuario.h"
#include "sistema.h"

using namespace std;
Usuario::Usuario()
{
    this->email = "\0";
    this->senha = "\0";
    this->nome = "\0";
}

Usuario::Usuario(const string email, const string senha, const string nome)
{
    this->email = email;
    this->senha = senha;
    this->nome = nome;
}

void Usuario::criarUsuario(const string email, const string senha, const string nome)
{

    this->email = email;
    this->senha = senha;
    this->nome = nome;
}

int Usuario::getId()
{
    return id;
}
string Usuario::getNome()
{
    return nome;
}
string Usuario::getEmail()
{
    return email;
}
string Usuario::getSenha()
{
    return senha;
}
void Usuario::setId(int id){
    this->id = id;
}