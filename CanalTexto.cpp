#include "CanalTexto.h"

#include <iostream>
#include <string>

#include "Canal.h"

using namespace std;

CanalTexto::CanalTexto(string nome) : Canal(nome) {
    cout << "CanalTexto: " << nome << endl;
    this->setNome(nome);
    this->setTipo("texto");
}