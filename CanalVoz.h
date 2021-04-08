#ifndef CANALDEVOZ_H
#define CANALDEVOZ_H

#include <string>

#include "Canal.h"
#include "Mensagem.h"

using namespace std;

/** Classe responsável pelo Canal de Voz
* Assinatura dos métodos utilizados no arquivo .cpp 
* @author Herlmanoel Fernandes Barbosa
* @version 1.0
* @param ultimaMensagem - string - guarda a última mensagem do canal de voz
**/

class CanalVoz : public Canal {
   public:
    Mensagem ultimaMensagem;
    CanalVoz();
    CanalVoz(string nome);

    // string getNome(){
    //     return this->nome;
    // }
    // void setNome(string nome){
    //     this->setNome(nome);
    // }
    // string getTipo(){
    //     return this->getTipo();
    // }
    // void setTipo(string tipo){
    //     this->setTipo(tipo);
    // }
};

#endif