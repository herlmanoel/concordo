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
   private:
    string nome;
    string tipo;

   public:
    string getNome();
    void setNome(string nome);
    string getTipo();
    void setTipo(string tipo);
};

#endif