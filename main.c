#include <stdio.h>
#include <stdlib.h> 
#include "usuarios.h"
#include "alimentos.h"
#include "refeicoes.h"
#include "consumo_alimentos.h"
#include "consumo_agua.h"
#include "relatorios.h"





void bem_vindo(void);
void sobre(void);
void menu_principal(void);










void sair(void);



int main(void){
    char opcao;
    bem_vindo();
    sobre();

    do {
        menu_principal();
        printf("Escolha uma opção: ");
        scanf(" %c", &opcao);
        getchar();

        switch(opcao){
            case '1': moduloUsuarios(); break;
            case '2': moduloAlimentos(); break;
            case '3': moduloRefeicoes(); break;
            case '4': modulo_consumoAlimentos(); break;
            case '5': modulo_consumoAgua(); break;
            case '6': relatorios(); break;
            case '0': sair(); break;
            
        }
    } while(opcao != '0');

    return 0;
}

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



void menu_principal(void){
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                 Centro de Ensino Superior do Seridó                     ///\n");
    printf("///               Departamento de Computação e Tecnologia                   ///\n");
    printf("///                  Disciplina DCT1106 -- Programação                      ///\n");
    printf("///               Projeto Sistema de Planejamento de Dietas                 ///\n");
    printf("///                           SIG-DietPlan                                  ///\n");
    printf("///         Criado por @thiagobraga9a e gabrieluchoa_1 -- desde Ago, 2025   ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = Planejamento de Dietas = = = = =                   ///\n");
    printf("///                                                                         ///\n");
    printf("///                      1. Usuários                                        ///\n");
    printf("///                      2. Alimentos                                       ///\n");
    printf("///                      3. Refeições                                       ///\n");
    printf("///                      4. Consumo Diário(Alimentos)                       ///\n");
    printf("///                      5. Consumo Diário(Água)                            ///\n");
    printf("///                      6. Relatórios                                      ///\n");
    printf("///                      0. Sair                                            ///\n");
    printf("///                                                                         ///\n");
    getchar();
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
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

