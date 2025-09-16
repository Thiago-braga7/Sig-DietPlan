#include <stdio.h>
#include <stdlib.h>
#include "usuarios.h"
#include "util.h"
#include <ctype.h>


#define RESET   "\033[0m"
#define RED     "\033[31m"
#define CYAN    "\033[36m"


void modulo_usuarios(void) {
    char opcao;
    do {
        usuarios();
        printf("Escolha uma opção: ");
        scanf(" %c", &opcao);
        getchar();


        switch(opcao) {
            case '1': cadastrar_usuario(); break;
            case '2': buscar_usuario(); break;
            case '3': alterar_usuario(); break;
            case '4': excluir_usuario(); break;
            case '5': calcular_imc(); break;
            case '6': calcular_bf(); break;
            
        }
    } while (opcao != '0');  
    
}






void usuarios(void){
    limpar_tela();
    printf("\n");
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                    = = = = =   Usuários  = = = = =                      ///\n");
    printf("///                                                                         ///\n");
    printf("///                    1. Cadastrar Usuário                                 ///\n");
    printf("///                    2. Buscar Usuário                                    ///\n");
    printf("///                    3. Alterar Dados do Usuário                          ///\n");
    printf("///                    4. Excluir Usuário                                   ///\n");
    printf("///                    5. Calcular IMC                                      ///\n");
    printf("///                    6. Calcular BF                                       ///\n");
    printf("///                    0. Voltar ao Menu Principal                          ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n"RESET);
}

void cadastrar_usuario(void){
    char nome[100], cpf[12], telefone[10];
    int idade;
    float peso, altura, bf;   
    limpar_tela();
    printf("\n");
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                Usuários                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = =  Cadastrar Usuário = = = = =                  ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n"RESET);
    
    printf(RED"///                         Nome:                                           ///\n");
    scanf("%s", nome); 
    getchar();

    printf("///                         CPF (Apenas números):                           ///\n");
    scanf("%s", cpf); 
    getchar();

    printf("///                         Telefone (Apenas números):                      ///\n");
    scanf("%s", telefone); 
    getchar();

    printf("///                         Idade:                                          ///\n");
    scanf("%d", &idade); 
    getchar();

    printf("///                         Peso (Kg):                                      ///\n");
    scanf("%f", &peso); 
    getchar();

    printf("///                         Altura (m):                                     ///\n");
    scanf("%f", &altura); 
    getchar();

    printf("///                         Percentual de Gordura (%%):                     ///\n"RESET);
    scanf("%f", &bf); 
    getchar();

    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("                    Usuário Cadastrado com Sucesso!                         \n");
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n"RESET);
    pausar();
}

void buscar_usuario(void){
    char cpf[15];
    limpar_tela();
    printf("\n");
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                               Usuários                                  ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = =  Buscar Usuário = = = = =                     ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe o CPF(Apenas números):                  ///\n");
    scanf("%s", cpf);
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                        Informações do Usuário                           ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Nome Completo:                                  ///\n");
    printf("///                         CPF:                                            ///\n");
    printf("///                         Telefone:                                       ///\n");
    printf("///                         Idade:                                          ///\n");
    printf("///                         Peso(Kg):                                       ///\n");
    printf("///                         Altura(m):                                      ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n"RESET);
    pausar();
}

 
void alterar_usuario(void){
    char cpf[15], novo_cpf[15], novo_nome[100], novo_telefone[15];
    int nova_idade;
    float novo_peso, nova_altura, novo_bf;
    limpar_tela();
    printf("\n");
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                               Usuários                                  ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = = Alterar Dados do Usuário = = = = =            ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe o CPF(Apenas números):                  ///\n");
    scanf("%s", cpf);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                        Novos Dados do Usuário                           ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Nome Completo:                                  ///\n");
    scanf("%[^\n]", novo_nome);
    getchar();
    printf("///                         CPF:                                            ///\n");
    scanf("%s", novo_cpf);
    getchar();
    printf("///                         Telefone:                                       ///\n");
    scanf("%s", novo_telefone);
    getchar();
    printf("///                         Idade:                                          ///\n");
    scanf("%d", &nova_idade);
    getchar();
    printf("///                         Peso(Kg):                                       ///\n");
    scanf("%f", &novo_peso);
    getchar();
    printf("///                         Altura(m):                                      ///\n");
    scanf("%f", &nova_altura);
    getchar();
    printf("///                         Percentual de gordura(Porcentagem):                                      ///\n");
    scanf("%f", &novo_bf);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                    Usuário alterado com sucesso!                        ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf("\n");
    pausar();

}

        
   
