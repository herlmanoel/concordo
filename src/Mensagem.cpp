#include "Mensagem.h"

#include <chrono>
#include <ctime>
#include <string>

using namespace std;

// Acessa a hora e data atual
string dataHoraAtual();

/* 
* Constructor. Adiciona valores "nulos" a Mensagem
*/
Mensagem::Mensagem() {
    this->dataHora = dataHoraAtual();
    this->enviadaPor = 0;
    this->conteudo = "";
}

/** Constructor. Constrói uma Mensagem com os parametros passados e data e hora atual
* @param enviadaPor - int  
* @param conteudo - string  
*/
Mensagem::Mensagem(int enviadaPor, string conteudo) {
    this->dataHora = dataHoraAtual();
    this->enviadaPor = enviadaPor;
    this->conteudo = conteudo;
}

/** Constructor cópia. Recebe a referência de uma Mensagem e faz a cópia para outra Mensagem
* @param m - Mensagem    
*/
Mensagem::Mensagem(const Mensagem &m) {
    this->dataHora = m.dataHora;
    this->enviadaPor = m.enviadaPor;
    this->conteudo = m.conteudo;
}

/** Acessa a hora e data atual
* @return dataHoraAtual - string formatada com a data e hora atual
*/
string dataHoraAtual() {
    time_t now = chrono::system_clock::to_time_t(chrono::system_clock::now());
    string s(17, ' ');
    strftime(&s[0], s.size(), "%d/%m/%Y %H:%M", localtime(&now));
    return s;
}

/** Add data a mensagem
* @param dataHora - string   
*/
void Mensagem::setData(string dataHora){
    this->dataHora = dataHora;
}