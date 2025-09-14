#include <stdio.h>
#include <stdlib.h>
#include "agendamentos.h"
#include "util.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"



char agendamentos(void){
    char opcao;
    printf("\n");
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = =   Agendamentos   = = = = =                    ///\n");
    printf("///                                                                         ///\n");
    printf("///                    1. Cadastrar Agendamento                             ///\n");
    printf("///                    2. Buscar Agendamento                                ///\n");
    printf("///                    3. Alterar Agendamento                               ///\n");
    printf("///                    4. Excluir Agendamento                               ///\n");
    printf("///                    0. Voltar ao Menu Principal                          ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                      Escolha a opção desejada:                          ///\n"RESET);
    scanf("%c", &opcao);
    getchar();
    return opcao;
}
void cadastrar_agendamento(void){
    char cpf[15], data[15], hora[10];
    char tipo[50], profissional[100], observacoes[200];
    limpar_tela();

    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                   = = = = = Cadastrar Agendamento = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///                         CPF do Paciente:                                ///\n");
    scanf("%s", cpf); 
    getchar();
    printf("///                         Data (DD/MM/AAAA):                              ///\n");
    scanf("%s", data); 
    getchar();
    printf("///                         Hora (HH:MM):                                   ///\n");
    scanf("%s", hora); 
    getchar();
    printf("///                         Tipo de Agendamento:                            ///\n");
    scanf("%s", tipo); 
    getchar();
    printf("///                         Profissional Responsável:                       ///\n");
    scanf("%s", profissional); 
    getchar();
    printf("///                         Observações:                                    ///\n");
    scanf("%s", observacoes); 
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                 Agendamento cadastrado com sucesso!                     ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n"RESET);
}
void buscar_agendamento(void){
    char cpf[15], data[15];
    limpar_tela();
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                     = = = = = Buscar Agendamento = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///                         CPF do Paciente:                                ///\n");
    scanf("%s", cpf);
    printf("///                         Data (DD/MM/AAAA):                              ///\n");
    scanf("%s", data);
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                     Informações do Agendamento                          ///\n");
    printf("///                         CPF:                                            ///\n");
    printf("///                         Data:                                           ///\n");
    printf("///                         Hora:                                           ///\n");
    printf("///                         Tipo:                                           ///\n");
    printf("///                         Profissional:                                   ///\n");
    printf("///                         Observações:                                    ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n"RESET);
}
void alterar_agendamento(void){
    char data[15];
    char novo_cpf[15], nova_data[15], nova_hora[10];
    char novo_tipo[50], novo_profissional[100], novas_observacoes[200];

    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                     = = = = = Alterar Agendamento = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe a Data (DD/MM/AAAA):                    ///\n");
    scanf("%s", data); getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                        Novos Dados do Agendamento                       ///\n");
    printf("///                         CPF do Paciente:                                ///\n");
    scanf("%s", novo_cpf); getchar();
    printf("///                         Data (DD/MM/AAAA):                              ///\n");
    scanf("%s", nova_data); getchar();
    printf("///                         Hora (HH:MM):                                   ///\n");
    scanf("%s", nova_hora); getchar();
    printf("///                         Tipo:                                           ///\n");
    scanf("%s", novo_tipo); getchar();
    printf("///                         Profissional:                                   ///\n");
    scanf("%s", novo_profissional); getchar();
    printf("///                         Observações:                                    ///\n");
    scanf("%s", novas_observacoes); getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                 Agendamento alterado com sucesso!                       ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n"RESET);
}
void excluir_agendamento(void){
    char data[15];
    limpar_tela();
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                     = = = = = Excluir Agendamento = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe a Data (DD/MM/AAAA):                    ///\n");
    scanf("%s", data); getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                           Excluindo Agendamento                         ///\n");
    printf("///                         CPF:                                            ///\n");
    printf("///                         Data:                                           ///\n");
    printf("///                         Hora:                                           ///\n");
    printf("///                         Tipo:                                           ///\n");
    printf("///                         Profissional:                                   ///\n");
    printf("///                         Observações:                                    ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");

    char resposta = confirmar_acao();
    if (resposta == 'S') {
        printf(RED"///                 Agendamento excluído com sucesso!                       ///\n");
    } else {
        printf(RED"///                 Operação de exclusão cancelada!                         ///\n");
    }
}