#include "CanalTexto.h"
#include "Canal.h"
#include <iostream>
#include <string>

using namespace std;

CanalTexto::CanalTexto(string nome) {
    cout << "criando nome: " << nome << endl;
    this->setNome(nome);
    this->setTipo("texto");
}

CanalTexto::CanalTexto() {
    this->setNome("");
    this->setTipo("texto");
}