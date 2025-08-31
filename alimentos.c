#include <stdio.h>
#include <stdlib.h>
#include "alimentos.h"


#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"






void modulo_alimentos(void) {
    char opcao;
    do {
        opcao = alimentos();
        switch(opcao) {
            case '1': cadastrar_alimento(); break;
            case '2': buscar_alimento(); break;
            case '3': alterar_alimento(); break;
            case '4': excluir_alimento(); break;
            
        }
    } while (opcao != '0');  
}


char alimentos(void){
    char opcao;
    system("clear||cls");

    printf("\n");
    printf(CYAN"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf(RED"///                    = = = = =   Alimentos   = = = = =                    ///\n"RESET);
    printf("///                                                                         ///\n");
    printf(CYAN"///                    1. Cadastrar Alimento na Dieta                       ///\n");
    printf("///                    2. Buscar Alimento na Dieta                          ///\n");
    printf("///                    3. Alterar Alimento da Dieta                         ///\n");
    printf("///                    4. Excluir Alimento da Dieta                         ///\n");
    printf("///                    0. Voltar ao Menu Principal                          ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
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

void cadastrar_alimento(void){
    char nome_alimento[100], tipo[50];
    float calorias, proteinas, carboidratos, gorduras;
    system("clear||cls");

    printf("\n");
    printf(CYAN"///////////////////////////////////////////////////////////////////////////////\n");
    printf(RED"///                               Alimentos                                 ///\n"RESET);
    printf(CYAN"///                                                                         ///\n");
    printf(RED"///                 = = = = =  Cadastrar Alimento na Dieta  = = = = =       ///\n"RESET);
    printf(CYAN"///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Nome do Alimento:                               ///\n"RESET);
    scanf("%[^\n]", nome_alimento);
    getchar();
    printf(CYAN"///                         Tipo(Fruta, Carne):                             ///\n"RESET);
    scanf("%[^\n]", tipo);
    getchar();
    printf(CYAN"///                         Calorias(kcal):                                 ///\n"RESET);
    scanf("%f", &calorias);
    getchar();
    printf(CYAN"///                         Proteínas:                                      ///\n"RESET);
    scanf("%f", &proteinas);
    getchar();
    printf(CYAN"///                         Carboidratos:                                   ///\n"RESET);
    scanf("%f", &carboidratos);
    getchar();
    printf(CYAN"///                         Gorduras:                                       ///\n"RESET);
    scanf("%f", &gorduras);
    getchar();
    printf(CYAN"///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf(RED"///                    Alimento cadastrado com sucesso!                     ///\n"RESET);
    printf(CYAN"///////////////////////////////////////////////////////////////////////////////\n"RESET);

}

void buscar_alimento(void){
    char nome_alimento[100];
    system("clear||cls");

    printf("\n");
    printf(CYAN"///////////////////////////////////////////////////////////////////////////////\n");
    printf(RED"///                               Alimentos                                 ///\n"RESET);
    printf(CYAN"///                                                                         ///\n");
    printf(RED"///                 = = = = =  Buscar Alimento na Dieta= = = = =            ///\n"RESET);
    printf(CYAN"///                                                                         ///\n");
    printf("///                         Informe o nome do Alimento:                     ///\n"RESET);
    scanf("%[^\n]", nome_alimento);
    getchar();
    printf(CYAN"///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf(RED"///                        Informações do Alimento                          ///\n"RESET);
    printf(CYAN"///                                                                         ///\n");
    printf("///                         Nome do Alimento:                               ///\n");
    printf("///                         Tipo(Fruta, Carne):                             ///\n");
    printf("///                         Calorias(kcal):                                 ///\n");
    printf("///                         Proteínas:                                      ///\n");
    printf("///                         Carboidratos:                                   ///\n");
    printf("///                         Gorduras:                                       ///\n");
    printf(CYAN"///////////////////////////////////////////////////////////////////////////////\n"RESET);

}

void alterar_alimento(void){
    char nome_alimento[100], novo_tipo[50], novo_nome_alimento[100];
    float novas_calorias, novas_proteinas, novos_carboidratos, novas_gorduras;
    system("clear||cls");

    printf("\n");
    printf(CYAN"///////////////////////////////////////////////////////////////////////////////\n");
    printf(RED"///                               Alimentos                                 ///\n"RESET);
    printf(CYAN"///                                                                         ///\n");
    printf(RED"///                 = = = = = Alterar Alimento na Dieta = = = = =           ///\n"RESET);
    printf(CYAN"///                                                                         ///\n");
    printf("///                         Informe o nome do Alimento:                     ///\n"RESET);
    scanf("%[^\n]", nome_alimento);
    getchar();
    printf(CYAN"///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf(RED"///                        Novas Informações do ALimento                    ///\n"RESET);
    printf(CYAN"///                                                                         ///\n");
    printf("///                         Nome do Alimento:                               ///\n"RESET);
    scanf("%[^\n]", novo_nome_alimento);
    getchar();
    printf(CYAN"///                         Tipo(Fruta, Carne):                             ///\n"RESET);
    scanf("%[^\n]", novo_tipo);
    getchar();
    printf(CYAN"///                         Calorias(kcal):                                 ///\n"RESET);
    scanf("%f", &novas_calorias);
    getchar();
    printf(CYAN"///                         Proteínas:                                      ///\n"RESET);
    scanf("%f", &novas_proteinas);
    getchar();
    printf(CYAN"///                         Carboidratos:                                   ///\n"RESET);
    scanf("%f", &novos_carboidratos);
    getchar();
    printf(CYAN"///                         Gorduras:                                       ///\n"RESET);
    scanf("%f", &novas_gorduras);
    getchar();
    printf(CYAN"///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf(RED"///                    Alimento alterado com sucesso!                       ///\n"RESET);
    printf(CYAN"///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf("\n");
}

void excluir_alimento(void){
    char nome_alimento[100], confirmacao;
    system("clear||cls");

    printf("\n");
    printf(CYAN"///////////////////////////////////////////////////////////////////////////////\n");
    printf(RED"///                               Alimentos                                 ///\n"RESET);
    printf(CYAN"///                                                                         ///\n");
    printf(RED"///                 = = = = = Excluir Alimento da Dieta = = = = =           ///\n"RESET);
    printf(CYAN"///                                                                         ///\n");
    printf("///                         Informe o nome do Alimento:                     ///\n"RESET);
    scanf("%[^\n]", nome_alimento);
    getchar();
    printf(CYAN"///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf(RED"///                           Excluindo Alimento                            ///\n"RESET);
    printf(CYAN"///                                                                         ///\n");
    printf(RED"///                            Informações do Alimento                      ///\n"RESET);
    printf(CYAN"///                                                                         ///\n");
    printf("///                         Nome do Alimento:                               ///\n");
    printf("///                         Tipo(Fruta, Carne):                             ///\n");
    printf("///                         Calorias(kcal):                                 ///\n");
    printf("///                         Proteínas:                                      ///\n");
    printf("///                         Carboidratos:                                   ///\n");
    printf("///                         Gorduras:                                       ///\n");
    printf(CYAN"///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf("///                      Deseja excluir este alimento?(S/N):                ///\n");
    printf(CYAN"///////////////////////////////////////////////////////////////////////////////\n"RESET);
    scanf("%c", &confirmacao);
    getchar();
    
    if (confirmacao == 'S' || confirmacao == 's') {
        printf(RED"///                    Alimento excluído com sucesso!                      ///\n"RESET);
    } else {
        printf(RED"///                    Operação de exclusão cancelada!                    ///\n"RESET);
    }
}
