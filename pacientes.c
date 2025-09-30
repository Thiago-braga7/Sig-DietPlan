#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pacientes.h"
#include "util.h"
#include <ctype.h>


#define RESET   "\033[0m"
#define RED     "\033[31m"
#define CYAN    "\033[36m"


void modulo_pacientes(void) {
    char opcao;
    do {
        limpar_tela();
        opcao = tela_pacientes();
        switch(opcao) {
            case '1': cadastrar_paciente(); break;
            case '2': buscar_paciente(); break;
            case '3': alterar_paciente(); break;
            case '4': excluir_paciente(); break;
            case '5': calcular_imc(); break;
            case '6': calcular_bf(); break;
            
        }
    } while (opcao != '0');  
}


char tela_pacientes(void){
    char opcao;
    limpar_tela();
    printf("\n");
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                    = = = = =   Pacientes = = = = =                      ///\n");
    printf("///                                                                         ///\n");
    printf("///                    1. Cadastrar Paciente                                ///\n");
    printf("///                    2. Buscar Paciente                                   ///\n");
    printf("///                    3. Alterar Dados do Paciente                         ///\n");
    printf("///                    4. Excluir Paciente                                  ///\n");
    printf("///                    5. Calcular IMC                                      ///\n");
    printf("///                    6. Calcular BF                                       ///\n");
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

void cadastrar_paciente(void){
    FILE *arq_paciente;
    char nome[100];
    char cpf[13];
    char tel[11];
    int idade;
    float peso;
    float altura;

    limpar_tela();
    printf("\n");
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                Pacientes                                ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = =  Cadastrar Paciente = = = = =                 ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n"RESET);
    
    printf(RED"///                         Nome:                                        ///\n");
    scanf("%s", nome); 
    getchar();

    printf("///                         CPF (Apenas números):                           ///\n");
    scanf("%s", cpf); 
    getchar();

    printf("///                         Telefone (Apenas números):                      ///\n");
    scanf("%s", tel); 
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

    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("                    Paciente Cadastrado com Sucesso!                         \n");
    printf("///////////////////////////////////////////////////////////////////////////////\n"RESET);


    arq_paciente = fopen("arq_paciente.csv", "at");
    if (arq_paciente == NULL) {
        printf("Erro na criacao do arquivo\n");
        return;
    }

    fprintf(arq_paciente, "%s;", nome);
    fprintf(arq_paciente, "%s;", cpf);
    fprintf(arq_paciente, "%s;", tel);
    fprintf(arq_paciente, "%d;", idade);
    fprintf(arq_paciente, "%f;", peso);
    fprintf(arq_paciente, "%f\n", altura);
    fclose(arq_paciente);
    pausar();
}


void buscar_paciente(void){
    FILE *arq_paciente;
    char nome[100];
    char cpf[13];
    char tel[11];
    int idade;
    float peso;
    float altura;
    char cpf_lido[13];

    limpar_tela();
    printf("\n");
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                               Pacientes                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = =  Buscar Paciente = = = = =                    ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe o CPF(Apenas números):                  ///\n");
    scanf("%s", cpf_lido);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                        Informações do Paciente                          ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Nome Completo:                                  ///\n");
    printf("///                         CPF:                                            ///\n");
    printf("///                         Telefone:                                       ///\n");
    printf("///                         Idade:                                          ///\n");
    printf("///                         Peso(Kg):                                       ///\n");
    printf("///                         Altura(m):                                      ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n"RESET);
    pausar();

    arq_paciente = fopen("arq_paciente.csv", "rt");

    if (arq_paciente == NULL){
        printf("Erro na criacao do arquivo\n");
        return;
     }

    while (!feof(arq_paciente)) {
        fscanf(arq_paciente, "%[^;]", nome);
        fgetc(arq_paciente);
        fscanf(arq_paciente, "%[^;]", cpf);
        fgetc(arq_paciente);
        fscanf(arq_paciente, "%[^;]", tel);
        fgetc(arq_paciente);
        fscanf(arq_paciente, "%d", &idade);
        fgetc(arq_paciente);
        fscanf(arq_paciente, "%f", &peso);
        fgetc(arq_paciente);
        fscanf(arq_paciente, "%f", &altura);
        fgetc(arq_paciente);
    }

    if (strcmp(cpf, cpf_lido) == 0) {
        printf("Paciente encontrado");
        printf("Nome: %s\n", nome);
        printf("CPF: %s\n", cpf);
        printf("Telefone: %s\n", tel);
        printf("Idade: %d\n", idade);
        printf("Peso: %f\n", peso);
        printf("Altura: %f\n", altura);
        getchar();
        fclose(arq_paciente);
        return;
    }
}

 
void alterar_paciente(void){
    char cpf[15], novo_cpf[15], novo_nome[100], novo_telefone[15];
    int nova_idade;
    float novo_peso, nova_altura, novo_bf;
    limpar_tela();
    printf("\n");
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                               Pacientes                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = = Alterar Dados do Paciente = = = = =           ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe o CPF(Apenas números):                  ///\n");
    scanf("%s", cpf);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                        Novos Dados do Paciente                          ///\n");
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
    printf("///                         Percentual de gordura(Porcentagem):             ///\n");
    scanf("%f", &novo_bf);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                    Paciente alterado com sucesso!                        ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf("\n");
    pausar();

}

        
   
void excluir_paciente(void){
    limpar_tela();
    char cpf[15];
    printf("\n");
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                Pacientes                                ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = = Excluir Paciente = = = = =                    ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe o CPF(Apenas números):                  ///\n");
    scanf("%s", cpf); 
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                           Excluindo Paciente                            ///\n");
    printf("///                                                                         ///\n");
    printf("///                            Dados do Paciente                            ///\n");
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
            printf(RED"Paciente Excluído com Sucesso!    \n"RESET);
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
        printf("///                                Pacientes                                    ///\n");
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
        printf("///                                Pacientes                                    ///\n");
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

    

    

