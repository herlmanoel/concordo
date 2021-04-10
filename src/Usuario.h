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
    int id;
    string nome;
    string email;
    string senha;

   public:
    Usuario(const string email, const string senha, const string nome);
    Usuario();
    void criarUsuario(const string email, const string senha, const string nome);
    string getNome();
    string getEmail();
    string getSenha();
    int getId();
    void setId(int id);
};

#endif