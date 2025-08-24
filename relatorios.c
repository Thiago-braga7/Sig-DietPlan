#include <stdio.h>
#include <stdlib.h>
#include "relatorios.h"

void relatorios(void){
    char opcao;
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                    = = = = =  Relatórios  = = = = =                     ///\n");
    printf("///                                                                         ///\n");
    printf("///                    1. Alimentos mais Consumidos                         ///\n");
    printf("///                    2. Total de Calorias(Dia)                            ///\n");
    printf("///                    3. Meta Diária de Calorias                           ///\n");
    printf("///                    4. Meta Diária de Água                               ///\n");
    printf("///                    5. Excluir Registro de Consumo                       ///\n");
    printf("///                    0. Voltar ao Menu Principal                          ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                      Escolha a opção desejada: ");
    scanf("%c", &opcao);
    getchar();
    
}