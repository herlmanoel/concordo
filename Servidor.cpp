#include "Servidor.h"

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

Canal* Servidor::findCanal(string nome) {
    for (int i = 0; i < (int)this->canais.size(); i++) {
        if (this->canais[i].getNome() == nome) {
            return &(this->canais[i]);
        }
    }
    return NULL;
}

bool Servidor::existCanal(string nome) {
    for (int i = 0; i < (int)this->canais.size(); i++) {
        if (this->canais[i].getNome() == nome) {
            return true;
        }
    }
    return false;
}

void Servidor::listarCanais() {
    vector<Canal> canais = this->canais;
    vector<CanalTexto> canaisTexto;
    vector<CanalVoz> canaisVoz;

    vector<Canal>::iterator ptr;

    cout << "#canais de texto" << endl;
    for (ptr = canais.begin(); ptr < canais.end(); ptr++) {
        if(ptr->getTipo().compare("texto") == 0) {
            cout << ptr->getNome() << endl;
        }
    }
    cout << "#canais de voz" << endl;
    for (ptr = canais.begin(); ptr < canais.end(); ptr++) {
        if(ptr->getTipo().compare("voz") == 0) {
            cout << ptr->getNome() << endl;
        }
    }
}