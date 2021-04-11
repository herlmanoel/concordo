#ifndef USUARIO_H
#define USUARIO_H
#include <istream>
#include <string>

using namespace std;

/** Classe responsável pelo Usuário
* Assinatura dos métodos utilizados no arquivo .cpp 
* @author Herlmanoel Fernandes Barbosa
* @version 1.0
* @param int id
* @param string nome
* @param string email
* @param string senha
**/

class Usuario {
   private:
    // Atributos privados
    int id;
    string nome;
    string email;
    string senha;

   public:
    // Métodos públicos
    // Constructor. Seta os @params do usuário passados
    Usuario(const string email, const string senha, const string nome);
    // Constructor. Seta os @params do usuário como "nulos"
    Usuario();
    // Método para acessar o nome do usuário
    string getNome();
    // Método para acessar o email do usuário
    string getEmail();
    // Método para acessar a senha do usuário
    string getSenha();
    // Método para acessar id do usuário
    int getId();
    // Método para setar o id do usuário
    void setId(int id);
};

#endif