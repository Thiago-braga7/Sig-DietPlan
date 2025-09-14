#include <stdio.h>
#include <stdlib.h>
#include "usuarios.h"
#include "util.h"
#include <ctype.h>
#include <string.h>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define CYAN    "\033[36m"


    static char nome[100], cpf[12], telefone[10];
    static int idade;
    static float peso, altura, bf;   








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
    system("clear||cls");
    printf("\n");
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n"RESET);
    printf(CYAN"///             = = = = =   🆄 🆂 🆄 🅰 🆁 🅸 🅾 🆂   = = = = =                ///\n"RESET);
    printf(RED"///                                                                         ///\n");
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
    
    limpar_tela();
    printf("\n");
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf(CYAN"///                          🆄 🆂 🆄 🅰 🆁 🅸 🅾 🆂                           ///\n"RESET);
    printf(RED"///                                                                         ///\n");
    printf("///                 = = = = =  Cadastrar Usuário = = = = =                  ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Nome Completo:                                  ///\n");
    scanf("%[^\n]", nome);
    getchar();
    do {
    printf("/// CPF(Apenas números): ///\n");
    scanf("%s", cpf);
    getchar();

    if (!validar_cpf(cpf)) {
        printf("CPF inválido! Tente novamente.\n" );
    }
}   while (!validar_cpf(cpf));  
    do {
        printf("/// Telefone (Apenas números): ///\n");
        scanf("%s", telefone);
        getchar();

    if (!validar_telefone(telefone)) {
        printf("Telefone inválido! Tente novamente.\n");
    }
}   while (!validar_telefone(telefone));

    do {
        printf("/// Idade: ///\n");
        scanf("%d", &idade);
        getchar();
    if (!validar_idade(idade)) {
        printf("Idade inválida! Tente novamente.\n");
    }
}   while (!validar_idade(idade));

    do {
        printf("/// Peso(Kg): ///\n");
        scanf("%f", &peso);
        getchar();
    if (!validar_peso(peso)) {
        printf("Peso inválido! Tente novamente.\n");
    }
}   while (!validar_peso(peso));
    do {
        printf("/// Altura(m): ///\n");
        scanf("%f", &altura);
        getchar();
    if (!validar_altura(altura)) {
        printf("Altura inválida! Tente novamente.\n");
    }
}   while (!validar_altura(altura));

    do {
        printf("/// Percentual de gordura(Porcentagem): ///\n");
        scanf("%f", &bf);
        getchar();
    if (!validar_bf(bf)) {
        printf("Percentual de gordura invalido! Tente novamente.\n");
    }
}   while (!validar_bf(bf));
    printf("///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf(CYAN"  🆄 🆂 🆄 🅰 🆁 🅸 🅾  🅲 🅰 🅳 🅰 🆂 🆃 🆁 🅰 🅳 🅾  🅲 🅾 🅼  🆂 🆄 🅲 🅴 🆂 🆂 🅾   \n"RESET);
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n"RESET);
    
}

