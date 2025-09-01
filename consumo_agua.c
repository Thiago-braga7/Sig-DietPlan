#include <stdio.h>
#include <stdlib.h>
#include "consumo_agua.h"


#define RED   "\033[31m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define RESET  "\033[0m"








void modulo_consumo_agua(void) {
    char opcao;
    do {
        opcao = consumo_agua();
        switch(opcao) {
            case '1': cadastrar_consumo_agua(); break;
            case '2': buscar_consumo_agua(); break;
            case '3': alterar_consumo_agua(); break;
            case '4': excluir_consumo_agua(); break;

            
        }
    } while (opcao != '0');  
}

char consumo_agua(void){
    char opcao;
    system("clear||cls");
    printf("\n");
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
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
    printf("///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    return opcao;
}

void cadastrar_consumo_agua(void){
    int quantidade_agua;
    char data[15];
    system("clear||cls");

    printf("\n");
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                               Consumo Água                              ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = =  Cadastrar Consumo de Água = = = = =          ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe a quantidade (ml):                      ///\n");
    scanf("%d", &quantidade_agua);
    getchar();
    printf("///                         Informe a data (DD/MM/AAAA):                    ///\n");
    scanf("%10s", data);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf("\n");
}

void buscar_consumo_agua(void){
    char data[15];
    system("clear||cls");

    printf("\n");
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                               Consumo Água                              ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = =  Buscar Consumo de Água = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe a data (DD/MM/AAAA):                    ///\n");
    scanf("%10s", data);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                     Registro de Consumo (Água) no dia (DD/MM/AAAA)      ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf("\n");
}

void alterar_consumo_agua(void){
    char data[15];
    int nova_quantidade_agua;
    char nova_data[15];
    system("clear||cls");
    
    printf("\n");
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                               Consumo Água                              ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = =  Alterar Consumo de Água = = = = =            ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe a data (DD/MM/AAAA):                    ///\n");
    scanf("%10s", data);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                     Registro de Consumo(Água) no dia (DD/MM/AAAA)       ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                     Novas Informações Consumo de Água                   ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe a quantidade (ml):                      ///\n");
    scanf("%d", &nova_quantidade_agua);
    getchar();
    printf("///                         Informe a data (DD/MM/AAAA):                    ///\n");
    scanf("%10s", nova_data);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf("\n");
}

void excluir_consumo_agua(void){
    char data[15], confirmacao;
    system("clear||cls");

    printf("\n");
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                               Consumo Água                              ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = =  Excluir Consumo de Água = = = = =            ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe a data (DD/MM/AAAA):                    ///\n");
    scanf("%10s", data);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                       Informações Consumo de Água                       ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Quantidade Água(ml):                            ///\n");
    printf("///                         Data(DD/MM/AAAA):                               ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                      Deseja excluir este registro?(S/N):                ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n"RESET);
    scanf("%c", &confirmacao);
    getchar();
    
    if (confirmacao == 'S' || confirmacao == 's') {
        printf("///            Registro de Consumo de Água excluído com sucesso  ///\n");
    } else {
        printf("///                    Operação de exclusão cancelada!                    ///\n");
    }
}
