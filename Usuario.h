#ifndef USUARIO_H
#define USUARIO_H
#include "sistema.h"
#include <istream>
#include <ostream>
#include <sstream>
#include <string>

using namespace std;

class Usuario {
    private:
        int id;
        string nome;
        string email;
        string senha;
    public:
        Usuario();
        void criarUsuario();
};

#endif