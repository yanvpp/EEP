#include <include/questoes.h>
#include <stdio.h>

/*
54)

Considerando os dígitos 1, 2, 3, 4 e 5, quantos
números de 2 algarismos distintos podem ser formados?
*/

void enunciado54() {
    printf("\n|------------------------|\n");
    printf("|------ Questão 54 ------|\n");
    printf("|------------------------|\n");
    return;
}

void q54() {
    enunciado54();

    int digitos[] = {1 ,2 , 3, 4, 5};
    int totalDigitos = 5;
    int combinacoes = 0;

    printf("\nCombinações possíveis: \n");
    printf("\n");

    // primeiro for para a casa 1
    for(int i = 0; i < totalDigitos; i++) {
        // segundo for para a casa 2
        for(int j = 0; j < totalDigitos; j++){
            // se o número formado tiver 2 algarismos distintos
            if (digitos[i] != digitos[j]) {
                printf("%d%d\t", digitos[i], digitos[j]);
                combinacoes++; // incrementa o total de combinações
            }
        }
        printf("\n");
    }

    printf("\nQuantidade de combinações: %d\n", combinacoes);

    return;
}