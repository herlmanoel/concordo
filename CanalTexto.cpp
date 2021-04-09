#include "CanalTexto.h"

#include <iostream>
#include <string>

#include "Canal.h"

using namespace std;

CanalTexto::CanalTexto(string nome) : Canal(nome) {
    this->setNome(nome);
}


string CanalTexto::getTipo() {
    return "texto";
}
