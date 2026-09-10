#include <include/questoes.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

/*
181)

Peças produzidas por uma máquina são classificadas como defeituosas, recuperáveis ou perfeitas
com probabilidade de 0,1; 0,2 e 0,7 respectivamente.

De um grande lote dessas peças, foram sorteadas duas delas e 
sua classificação observada. 

Determine a probabilidade de:

a.) Duas serem defeituosas.

b.) Pelo menos uma ser perfeita.

c.) Uma ser recuperável e uma perfeita.

*/

void enunciado181() {
    printf("\n|-------------------------|\n");
    printf("|------ Questão 181 ------|\n");
    printf("|-------------------------|\n");
    return;
}

void q181() {
    enunciado181();

    printf("\n|--------------------------|\n");
    printf("|------ Sem iteração ------|\n");
    printf("|--------------------------|\n");

    double prob_defeituosa = 0.1;
    double prob_recuperavel =  0.2;
    double prob_perfeita = 0.7;

    double prob_2_defeituosas = prob_defeituosa * prob_defeituosa;

    printf("\nProbabilidade de ambas serem defeituosas: %.2f%%\n", prob_2_defeituosas * 100);

    double prob_nao_perfeita = prob_defeituosa + prob_recuperavel;
    double prob_nenhuma_perfeita = prob_nao_perfeita * prob_nao_perfeita;
    double prob_pelo_menos_uma_perfeita = 1.0 - prob_nenhuma_perfeita;

    printf("\nProbabilidde de pelo menos uma ser perfeita: %.2f%%\n", prob_pelo_menos_uma_perfeita * 100);

    double prob_rec_perfeita = prob_recuperavel * prob_perfeita;
    double prob_perfeita_rec = prob_perfeita * prob_recuperavel;

    printf("\nProbabilidade de uma ser recuperável e uma perfeita: %.2f%%\n", (prob_rec_perfeita + prob_perfeita_rec) * 100);




    printf("\n|--------------------------|\n");
    printf("|------ Com iteração ------|\n");
    printf("|--------------------------|\n");

    srand(time(NULL));

    long iteracoes = pow(10, 6);
    long duas_defeituosas = 0;
    long ao_menos_uma_perfeita = 0;
    long recuperavel_e_perfeita = 0;

    for (long i = 0; i < iteracoes; i++) {
        int peca1 = (rand() % 100) + 1;
        int peca2 = (rand() % 100) + 1;

        int peca1_defeituosa = (peca1 >= 1 && peca1 <= 10);
        int peca1_recuperavel = (peca1 >= 11 && peca1 <= 30);
        int peca1_perfeita = (peca1 >= 31 && peca1 <= 100);

        int peca2_defeituosa = (peca2 >= 1 && peca2 <= 10);
        int peca2_recuperavel = (peca2 >= 11 && peca2 <= 30);
        int peca2_perfeita = (peca2 >= 31 && peca2 <= 100);

        if (peca1_defeituosa && peca2_defeituosa) {
            duas_defeituosas++;
        }

        if (peca1_perfeita || peca2_perfeita) {
            ao_menos_uma_perfeita++;
        }

        if ((peca1_recuperavel && peca2_perfeita) || (peca1_perfeita && peca2_recuperavel)) {
            recuperavel_e_perfeita++;
        }
    }

    printf("\nProbabilidade de ambas serem defeituosas: %.2f%%\n", ((double)duas_defeituosas / iteracoes) * 100);
    printf("Probabilidade de ao menos uma ser perfeita: %.2f%%\n", ((double)ao_menos_uma_perfeita / iteracoes) * 100);
    printf("Probabilidade de uma ser recuperável e uma perfeita: %.2f%%\n", ((double)recuperavel_e_perfeita / iteracoes) * 100);

    return;
}