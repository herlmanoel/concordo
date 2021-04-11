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
# Você pode rodar o sistema e em logo depois digitar os comandos seguidos de ENTER
./concordo

# Você também pode executar a patir do arquivo "comandos.txt" que possui uma lista de comandos
./concordo < comandos.txt
```

## Exemplo 
**create-user**
```console
create-user isaacfranco@imd.ufrn.br senhalegal Isaac Franco Fernandes
create-user herlmanoel@gmail.com.br 123 Herlmanoel Fernandes
create-user renan@imd.ufrn.br senha Renan
```

**login**
```console
login herlmanoel@gmail.com.br 123
```

**create-server**
```console
create-server servidor-legal
```

**enter-server**
```console
enter-server servidor-legal
```

**create-channel**
Não podem haver canais dentro do servidor não podem ter o mesmo nome.
```console
create-channel canal-01 texto
create-channel canal-02 voz
```

**list-channels**
```console
list-channels
```

**enter-channel**
```console
enter-channel canal-01
```

**send-message**
```console
send-message bom dia
send-message tudo bem com voces?
```
**list-messages**
```console
list-messages
```