#include "CanalVoz.h"

#include <iostream>
#include <string>

using namespace std;


CanalVoz::CanalVoz() {
    this->setNome("");
    this->setTipo("voz");
}

CanalVoz::CanalVoz(string nome) : Canal(nome) {
    cout << "CanalVoz: " << nome << endl;
    this->setNome(nome);
    this->setTipo("voz");
}
