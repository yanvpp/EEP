#include <include/questoes.h>
#include <stdio.h>

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

void enunciado125() {
    printf("\n|-------------------------|\n");
    printf("|------ Questão 125 ------|\n");
    printf("|-------------------------|\n");
    return;
}

void q125() {
    enunciado125();

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

    return;
}