#include <stdio.h>
#include <stdlib.h>
#include "usuarios.h"


#define RESET   "\033[0m"
#define RED     "\033[31m"
#define CYAN    "\033[36m"






void modulo_usuarios(void) {
    char opcao;
    do {
        opcao = usuarios();
        switch(opcao) {
            case '1': cadastrar_usuario(); break;
            case '2': buscar_usuario(); break;
            case '3': alterar_usuario(); break;
            case '4': excluir_usuario(); break;
            case '5': calcular_imc(); break;
            
        }
    } while (opcao != '0');  
}


char usuarios(void){
    char opcao;
    system("clear||cls");
    printf("\n");
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                    = = = = =   Usuários   = = = = =                     ///\n");
    printf("///                                                                         ///\n");
    printf("///                    1. Cadastrar Usuário                                 ///\n");
    printf("///                    2. Buscar Usuário                                    ///\n");
    printf("///                    3. Alterar Dados do Usuário                          ///\n");
    printf("///                    4. Excluir Usuário                                   ///\n");
    printf("///                    5. Calcular IMC                                      ///\n");
    printf("///                    0. Voltar ao Menu Principal                          ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                      Escolha a opção desejada:                          ///\n"RESET);
    scanf("%c", &opcao);
    getchar();
    return opcao;
}

void cadastrar_usuario(void){
    char nome[100], cpf[15], telefone[15];
    int idade;
    float peso, altura;   
    system("clear||cls");
    printf("\n");
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                               Usuários                                  ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = =  Cadastrar Usuário = = = = =                  ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Nome Completo:                                  ///\n");
    scanf("%[^\n]", nome);
    getchar();
    printf("///                         CPF(Apenas números):                            ///\n");
    scanf("%s", cpf);
    getchar();
    printf("///                         Telefone(Apenas números):                       ///\n");
    scanf("%s", telefone);
    getchar();
    printf("///                         Idade:                                          ///\n");
    scanf("%d", &idade);
    getchar();
    printf("///                         Peso(Kg):                                       ///\n");
    scanf("%f", &peso);
    getchar();
    printf("///                         Altura(m):                                      ///\n");
    scanf("%f", &altura);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                    Usuário cadastrado com sucesso!                      ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n"RESET);
}

void buscar_usuario(void){
    char cpf[15];
    system("clear||cls");
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
}

void alterar_usuario(void){
    char cpf[15], novo_cpf[15], novo_nome[100], novo_telefone[15];
    int nova_idade;
    float novo_peso, nova_altura;
    system("clear||cls");

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
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                    Usuário alterado com sucesso!                        ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf("\n");
}

void excluir_usuario(void){
    system("clear||cls");
    char cpf[15], confirmacao;
    printf("\n");
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                               Usuários                                  ///\n");
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
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                      Deseja excluir este usuário?(S/N):                  ///\n"RESET);
    scanf("%c", &confirmacao);
    getchar();
    if (confirmacao == 'S' || confirmacao == 's') {
        printf(RED"///                    Usuário excluído com sucesso!                      ///\n");
    } else {
        printf(RED"///                    Operação de exclusão cancelada!                    ///\n");
    }
}
void calcular_imc(void){
    float peso, altura, imc;
    system("clear||cls");

    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                 Usuários                                    ///\n");
    printf("///                                                                             ///\n");
    printf("///                     = = = = = Calcular IMC = = = = =                        ///\n");
    printf("///                                                                             ///\n");
    printf("///                           Informe seu peso (kg):                            ///\n");
    scanf(" %f", &peso);  
    printf("///                           Informe sua altura (m):                           ///\n");
    scanf(" %f", &altura); 
    printf("///////////////////////////////////////////////////////////////////////////////////\n");

    if (altura <= 0) {
        printf("Altura inválida!\n");
        return;
    }

    imc = peso / (altura * altura);

    printf("///                                   IMC                                       ///\n");
    printf("///                                                                             ///\n");
    printf("\nIMC é: %.2f\n", imc);

    if (imc < 18.5) {
        printf("Classificação: Abaixo do peso\n");
    } else if (imc < 24.9) {
        printf("Classificação: Peso normal\n");
    } else if (imc < 29.9) {
        printf("Classificação: Sobrepeso\n");
    } else if (imc < 34.9) {
        printf("Classificação: Obesidade grau I\n");
    } else if (imc < 39.9) {
        printf("Classificação: Obesidade grau II\n");
    } else {
        printf("Classificação: Obesidade grau III\n");
    }

    printf("///////////////////////////////////////////////////////////////////////////////////\n");
    printf("\nPressione ENTER para voltar ao menu...");
    getchar(); 
    getchar(); 
}
