#include "CanalTexto.h"

#include <algorithm>
#include <iostream>
#include <string>

#include "Canal.h"
#include "Mensagem.h"
#include "Usuario.h"
#include "sistema.h"

using namespace std;

/** Constructor. Adiciona o nome ao Canal de Texto
* @param nome - string  
*/
CanalTexto::CanalTexto(string nome) : Canal(nome) {
    this->setNome(nome);
}

/** Acessa o tipo do canal
* @return tipo - string, no caso "texto"  
*/
string CanalTexto::getTipo() {
    return "texto";
}

/** Imprime todos as mensagens do canal
* @param usuarios - vector<Usuario>, lista de usuários para mostrar o nome de quem enviou a mensagem 
*/
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