#include <stdio.h>
#include <stdlib.h>
#include "sobre.h"


void bem_vindo(void) {
    char nome[50];
    char genero;

    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                           SIG-DietPlan                                  ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");

    printf("\nInforme seu nome: ");
    scanf("%[^\n]", nome);  

    printf("Informe seu gênero (M = Masculino, F = Feminino, N = Prefiro não informar): ");
    scanf(" %c", &genero);

    if (genero == 'M' || genero == 'm') {
        printf("\nBem-vindo 😁, %s!\n", nome);
    } else if (genero == 'F' || genero == 'f') {
        printf("\nBem-vinda 😁, %s!\n", nome);
    } else {
        printf("\nBem-vindo(a) 😁, %s!\n", nome);
    }

   
}

void sobre(void){
    printf("Sig-DietaPlan é um sistema desenvolvido na disciplina de Programação da UFRN\n");
    printf("para auxiliar no planejamento e acompanhamento de dietas.\n");
    printf("\n");
    printf("Ele permite:\n");
    printf("- Cadastro de usuários;\n");
    printf("- Gestão de alimentos e valores nutricionais;\n");
    printf("- Registro de consumos diários;\n");
    printf("- Planejamento de refeições personalizadas.\n");
    printf("\n");

    
    printf("Estamos felizes em ter você no SIG-DietPlan! 😊👍\n\n");
    printf("Gerencie sua saúde de forma prática: cadastre usuários, registre alimentos, acompanhe a quantidade de água ingerida e controle suas calorias diárias!");
    printf("\n");

}

void sair(void){
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                 Obrigado por usar o SIG-DietPlan!                       ///\n");
    printf("///                         Até a proxima!                                  ///\n");
    printf("///              📷 Instagram: @thiago.braga9a e gabrieluchoa_1             ///\n");
    printf("///              🐙 GitHub: github.com/Thiago-braga7                        ///\n");
    printf("///                         github/GabrielUchoa17                           ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");

}
