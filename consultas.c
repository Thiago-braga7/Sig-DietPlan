#include <stdio.h>
#include <stdlib.h>
#include "consultas.h"
#include "util.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define CYAN    "\033[36m"



void modulo_consultas(void) {
    char opcao;
    do {
        limpar_tela();
        opcao = consultas();
        switch(opcao) {
            case '1': cadastrar_consulta(); break;
            case '2': buscar_consulta(); break;
            case '3': alterar_consulta(); break;
            case '4': excluir_consulta(); break;
        }
    } while (opcao != '0');  
}


char consultas(void){
    char opcao;
    printf("\n");
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                     = = = = = Consultas  = = = = =                      ///\n");
    printf("///                                                                         ///\n");
    printf("///                    1. Cadastrar Consulta                                ///\n");
    printf("///                    2. Buscar Consulta                                   ///\n");
    printf("///                    3. Alterar Consulta                                  ///\n");
    printf("///                    4. Excluir Consulta                                  ///\n");
    printf("///                    0. Voltar ao Menu Principal                          ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                      Escolha a opção desejada:                          ///\n"RESET);
    scanf("%c", &opcao);
    getchar();
    return opcao;
}



void cadastrar_consulta(void){
    char nome[100], data[15], hora[10];
    char medico[100], observacoes[200];
    limpar_tela();

    printf("\n");
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                               Consultas                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///                  = = = = =  Cadastrar Consulta  = = = = =               ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Nome do Usuário:                                ///\n");
    scanf("%s", nome);
    getchar();
    printf("///                         Data da Consulta (DD/MM/AAAA):                  ///\n");
    scanf("%s", data);
    getchar();
    printf("///                         Hora da Consulta (HH:MM):                       ///\n");
    scanf("%s", hora);
    getchar();
    printf("///                         Nome do Médico:                                  ///\n");
    scanf("%s", medico);
    getchar();
    printf("///                         Observações:                                    ///\n");
    scanf("%s", observacoes);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("                        Consulta Cadastrada com Sucesso!                        \n");
    printf("///////////////////////////////////////////////////////////////////////////////\n"RESET);
    pausar();
}
void buscar_consulta(void){
    char nome[100], data[15];
    limpar_tela();
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                               Consultas                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///                  = = = = =  Buscar Consulta  = = = = =                  ///\n");
    printf("///                                                                         ///\n");
    printf("///                     Informe o nome do Usuário:                          ///\n");
    scanf("%s", nome);
    printf("///                     Data da Consulta (DD/MM/AAAA):                      ///\n");
    scanf("%s", data);
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                        Informações da Consulta                          ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Nome do Usuário:                                ///\n");
    printf("///                         Data da Consulta (DD/MM/AAAA):                  ///\n");
    printf("///                         Hora da Consulta (HH:MM):                       ///\n");
    printf("///                         Nome do Médico:                                 ///\n");
    printf("///                         Observações:                                    ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n"RESET);
}

void alterar_consulta(void){
    char data[15];
    char novo_nome[100], nova_data[15], nova_hora[10];
    char novo_medico[100], novas_observacoes[200];
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n"RESET);
    printf("///                               Consultas                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///                  = = = = =  Alterar Consulta  = = = = =                 ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe a Data(DD/MM/AAAA):                     ///\n");
    scanf("%s", data);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                        Novos Dados da Consulta                          ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Nome do Usuário:                                ///\n");
    scanf("%s", novo_nome);
    getchar();
    printf("///                         Data da Consulta (DD/MM/AAAA):                  ///\n");
    scanf("%s", nova_data);
    getchar();
    printf("///                         Hora da Consulta (HH:MM):                        ///\n");
    scanf("%s", nova_hora);
    getchar();
    printf("///                         Nome do Médico:                                 ///\n");
    scanf("%s", novo_medico);
    getchar();
    printf("///                         Observações:                                    ///\n"RESET);
    scanf("%s", novas_observacoes);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("                        Consulta Alterada com Sucesso!                        \n");
    printf("///////////////////////////////////////////////////////////////////////////////\n"RESET);
    pausar();
}
void excluir_consulta(void){
    limpar_tela();
    char data[15];
    printf("\n");
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                               Consultas                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///                  = = = = =  Alterar Consulta  = = = = =                 ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe a Data(DD/MM/AAAA):                     ///\n");
    scanf("%s", data);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                           Excluindo Consulta                            ///\n");
    printf("///                                                                         ///\n");
    printf("///                            Dados da Consulta                            ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Nome do Usuário:                                ///\n");
    printf("///                         Data da Consulta (DD/MM/AAAA):                  ///\n");
    printf("///                         Hora da Consulta (HH:MM):                       ///\n");
    printf("///                         Nome do Médico:                                 ///\n");
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
        printf(RED"/// Consulta excluída com sucesso! ///\n");
    } else {
        printf(RED"/// Operação de exclusão cancelada! ///\n");
}
    pausar();

}
