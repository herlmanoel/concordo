#ifndef CANALTEXTO_H
#define CANALTEXTO_H

#include <string>
#include <vector>

#include "Canal.h"
#include "Mensagem.h"
#include "Usuario.h"

using namespace std;

/** Classe responsável pelo Canal de texto
* Assinatura dos métodos utilizados no arquivo .cpp 
* @author Herlmanoel Fernandes Barbosa
* @version 1.0
* @param nome - string - nome do canal
**/

class CanalTexto : public Canal {
   public:
    // Atributo público
    vector<Mensagem> mensagens;

    // Constructor. Adiciona o nome ao Canal de Texto
    CanalTexto(string nome);
    // Acessa o tipo do canal
    string getTipo();
    // Imprime todos as mensagens do canal
    void imprimirMensagens(vector<Usuario> usuarios);
};

#endif