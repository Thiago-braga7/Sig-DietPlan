#include <stdio.h>
#include <stdlib.h> 
#include "usuarios.h"
#include "dietas.h"
#include "consumo.h"
#include "consultas.h"
#include "agendamentos.h"
#include "relatorios.h"
#include "sobre.h"
#include "util.h"


#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"





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
            case '2': modulo_dietas(); break;
            case '3': modulo_consumo(); break;
            case '4': modulo_consultas(); break;
            case '5': modulo_agendamentos(); break;
            case '6': relatorios(); break;
            case '0': sair(); break;
            
        }
    } while(opcao != '0');

    return 0;
}





void menu_principal(void){
    limpar_tela();
    printf("\n");
    printf(CYAN"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n"RESET);
    printf(CYAN"///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                 Centro de Ensino Superior do Seridó                     ///\n");
    printf("///               Departamento de Computação e Tecnologia                   ///\n");
    printf("///                  Disciplina DCT1106 -- Programação                      ///\n");
    printf("///               Projeto Sistema de Planejamento de Dietas                 ///\n");
    printf("///                           SIG-DietPlan                                  ///\n");
    printf("///         Criado por @thiagobraga9a e gabrieluchoa_1 -- desde Ago, 2025   ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf("\n");
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = Planejamento de Dietas = = = = =                   ///\n");
    printf("///                                                                         ///\n");
    printf("///                      1. Usuários                                        ///\n");
    printf("///                      2. Dietas                                          ///\n");
    printf("///                      3. Consumo(Alimentos/Água)                         ///\n");
    printf("///                      4. Consultas                                       ///\n");
    printf("///                      5. Agendamentos                                    ///\n");
    printf("///                      6. Relatórios                                      ///\n");
    printf("///                      0. Sair                                            ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf("\n");
}




