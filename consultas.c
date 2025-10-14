#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "consultas.h"
#include "util.h"
#define True 1
#define False 0


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
    FILE * arq_consulta;
    Consulta * con;
    con = (Consulta*)malloc(sizeof(Consulta));

    con->id_consulta = 1;

    arq_consulta = fopen("arq_consulta.dat", "rb");

    // Créditos: Função adaptada do gemini;
    if (arq_consulta != NULL){
        
        fseek(arq_consulta, 0, SEEK_END);  
        
        long num_registros = ftell(arq_consulta) / sizeof(Consulta);
        
        con->id_consulta = num_registros + 1;
        
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
    scanf("%s", con->nome);
    getchar();
    printf("///                         Data da Consulta (DD/MM/AAAA):                  ///\n");
    scanf("%s", con->data);
    getchar();
    printf("///                         Hora da Consulta (HH:MM):                       ///\n");
    scanf("%s", con->hora);
    getchar();
    printf("///                         Nome do Médico:                                  ///\n");
    scanf("%s", con->medico);
    getchar();
    printf("///                         Observações:                                    ///\n");
    scanf("%s", con->observacoes);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("                        Consulta Cadastrada com Sucesso!                        \n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    
    con->status = True;

    arq_consulta = fopen("arq_consulta.dat", "a+b");
    if (arq_consulta == NULL) {
        printf("Erro na criação do arquivo\n");
        return;
    }

    fwrite(con, sizeof(Consulta), 1, arq_consulta);
    fclose(arq_consulta);
    free(con);
    pausar();
}


void buscar_consulta(void){
    FILE * arq_consulta;
    Consulta * con;
    int id_busca;
    int encontrado;
    
    con = (Consulta*)malloc(sizeof(Consulta));

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

    encontrado = False;

    arq_consulta = fopen("arq_consulta.dat", "rb");

    if (arq_consulta == NULL){
        printf("Erro na criacao do arquivo\n");
        getchar();
        return;
     }

    while (fread(con, sizeof(Consulta), 1, arq_consulta)){
        if ((id_busca == con->id_consulta) && (con->status == True)) {
            printf("Consulta encontrada\n");
            printf("Nome: %s\n", con->nome);
            printf("Data: %s\n", con->data);
            printf("Hora: %s\n", con->hora);
            printf("Médico: %s\n", con->medico);
            printf("Observações: %s\n", con->observacoes);
            encontrado = 1;
            break;
        }
    }
    
    if (!encontrado) {
        printf("\nPaciente não encontrado!\n");
    }

    fclose(arq_consulta);
    free(con);
    getchar();
}

void alterar_consulta(void){
    FILE *arq_consulta;
    FILE *arq_consulta_temp;

    Consulta con;
    int id_busca;
    int encontrado = 0;
    char opcao;
    char continuar = 'S';


    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                               Consultas                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///                  = = = = =  Alterar Consulta  = = = = =                 ///\n");
    printf("///                                                                         ///\n");
    printf("///                          Informe o ID da consulta:                      ///\n");
    scanf("%d", &id_busca);
    getchar();

    arq_consulta = fopen("arq_consulta.csv", "rt");
    arq_consulta_temp = fopen("arq_consulta_temp.csv", "wt");

    if (arq_consulta == NULL || arq_consulta_temp == NULL){
        printf("Erro na criacao do arquivo\n");
        return;
    }

    while (fscanf(arq_consulta, "%d;%[^;];%[^;];%[^;];%[^;];%[^\n]\n", &con.id_consulta, con.nome, con.data, con.hora, con.medico, con.observacoes) == 6) {
        if(con.id_consulta == id_busca){
            encontrado = 1;
            do{
                printf("\n    Dados atuais da consulta    \n");
                printf("Nome: %s\n", con.nome);
                printf("Data: %s\n", con.data);
                printf("Hora: %s\n", con.hora);
                printf("Médico: %s\n", con.medico);
                printf("Observações: %s\n", con.observacoes);

                printf("\nQual campo deseja alterar?\n");
                printf("1. Nome\n");
                printf("2. Data\n");
                printf("3. Hora\n");
                printf("4. Médico\n");
                printf("5. Observações\n");
                printf("Escolha uma opção: ");
                scanf(" %c", &opcao);
                getchar();

                 switch (opcao) {
                    case '1':
                        printf("Novo nome: ");
                        scanf("%s", con.nome);
                        getchar();
                        break;
                    case '2':
                        printf("Novo data: ");
                        scanf("%s", con.data);
                        getchar();
                        break;
                    case '3':
                        printf("Nova hora: ");
                        scanf("%s", con.hora);
                        getchar();
                        break;
                    case '4':
                        printf("Novo médico: ");
                        scanf("%s", con.medico);
                        getchar();
                        break;
                    case '5':
                        printf("Nova observação: ");
                        scanf("%s", con.observacoes);
                        getchar();
                        break;
                    default:
                        printf("Opção inválida!\n");
                        break;
                }
                printf("\n    Dados atualizados    \n");
                printf("Nome: %s\n", con.nome);
                printf("Data: %s\n", con.data);
                printf("Hora: %s\n", con.hora);
                printf("Médico: %s\n", con.medico);
                printf("Observações: %s\n", con.observacoes);

                printf("\nDeseja alterar outro campo? (S/N): ");
                scanf(" %c", &continuar);
                continuar = confirmar_acao(continuar);
            } while (continuar == 'S');
        }
        fprintf(arq_consulta_temp, "%d;%s;%s;%s;%s;%s\n",
                con.id_consulta, con.nome, con.data, con.hora, con.medico, con.observacoes);
    }
    
    fclose(arq_consulta);
    fclose(arq_consulta_temp);

    if (encontrado){
        remove("arq_consulta.csv");
        rename("arq_consulta_temp.csv", "arq_consulta.csv");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                  Consulta Alterada com sucesso!                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
    } else {
        remove("arq_consulta_temp.csv");
        printf("\nConsulta não encontrada!\n");
    }
    pausar();

}


void excluir_consulta(void){
    FILE *arq_consulta;
    FILE *arq_consulta_temp;

    Consulta con;
    int id_busca;
    int encontrado = 0;

    limpar_tela();
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                               Consultas                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///                  = = = = =  Excluir Consulta  = = = = =                 ///\n");
    printf("///                                                                         ///\n");
    printf("///                        Informe o ID da consulta:                        ///\n");
    scanf("%d", &id_busca);
    getchar();


    char resposta;

    // Busca e exibe consultas
    do {
        arq_consulta = fopen("arq_consulta.csv", "rt");

        if (arq_consulta == NULL){
            printf("Erro na criacao do arquivo\n");
            return;
        }

        while (fscanf(arq_consulta, "%d;%[^;];%[^;];%[^;];%[^;];%[^\n]\n", &con.id_consulta, con.nome, con.data, con.hora, con.medico, con.observacoes) == 6) {
            if (con.id_consulta == id_busca) {
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
            printf("\nConsulta não encontrada!\n");
        }

        fclose(arq_consulta);
        getchar();
        printf("Deseja confirmar a ação? (S/N): ");
        scanf(" %c", &resposta);

        resposta = confirmar_acao(resposta); 

        if (resposta == 0) {  
            printf("Opção inválida! Digite apenas S ou N.\n");
        }

    } while (resposta == 0); 

    // Exclui caso a resposta seja "S"
    if (resposta == 'S') {
        arq_consulta = fopen("arq_consulta.csv", "rt");
        arq_consulta_temp = fopen("arq_consulta_temp.csv", "wt");

        if (arq_consulta == NULL || arq_consulta_temp == NULL){
            printf("Erro na criacao do arquivo\n");
            return;
        }

        while (fscanf(arq_consulta, "%d;%[^;];%[^;];%[^;];%[^;];%[^\n]\n", &con.id_consulta, con.nome, con.data, con.hora, con.medico, con.observacoes) == 6) {
            if(con.id_consulta != id_busca){
                fprintf(arq_consulta_temp, "%d;%s;%s;%s;%s;%s\n", con.id_consulta, con.nome, con.data, con.hora, con.medico, con.observacoes);
            }
        }
        
        fclose(arq_consulta);
        fclose(arq_consulta_temp);

        remove("arq_consulta.csv");
        rename("arq_consulta_temp.csv", "arq_consulta.csv");

        printf("Consulta Excluída com Sucesso!    \n");

    } else {
            printf("Operação de Exclusão Cancelada !  \n");
    }
    pausar();
}
