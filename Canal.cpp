#include "Canal.h"

#include <iostream>
#include <string>

using namespace std;

Canal::Canal() {
    this->nome = "";
}

Canal::Canal(string nome) {
    cout << "Canal: " << nome << endl;
    this->nome = nome;
}
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
