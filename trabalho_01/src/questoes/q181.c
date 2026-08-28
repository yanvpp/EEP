#include <include/questoes.h>
#include <stdio.h>

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

    double prob_defeituosa = 0.1;
    double prob_recuperavel =  0.2;
    double prob_perfeita = 0.7;

    double prob_2_defeituosas = prob_defeituosa * prob_defeituosa;

    printf("\nProbabilidade de ambas serem defeituosas: %.2f%%\n", prob_2_defeituosas);

    double prob_nao_perfeita = prob_defeituosa + prob_recuperavel;
    double prob_nenhuma_perfeita = prob_nao_perfeita * prob_nao_perfeita;
    double prob_pelo_menos_uma_perfeita = 1.0 - prob_nenhuma_perfeita;

    printf("\nProbabilidde de pelo menos uma ser perfeita: %.2f%%\n", prob_pelo_menos_uma_perfeita);

    double prob_rec_perfeita = prob_recuperavel * prob_perfeita;
    double prob_perfeita_rec = prob_perfeita * prob_recuperavel;

    printf("\nProbabilidade de uma ser recuperável e uma perfeita: %.2f%%\n", (prob_rec_perfeita + prob_perfeita_rec) * 100);

    return;
}