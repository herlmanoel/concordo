#include "CanalVoz.h"

#include <string>

using namespace std;

CanalVoz::CanalVoz(string nome) {
    this->setNome(nome);
    this->setTipo("voz");
}

CanalVoz::CanalVoz() {
    this->setNome("");
    this->setTipo("voz");
}

CanalVoz::CanalVoz(string nome, Mensagem ultimaMensagem) {
    this->setNome(nome);
    this->ultimaMensagem = ultimaMensagem;
    this->setTipo("voz");
}