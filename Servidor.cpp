#include "sistema.h"
#include <istream>
#include <ostream>
#include <sstream>
#include "Canal.h"
#include "Servidor.h"

using namespace std;

/** Constructor. Adiciona nome e o id ao Servidor
* @param nome - string - nome do Servidor 
* @param usuarioDonoId - int - id do Usuário
*/
Servidor::Servidor(string nome, int usuarioDonoId)
{
    this->nome = nome;
    this->usuarioDonoId = usuarioDonoId;
}