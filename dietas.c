#include <stdio.h>
#include <stdlib.h>
#include "dietas.h"
#include "util.h"
#include <string.h>



#define RESET   "\033[0m"
#define RED     "\033[31m"
#define CYAN    "\033[36m"



static char cpf[15]; 
static char nome_dieta[50];              
static char refeicoes[200];                    
static int calorias;   













void modulo_dietas(void) {
    char opcao;
    do {
        limpar_tela();
        opcao = dietas();
        switch(opcao) {
            case '1': cadastrar_dieta(); break;
            case '2': buscar_dieta(); break;
            case '3': alterar_dieta(); break;
            case '4': excluir_dieta(); break;
            
        }
    } while (opcao != '0');  
}



char dietas(void){
    char opcao;
    limpar_tela();

    printf("\n");
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n"RESET);
    printf(CYAN"///                = = = = = 🅳 🅸 🅴 🆃 🅰 🆂  = = = = =                     ///\n"RESET);
    printf(RED"///                                                                         ///\n");
    printf("///                    1. Cadastrar Dieta                                   ///\n");
    printf("///                    2. Buscar Dieta                                      ///\n");
    printf("///                    3. Alterar Dieta                                     ///\n");
    printf("///                    4. Excluir Dieta                                     ///\n");
    printf("///                    0. Voltar ao Menu Principal                          ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                      Escolha a opção desejada: ");
    scanf("%c", &opcao);
    getchar();
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf("\n");
    pausar();
    return opcao;
}

void cadastrar_dieta(void){
    
    limpar_tela();
    
    printf("\n");
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf(CYAN"///                             🅳 🅸 🅴 🆃 🅰 🆂                            ///\n"RESET);
    printf(RED"///                                                                         ///\n");
    printf("///                  = = = = =  Cadastrar Dieta  = = = = =                  ///\n");
    printf("///                                                                         ///\n");
    printf("///                         CPF do Usuário:                                 ///\n");
    scanf("%s", cpf);
    getchar();
    printf("///                         Nome da Dieta:                                  ///\n");
    scanf("%s", nome_dieta);
    getchar();
    printf("///                         Total de Calorias por dia:                      ///\n");
    scanf("%d", &calorias);
    getchar();
    printf("///                         Refeições (breve descrição):                    ///\n");
    scanf("%[^\n]", refeicoes);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf(CYAN"  🅳 🅸 🅴 🆃 🅰  🅲 🅰 🅳 🅰 🆂 🆃 🆁 🅰 🅳 🅰  🅲 🅾 🅼  🆂 🆄 🅲 🅴 🆂 🆂 🅾 ❗  \n"RESET);
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n"RESET);
    pausar();
}
void buscar_dieta(void){
    char dieta_busca[15];
    int resp;
    int continuar = 1;
    limpar_tela();

    printf("\n");
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                             🅳 🅸 🅴 🆃 🅰 🆂                                ///\n");
    printf("///                                                                         ///\n");
    printf("///                  = = = = =  Buscar Dieta  = = = = =                     ///\n");
    printf("///                                                                         ///\n"RESET);
    while (continuar) {
        printf(RED"\nDigite o nome da dieta: "RESET);
        scanf(" %[^\n]", dieta_busca);

        if (strcmp(dieta_busca, nome_dieta) == 0) {
          
            printf(RED"/////////////////////////////////////////////////////////////////////////////////\n"RESET);
            printf(CYAN"///                          Informações do Dieta                            ///\n"RESET);
            printf(RED"/////////////////////////////////////////////////////////////////////////////////\n");

            printf("/// %-15s : %-45s ///\n", "Nome da Dieta", nome_dieta);
            printf("/// %-15s : %-45.2d ///\n", "Calorias por dia", calorias);
            printf("/// %-200s : %-45s ///\n", "Refeições", refeicoes);
            
            printf("/////////////////////////////////////////////////////////////////////////////////\n");

            pausar();
            continuar = 0; 
        } else {
            
            printf("\nDieta não encontrada! Deseja tentar novamente?\n");
            printf("Digite 1 para tentar novamente ou 10 para sair: "RESET);
            scanf("%d", &resp);
            if (resp == 10) {
                printf(RED"\nSaindo da busca...\n"RESET);
                continuar = 0; 
            }
            
        }
    }
}


