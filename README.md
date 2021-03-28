# Atividade 03 de Linguagem de Programação I
Atividade 03 desenvolvida por Herlmanoel Fernandes Barbosa, com o código base do Prof. Ms. Isaac Franco Fernandes apresentada a disciplina de Linguagem de Programação I, com a orientação do Prof. Dr. Renan Cipriano Moioli. A atividade tem como objetivo colocar em prática os conteúdos repassados em aula desenvolvendo o "clone do Discord, para humanos mais civilizados". Com isso, produzimos um sistema chamado "Concordo" com recursos similares ao Discord, porém vai funcionar somente em modo texto e sem recursos de rede.

## Para compilar
Para compilar e rodar o programa utilizamos o makefile que é um arquivo contendo um conjunto de diretivas usadas para automatizar a compilação e gerar um executável. Desse modo, abaixo temos um exemplo de como compilar, executar e, assim, utilizar o "Concordo". No sistema Linux,

```console
make
```

## Para executar
Você pode rodar o sistema e em logo depois digitar os comandos seguidos de ENTER
```console
./concordo
```
## Comandos para executar
```console
create-user isaacfranco@imd.ufrn.br senhalegal Isaac Franco Fernandes
login isaacfranco@imd.ufrn.br senhalegal
disconnect
login isaacfranco@imd.ufrn.br senhalegal
create-server servidor-legal
create-server servidor-legal-02
set-server-desc servidor-legal Um servidor muito banaca e coisa e tal
set-server-invite-code servidor-legal 123
list-servers
remove-server servidor-legal-02
enter-server servidor-legal
list-participants
quit
```

Ou pode criar um arquivo de texto com uma lista de comandos (um por linha) e executar o sistema redirecionando esse arquivo como entrada padrão:
```console
./concordo < comandos.txt
```