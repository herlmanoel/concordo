#include "Mensagem.h"

#include <string>
#include <ctime>
using namespace std;

string dataHoraAtual ();

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

string dataHoraAtual () {
    time_t curr_time;
	curr_time = time(NULL);
	char *tm = ctime(&curr_time);
    return tm;
}