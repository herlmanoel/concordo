#include "CanalVoz.h"

#include <iostream>
#include <string>

using namespace std;

CanalVoz::CanalVoz(string nome) : Canal(nome) {
    this->setNome(nome);
}


string CanalVoz::getTipo() {
    return "voz";
}
