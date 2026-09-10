#include <include/questoes.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

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

void enunciado243()
{
    printf("\n|-------------------------|\n");
    printf("|------ Questão 243 ------|\n");
    printf("|-------------------------|\n");
    return;
}

void q243()
{
    enunciado243();

    printf("\n|--------------------------|\n");
    printf("|------ Sem iteração ------|\n");
    printf("|--------------------------|\n");

    srand(time(NULL));

    printf("\nPrimeiro, resolverei a questão 204, conforme solicitado pelo enunciado.\n");

    int m_alternativas = (rand() % 9) + 2; // entre 2 e 10 questões
    int p_saber_resposta = (rand() % 101); // 0 a 100%
    int k_marcar_certo = (rand() % 101);

    printf("\nVariáveis geradas:\n");
    printf("Número de alternativas (m): %d\n", m_alternativas);
    printf("Probabilidade de saber a resposta(p): %d%%\n", p_saber_resposta);
    printf("Probabilidade de marar certo sabendo a resposta(k): %d%%\n", k_marcar_certo);

    double prob_chutar = 1.0 - p_saber_resposta;
    double chance_acertar_chutando = 1.0 / m_alternativas;

    printf("\n|--------------------------|\n");
    printf("|------ Com iteração ------|\n");
    printf("|--------------------------|\n");

    long iteracoes = pow(10, 6);
    long sucessos = 0;

    printf("\nVariáveis geradas:\n");
    printf("Número de alternativas (m): %d\n", m_alternativas);
    printf("Probabilidade de saber a resposta (p): %d%%\n", p_saber_resposta);
    printf("Probabilidade de marcar certo sabendo a resposta (k): %d%%\n", k_marcar_certo);

    for (long i = 0; i < iteracoes; i++)
    {
        bool sabe_resposta = ((rand() % 100) + 1) <= p_saber_resposta;

        if (sabe_resposta)
        {
            bool marca_certo = ((rand() % 100) + 1) <= k_marcar_certo;

            if (marca_certo)
            {
                sucessos++;
            }
        }
        else
        {
            bool chuta_certo = ((rand() % m_alternativas) == 0);

            if (chuta_certo)
            {
                sucessos++;
            }
        }
    }

    printf("\nProbabilidade de o aluno responder corretamente: %.2f%%\n", ((double)sucessos / iteracoes) * 100);

    return;
}