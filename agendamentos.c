#include <stdio.h>
#include <stdlib.h>
#include "agendamentos.h"
#include "util.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define CYAN    "\033[36m"


void modulo_agendamentos(void) {
    char opcao;
    do {
        limpar_tela();
        opcao = tela_agendamentos();
        switch(opcao) {
            case '1': cadastrar_agendamento(); break;
            case '2': buscar_agendamento(); break;
            case '3': alterar_agendamento(); break;
            case '4': excluir_agendamento(); break;
        }
    } while (opcao != '0');  
}

char tela_agendamentos(void){
    char opcao;
    printf("\n");
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                  = = = = =  Agendamentos  = = = = =                     ///\n");
    printf("///                                                                         ///\n");
    printf("///                    1. Cadastrar Agendamento                             ///\n");
    printf("///                    2. Buscar Agendamento                                ///\n");
    printf("///                    3. Alterar Agendamento                               ///\n");
    printf("///                    4. Excluir Agendamento                               ///\n");
    printf("///                    0. Voltar ao Menu Principal                          ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                      Escolha a opção desejada:                          ///\n");
    scanf("%c", &opcao);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n"RESET);
    return opcao;
}
void cadastrar_agendamento(void){
    char cpf[15], data[15], hora[10];
    char tipo[50], profissional[100], observacoes[200];
    limpar_tela();

    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                             Agendamentos                                ///\n");
    printf("///                                                                         ///\n");
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
    printf("///                  Agendamento Cadastrado com Sucesso !                   ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n"RESET);
    pausar();
}
void buscar_agendamento(void){
    char cpf[15], data[15];
    limpar_tela();
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                             Agendamentos                                ///\n");
    printf("///                                                                         ///\n");
    printf("///                   = = = = = Buscar Agendamento = = = = =                ///\n");
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
    pausar();
}
void alterar_agendamento(void){
    char data[15];
    char novo_cpf[15], nova_data[15], nova_hora[10];
    char novo_tipo[50], novo_profissional[100], novas_observacoes[200];
    limpar_tela();
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                             Agendamentos                                ///\n");
    printf("///                                                                         ///\n");
    printf("///                   = = = = = Alterar Agendamento = = = = =               ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe a Data (DD/MM/AAAA):                    ///\n");
    scanf("%s", data); 
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                        Novos Dados do Agendamento                       ///\n");
    printf("///                                                                         ///\n");
    printf("///                         CPF do Paciente:                                ///\n");
    scanf("%s", novo_cpf); 
    getchar();
    printf("///                         Data (DD/MM/AAAA):                              ///\n");
    scanf("%s", nova_data); 
    getchar();
    printf("///                         Hora (HH:MM):                                   ///\n");
    scanf("%s", nova_hora); 
    getchar();
    printf("///                         Tipo:                                           ///\n");
    scanf("%s", novo_tipo); 
    getchar();
    printf("///                         Profissional:                                   ///\n");
    scanf("%s", novo_profissional); 
    getchar();
    printf("///                         Observações:                                    ///\n");
    scanf("%s", novas_observacoes); 
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                  Agendamento Alterado com Sucesso !                     ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n"RESET);
    pausar();
}
void excluir_agendamento(void){
    char data[15];
    limpar_tela();
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                             Agendamentos                                ///\n");
    printf("///                                                                         ///\n");
    printf("///                   = = = = = Excluir Agendamento = = = = =               ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe a Data (DD/MM/AAAA):                    ///\n");
    scanf("%s", data); 
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                         Excluindo Agendamento                           ///\n");
    printf("///                                                                         ///\n");
    printf("///                         CPF:                                            ///\n");
    printf("///                         Data:                                           ///\n");
    printf("///                         Hora:                                           ///\n");
    printf("///                         Tipo:                                           ///\n");
    printf("///                         Profissional:                                   ///\n");
    printf("///                         Observações:                                    ///\n");
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
            printf(RED"///           Agendamento excluído com sucesso!                 ///\n");
        } else {
            printf(RED"///           Operação de exclusão cancelada!                   ///\n");
    }
    pausar();

}