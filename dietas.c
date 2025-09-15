#include <stdio.h>
#include <stdlib.h>
#include "dietas.h"
#include "util.h"
#include <string.h>



#define RESET   "\033[0m"
#define RED     "\033[31m"
#define CYAN    "\033[36m"

















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
    static char cpf[15]; 
    char nome_dieta[50];              
    char refeicoes[200];                    
    int calorias;   
    
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
    
    static char nome_dieta[50];              

    limpar_tela();

    printf("\n");
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                             🅳 🅸 🅴 🆃 🅰 🆂                                ///\n");
    printf("///                                                                         ///\n");
    printf("///                  = = = = =  Buscar Dieta  = = = = =                     ///\n");
    printf("///                                                                         ///\n"RESET);
    
        printf(RED"\nDigite o nome da dieta: "RESET);
        scanf(" %[^\n]", nome_dieta);

       
          
        printf(RED"/////////////////////////////////////////////////////////////////////////////////\n"RESET);
        printf(CYAN"///                          Informações do Dieta                            ///\n"RESET);
        printf(RED"/////////////////////////////////////////////////////////////////////////////////\n");

        printf("/// %-15s : %-45s ///\n", "Nome da Dieta", "valor");
        printf("/// %-15s : %-45s ///\n", "Calorias por dia", "valor");
        printf("/// %-200s : %-45s ///\n", "Refeições", "valor");
        
        printf("/////////////////////////////////////////////////////////////////////////////////\n");

        pausar();
        
            
    }
  


void alterar_dieta(void){
    
    char nome_dieta[50];              
    


    limpar_tela();
    printf("\n");
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf(CYAN"///                             🅳 🅸 🅴 🆃 🅰 🆂                                ///\n"RESET);
    printf(RED"///                                                                         ///\n");
    printf("///                  = = = = =  Alterar Dieta  = = = = =                    ///\n");
    printf("///                                                                         ///\n"RESET);
    
        printf(RED"\nDigite o nome da dieta: "RESET);
        scanf(" %[^\n]", nome_dieta);

        
            printf(RED"///////////////////////////////////////////////////////////////////////////////\n"RESET);
            printf(CYAN"///                        Novos Dados da Dieta                             ///\n"RESET);
            printf(RED"///                                                                         ///\n");
            printf("///                         CPF do Usuário:                                 ///\n");
            
            printf("///                         Nome da Dieta:                                  ///\n");
            
            printf("///                         Total de Calorias por dia:                      ///\n");
            
            printf("///                         Refeições (breve descrição):                    ///\n"RESET);
            printf(RED"///////////////////////////////////////////////////////////////////////////////\n"RESET);
            printf(CYAN"      🅳 🅸 🅴 🆃 🅰  🅰 🅻 🆃 🅴 🆁 🅰 🅳 🅰  🅲 🅾 🅼  🆂 🆄 🅲 🅴 🆂 🆂 🅾 ❗      \n"RESET);
            printf(RED"///////////////////////////////////////////////////////////////////////////////\n"RESET);
            pausar();
}
        
    

void excluir_dieta(void){
    
    char nome_dieta[50];              
 
    limpar_tela();
    printf("\n");
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf(CYAN"///                             🅳 🅸 🅴 🆃 🅰 🆂                                ///\n"RESET);
    printf(RED"///                                                                         ///\n");
    printf("///                  = = = = =  Excluir Dieta  = = = = =                    ///\n");
    printf("///                                                                         ///\n"RESET);
    
        printf(RED"\nDigite o nome da dieta: "RESET);
        scanf(" %[^\n]", nome_dieta);

        
            printf(RED"///////////////////////////////////////////////////////////////////////////////\n"RESET);
            printf(CYAN"                   🅴 🆇 🅲 🅻 🆄 🅸 🅽 🅳 🅾  🅳 🅸 🅴 🆃 🅰                      \n"RESET);
            printf(RED"///////////////////////////////////////////////////////////////////////////////\n"RESET);
            pausar();
            
    
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

    pausar();

}
































































    