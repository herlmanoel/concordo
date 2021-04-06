#include "Canal.h"

#include <string>
#include <iostream>

using namespace std;

string Canal::getNome() {
    return this->nome;
}

void Canal::setNome(string nome) {
    this->nome = nome;
}

string Canal::getTipo() {
    return this->tipo;
}

void Canal::setTipo(string tipo) {
    this->tipo = tipo;
}
