#ifndef USUARIO_H
#define USUARIO_H
#include "sistema.h"
#include <istream>
#include <ostream>
#include <sstream>
#include <string>

using namespace std;

class Usuario
{
private:
    int id;
    string nome;
    string email;
    string senha;

public:
    Usuario(const string email, const string senha, const string nome);
    Usuario();
    void criarUsuario(const string email, const string senha, const string nome);
    int getId();
    string getNome();
    string getEmail();
    string getSenha();
    void setId(int id);
};

#endif