#include "CanalVoz.h"

#include <algorithm>
#include <iostream>
#include <string>

#include "Mensagem.h"

using namespace std;

CanalVoz::CanalVoz(string nome) : Canal(nome) {
    this->setNome(nome);
    this->ultimaMensagem.conteudo = "";
}

string CanalVoz::getTipo() {
    return "voz";
}

void CanalVoz::imprimirUltimaMensagem(vector<Usuario> usuarios) {
    Mensagem mensagem = this->ultimaMensagem;
    vector<Mensagem>::iterator ptr;

    cout << "--------------------" << endl;
    int idUser = mensagem.enviadaPor;
    vector<Usuario>::iterator it = find_if(usuarios.begin(), usuarios.end(), [idUser](Usuario &usu) { return usu.getId() == idUser; });
    Usuario user = *it;
    cout << user.getNome() << "<" << mensagem.dataHora << ">: " << mensagem.conteudo << endl;
    cout << "--------------------" << endl;
}
