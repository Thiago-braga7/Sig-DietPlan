#include <stdio.h>
#include <stdlib.h>
#include "consumo_alimentos.h"

#define RED     "\x1b[31m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"






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
    system("clear||cls");

    printf("\n");
    printf(CYAN"///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf("///                                                                         ///\n");
    printf(RED"///                    = = = = =  Consumo Diário(Alimentos)  = = = = =      ///\n"RESET);
    printf("///                                                                         ///\n");
    printf(CYAN"///                    1. Registrar Consumo de Alimentos                    ///\n");
    printf("///                    2. Consultar Consumo(Dia) de Alimentos               ///\n");
    printf("///                    3. Alterar Registro de Consumo de Alimentos          ///\n");
    printf("///                    4. Excluir Registro de Consumo de Alimentos          ///\n");
    printf("///                    0. Voltar ao Menu Principal                          ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf("///                                                                         ///\n");
    printf("///                      Escolha a opção desejada: "RESET);
    scanf("%c", &opcao);
    getchar();
    printf("///                                                                         ///\n");
    printf(CYAN"///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    return opcao;
}

void cadastrar_consumo_alimentos(void){
    char alimento[100], data[15];
    float quantidade;
    system("clear||cls");

    printf("\n");
    printf(CYAN"///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf(RED"///                               Consumo Alimentos                         ///\n"RESET);
    printf(CYAN"///                                                                         ///\n");
    printf(RED"///                 = = = = =  Cadastrar Consumo de Alimentos = = = = =     ///\n"RESET);
    printf(CYAN"///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe o Alimento:                             ///\n"RESET);
    scanf("%[^\n]", alimento);
    getchar();
    printf(CYAN"///                         Quantidade(kcal):                               ///\n"RESET);
    scanf("%f", &quantidade);
    getchar();
    printf(CYAN"///                         Informe a data (DD/MM/AAAA):                    ///\n"RESET);
    scanf("%[^\n]", data);
    getchar();
    printf(CYAN"///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf("\n");
}

void buscar_consumo_alimentos(void){
    char data[15];
    system("clear||cls");

    printf("\n");
    printf(CYAN"///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf(RED"///                               Consumo Alimentos                         ///\n"RESET);
    printf(CYAN"///                                                                         ///\n");
    printf(RED"///                 = = = = =  Buscar Consumo de Alimentos = = = = =        ///\n"RESET);
    printf(CYAN"///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe a data (DD/MM/AAAA):                    ///\n"RESET);
    scanf("%[^\n]", data);
    getchar();
    printf(CYAN"///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf(RED"///                     Registro de Consumo no dia (DD/MM/AAAA)             ///\n"RESET);
    printf(CYAN"///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf("\n");
}

void alterar_consumo_alimentos(void){
    char data[15], alimento[100], nova_data[15];
    float nova_quantidade;
    system("clear||cls");

    printf("\n");
    printf(CYAN"///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf(RED"///                               Consumo Alimentos                         ///\n"RESET);
    printf(CYAN"///                                                                         ///\n");
    printf(RED"///                 = = = = =  Alterar Consumo de Alimentos = = = = =       ///\n"RESET);
    printf(CYAN"///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe a data (DD/MM/AAAA):                    ///\n"RESET);
    scanf("%[^\n]", data);
    getchar();
    printf(CYAN"///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf(RED"///                     Registro de Consumo no dia (DD/MM/AAAA)             ///\n"RESET);
    printf(CYAN"///                                                                         ///\n");
    printf("///                     Qual alimento deseja alterar? (número):             ///\n"RESET);
    int opcaoAlimento;
    scanf("%d", &opcaoAlimento);
    getchar();
    printf(CYAN"///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf(RED"///                     Novas Informações Consumo de Alimentos              ///\n"RESET);
    printf(CYAN"///                                                                         ///\n");
    printf("///                         Informe o Alimento:                             ///\n"RESET);
    scanf("%[^\n]", alimento);
    getchar();
    printf(CYAN"///                         Quantidade(kcal):                               ///\n"RESET);
    scanf("%f", &nova_quantidade);
    getchar();
    printf(CYAN"///                         Informe a data (DD/MM/AAAA):                    ///\n"RESET);
    scanf("%[^\n]", nova_data);
    getchar();
    printf("\n");
}

void excluir_consumo_alimentos(void){
    char data[15], alimento[100];
    system("clear||cls");

    printf("\n");
    printf(CYAN"///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf(RED"///                               Consumo Alimentos                         ///\n"RESET);
    printf(CYAN"///                                                                         ///\n");
    printf(RED"///                 = = = = =  Excluir Consumo de Alimentos = = = = =       ///\n"RESET);
    printf(CYAN"///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe a data (DD/MM/AAAA):                    ///\n"RESET);
    scanf("%[^\n]", data);
    getchar();
    printf(CYAN"///                         Informe o Alimento:                             ///\n"RESET);
    scanf("%[^\n]", alimento);
    getchar();
    printf(CYAN"///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf(RED"///                       Informações Consumo de Alimentos                  ///\n"RESET);
    printf(CYAN"///                                                                         ///\n");
    printf("///                         Alimento:                                       ///\n");
    printf("///                         Quantidade(kcal):                               ///\n");
    printf("///                         Data(DD/MM/AAAA):                               ///\n");
    printf(CYAN"///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf("///                      Deseja excluir este alimento?(S/N):                ///\n");
    printf(CYAN"///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf("\n");
}
