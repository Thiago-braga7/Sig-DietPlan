#include <stdio.h>
#include <stdlib.h>
#include "usuarios.h"
#include "util.h"
#include <ctype.h>
#include <string.h>

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
    char nome[100], cpf[12], telefone[10];
    int idade;
    float peso, altura, bf;   
    limpar_tela();
    printf("\n");
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf(CYAN"///                          🆄 🆂 🆄 🅰 🆁 🅸 🅾 🆂                           ///\n"RESET);
    printf(RED"///                                                                         ///\n");
    printf("///                 = = = = =  Cadastrar Usuário = = = = =                  ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Nome Completo:                                  ///\n");
    scanf("%s[^\n]", nome);
    getchar();
    do {
    printf("/// CPF(Apenas números): ///\n");
    scanf(" %[^\n]", cpf);
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

    char cpf[12];
    
    limpar_tela();
    printf("\n");
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf(CYAN"///                       🆄 🆂 🆄 🅰 🆁 🅸 🅾 🆂                              ///\n"RESET);
    printf(RED"///                                                                         ///\n");
    printf("///                 = = = = =  Buscar Usuário = = = = =                     ///\n");
    printf("///                                                                         ///\n");

    printf("\nDigite o CPF do usuário: ");
    scanf(" %[^\n]", cpf);

        
    printf(RED"/////////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf(CYAN"///                          Informações do Usuário                           ///\n"RESET);
    printf(RED"/////////////////////////////////////////////////////////////////////////////////\n");

    printf("/// %-15s | %-45s ///\n", "Nome", "valor");
    printf("/// %-15s | %-45s ///\n", "CPF", "valor");
    printf("/// %-15s | %-45s ///\n", "Telefone", "valor");
    printf("/// %-15s | %-45s ///\n", "Idade", "valor");
    printf("/// %-15s | %-45s ///\n", "Peso (Kg)", "valor");
    printf("/// %-15s | %-45s ///\n", "Altura (m)", "valor");
    printf("/// %-15s | %-45s ///\n", "Body Fat %%", "valor"); 

    printf("/////////////////////////////////////////////////////////////////////////////////\n"RESET);

    pausar();
}
 
void alterar_usuario(void){
    char cpf[12];
    
    
    
    limpar_tela();
    printf("\n");
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf(CYAN"///                     🆄 🆂 🆄 🅰 🆁 🅸 🅾 🆂                                ///\n"RESET);
    printf(RED"///                                                                         ///\n");
    printf("///                 = = = = = Alterar Dados do Usuário = = = = =            ///\n");
    printf("///                                                                         ///\n");
    


    printf("\nDigite o CPF do usuário: ");
    scanf(" %[^\n]", cpf);

        
            
            printf("///////////////////////////////////////////////////////////////////////////////\n");
            printf("///                        Novos Dados do Usuário                           ///\n");
            printf("///                                                                         ///\n");

            printf("///                         Nome Completo:                                  ///\n");
            

            printf("///                         CPF:                                            ///\n");
            
            printf("///                         Telefone:                                       ///\n");
            

            printf("///                         Idade:                                          ///\n");
            

            printf("///                         Peso(Kg):                                       ///\n");
           

            printf("///                         Altura(m):                                      ///\n");
            

            printf("///                         Percentual de gordura(%%):                       ///\n");
            

            printf("///////////////////////////////////////////////////////////////////////////////\n"RESET);
            printf(CYAN"   🆄 🆂 🆄 🅰 🆁 🅸 🅾  🅰 🅻 🆃 🅴 🆁 🅰 🅳 🅾  🅲 🅾 🅼  🆂 🆄 🅲 🅴 🆂 🆂 🅾 ❗    \n"RESET);
            printf(RED"///////////////////////////////////////////////////////////////////////////////\n"RESET);
            pausar();
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
    scanf(" %[^\n]", cpf);
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
            printf(CYAN"  🆄 🆂 🆄 🅰 🆁 🅸 🅾  🅴 🆇 🅲 🅻 🆄 🅸 🅳 🅾  🅲 🅾 🅼  🆂 🆄 🅲 🅴 🆂 🆂 🅾 ❗   \n"RESET);
    }   else {
            printf(CYAN"  🅴 🆇 🅲 🅻 🆄 🆂 🅰 🅾  🅲 🅰 🅽 🅲 🅴 🅻 🅰 🅳 🅰  🅴 🆇 🅲 🅻 🆄 🆂 🅰 🅾  🅲 🅰 🅽 🅲 🅴 🅻 🅰 🅳 🅰   \n"RESET);
     }
    pausar();

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

                if (resultado <= 0) {
                    printf(RED"Altura inválida!\n");
                } else {
                    printf("\nSeu IMC é: %.2f\n"RESET, resultado);
                    classificação_imc(resultado);

                    float min = peso_ideal_min(altura);
                    float max = peso_ideal_max(altura);

                    if (min > 0 && max > 0) {
                        printf(RED"Peso ideal para sua altura: entre %.1fkg e %.1fkg\n"RESET, min, max);
                    } else {
                        printf(RED"Altura inválida!\n"RESET);
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
                
                do {
                    printf(CYAN"Informe seu gênero (M = Masculino, F = Feminino, N = Prefiro não informar): "RESET);
                    scanf(" %c", &genero);

                    genero = ler_genero(genero); 

                    if (genero == 0) {
                        printf(CYAN"Opção inválida! Digite apenas M, F ou N.\n"RESET);
                    }
                } while (genero == 0);

                printf("Informe seu percentual de gordura corporal (BF %%): ");
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

    

    