void alterar_dieta(void){
    char dieta_busca[15];
    int resp, novas_calorias;
    int continuar = 1;
    char novo_cpf[15];          
    char novo_nome_dieta[50];   
    char novas_refeicoes[200];  



    limpar_tela();
    printf("\n");
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf(CYAN"///                             🅳 🅸 🅴 🆃 🅰 🆂                                ///\n"RESET);
    printf(RED"///                                                                         ///\n");
    printf("///                  = = = = =  Alterar Dieta  = = = = =                    ///\n");
    printf("///                                                                         ///\n"RESET);
    while (continuar) {
        printf(RED"\nDigite o nome da dieta: "RESET);
        scanf(" %[^\n]", dieta_busca);

        if (strcmp(dieta_busca, nome_dieta) == 0) {
            printf(RED"///////////////////////////////////////////////////////////////////////////////\n"RESET);
            printf(CYAN"///                        Novos Dados da Dieta                             ///\n"RESET);
            printf(RED"///                                                                         ///\n");
            printf("///                         CPF do Usuário:                                 ///\n");
            scanf(" %14s", novo_cpf);
            getchar();
            printf("///                         Nome da Dieta:                                  ///\n");
            scanf(" %49[^\n]", novo_nome_dieta);
            getchar();
            printf("///                         Total de Calorias por dia:                      ///\n");
            scanf("%d", &novas_calorias);
            getchar();
            printf("///                         Refeições (breve descrição):                    ///\n"RESET);
            scanf(" %199[^\n]", novas_refeicoes );
            getchar();

            
            strcpy(cpf, novo_cpf);
            strcpy(nome_dieta, novo_nome_dieta);
            calorias = novas_calorias;
            strcpy(refeicoes, novas_refeicoes);

            printf(RED"///////////////////////////////////////////////////////////////////////////////\n"RESET);
            printf(CYAN"      🅳 🅸 🅴 🆃 🅰  🅰 🅻 🆃 🅴 🆁 🅰 🅳 🅰  🅲 🅾 🅼  🆂 🆄 🅲 🅴 🆂 🆂 🅾 ❗      \n"RESET);
            printf(RED"///////////////////////////////////////////////////////////////////////////////\n"RESET);
            pausar();
            continuar = 0;
        }  else {
            
                printf(RED"\nDieta não encontrada! Deseja tentar novamente?\n");
                printf("Digite 1 para tentar novamente ou 10 para sair: "RESET);
                scanf("%d", &resp);
                if (resp == 10) {
                    printf(RED"\nSaindo da busca...\n"RESET);
                    continuar = 0; 
                }
            }
    }
}
        
    

void excluir_dieta(void){
    char dieta_busca[15];
    int resp;
    int continuar = 1;
    limpar_tela();
    printf("\n");
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf(CYAN"///                             🅳 🅸 🅴 🆃 🅰 🆂                                ///\n"RESET);
    printf(RED"///                                                                         ///\n");
    printf("///                  = = = = =  Excluir Dieta  = = = = =                    ///\n");
    printf("///                                                                         ///\n"RESET);
    while (continuar) {
        printf(RED"\nDigite o nome da dieta: "RESET);
        scanf(" %[^\n]", dieta_busca);

        if (strcmp(dieta_busca, nome_dieta) == 0) {

            printf(RED"///////////////////////////////////////////////////////////////////////////////\n"RESET);
            printf(CYAN"                   🅴 🆇 🅲 🅻 🆄 🅸 🅽 🅳 🅾  🅳 🅸 🅴 🆃 🅰                      \n"RESET);
            printf(RED"///////////////////////////////////////////////////////////////////////////////\n"RESET);
            pausar();
            continuar = 0;
        }  else {
            
                printf(RED"\nDieta não encontrada! Deseja tentar novamente?\n");
                printf("Digite 1 para tentar novamente ou 10 para sair: "RESET);
                scanf("%d", &resp);
                if (resp == 10) {
                    printf(RED"\nSaindo da busca...\n"RESET);
                    continuar = 0; 
                }
            }
    }
    pausar();
    char resposta;

    do {
        printf(RED"Deseja confirmar a ação? (S/N): "RESET);
        scanf(" %c", &resposta);

        resposta = confirmar_acao(resposta); 

        if (resposta == 0) {  
            printf(RED"Opção inválida! Digite apenas S ou N.\n"RESET);
        }
    } while (resposta == 0); 

    if (resposta == 'S') {
        printf(RED"/// Dieta excluída com sucesso! ///\n");
    } else {
        printf(RED"/// Operação de exclusão cancelada! ///\n");
}
    // if (resposta == 'S') {
    //     printf(RED"///                    Dieta excluída com sucesso!                        ///\n");
    //     cpf[0] = '\0';
    //     nome_dieta[0] = '\0';
    //     calorias = 0;
    //     refeicoes[0] = '\0';
    // } else {
    //     printf(RED"///                    Operação de exclusão cancelada!                    ///\n");
    // }
    pausar();

}
































































    