#include <include/questoes.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

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

    printf("\n|--------------------------|\n");
    printf("|------ Sem iteração ------|\n");
    printf("|--------------------------|\n");

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






    printf("\n|--------------------------|\n");
    printf("|------ Com iteração ------|\n");
    printf("|--------------------------|\n");

    srand(time(NULL));
    long iteracoes = pow(10, 6);
    long ambas_espadas = 0;
    long espadas_e_copas = 0;
    int quantidade_de_cartas = 52;

    for (long i = 0; i < iteracoes; i++) {
        int carta1 = (rand() % quantidade_de_cartas) + 1;
        int carta2;
        do {
            carta2 = (rand() % quantidade_de_cartas) + 1;
        } while (carta2 == carta1);

        // espadas da carta 1 à 13
        int carta1_espadas = (carta1 >= 1 && carta1 <= 13);
        int carta2_espadas = (carta2 >= 1 && carta2 <= 13);
        // copas da carta 14 à 26
        int carta1_copas = (carta1 >= 14 && carta1 <= 26);
        int carta2_copas = (carta2 >= 14 && carta2 <= 26);

        // ambas espadas
        if (carta1_espadas && carta2_espadas) {
            ambas_espadas++;
        }

        // uma de espadas e uma de copas
        if ((carta1_espadas && carta2_copas) || (carta1_copas && carta2_espadas)) {
            espadas_e_copas++;
        }
    }

    printf("\nProbabilidade de ambas as cartas serem de espadas: %.2f%%\n", ((double)ambas_espadas / iteracoes) * 100);
    printf("Probabilidade de tirar uma de espadas e uma de copas: %.2f%%\n", ((double)espadas_e_copas / iteracoes) * 100);

    return;
}