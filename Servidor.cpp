#include "sistema.h"
#include <istream>
#include <ostream>
#include <sstream>
#include "Canal.h"
#include "Servidor.h"

using namespace std;

Servidor::Servidor(string nome, int usuarioDonoId)
{
    this->nome = nome;
    this->usuarioDonoId = usuarioDonoId;
}