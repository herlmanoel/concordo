#include "CanalVoz.h"

#include <string>

using namespace std;


CanalVoz::CanalVoz() {
    this->setNome("");
    this->setTipo("voz");
}

CanalVoz::CanalVoz(string nome) {
    this->setNome(nome);
    this->setTipo("voz");
}
