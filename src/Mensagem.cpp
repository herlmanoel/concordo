#include "Mensagem.h"

#include <chrono>
#include <ctime>
#include <string>

using namespace std;

string dataHoraAtual();

Mensagem::Mensagem() {
    this->dataHora = dataHoraAtual();
    this->enviadaPor = 0;
    this->conteudo = "";
}

Mensagem::Mensagem(int enviadaPor, string conteudo) {
    this->dataHora = dataHoraAtual();
    this->enviadaPor = enviadaPor;
    this->conteudo = conteudo;
}

Mensagem::Mensagem(const Mensagem &m) {
    this->dataHora = m.dataHora;
    this->enviadaPor = m.enviadaPor;
    this->conteudo = m.conteudo;
}

string dataHoraAtual() {
    time_t now = chrono::system_clock::to_time_t(chrono::system_clock::now());
    string s(17, '\0');
    strftime(&s[0], s.size(), "%d/%m/%Y %H:%M", localtime(&now));
    return s;
}