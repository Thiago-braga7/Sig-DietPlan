#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "consultas.h"
#include "util.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define CYAN    "\033[36m"



void modulo_consultas(void) {
    char opcao;
    do {
        limpar_tela();
        opcao = tela_consultas();
        switch(opcao) {
            case '1': cadastrar_consulta(); break;
            case '2': buscar_consulta(); break;
            case '3': alterar_consulta(); break;
            case '4': excluir_consulta(); break;
        }
    } while (opcao != '0');  
}


char tela_consultas(void){
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
    FILE *arq_consulta;

    char nome[100];
    char data[10];
    char hora[6];
    char medico[100];
    char observacoes[200];
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
    
    arq_consulta = fopen("arq_consulta.csv", "at");
    if (arq_consulta == NULL) {
        printf("Erro na criacao do arquivo\n");
        return;
    }

    fprintf(arq_consulta, "%s;", nome);
    fprintf(arq_consulta, "%s;", data);
    fprintf(arq_consulta, "%s;", hora);
    fprintf(arq_consulta, "%s;", medico);
    fprintf(arq_consulta, "%s\n", observacoes);

    fclose(arq_consulta);

    pausar();
}


void buscar_consulta(void){
    FILE *arq_consulta;
    char nome[100];
    char nome_lido[100];
    char data[10];
    char data_lida[10];
    char hora[6];
    char medico[100];
    char observacoes[200];
    

    limpar_tela();
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                               Consultas                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///                  = = = = =  Buscar Consulta  = = = = =                  ///\n");
    printf("///                                                                         ///\n");
    printf("///                     Informe o nome do Usuário:                          ///\n");
    scanf("%s", nome_lido);
    getchar();
    printf("///                     Data da Consulta (DD/MM/AAAA):                      ///\n");
    scanf("%s", data_lida);
    getchar();
    pausar();

    arq_consulta = fopen("arq_consulta.csv", "rt");

    if (arq_consulta == NULL){
        printf("Erro na criacao do arquivo\n");
        getchar();
        return;
     }

    while (!feof(arq_consulta)) {
        fscanf(arq_consulta, "%[^;]", nome);
        fgetc(arq_consulta);
        fscanf(arq_consulta, "%[^;]", data);
        fgetc(arq_consulta);
        fscanf(arq_consulta, "%[^;]", hora);
        fgetc(arq_consulta);
        fscanf(arq_consulta, "%[^;]", medico);
        fgetc(arq_consulta);
        fscanf(arq_consulta, "%[^\n]", observacoes);
        fgetc(arq_consulta);

        if ((strcmp(nome, nome_lido) == 0) && (strcmp(data, data_lida) == 0)) {
            printf("Consulta encontrada\n");
            printf("Nome: %s\n", nome);
            printf("Data: %s\n", data);
            printf("Hora: %s\n", hora);
            printf("Médico: %s\n", medico);
            printf("Observações: %s\n", observacoes);
            getchar();
            fclose(arq_consulta);
            return;
        }
    }
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
