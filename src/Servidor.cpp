#include "Servidor.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "Canal.h"
#include "CanalTexto.h"
#include "CanalVoz.h"

using namespace std;

/** Constructor. Adiciona nome e o id ao Servidor
* @param nome - string - nome do Servidor 
* @param usuarioDonoId - int - id do Usuário
*/
Servidor::Servidor(string nome, int usuarioDonoId) {
    this->nome = nome;
    this->usuarioDonoId = usuarioDonoId;
}

/** Constructor. Adiciona nome e o id ao Servidor
* @param nome - string - nome do Servidor 
* @param usuarioDonoId - int - id do Usuário
* @param descricao - string
* @param codigoConvite - string
*/
Servidor::Servidor(string nome, int usuarioDonoId, string descricao, string codigoConvite){
    this->nome = nome;
    this->usuarioDonoId = usuarioDonoId;
    this->descricao = descricao;
    this->codigoConvite = codigoConvite;
}

/** Método para pesquisar um canal na lista de canais do Servidor
* @param nome - string - nome do Canal 
* @return Canal* - Canal
*/
Canal *Servidor::findCanal(string nome) {
    for (int i = 0; i < (int)this->canais.size(); i++) {
        if (this->canais[i]->getNome() == nome) {
            return this->canais[i];
        }
    }
    return NULL;
}

/** Método para verificar se existe um canal com este nome na lista de canais do Servidor
* @param nome - string - nome do Canal 
* @return bool 
*/
bool Servidor::existCanal(string nome) {
    vector<Canal *> canais = this->canais;
    vector<Canal *>::iterator ptr;
    for (ptr = canais.begin(); ptr != canais.end(); ptr++) {
        Canal *canal = *ptr;
        if (canal->getNome().compare(nome) == 0) {
            return true;
        }
    }
    return false;
}

/* 
* Método para imprimir os elementos da lista de canais do Servidor
*/
void Servidor::listarCanais() {
    vector<Canal *> canais = this->canais;
    vector<Canal *>::iterator ptr;

    cout << "--------------------" << endl;
    for (ptr = canais.begin(); ptr != canais.end(); ptr++) {
        Canal *canal = *ptr;
        if (canal->getTipo().compare("texto") == 0) {
            cout << canal->getNome() << " | #"
                 << canal->getTipo() << endl;
        }
        if (canal->getTipo().compare("voz") == 0) {
            cout << canal->getNome() << " | #"
                 << canal->getTipo() << endl;
        }
    }
    cout << "--------------------" << endl;
}