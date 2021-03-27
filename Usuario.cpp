#include "Usuario.h"

#include <istream>
#include <string>


using namespace std;

// Constructor. Seta os @params do usuário como "nulos"
Usuario::Usuario() {
    this->email = "\0";
    this->senha = "\0";
    this->nome = "\0";
}

/** Constructor. Seta os @params do usuário passados
* @param email - string
* @param senha - string
* @param nome - string
*/
Usuario::Usuario(const string email, const string senha, const string nome) {
    this->email = email;
    this->senha = senha;
    this->nome = nome;
}

/** Método para acessar id do usuário
* @return id
*/
int Usuario::getId() {
    return id;
}

/** Método para acessar o nome do usuário
* @return string
*/
string Usuario::getNome() {
    return nome;
}

/** Método para acessar o email do usuário
* @return string
*/
string Usuario::getEmail() {
    return email;
}

/** Método para acessar a senha do usuário
* @return string
*/
string Usuario::getSenha() {
    return senha;
}

/** Método para setar o id do usuário
* @param id - int
*/
void Usuario::setId(int id) {
    this->id = id;
}