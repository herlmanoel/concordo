#ifndef CANALDEVOZ_H
#define CANALDEVOZ_H

#include <string>
#include <vector>

#include "Canal.h"
#include "Mensagem.h"
#include "Usuario.h"

using namespace std;

/** Classe responsável pelo Canal de Voz
* Assinatura dos métodos utilizados no arquivo .cpp 
* @author Herlmanoel Fernandes Barbosa
* @version 1.0
* @param ultimaMensagem - string - guarda a última mensagem do canal de voz
**/

class CanalVoz : public Canal {
   public:
    // Atributo público
    Mensagem ultimaMensagem;

    // Constructor. Adiciona o nome ao Canal de Voz
    CanalVoz(string nome);
    // Acessa o tipo do canal
    string getTipo();
    // Imprime a mensagem do canal
    void imprimirUltimaMensagem(vector<Usuario> usuarios);
};

#endif