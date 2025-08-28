#include <stdio.h>
#include <stdlib.h>
#include "usuarios.h"



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
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                    = = = = =   Usuários   = = = = =                     ///\n");
    printf("///                                                                         ///\n");
    printf("///                    1. Cadastrar Usuário                                 ///\n");
    printf("///                    2. Buscar Usuário                                    ///\n");
    printf("///                    3. Alterar Dados do Usuário                          ///\n");
    printf("///                    4. Excluir Usuário                                   ///\n");
    printf("///                    0. Voltar ao Menu Principal                          ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                      Escolha a opção desejada:                          ///\n");
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
    printf("///////////////////////////////////////////////////////////////////////////////\n");
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
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    

}

void buscar_usuario(void){
    char cpf[15];
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
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
    printf("///////////////////////////////////////////////////////////////////////////////\n");

}
void alterar_usuario(void){
    char cpf[15], novo_cpf[15], novo_nome[100], novo_telefone[15];
    int nova_idade;
    float novo_peso, nova_altura;
    system("clear||cls");

    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
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
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    

}
void excluir_usuario(void){
    system("clear||cls");
    char cpf[15], confirmacao;
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
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
    printf("///                      Deseja excluir este usuário?(S/N):                  ///\n");
    scanf("%c", &confirmacao);
    getchar();
    if (confirmacao == 'S' || confirmacao == 's') {
        printf("///                    Usuário excluído com sucesso!                      ///\n");
    } else {
        printf("///                    Operação de exclusão cancelada!                    ///\n");
    }

}