#include <include/questoes.h>
#include <stdio.h>
#include <stdlib.h>

/*
243)

Retorne ao enunciado do problema resolvido
204.) e considere que a probabilidade de o aluno
marcar corretamente a questão que ele conhece a
resposta é k. Em outras palavras, o aluno pode
fazer a conta e encontrar a resposta correta, que
seria por exemplo letra c, mas o aluno marca
erradamente o cartão de respostas na letra b.

Qual seria a expressão do item a.) do problema?


204)

A probabilidade de que um aluno saiba a resposta de uma questão de um exame de múltipla
escolha é p. Há m respostas possíveis para cada questão, das quais apenas uma é correta.
Se o aluno não sabe a resposta para uma dada questão,
ele escolhe ao acaso uma das m respostas possíveis.

a.) Qual é a probabilidade de o aluno responder
corretamente uma questão?

b.) Se o aluno respondeu corretamente a
questão, qual é a probabilidade de que ele
tenha “chutado” a resposta?

*/

void enunciado243() {
    printf("\n|-------------------------|\n");
    printf("|------ Questão 243 ------|\n");
    printf("|-------------------------|\n");
    return;
}

void q243() {
    enunciado243();

    printf("\nPrimeiro, resolverei a questão 204, conforme solicitado pelo enunciado.\n");

    int num_alternativas = (rand() % 9) + 2; // m entre 2 e 10 alternativas

    double prob_saber_resposta = (double)(rand() % 101) / 100.0; // p

    double prob_marcar_certo_sabendo_resposta = (double)(rand() % 101) / 100.0;// k

    printf("\nVariáveis geradas:\n");
    printf("Número de alternativas: %d\n", num_alternativas);
    printf("Probabilidade de saber a resposta: %d%%\n", prob_saber_resposta * 100);
    printf("Probabilidade de marar certo sabendo a resposta: %d%%\n", prob_marcar_certo_sabendo_resposta);
    
    double prob_chutar = 1.0 - prob_saber_resposta;
    double chance_acertar_chutando = 1.0 / num_alternativas;

    
    return;
}