#include <stdio.h>
#include <stdlib.h>
#include "refeicoes.h"



void moduloRefeicoes(void) {
    char opcao;
    do {
        opcao = refeicoes();
        switch(opcao) {
            case '1': cadastrar_refeicao(); break;
            case '2': buscar_refeicao(); break;
            case '3': alterar_refeicao(); break;
            case '4': excluir_refeicao(); break;
            case '5': refeicoes_usuario(); break;

            
        }
    } while (opcao != '0');  
}

char refeicoes(void){
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
    return opcao;
}
void cadastrar_refeicao(void){
    char nome_refeição[100], tipo[50];
    float calorias, proteinas, carboidratos, gorduras;
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                Refeições                                ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = =  Cadastrar Refeição = = = = =                 ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Nome da Refeição:                               ///\n");
    scanf("%[^\n]", nome_refeição);
    getchar();
    printf("///                         Tipo (Café, Almoço, Jantar, Lanche):            ///\n");
    scanf("%[^\n]", tipo);
    getchar();
    printf("///                         Calorias (kcal):                                ///\n");
    scanf("%f", &calorias);
    getchar();
    printf("///                         Proteínas (g):                                  ///\n");
    scanf("%f", &proteinas);
    getchar();
    printf("///                         Carboidratos (g):                               ///\n");
    scanf("%f", &carboidratos);
    getchar();
    printf("///                         Gorduras (g):                                   ///\n");
    scanf("%f", &gorduras);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                    Refeição cadastrada com sucesso!                     ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    
}
void buscar_refeicao(void){
    char nome_refeicao[100];
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                Refeições                                ///\n");
    printf("///                                                                         ///\n");
    printf("///                   = = = = =  Buscar Refeição = = = = =                  ///\n");
    printf("///                                                                         ///\n");
    printf("///                        Informe o nome da Refeição:                      ///\n");
    scanf("%[^\n]", nome_refeicao);
    getchar(); 
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                        Informações da Refeição                          ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Nome:                                           ///\n");
    printf("///                         Tipo:                                           ///\n");
    printf("///                         Calorias:                                       ///\n");
    printf("///                         Proteínas:                                      ///\n");
    printf("///                         Carboidratos:                                   ///\n");
    printf("///                         Gorduras:                                       ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");

      
}
void alterar_refeicao(void){
    char nome_refeicao[100], novo_nomeRefeicao[100], novoTipo[50];
    float novasCalorias, novasProteinas, novosCarboidratos, novasGorduras;
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                Refeições                                ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = =  Alterar Refeição = = = = =                   ///\n");
    printf("///                                                                         ///\n");
    printf("///                  Informe o nome da Refeição a alterar:                  ///\n");
    scanf("%[^\n]", nome_refeicao);
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();
    printf("///                                                                         ///\n");
    printf("///                              Novos dados:                               ///\n");
    printf("///                                                                         ///\n");
    printf("///                      Nome da Refeição:                                  ///\n");
    scanf("%[^\n]", novo_nomeRefeicao);
    getchar();
    printf("///                      Tipo (Café, Almoço, Jantar, Lanche):               ///\n");
    scanf("%[^\n]", novoTipo);
    getchar();
    printf("///                      Calorias (kcal):                                   ///\n");
    scanf("%f", &novasCalorias);
    getchar();
    printf("///                      Proteínas (g):                                     ///\n");
    scanf("%f", &novasProteinas);
    getchar();
    printf("///                      Carboidratos (g):                                  ///\n");
    scanf("%f", &novosCarboidratos);
    getchar();
    printf("///                      Gorduras (g):                                      ///\n");
    scanf("%f", &novasGorduras);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                    Refeição alterada com sucesso!                       ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
   

}
void excluir_refeicao(void){
    char nome_refeicao[100];
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                Refeições                                ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = =  Excluir Refeição = = = = =                   ///\n");
    printf("///                                                                         ///\n");
    printf("///                  Informe o nome da Refeição a excluir:                  ///\n");
    scanf("%[^\n]", nome_refeicao);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                         Informação da Refeição                          ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Nome:                                           ///\n");
    printf("///                         Tipo:                                           ///\n");
    printf("///                         Calorias:                                       ///\n");
    printf("///                         Proteínas:                                      ///\n");
    printf("///                         Carboidratos:                                   ///\n");
    printf("///                         Gorduras:                                       ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                      Deseja excluir esta refeição?(S/N):                ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
   
     
}
void refeicoes_usuario(void){
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                Refeições                                ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = =  Refeições Usuário = = = = =                  ///\n");
    printf("///                                                                         ///\n");
    printf("///                        Informe o nome do Usuário:                       ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                           Refeições do Usuário                          ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
