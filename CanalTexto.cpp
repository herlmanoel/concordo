#include "CanalTexto.h"

#include <string>

using namespace std;

CanalTexto::CanalTexto(string nome) {
    this->setNome(nome);
    this->setTipo("texto");
}

CanalTexto::CanalTexto() {
    this->setNome("");
    this->setTipo("texto");
}
