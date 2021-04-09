#include "Canal.h"

#include <iostream>
#include <string>

using namespace std;

Canal::Canal(string nome) {
    this->nome = nome;
}

string Canal::getNome() {
    return this->nome;
}

void Canal::setNome(string nome) {
    this->nome = nome;
}

string Canal::getTipo() {
    return "";
}
