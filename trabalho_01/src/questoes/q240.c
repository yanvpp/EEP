#include <include/questoes.h>
#include <stdio.h>

/*
240)

A probabilidade de conseguir comprar, por telefone, ingressos para um concerto é igual a 0,92.
Para o mesmo evento, a probabilidade de acessar o site do vendedor na internet é igual a 0,95.

Considere que essas duas maneiras de comprar ingressos sejam independentes.

Qual é a probabilidade de alguém que tente comprar ingressos
pela internet e por telefone conseguir obtê-los?

*/

void enunciado240() {
    printf("\n|-------------------------|\n");
    printf("|------ Questão 240 ------|\n");
    printf("|-------------------------|\n");
    return;
}

void q240() {
    enunciado240();

    double prob_telefone = 0.92;
    double prob_internet = 0.95;

    double prob_ambas = prob_telefone * prob_internet;

    double prob_compra = prob_telefone + prob_internet - prob_ambas;

    printf("\nChance de obter tentando comprar por telefone e pela internet: %.2f%%\n", prob_compra * 100);

    return;
}