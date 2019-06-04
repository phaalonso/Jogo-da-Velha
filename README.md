# Jogo-da-Velha
Jogo da velha desenvolvido durante o segundo semestre(2018), embora se passaram alguns meses já identifico varias alterações que poderiam ser feitas para aperfeiçoalo.

This is a hash game make with C during the second half of the first year of university. The code is really bad, so when I have some time I will upgrade it.

Requerimentos da professora:
PROJETO INDIVIDUAL
ENTREGA NO MOODLE ATÉ O DIA 10/09/2018
O jogo da velha é composto por 2 jogadores, no caso, um dos jogadores será o
computador (ou melhor o seu programa).
Para a realização deste jogo, é necessário criar uma matriz 3x3, onde cada posição
pode armazenar um sinal, no caso, os caracteres “O” ou “X”.
Vence o jogo aquele que conseguir fechar com o mesmo sinal na diagonal principal,
ou na diagonal secundária, ou na linha, ou na coluna.

Observações:
  - Devem existir FUNÇÕES separadas para verificar se houve ganhador na vertical, na
horizontal, e nas diagonais (principal e secundária).
  - A maioria das FUNÇÕES devem ser através de passagem de parâmetros
  - O computador deverá ser o sinal “O”, e o usuário deverá ser o sinal “X”
  - Deverá ter uma pergunta inicial para saber quem irá começar o jogo, se o computador
ou o usuário.
  - Fazer uma FUNÇÃO para verificar se houve empate (preenchimento de todos os
campos)
  - Informar, no final, a situação do jogo (quem ganhou, SE o computador; ou se houve
empate).
  - Permitir que o usuário jogue novamente.

OBS: o computador NÃO poderá perder o jogo.

A função rand (abreviatura de random), definida na biblioteca stdlib é usada para
gerar números aleatórios. Cada chamada da função produz um número aleatório no
intervalo fechado 0..RAND_MAX (constante).
