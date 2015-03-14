# Organização do projeto #

## Código ##

### Senha para commit ###

Uma utilidade de centralização de senhas do GNOME estava se intrometendo na hora de `checkout` o projeto.
A solução foi desabilitar o GNOME\_KEYRING, em Aplicativos > Acessórios > Senhas e chaves de criptografia.

# Problemas técnicos #

## C++ ##

### Forking ###

Desejamos que um único processo dê origem a dois processos,
> - o corpo do jogo em si, um programa C++, e
> - o programa responsável pelo processamento do ambiente BDI, escrito em Java.

A saída foi recorrer às funções
> - `fork`, que duplica a imagem do processo atual, e retorna
    * zero para o processo-filho,
    * um valor negativo se não foi possível executar o fork, e
    * 1 para o processo pai; e
> - `execl` que substitui a imagem do processo pela de um outro processo, dado o nome do executável cuja imagem substituirá a do processo atual, seu caminho para invocação e uma lista de parâmetros (terminada por `NULL` cast to `(char *)`).

## Java ##