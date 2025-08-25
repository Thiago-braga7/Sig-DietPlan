#include <stdio.h>
#include <stdlib.h>
#include "consumo_alimentos.h"

void modulo_consumo_alimentos(void) {
    char opcao;
    do {
        opcao = consumo_alimentos();
        switch(opcao) {
            case '1': cadastrar_consumo_alimentos(); break;
            case '2': buscar_consumo_alimentos(); break;
            case '3': alterar_consumo_alimentos(); break;
            case '4': excluir_consumo_alimentos(); break;
            
        }
    } while (opcao != '0');  
}


char consumo_alimentos(void){
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
    return opcao;
}

void cadastrar_consumo_alimentos(void){
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

void buscar_consumo_alimentos(void){
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

void alterar_consumo_alimentos(void){
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                               Consumo Alimentos                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = =  Alterar Consumo de Alimentos = = = = =       ///\n");
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
void excluir_consumo_alimentos(void){
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
    printf("///                         Alimento:                                       ///\n");
    printf("///                         Quantidade(kcal):                               ///\n");
    printf("///                         Data(DD/MM/AAAA):                               ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                      Deseja excluir este alimento?(S/N):                ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}