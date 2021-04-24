#ifndef CANAL_H
#define CANAL_H

#include <string>

using namespace std;

/** Classe responsável pelo Canal
* Assinatura dos métodos utilizados no arquivo .cpp 
* @author Herlmanoel Fernandes Barbosa
* @version 1.0
* @param nome - string - nome do canal
**/

class Canal {
   public:
    // Atributos públicos
    string nome;
    string tipo;

    // Constructor. Adiciona nome ao Canal
    Canal(string nome);
    // Acessa o nome
    string getNome();
    // Adiciona o nome ao Canal
    void setNome(string nome);
    // Acessa o tipo do canal
    virtual string getTipo();
};

#endif