void excluir_usuario(void){
    limpar_tela();
    char cpf[15];
    printf("\n");
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                Usuários                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = = Excluir Usuário = = = = =                     ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe o CPF(Apenas números):                  ///\n");
    scanf("%s", cpf); 
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                           Excluindo Usuário                             ///\n");
    printf("///                                                                         ///\n");
    printf("///                            Dados do Usuário                             ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Nome Completo:                                  ///\n");
    printf("///                         CPF:                                            ///\n");
    printf("///                         Telefone:                                       ///\n");
    printf("///                         Idade:                                          ///\n");
    printf("///                         Peso(Kg):                                       ///\n");
    printf("///                         Altura(m):                                      ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n"RESET);
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
            printf(RED"Usuário Excluído com Sucesso!    \n"RESET);
    }   else {
            printf(RED"Operação de Exclusão Cancelada !  \n"RESET);
     }
    pausar();

}


void calcular_imc(void) {
    char opcao;
    float peso, altura, resultado;

    do {
        limpar_tela();
        printf("\n");
        printf(RED"///////////////////////////////////////////////////////////////////////////////////\n");
        printf("///                                Usuários                                     ///\n");
        printf("///                                                                             ///\n");
        printf("///                     = = = = = Calcular IMC = = = = =                        ///\n");
        printf("///                                                                             ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////////\n");
        printf("///                             1. Calcular IMC                                 ///\n");
        printf("///                             0. Voltar                                       ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////////\n"RESET);
        
        do {
            printf("Escolha a opção desejada (0 ou 1): ");
            scanf(" %c", &opcao);
            getchar();

            if (opcao != '0' && opcao != '1') {
                printf("Opção inválida! Digite apenas 0 ou 1.\n"RESET);
                pausar();
                limpar_tela();
            }
        } while (opcao != '0' && opcao != '1'); 
        

        switch (opcao) {
            case '1': {
                printf(RED"Informe seu peso (kg): ");
                scanf("%f", &peso);
                printf("Informe sua altura (m): ");
                scanf("%f", &altura );

                resultado = imc(peso, altura);

                if (resultado <= 0) {
                    printf(RED"Resultado inválido!\n");
                } else {
                    printf(RED"\nSeu IMC é: %.2f\n"RESET, resultado);
                    classificação_imc(resultado);

                    float min = peso_ideal_min(altura);
                    float max = peso_ideal_max(altura);

                    if (min > 0 && max > 0) {
                        printf(RED"Peso ideal para sua altura: entre %.1fkg e %.1fkg\n"RESET, min, max);
                    } else {
                        printf(RED"Resultado inválido!\n"RESET);
                    }
                }

                pausar();
                break;
            }

            case '0': {
                printf(RED"Voltando ao menu...\n"RESET);
                break;
            }
        }

    } while (opcao != '0'); 
}
    
void calcular_bf(void) {
    char opcao;
    float bf;
    char genero;

    do {
        limpar_tela();
        printf("\n");
        printf("\n");
        printf(RED"///////////////////////////////////////////////////////////////////////////////////\n");
        printf("///                                Usuários                                     ///\n");
        printf("///                                                                             ///\n");
        printf("///                     = = = = = Classificar Porcentagem de Gordura = = = = =  ///\n");
        printf("///                                                                             ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////////\n");
        printf("///                             1. Calcular por BF                              ///\n");
        printf("///                             0. Voltar                                       ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////////\n"RESET);
        printf("Escolha a opção desejada: ");
        scanf(" %c", &opcao);
        getchar();

        switch(opcao) {
            case '1':
                
                do {
                    printf(RED"Informe seu gênero (M = Masculino, F = Feminino, N = Prefiro não informar): "RESET);
                    scanf(" %c", &genero);

                    genero = ler_genero(genero); 

                    if (genero == 0) {
                        printf(CYAN"Opção inválida! Digite apenas M, F ou N.\n"RESET);
                    }
                } while (genero == 0);

                printf(RED"Informe seu percentual de gordura corporal (BF %%): "RESET);
                scanf("%f", &bf);

                
                classificar_bf(genero, bf);

                pausar();
                break;

            case '0':
                printf("Voltando ao menu...\n"RESET);
                break;

            default:
                printf("Opção inválida!\n"RESET);
                pausar();
                break;
        }

    } while(opcao != '0');
}

    

    

