#include <stdio.h>
#include <stdlib.h>
#include "dietas.h"
#include "util.h"




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
    printf(CYAN"///                                Dietas                                   ///\n"RESET);
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
    char nome_dieta[50];
    limpar_tela();

    printf("\n");
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                Dietas                                   ///\n");
    printf("///                                                                         ///\n");
    printf("///                  = = = = =  Buscar Dieta  = = = = =                     ///\n");
    printf("///                                                                         ///\n");
    printf("///                        Informe o nome da Dieta:                         ///\n");
    scanf("%s", nome_dieta);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                        Informações da Dieta                             ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Nome da Dieta:                                  ///\n");
    printf("///                         Total de Calorias por dia:                      ///\n");
    printf("///                         Refeições:                                      ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n"RESET);

}
void alterar_dieta(void){
    char nome_dieta[50];
    char novo_cpf[15]; 
    char novo_nome_dieta[50];              
    char novas_refeicoes[200];                    
    int novas_calorias;   
    limpar_tela();
    printf("\n");
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                Dietas                                   ///\n");
    printf("///                                                                         ///\n");
    printf("///                  = = = = =  Alterar Dieta  = = = = =                    ///\n");
    printf("///                                                                         ///\n");
    printf("///                        Informe o nome da Dieta:                         ///\n");
    scanf("%s", nome_dieta);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                        Novos Dados da Dieta                             ///\n");
    printf("///                                                                         ///\n");
    printf("///                         CPF do Usuário:                                 ///\n");
    scanf("%s", novo_cpf);
    getchar();
    printf("///                         Nome da Dieta:                                  ///\n");
    scanf("%s", novo_nome_dieta);
    getchar();
    printf("///                         Total de Calorias por dia:                      ///\n");
    scanf("%d", &novas_calorias);
    getchar();
    printf("///                         Refeições (breve descrição):                    ///\n");
    scanf("%[^\n]", novas_refeicoes);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                    Dieta Alterada com sucesso!                          ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n"RESET);
}

void excluir_dieta(void){
    char nome_dieta[50];
    limpar_tela();
    printf("\n");
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                               Dietas                                    ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = = Excluir Dieta = = = = =                       ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe o nome da Dieta:                        ///\n");
    scanf("%s", nome_dieta);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                           Excluindo Dieta                               ///\n");
    printf("///                                                                         ///\n");
    printf("///                           Dados da Dieta                                ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Nome da Dieta:                                  ///\n");
    printf("///                         Total de Calorias por dia:                      ///\n");
    printf("///                         Refeições:                                      ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    char resposta = confirmar_acao();
    if (resposta == 'S') {
        printf(RED"///                    Dieta excluída com sucesso!                        ///\n");
    } else {
        printf(RED"///                    Operação de exclusão cancelada!                    ///\n");
    }
    
}
