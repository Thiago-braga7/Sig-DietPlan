#include <stdio.h>
#include <stdlib.h>
#include "consumo_alimentos.h"




void consumo_alimentos(void){
    char opcao;
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                    = = = = =  Consumo Diário(Alimentos)  = = = = =      ///\n");
    printf("///                                                                         ///\n");
    printf("///                    1. Registrar Consumo de Alimentos                    ///\n");
    printf("///                    2. Consultar Consumo(Dia) de Alimentos               ///\n");
    printf("///                    3. Alterar Registro de Consumo de Alimentos          ///\n");
    printf("///                    4. Excluir Registro de Consumo de Alimentos          ///\n");
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
    switch(opcao){
        case '1': cadastrar_consumoAlimentos(); break;
        case '2': buscar_consumoAlimentos(); break;
        case '3': alterar_consumoAlimentos(); break;
        case '4': excluir_consumoAlimentos(); break;
        case '0': return; 
    }
}

void cadastrar_consumoAlimentos(void){
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                               Consumo Alimentos                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = =  Cadastrar Consumo de Alimentos = = = = =     ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe o Alimento:                             ///\n");
    printf("///                         Quantidade(kcal):                               ///\n");
    printf("///                         Informe a data (DD/MM/AAAA):                    ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
   
}

void buscar_consumoAlimentos(void){
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                               Consumo Alimentos                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = =  Buscar Consumo de Alimentos = = = = =        ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe a data (DD/MM/AAAA):                    ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                     Registro de Consumo no dia (DD/MM/AAAA)             ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void alterar_consumoAlimentos(void){
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                               Consumo Alimentos                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = =  Alterar Consumo de Alimentos = = = = =        ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe a data (DD/MM/AAAA):                    ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                     Registro de Consumo no dia (DD/MM/AAAA)             ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                     Novas Informações Consumo de Alimentos              ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe o Alimento:                             ///\n");
    printf("///                         Quantidade(kcal):                               ///\n");
    printf("///                         Informe a data (DD/MM/AAAA):                    ///\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}
void excluir_consumoAlimentos(void){
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                               Consumo Alimentos                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = =  Excluir Consumo de Alimentos = = = = =       ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe a data (DD/MM/AAAA):                    ///\n");
    printf("///                         Informe o Alimento:                             ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                       Informações Consumo de Alimentos                  ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe o Alimento:                             ///\n");
    printf("///                         Quantidade(kcal):                               ///\n");
    printf("///                         Data(DD/MM/AAAA):                               ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
     printf("///                      Deseja excluir este alimento?(S/N):               ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}