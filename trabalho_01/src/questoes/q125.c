#include <include/questoes.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

/*
125)

Uma carta é retirada de um pacote padrão de 52 cartas
bem embaralhadas.

Qual é a probabilidade de que seja um rei?

Após o sorteio desta carta rei, uma segunda é sorteada, qual é
a probabilidade de que a segunda carta retirada seja também um rei?

Qual é a probabilidade de que as primeiras quatro cartas serem
retiradas de um baralho padrão de 52 cartas bem embaralhadas sejam
todas de reis?

Considere que, uma vez sorteada:

a.) uma carta não é reposta ao baralho.
b.) uma carta é reposta ao baralho.

*/

void enunciado125()
{
    printf("\n|-------------------------|\n");
    printf("|------ Questão 125 ------|\n");
    printf("|-------------------------|\n");
    return;
}

void q125()
{
    enunciado125();

    printf("\n|--------------------------|\n");
    printf("|------ Sem iteração ------|\n");
    printf("|--------------------------|\n");

    double totalDeCartas = 52.0;
    double reisIniciais = 4.0;

    double prob_1_rei = reisIniciais / totalDeCartas;
    printf("\nProbabilidade de a primeira carta ser um rei: %.2f%%\n", prob_1_rei * 100);

    double prob_2_rei_sem_repo = (reisIniciais - 1) / (totalDeCartas - 1);
    double prob_2_rei_com_repo = reisIniciais / totalDeCartas;

    printf("\nProbabilidade de a segunda carta também ser um rei:\n");
    printf("\tSem reposição de cartas: %.2f%%\n", prob_2_rei_sem_repo * 100);
    printf("\tCom reposição de cartas: %.2f%%\n", prob_2_rei_com_repo * 100);

    double prob_3_rei_sem_repo = (reisIniciais - 2) / (totalDeCartas - 2);
    double prob_3_rei_com_repo = reisIniciais / totalDeCartas;

    double prob_4_rei_sem_repo = (reisIniciais - 3) / (totalDeCartas - 3);
    double prob_4_rei_com_repo = reisIniciais / totalDeCartas;

    double prob_4_reis_seguidos_sem_repo = prob_1_rei * prob_2_rei_sem_repo * prob_3_rei_sem_repo * prob_4_rei_sem_repo;
    double prob_4_reis_seguidos_com_repo = prob_1_rei * prob_2_rei_com_repo * prob_3_rei_com_repo * prob_4_rei_com_repo;

    printf("\nProbabilidade de as 4 primeiras cartas serem todas reis:\n");
    printf("\tSem reposição de cartas: %f%%\n", prob_4_reis_seguidos_sem_repo * 100);
    printf("\tCom reposição de cartas: %f%%\n", prob_4_reis_seguidos_com_repo * 100);




    

    printf("\n|--------------------------|\n");
    printf("|------ Com iteração ------|\n");
    printf("|--------------------------|\n");

    srand(time(NULL));

    long iteracoes = pow(10, 6); // 10^6 iterações
    long rei1 = 0;
    long rei2_sem = 0, rei2_com = 0;
    long rei4_sem = 0, rei4_com = 0;
    int quantidade_de_cartas = 52;
    int quantidade_de_reis = 4;
    int reis[4] = {13, 26, 39, 52};

    for (long i = 0; i < iteracoes; i++)
    {

        // primeira carta ser rei
        bool carta1_eh_rei = false;
        int carta1 = (rand() % quantidade_de_cartas) + 1; // sorteia uma carta entre 1 e 52
        for (int j = 0; j < quantidade_de_reis; j++)
        {
            if (carta1 == reis[j])
            {
                rei1++;
                carta1_eh_rei = true;
                break;
            }
        }

        if (carta1_eh_rei == true)
        {

            // segunda carta com reposição
            int carta2_com = (rand() % quantidade_de_cartas) + 1;
            for (int j = 0; j < quantidade_de_reis; j++)
            {
                if (carta2_com == reis[j])
                {
                    rei2_com++;
                }
            }

            // segunda carta sem reposição
            int carta2_sem;
            do
            {
                carta2_sem = (rand() % quantidade_de_cartas) + 1;
            } while (carta2_sem == carta1);

            if (carta1)
                for (int j = 0; j < quantidade_de_reis; j++)
                {
                    if (carta2_sem == reis[j])
                    {
                        rei2_sem++;
                        break;
                    }
                }
        }

        // quatro reis seguidos
        // com reposição
        int sucessos_com = 0;
        for (int k = 0; k < 4; k++)
        {
            int carta = (rand() % quantidade_de_cartas) + 1;
            for (int j = 0; j < quantidade_de_reis; j++)
            {
                if (carta == reis[j])
                {
                    sucessos_com++;
                    break;
                }
            }
        }
        if (sucessos_com == 4)
        {
            rei4_com++;
        }

        // sem reposição
        int sucessos_sem = 0;
        int cartas_sorteadas[4] = {0, 0, 0, 0};

        for (int k = 0; k < 4; k++)
        {
            int carta_sem;
            int repetida;

            do
            {
                repetida = 0;
                carta_sem = (rand() % quantidade_de_cartas) + 1;
                // verificar a carta já saiu nessa iteração
                for (int c = 0; c < k; c++)
                {
                    if (carta_sem == cartas_sorteadas[c])
                    {
                        repetida = 1;
                        break;
                    }
                }
            } while (repetida);

            cartas_sorteadas[k] = carta_sem;

            for (int j = 0; j < quantidade_de_reis; j++)
            {
                if (carta_sem == reis[j])
                {
                    sucessos_sem++;
                    break;
                }
            }
        }
        if (sucessos_sem == 4)
        {
            rei4_sem++;
        }
    }

    printf("\nProbabilidade de a primeira carta ser um rei: %.2f%%\n", ((double)rei1 / iteracoes) * 100);

    printf("\nProbabilidade de a segunda carta também ser um rei:\n");
    if (rei1 > 0)
    {
        printf("\tSem reposição: %.2f%%\n", ((double)rei2_sem / rei1) * 100);
        printf("\tCom reposição: %.2f%%\n", ((double)rei2_com / rei1) * 100);
    }

    printf("\nProbabilidade de as 4 primeiras cartas serem todas reis:\n");
    printf("\tSem reposição: %f%%\n", ((double)rei4_sem / iteracoes) * 100);
    printf("\tCom reposição: %f%%\n", ((double)rei4_com / iteracoes) * 100);

    return;
}