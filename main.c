#include <stdio.h>
#include <stdlib.h> 
#include "usuarios.h"
#include "alimentos.h"
#include "refeicoes.h"
#include "consumo_alimentos.h"
#include "consumo_agua.h"
#include "relatorios.h"
#include "sobre.h"


#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"
#define BOLD    "\033[1m"




void menu_principal(void);













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
            case '1': modulo_usuarios(); break;
            case '2': modulo_alimentos(); break;
            case '3': modulo_refeicoes(); break;
            case '4': modulo_consumo_alimentos(); break;
            case '5': modulo_consumo_agua(); break;
            case '6': relatorios(); break;
            case '0': sair(); break;
            
        }
    } while(opcao != '0');

    return 0;
}





void menu_principal(void){
    system("clear||cls");
    printf("\n");
    printf(CYAN"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n"RESET);
    printf(GREEN"///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                 Centro de Ensino Superior do Seridó                     ///\n");
    printf("///               Departamento de Computação e Tecnologia                   ///\n");
    printf("///                  Disciplina DCT1106 -- Programação                      ///\n");
    printf("///               Projeto Sistema de Planejamento de Dietas                 ///\n");
    printf("///                           SIG-DietPlan                                  ///\n");
    printf("///         Criado por @thiagobraga9a e gabrieluchoa_1 -- desde Ago, 2025   ///\n");
    printf("///                                                                         ///\n"RESET);
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf(RED"///            = = = = = Planejamento de Dietas = = = = =                   ///\n");
    printf("///                                                                         ///\n");
    printf("///                      1. Usuários                                        ///\n");
    printf("///                      2. Alimentos                                       ///\n");
    printf("///                      3. Refeições                                       ///\n");
    printf("///                      4. Consumo Diário(Alimentos)                       ///\n");
    printf("///                      5. Consumo Diário(Água)                            ///\n");
    printf("///                      6. Relatórios                                      ///\n");
    printf("///                      0. Sair                                            ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf("\n");
}




