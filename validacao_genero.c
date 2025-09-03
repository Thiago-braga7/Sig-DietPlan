#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char ler_genero(void) {
    char genero;
    do {
        printf("Informe seu gênero (M = Masculino, F = Feminino, N = Prefiro não informar): ");
        scanf(" %c", &genero);
        genero = toupper(genero);

        if (genero != 'M' && genero != 'F' && genero != 'N') {
            printf("Opção inválida! Digite apenas M, F ou N.\n");
        }
    } while (genero != 'M' && genero != 'F' && genero != 'N');

    return genero;
}