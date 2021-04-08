#ifndef CANALTEXTO_H
#define CANALTEXTO_H

#include <string>
#include <vector>

#include "Canal.h"
#include "Mensagem.h"

using namespace std;

class CanalTexto : public Canal {
   public:
    CanalTexto(string nome);
    vector<Mensagem> mensagens;

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