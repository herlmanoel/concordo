#include "CanalTexto.h"
#include <string>
#include <vector>

#include "Canal.h"
#include "Mensagem.h"
#include "sistema.h"

using namespace std;

CanalTexto::CanalTexto(string nome){
    this->setNome(nome);
}
