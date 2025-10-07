#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "consultas.h"
#include "util.h"



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
    printf("///////////////////////////////////////////////////////////////////////////////\n");
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
    printf("///                      Escolha a opção desejada:                          ///\n");
    scanf("%c", &opcao);
    getchar();
    return opcao;
}



void cadastrar_consulta(void){
    FILE *arq_consulta;
    Consulta con;

    con.id_consulta = 1;

    arq_consulta = fopen("arq_consulta.csv", "rt");
    if (arq_consulta != NULL)
    {
        char linha[512];
        while (fgets(linha, sizeof(linha), arq_consulta) != NULL)
        {
            con.id_consulta++;
        }
        fclose(arq_consulta);
    }

    limpar_tela();

    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                               Consultas                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///                  = = = = =  Cadastrar Consulta  = = = = =               ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Nome do Usuário:                                ///\n");
    scanf("%s", con.nome);
    getchar();
    printf("///                         Data da Consulta (DD/MM/AAAA):                  ///\n");
    scanf("%s", con.data);
    getchar();
    printf("///                         Hora da Consulta (HH:MM):                       ///\n");
    scanf("%s", con.hora);
    getchar();
    printf("///                         Nome do Médico:                                  ///\n");
    scanf("%s", con.medico);
    getchar();
    printf("///                         Observações:                                    ///\n");
    scanf("%s", con.observacoes);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("                        Consulta Cadastrada com Sucesso!                        \n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    
    arq_consulta = fopen("arq_consulta.csv", "at");
    if (arq_consulta == NULL) {
        printf("Erro na criacao do arquivo\n");
        return;
    }

    fprintf(arq_consulta, "%d;", con.id_consulta);
    fprintf(arq_consulta, "%s;", con.nome);
    fprintf(arq_consulta, "%s;", con.data);
    fprintf(arq_consulta, "%s;", con.hora);
    fprintf(arq_consulta, "%s;", con.medico);
    fprintf(arq_consulta, "%s\n", con.observacoes);

    fclose(arq_consulta);

    pausar();
}


void buscar_consulta(void){
    FILE *arq_consulta;
    Consulta con;
    int id_busca;
    int encontrado = 0;
    

    limpar_tela();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                               Consultas                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///                  = = = = =  Buscar Consulta  = = = = =                  ///\n");
    printf("///                                                                         ///\n");
    printf("///                      Informe o ID da consulta:                          ///\n");
    scanf("%d", &id_busca);
    getchar();
    pausar();

    arq_consulta = fopen("arq_consulta.csv", "rt");

    if (arq_consulta == NULL){
        printf("Erro na criacao do arquivo\n");
        getchar();
        return;
     }

    while (fscanf(arq_consulta, "%d;%[^;];%[^;];%[^;];%[^;];%[^\n]\n", &con.id_consulta, con.nome, con.data, con.hora, con.medico, con.observacoes) == 6) {
        if (id_busca == con.id_consulta) {
            printf("Consulta encontrada\n");
            printf("Nome: %s\n", con.nome);
            printf("Data: %s\n", con.data);
            printf("Hora: %s\n", con.hora);
            printf("Médico: %s\n", con.medico);
            printf("Observações: %s\n", con.observacoes);
            encontrado = 1;
            break;
        }
    }
    
    if (!encontrado) {
        printf("\nPaciente não encontrado!\n");
    }

    fclose(arq_consulta);
    getchar();
}

void alterar_consulta(void){
    Consulta nova_con;
    int id_busca;


    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                               Consultas                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///                  = = = = =  Alterar Consulta  = = = = =                 ///\n");
    printf("///                                                                         ///\n");
    printf("///                          Informe o ID da consulta:                      ///\n");
    scanf("%d", &id_busca);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                        Novos Dados da Consulta                          ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Nome do Usuário:                                ///\n");
    scanf("%s", nova_con.nome);
    getchar();
    printf("///                         Data da Consulta (DD/MM/AAAA):                  ///\n");
    scanf("%s", nova_con.data);
    getchar();
    printf("///                         Hora da Consulta (HH:MM):                        ///\n");
    scanf("%s", nova_con.hora);
    getchar();
    printf("///                         Nome do Médico:                                 ///\n");
    scanf("%s", nova_con.medico);
    getchar();
    printf("///                         Observações:                                    ///\n");
    scanf("%s", nova_con.observacoes);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("                        Consulta Alterada com Sucesso!                        \n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    pausar();
}


void excluir_consulta(void){
    int id_busca;
    limpar_tela();
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                               Consultas                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///                  = = = = =  Alterar Consulta  = = = = =                 ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe a Data(DD/MM/AAAA):                     ///\n");
    scanf("%d", &id_busca);
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
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    char resposta;

    do {
        printf("Deseja confirmar a ação? (S/N): ");
        scanf(" %c", &resposta);

        resposta = confirmar_acao(resposta); 

        if (resposta == 0) {  
            printf("Opção inválida! Digite apenas S ou N.\n");
        }
    } while (resposta == 0); 

    if (resposta == 'S') {
        printf("/// Consulta excluída com sucesso! ///\n");
    } else {
        printf("/// Operação de exclusão cancelada! ///\n");
}
    pausar();

}
