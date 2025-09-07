#include <stdio.h>
#include <stdlib.h>
#include "sobre.h"
#include "util.h"
#include "validacao_nome.h"




#define RESET   "\033[0m"
#define RED     "\033[31m"
#define CYAN    "\033[36m"




void bem_vindo(void) {
    char nome[50];
    char genero;
    bool valido = false;

    printf("\n");
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("░█▀▀▀█ ▀█▀ ░█▀▀█ ── ░█▀▀▄ ─▀─ █▀▀ ▀▀█▀▀ ░█▀▀█ █── █▀▀█ █▀▀▄ \n");
    printf("─▀▀▀▄▄ ░█─ ░█─▄▄ ▀▀ ░█─░█ ▀█▀ █▀▀ ──█── ░█▄▄█ █── █▄▄█ █──█ \n");
    printf("░█▄▄▄█ ▄█▄ ░█▄▄█ ── ░█▄▄▀ ▀▀▀ ▀▀▀ ──▀── ░█─── ▀▀▀ ▀──▀ ▀──▀ \n");                                                                                       
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n"RESET);
   
    do {
        printf("\nInforme seu nome: ");
        scanf(" %[^\n]", nome);  

        if(validar_nome(nome)) {
            valido = true;
        } else {
            printf("Nome inválido! Use apenas letras e espaços, palavras com no mínimo 2 letras, sem repetições absurdas.\n");
        }
    } while(!valido);

    genero = ler_genero();


    if (genero == 'M') {
        printf("\nBem-vindo 😁, %s!\n", nome);
    } else if (genero == 'F') {
        printf("\nBem-vinda 😁, %s!\n", nome);
    } else {
        printf("\nBem-vindo(a) 😁, %s!\n", nome);
    }
    pausar();
}


    



void sobre(void){
    printf(CYAN"Sig-DietaPlan é um sistema desenvolvido na disciplina de Programação da UFRN\n"RESET);
    printf(CYAN"para auxiliar no planejamento e acompanhamento de dietas.\n"RESET);
    printf("\n");
    printf(CYAN"Ele permite:\n"RESET);
    printf(CYAN"- Cadastro de usuários;\n"RESET);
    printf(CYAN"- Gestão de alimentos e valores nutricionais;\n"RESET);
    printf(CYAN"- Registro de consumos diários;\n"RESET);
    printf(CYAN"- Planejamento de refeições personalizadas.\n"RESET);
    printf("\n");

    printf(CYAN"Estamos felizes em ter você no SIG-DietPlan! 😊👍\n\n"RESET);
    printf(CYAN"Gerencie sua saúde de forma prática: cadastre usuários, registre alimentos, acompanhe a quantidade de água ingerida e controle suas calorias diárias!\n"RESET);
    printf("\n");
    pausar();
}

void sair(void){
    printf("\n");
    printf(CYAN"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf(CYAN"///                 Obrigado por usar o SIG-DietPlan!                       ///\n");
    printf("///                         Até a proxima!                                  ///\n");
    printf("///              📷 Instagram: @thiago.braga9a e gabrieluchoa_1             ///\n");
    printf("///              🐙 GitHub: github.com/Thiago-braga7                        ///\n");
    printf("///                         github/GabrielUchoa17                           ///\n");
    printf("///                                                                         ///\n");
    printf(CYAN"///////////////////////////////////////////////////////////////////////////////\n"RESET);
}
