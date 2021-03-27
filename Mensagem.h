#ifndef MENSAGEM_H
#define MENSAGEM_H
#include "sistema.h"
#include <istream>
#include <ostream>
#include <sstream>

using namespace std;

/** Classe responsável pela mensagem 
* @author Herlmanoel Fernandes Barbosa
* @version 1.0
* @param dataHora - string
* @param conteudo - string
* @param int enviadaPor - guardar o ID do usuário que enviou a mensagem
**/

class Mensagem {
    private:
        string dataHora;
        int enviadaPor;
        string conteudo;
};

#endif