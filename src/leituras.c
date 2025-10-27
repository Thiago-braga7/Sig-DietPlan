#include <stdio.h>
#include <string.h>
#include "validacoes.h"


void ler_nome(char *nome) {
    int valido = 0;

    do{
        printf("///                                 Nome:                               ///\n");
        scanf(" %50s", nome); 
        getchar();

        valido = validar_nome(nome);

        if(valido == 0){
            printf("Nome inválido! Digite novamente! \n");
        }
    } while (valido == 0);
}

void ler_cpf(char *cpf) {
    int valido = 0;
    
    do{
        printf("///                        CPF (Apenas números):                       ///\n");
        scanf(" %s", cpf); 
        getchar();

        valido = validar_cpf(cpf);

        if(valido == 0){
            printf("CPF inválido! Digite novamente! \n");
        }
    } while (valido == 0);
}