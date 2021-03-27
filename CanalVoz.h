#ifndef CANALDEVOZ_H
#define CANALDEVOZ_H
#include "sistema.h"
#include <istream>
#include <ostream>
#include <sstream>
#include "Mensagem.h"
#include "Canal.h"

using namespace std;

/** Classe responsável pelo Canal de Voz
* Assinatura dos métodos utilizados no arquivo .cpp 
* @author Herlmanoel Fernandes Barbosa
* @version 1.0
* @param ultimaMensagem - string - guarda a última mensagem do canal de voz
**/

class CanalVoz {
    public:
        Mensagem ultimaMensagem;
};

#endif