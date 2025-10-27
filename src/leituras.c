#include <stdio.h>
#include <string.h>
#include "validacoes.h"



void ler_nome(char *nome) {
    int valido = 0;

    do{
        printf("///                                 Nome:                                   ///\n");
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


void ler_tel(char *tel) {
    int valido = 0;
    
    do{
        printf("///                         Telefone (Apenas números):                      ///\n");
        scanf(" %11s", tel); 
        getchar();

        valido = valida_telefone(tel);

        if(valido == 0){
            printf("Telefone inválido! Digite novamente! \n");
        }
    } while (valido == 0);
}


void ler_idade(char *idade) {
    int valido = 0;

    do{
        printf("///                         Idade:                                          ///\n");
        scanf("%s", idade); 
        getchar();

        valido = valida_idade(idade);

        if(valido == 0){
            printf("Idade inválida! Digite novamente! \n");
        }
    } while (valido == 0);
}


void ler_peso(float peso) {
    int valido = 0;

    do{
        printf("///                       Peso (kg):                                      ///\n");
        scanf("%f", &peso); 
        getchar();

        valido = validar_peso(peso);

        if(valido == 0){
            printf("Peso inválido! Digite novamente! \n");
        }
    } while (valido == 0);
}


void ler_altura(float altura) {
    int valido = 0;
    
    do{
        printf("///                      Altura (m):                                     ///\n");
        scanf("%f", &altura); 
        getchar();

        valido = validar_altura(altura);

        if(valido == 0){
            printf("Altura inválida! Digite novamente! \n");
        }
    } while (valido == 0);
}