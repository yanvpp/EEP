#include <include/questoes.h>
#include <stdio.h>

/*
163)

Duas cartas são retiradas simultaneamente de
um baralho. Qual é a probabilidade de que:

a.) ambas sejam de espadas;
b.) uma seja de espadas e a outra de copas.

*/

void enunciado163() {
    printf("\n|-------------------------|\n");
    printf("|------ Questão 163 ------|\n");
    printf("|-------------------------|\n");
    return;
}

void q163() {
    enunciado163();

    double totalDeCartas = 52.0;
    double espadasIniciais = totalDeCartas / 4;
    double copasIniciais = totalDeCartas / 4;

    double prob_1_espadas = espadasIniciais / totalDeCartas;
    double prob_2_espadas = (espadasIniciais - 1) / (totalDeCartas - 1);

    double prob_ambas_espadas = prob_1_espadas * prob_2_espadas;

    printf("\nProbabilidade de ambas as cartas serem de espadas: %.2f%%\n", prob_ambas_espadas * 100);

    double prob_1_copas = copasIniciais / totalDeCartas;
    double prob_2_copas = copasIniciais / (totalDeCartas - 1);

    double prob_espadas_copas = prob_1_espadas * prob_2_copas;
    double prob_copas_espadas = prob_1_copas * prob_2_espadas;

    printf("\nProbabilidade de tirar uma de espadas e uma de copas: %.2f%%\n", (prob_espadas_copas + prob_copas_espadas) * 100);

    return;
}