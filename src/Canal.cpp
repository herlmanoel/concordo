#include "Canal.h"

#include <iostream>
#include <string>

using namespace std;

/** Constructor. Adiciona nome ao Canal
* @param nome - string  
*/
Canal::Canal(string nome) {
    this->nome = nome;
}

/** Acessa o nome
* @return nome - string  
*/
string Canal::getNome() {
    return this->nome;
}

/** Adiciona o nome ao Canal
* @param nome - string  
*/
void Canal::setNome(string nome) {
    this->nome = nome;
}

/** Acessa o tipo do canal
* @return tipo - string  
*/
string Canal::getTipo() {
    return "";
}