void buscar_usuario(void){
    char cpf_busca[15];
    limpar_tela();
    printf("\n");
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf(CYAN"///                       🆄 🆂 🆄 🅰 🆁 🅸 🅾 🆂                              ///\n"RESET);
    printf(RED"///                                                                         ///\n");
    printf("///                 = = = = =  Buscar Usuário = = = = =                     ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe o CPF(Apenas números):                  ///\n");
    scanf("%s", cpf_busca);
    
    if (strcmp(cpf_busca, cpf) == 0) {
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                        Informações do Usuário                           ///\n");
        printf("///                                                                         ///\n");
        printf("///                         Nome Completo:    %s                              ///\n", nome);
        printf("///                         CPF:          %s                                  ///\n", cpf);
        printf("///                         Telefone:                                       ///\n");
        printf("///                         Idade:                                          ///\n");
        printf("///                         Peso(Kg):                                       ///\n");
        printf("///                         Altura(m):                                      ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n"RESET);}
    pausar();
}
void alterar_usuario(void){
    char cpf[15], novo_cpf[15], novo_nome[100], novo_telefone[15];
    int nova_idade;
    float novo_peso, nova_altura, novo_bf;
    limpar_tela();
    printf("\n");
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf(CYAN"///                     🆄 🆂 🆄 🅰 🆁 🅸 🅾 🆂                                ///\n"RESET);
    printf(RED"///                                                                         ///\n");
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
    printf("///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf(CYAN"   🆄 🆂 🆄 🅰 🆁 🅸 🅾  🅰 🅻 🆃 🅴 🆁 🅰 🅳 🅾  🅲 🅾 🅼  🆂 🆄 🅲 🅴 🆂 🆂 🅾 ❗    \n"RESET);
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf("\n");
   

}

void excluir_usuario(void){
    limpar_tela();
    char cpf[15];
    printf("\n");
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf(CYAN"///                        🆄 🆂 🆄 🅰 🆁 🅸 🅾 🆂                             ///\n"RESET);
    printf(RED"///                                                                         ///\n");
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
    char resposta = confirmar_acao();
    if (resposta == 'S') {
        printf(CYAN"  🆄 🆂 🆄 🅰 🆁 🅸 🅾  🅴 🆇 🅲 🅻 🆄 🅸 🅳 🅾  🅲 🅾 🅼  🆂 🆄 🅲 🅴 🆂 🆂 🅾 ❗   \n"RESET);
    } else {
        printf(CYAN"  🅴 🆇 🅲 🅻 🆄 🆂 🅰 🅾  🅲 🅰 🅽 🅲 🅴 🅻 🅰 🅳 🅰  🅴 🆇 🅲 🅻 🆄 🆂 🅰 🅾  🅲 🅰 🅽 🅲 🅴 🅻 🅰 🅳 🅰   \n"RESET);
    }
    

}


void calcular_imc(void) {
    char opcao;
    float peso, altura, resultado;

    do {
        limpar_tela();
        printf("\n");
        printf(RED"///////////////////////////////////////////////////////////////////////////////////\n"RESET);
        printf(CYAN"///                         🆄 🆂 🆄 🅰 🆁 🅸 🅾 🆂                                ///\n"RESET);
        printf(RED"///                                                                             ///\n");
        printf("///                     = = = = = Calcular IMC = = = = =                        ///\n");
        printf("///                                                                             ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////////\n");
        printf("///                             1. Calcular IMC                                 ///\n");
        printf("///                             0. Voltar                                       ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////////\n");
        
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
                printf("Informe sua altura (m): "RESET);
                scanf("%f", &altura);

                resultado = imc(peso, altura);

                if (resultado < 0) {
                    printf(RED"Altura inválida!\n");
                } else {
                    printf("\nSeu IMC é: %.2f\n"RESET, resultado);
                    classificação_imc(resultado);
                }

                faixa_peso_ideal(altura);

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
    char sexo;

    do {
        limpar_tela();
        printf("\n");
        printf("\n");
        printf(RED"///////////////////////////////////////////////////////////////////////////////////\n"RESET);
        printf(CYAN"///                            🆄 🆂 🆄 🅰 🆁 🅸 🅾 🆂                             ///\n"RESET);
        printf(RED"///                                                                             ///\n");
        printf("///                     = = = = = Classificar Porcentagem de Gordura = = = = =  ///\n");
        printf("///                                                                             ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////////\n");
        printf("///                             1. Calcular por BF                              ///\n");
        printf("///                             0. Voltar                                       ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////////\n");
        printf("Escolha a opção desejada: ");
        scanf(" %c", &opcao);
        getchar();

        switch(opcao) {
            case '1':
                sexo =  ler_sexo();

                printf("Informe seu percentual de gordura corporal (BF %%): ");
                scanf("%f", &bf);

                
                classificar_bf(sexo, bf);

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

    

    

