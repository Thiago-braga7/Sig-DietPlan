#include <stdio.h>
#include <stdlib.h>
#include "alimentos.h"

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
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                    = = = = =   Alimentos   = = = = =                    ///\n");
    printf("///                                                                         ///\n");
    printf("///                    1. Cadastrar Alimento na Dieta                       ///\n");
    printf("///                    2. Buscar Alimento na Dieta                          ///\n");
    printf("///                    3. Alterar Alimento da Dieta                         ///\n");
    printf("///                    4. Excluir Alimento da Dieta                         ///\n");
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

void cadastrar_alimento(void){
    char nome_alimento[100], tipo[50];
    float calorias, proteinas, carboidratos, gorduras;
    system("clear||cls");

    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                               Alimentos                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = =  Cadastrar Alimento na Dieta  = = = = =       ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Nome do Alimento:                               ///\n");
    scanf("%[^\n]", nome_alimento);
    getchar();
    printf("///                         Tipo(Fruta, Carne):                             ///\n");
    scanf("%[^\n]", tipo);
    getchar();
    printf("///                         Calorias(kcal):                                 ///\n");
    scanf("%f", &calorias);
    getchar();
    printf("///                         Proteínas:                                      ///\n");
    scanf("%f", &proteinas);
    getchar();
    printf("///                         Carboidratos:                                   ///\n");
    scanf("%f", &carboidratos);
    getchar();
    printf("///                         Gorduras:                                       ///\n");
    scanf("%f", &gorduras);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                    Alimento cadastrado com sucesso!                     ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");

}
void buscar_alimento(void){
    char nome_alimento[100];
    system("clear||cls");

    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                               Alimentos                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = =  Buscar Alimento na Dieta= = = = =            ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe o nome do Alimento:                     ///\n");
    scanf("%[^\n]", nome_alimento);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                        Informações do Alimento                          ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Nome do Alimento:                               ///\n");
    printf("///                         Tipo(Fruta, Carne):                             ///\n");
    printf("///                         Calorias(kcal):                                 ///\n");
    printf("///                         Proteínas:                                      ///\n");
    printf("///                         Carboidratos:                                   ///\n");
    printf("///                         Gorduras:                                       ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");

}
void alterar_alimento(void){
    char nome_alimento[100], novo_tipo[50], novo_nome_alimento[100];
    float novas_calorias, novas_proteinas, novos_carboidratos, novas_gorduras;
    system("clear||cls");

    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                               Alimentos                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = = Alterar Alimento na Dieta = = = = =           ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe o nome do Alimento:                     ///\n");
    scanf("%[^\n]", nome_alimento);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                        Novas Informações do ALimento                    ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Nome do Alimento:                               ///\n");
    scanf("%[^\n]", novo_nome_alimento);
    getchar();
    printf("///                         Tipo(Fruta, Carne):                             ///\n");
    scanf("%[^\n]", novo_tipo);
    getchar();
    printf("///                         Calorias(kcal):                                 ///\n");
    scanf("%f", &novas_calorias);
    getchar();
    printf("///                         Proteínas:                                      ///\n");
    scanf("%f", &novas_proteinas);
    getchar();
    printf("///                         Carboidratos:                                   ///\n");
    scanf("%f", &novos_carboidratos);
    getchar();
    printf("///                         Gorduras:                                       ///\n");
    scanf("%f", &novas_gorduras);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                    Alimento alterado com sucesso!                       ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
   

}
void excluir_alimento(void){
    char nome_alimento[100], confirmacao;
    system("clear||cls");

    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                               Alimentos                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = = Excluir Alimento da Dieta = = = = =           ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe o nome do Alimento:                     ///\n");
    scanf("%[^\n]", nome_alimento);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                           Excluindo Alimento                            ///\n");
    printf("///                                                                         ///\n");
    printf("///                            Informações do Alimento                      ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Nome do Alimento:                               ///\n");
    printf("///                         Tipo(Fruta, Carne):                             ///\n");
    printf("///                         Calorias(kcal):                                 ///\n");
    printf("///                         Proteínas:                                      ///\n");
    printf("///                         Carboidratos:                                   ///\n");
    printf("///                         Gorduras:                                       ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                      Deseja excluir este alimento?(S/N):                ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    scanf("%c", &confirmacao);
    getchar();
    
    if (confirmacao == 'S' || confirmacao == 's') {
        printf("///                    Alimento excluído com sucesso!                      ///\n");
    } else {
        printf("///                    Operação de exclusão cancelada!                    ///\n");

}
}