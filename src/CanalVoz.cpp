#include "CanalVoz.h"

#include <algorithm>
#include <iostream>
#include <string>

#include "Mensagem.h"

using namespace std;

/** Constructor. Adiciona o nome ao Canal de Voz
* @param nome - string  
*/
CanalVoz::CanalVoz(string nome) : Canal(nome) {
    this->setNome(nome);
    this->ultimaMensagem.conteudo = "";
}

/** Acessa o tipo do canal
* @return tipo - string, no caso "voz"  
*/
string CanalVoz::getTipo() {
    return "voz";
}

/** Imprime a mensagem do canal
* @param usuarios - vector<Usuario>, lista de usuários para mostrar o nome de quem enviou a mensagem 
*/
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
