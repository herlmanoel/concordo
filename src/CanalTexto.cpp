#include "CanalTexto.h"

#include <algorithm>
#include <iostream>
#include <string>

#include "Canal.h"
#include "Mensagem.h"
#include "Usuario.h"
#include "sistema.h"

using namespace std;

CanalTexto::CanalTexto(string nome) : Canal(nome) {
    this->setNome(nome);
}

string CanalTexto::getTipo() {
    return "texto";
}

void CanalTexto::imprimirMensagens(vector<Usuario> usuarios) {
    vector<Mensagem> mensagens = this->mensagens;
    vector<Mensagem>::iterator ptr;

    cout << "--------------------" << endl;
    for (ptr = mensagens.begin(); ptr != mensagens.end(); ptr++) {
        Mensagem mensagem = *ptr;
        int idUser = mensagem.enviadaPor;
        vector<Usuario>::iterator it = find_if(usuarios.begin(), usuarios.end(), [idUser](Usuario &usu) { return usu.getId() == idUser; });
        Usuario user = *it;

        cout << user.getNome() << "<" << mensagem.dataHora << ">: " << mensagem.conteudo << endl;
    }
    cout << "--------------------" << endl;
}