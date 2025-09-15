#include <stdio.h>
#include <stdlib.h>
#include "relatorios.h"


#define RESET   "\033[0m"
#define RED     "\033[31m"
#define CYAN    "\033[36m"





char relatorios(void){
    char opcao;
    printf("\n");
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n"RESET);
    printf(CYAN"///           = = = = =  🆁 🅴 🅻 🅰 🆃 🅾 🆁 🅸 🅾 🆂  = = = = =           ///\n"RESET);
    printf(RED"///                                                                         ///\n");
    printf("///                    1. Alimentos mais Consumidos                         ///\n");
    printf("///                    2. Total de Calorias(Dia)                            ///\n");
    printf("///                    3. Meta Diária de Calorias                           ///\n");
    printf("///                    4. Meta Diária de Água                               ///\n");
    printf("///                    5. Excluir Registro de Consumo                       ///\n");
    printf("///                    0. Voltar ao Menu Principal                          ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                      Escolha a opção desejada: "RESET);
    scanf("%c", &opcao);
    getchar();
    return opcao;
}
