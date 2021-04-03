#include "Mensagem.h"

#include <string>

using namespace std;

Mensagem::Mensagem() {
    this->dataHora = "";
    this->enviadaPor = 0;
    this->conteudo = "";
}
Mensagem::Mensagem(string dataHora, int enviadaPor, string conteudo) {
    this->dataHora = dataHora;
    this->enviadaPor = enviadaPor;
    this->conteudo = conteudo;
}