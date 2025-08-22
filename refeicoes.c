#include <stdio.h>
#include <stdlib.h>
#include "refeicoes.h"


void refeicoes(void){
    char opcao;
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                    = = = = =   Refeições   = = = = =                    ///\n");
    printf("///                                                                         ///\n");
    printf("///                    1. Cadastrar Refeição                                ///\n");
    printf("///                    2. Buscar Refeição                                   ///\n");
    printf("///                    3. Alterar Dados da Refeição                         ///\n");
    printf("///                    4. Excluir Refeição                                  ///\n");
    printf("///                    5. Listar Refeições do Usuário                       ///\n");
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
}
void cadastrar_refeicao(void){
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                Cardápio                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = =  Cadastrar Refeição = = = = =                 ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Nome da Refeição:                               ///\n");
    printf("///                         Tipo (Café, Almoço, Jantar, Lanche):            ///\n");
    printf("///                         Calorias (kcal):                                ///\n");
    printf("///                         Proteínas (g):                                  ///\n");
    printf("///                         Carboidratos (g):                               ///\n");
    printf("///                         Gorduras (g):                                   ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return refeicoes();   
}
void buscar_refeicao(void){
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                Cardápio                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///                   = = = = =  Buscar Refeição = = = = =                  ///\n");
    printf("///                                                                         ///\n");
    printf("///                        Informe o nome da Refeição:                      ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return refeicoes();   
}
void alterar_refeicao(void){
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                Cardápio                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = =  Alterar Refeição = = = = =                   ///\n");
    printf("///                                                                         ///\n");
    printf("///                  Informe o nome da Refeição a alterar:                  ///\n");
    printf("///                                                                         ///\n");
    printf("///                  Novos dados:                                           ///\n");
    printf("///                      Nome da Refeição:                                  ///\n");
    printf("///                      Tipo (Café, Almoço, Jantar, Lanche):               ///\n");
    printf("///                      Calorias (kcal):                                   ///\n");
    printf("///                      Proteínas (g):                                     ///\n");
    printf("///                      Carboidratos (g):                                  ///\n");
    printf("///                      Gorduras (g):                                      ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return refeicoes();   
}
void excluir_refeicao(void){
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                Cardápio                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = =  Excluir Refeição = = = = =                   ///\n");
    printf("///                                                                         ///\n");
    printf("///                  Informe o nome da Refeição a excluir:                  ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                      Deseja excluir esta refeição?(S/N):                ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return refeicoes();   
}
