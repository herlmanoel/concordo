#ifndef CANAL_H
#define CANAL_H

#include <string>

using namespace std;

/** Classe responsável pelo Canal de texto
* Assinatura dos métodos utilizados no arquivo .cpp 
* @author Herlmanoel Fernandes Barbosa
* @version 1.0
* @param nome - string - nome do canal
**/

class Canal {
   public:
    string nome;
    string tipo;
    Canal();
    Canal(string nome);

    virtual string getNome();
    virtual void setNome(string nome);
    virtual string getTipo();
    virtual void setTipo(string tipo);
};

#endif