#include <stdio.h>
#include <stdlib.h>
#include "consumo_agua.h"

char consumo_agua(void){
    char opcao;
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                    = = = = =  Consumo Diário(Água)  = = = = =           ///\n");
    printf("///                                                                         ///\n");
    printf("///                    1. Registrar Consumo de Água                         ///\n");
    printf("///                    2. Consultar Consumo(Dia) de Água                    ///\n");
    printf("///                    3. Alterar Registro de Consumo de Água               ///\n");
    printf("///                    4. Excluir Registro de Consumo de Água               ///\n");
    printf("///                    0. Voltar ao Menu Principal                          ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                      Escolha a opção desejada: ");
    scanf("%c", &opcao);
    getchar();
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    return opcao;

}

void cadastrar_consumoAgua(void){
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                               Consumo Água                              ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = =  Cadastrar Consumo de Água = = = = =          ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe a quantidade (ml):                      ///\n");
    printf("///                         Informe a data (DD/MM/AAAA):                    ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void buscar_consumoAgua(void){
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                               Consumo Água                              ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = =  Buscar Consumo de Água = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe a data (DD/MM/AAAA):                    ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                     Registro de Consumo (Água) no dia (DD/MM/AAAA)      ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void alterar_consumoAgua(void){
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                               Consumo Água                              ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = =  Alterar Consumo de Água = = = = =            ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe a data (DD/MM/AAAA):                    ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                     Registro de Consumo(Água) no dia (DD/MM/AAAA)       ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                     Novas Informações Consumo de Água                   ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe a quantidade (ml):                      ///\n");
    printf("///                         Informe a data (DD/MM/AAAA):                    ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void excluir_consumoAgua(void){
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                               Consumo Água                              ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = =  Excluir Consumo de Água = = = = =            ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe a data (DD/MM/AAAA):                    ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                       Informações Consumo de Água                       ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Quantidade Água(ml):                            ///\n");
    printf("///                         Data(DD/MM/AAAA):                               ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                      Deseja excluir este registro?(S/N):                ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}