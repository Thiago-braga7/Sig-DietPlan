#include <stdio.h>
#include <stdlib.h>
#include "usuarios.h"


#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
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
            
        }
    } while (opcao != '0');  
}


char usuarios(void){
    char opcao;
    system("clear||cls");
    printf("\n");
    printf(CYAN"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf(RED"///                    = = = = =   Usuários   = = = = =                     ///\n"RESET);
    printf("///                                                                         ///\n");
    printf(CYAN"///                    1. Cadastrar Usuário                                 ///\n");
    printf("///                    2. Buscar Usuário                                    ///\n");
    printf("///                    3. Alterar Dados do Usuário                          ///\n");
    printf("///                    4. Excluir Usuário                                   ///\n");
    printf("///                    0. Voltar ao Menu Principal                          ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n"RESET);
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
    printf(CYAN"///////////////////////////////////////////////////////////////////////////////\n");
    printf(RED"///                               Usuários                                  ///\n"RESET);
    printf(CYAN"///                                                                         ///\n");
    printf(RED"///                 = = = = =  Cadastrar Usuário = = = = =                  ///\n"RESET);
    printf(CYAN"///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Nome Completo:                                  ///\n"RESET);
    scanf("%[^\n]", nome);
    getchar();
    printf(CYAN"///                         CPF(Apenas números):                            ///\n"RESET);
    scanf("%s", cpf);
    getchar();
    printf(CYAN"///                         Telefone(Apenas números):                       ///\n"RESET);
    scanf("%s", telefone);
    getchar();
    printf(CYAN"///                         Idade:                                          ///\n"RESET);
    scanf("%d", &idade);
    getchar();
    printf(CYAN"///                         Peso(Kg):                                       ///\n"RESET);
    scanf("%f", &peso);
    getchar();
    printf(CYAN"///                         Altura(m):                                      ///\n"RESET);
    scanf("%f", &altura);
    getchar();
    printf(CYAN"///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf(RED"///                    Usuário cadastrado com sucesso!                      ///\n"RESET);
    printf(CYAN"///////////////////////////////////////////////////////////////////////////////\n"RESET);
}

void buscar_usuario(void){
    char cpf[15];
    system("clear||cls");
    printf("\n");
    printf(CYAN"///////////////////////////////////////////////////////////////////////////////\n");
    printf(RED"///                               Usuários                                  ///\n"RESET);
    printf(CYAN"///                                                                         ///\n");
    printf(RED"///                 = = = = =  Buscar Usuário = = = = =                     ///\n"RESET);
    printf(CYAN"///                                                                         ///\n");
    printf("///                         Informe o CPF(Apenas números):                  ///\n"RESET);
    scanf("%s", cpf);
    printf(CYAN"///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf(RED"///                        Informações do Usuário                           ///\n"RESET);
    printf(CYAN"///                                                                         ///\n");
    printf("///                         Nome Completo:                                  ///\n");
    printf("///                         CPF:                                            ///\n");
    printf("///                         Telefone:                                       ///\n");
    printf("///                         Idade:                                          ///\n");
    printf("///                         Peso(Kg):                                       ///\n");
    printf("///                         Altura(m):                                      ///\n");
    printf(CYAN"///////////////////////////////////////////////////////////////////////////////\n"RESET);
}

void alterar_usuario(void){
    char cpf[15], novo_cpf[15], novo_nome[100], novo_telefone[15];
    int nova_idade;
    float novo_peso, nova_altura;
    system("clear||cls");

    printf("\n");
    printf(CYAN"///////////////////////////////////////////////////////////////////////////////\n");
    printf(RED"///                               Usuários                                  ///\n"RESET);
    printf(CYAN"///                                                                         ///\n");
    printf(RED"///                 = = = = = Alterar Dados do Usuário = = = = =            ///\n"RESET);
    printf(CYAN"///                                                                         ///\n");
    printf("///                         Informe o CPF(Apenas números):                  ///\n"RESET);
    scanf("%s", cpf);
    getchar();
    printf(CYAN"///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf(RED"///                        Novos Dados do Usuário                           ///\n"RESET);
    printf(CYAN"///                                                                         ///\n");
    printf("///                         Nome Completo:                                  ///\n"RESET);
    scanf("%[^\n]", novo_nome);
    getchar();
    printf(CYAN"///                         CPF:                                            ///\n"RESET);
    scanf("%s", novo_cpf);
    getchar();
    printf(CYAN"///                         Telefone:                                       ///\n"RESET);
    scanf("%s", novo_telefone);
    getchar();
    printf(CYAN"///                         Idade:                                          ///\n"RESET);
    scanf("%d", &nova_idade);
    getchar();
    printf(CYAN"///                         Peso(Kg):                                       ///\n"RESET);
    scanf("%f", &novo_peso);
    getchar();
    printf(CYAN"///                         Altura(m):                                      ///\n"RESET);
    scanf("%f", &nova_altura);
    getchar();
    printf(CYAN"///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf(RED"///                    Usuário alterado com sucesso!                        ///\n"RESET);
    printf(CYAN"///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf("\n");
}

void excluir_usuario(void){
    system("clear||cls");
    char cpf[15], confirmacao;
    printf("\n");
    printf(CYAN"///////////////////////////////////////////////////////////////////////////////\n");
    printf(RED"///                               Usuários                                  ///\n"RESET);
    printf(CYAN"///                                                                         ///\n");
    printf(RED"///                 = = = = = Excluir Usuário = = = = =                     ///\n"RESET);
    printf(CYAN"///                                                                         ///\n");
    printf("///                         Informe o CPF(Apenas números):                  ///\n"RESET);
    scanf("%s", cpf);
    getchar();
    printf(CYAN"///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf(RED"///                           Excluindo Usuário                             ///\n"RESET);
    printf(CYAN"///                                                                         ///\n");
    printf(RED"///                            Dados do Usuário                             ///\n"RESET);
    printf(CYAN"///                                                                         ///\n");
    printf("///                         Nome Completo:                                  ///\n");
    printf("///                         CPF:                                            ///\n");
    printf("///                         Telefone:                                       ///\n");
    printf("///                         Idade:                                          ///\n");
    printf("///                         Peso(Kg):                                       ///\n");
    printf("///                         Altura(m):                                      ///\n");
    printf(CYAN"///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf("///                      Deseja excluir este usuário?(S/N):                  ///\n");
    scanf("%c", &confirmacao);
    getchar();
    if (confirmacao == 'S' || confirmacao == 's') {
        printf(RED"///                    Usuário excluído com sucesso!                      ///\n"RESET);
    } else {
        printf(RED"///                    Operação de exclusão cancelada!                    ///\n"RESET);
    }
}
