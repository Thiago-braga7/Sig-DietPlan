#include <stdio.h>
#include <stdlib.h>
#include "agendamentos.h"
#include "util.h"
#include <string.h>




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
    printf("///////////////////////////////////////////////////////////////////////////////\n");
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
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    return opcao;
}
void cadastrar_agendamento(void){
    FILE *arq_agendamentos;
    char cpf[13];
    char data[15]; 
    char hora[10];
    char tipo[50];
    char profissional[100];
    char observacoes[200];
    int id_agendamento = 1;
    limpar_tela();

    arq_agendamentos = fopen("arq_agendamentos.csv", "rt");
    if (arq_agendamentos != NULL)
    {
        char linha[512];
        while (fgets(linha, sizeof(linha), arq_agendamentos) != NULL)
        {
            id_agendamento++;
        }
        fclose(arq_agendamentos);
    }

    printf("///////////////////////////////////////////////////////////////////////////////\n");
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
    printf("///                        ID gerado: %02d                                    ///\n", id_agendamento);
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    arq_agendamentos = fopen("arq_agendamentos.csv", "at");
    if (arq_agendamentos == NULL) {
        printf("Erro na criacao do arquivo\n");
        return;
    }
    fprintf(arq_agendamentos, "%d;", id_agendamento);
    fprintf(arq_agendamentos, "%s;", cpf);
    fprintf(arq_agendamentos, "%s;", data);
    fprintf(arq_agendamentos, "%s;", hora);
    fprintf(arq_agendamentos, "%s;", tipo);
    fprintf(arq_agendamentos, "%s;", profissional);
    fprintf(arq_agendamentos, "%s\n", observacoes);

    pausar();
}
void buscar_agendamento(void){
    FILE *arq_agendamentos;
    char cpf[13];
    char data[15]; 
    char hora[10];
    char tipo[50];
    char profissional[100];
    char observacoes[200];
    int id_agendamento;
    int id_busca;
    int encontrado = 0;

    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                             Agendamentos                                ///\n");
    printf("///                                                                         ///\n");
    printf("///                   = = = = = Buscar Agendamento = = = = =                ///\n");
    printf("///                                                                         ///\n");
    printf("///                        Informe o ID do Agendamento                      ///\n");
    scanf("%d", &id_busca);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");

    arq_agendamentos = fopen("arq_agendamentos.csv", "rt");

    if (arq_agendamentos == NULL){
        printf("Erro na criacao do arquivo\n");
        return;
    }

    while (fscanf(arq_agendamentos, "%d;%12[^;];%14[^;];%9[^;];%49[^;];%99[^;];%199[^\n]\n",
                  &id_agendamento, cpf, data, hora, tipo, profissional, observacoes) == 7){
        if (id_agendamento == id_busca){
            printf("///                        Agendamento Encontrado!                        ///\n");
            printf("ID:                %d\n", id_agendamento);
            printf("CPF:               %s\n", cpf);
            printf("Data:              %s\n", data);
            printf("Hora:              %s\n", hora);
            printf("Tipo:              %s\n", tipo);
            printf("Profissional:      %s\n", profissional);
            printf("Observações:       %s\n", observacoes);

            encontrado = 1;
            break;
        }
    }
    fclose(arq_agendamentos);

    if (encontrado == 0){
        printf("\n///               Agendamento com o ID %d nao foi encontrado.            ///\n", id_busca);
    }

    pausar();
}

void alterar_agendamento(void){
    char data[15];
    char novo_cpf[13];
    char nova_data[15];
    char nova_hora[10];
    char novo_tipo[50]; 
    char novo_profissional[100];
    char novas_observacoes[200];
    limpar_tela();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
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
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    pausar();
}
void excluir_agendamento(void){
    FILE *arq_agendamentos;
    FILE *arq_agendamentos_temp;
    char cpf[13];
    char data[15]; 
    char hora[10];
    char tipo[50];
    char profissional[100];
    char observacoes[200];
    int id_agendamento;
    int id_busca;
    int encontrado = 0;
    limpar_tela();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                             Agendamentos                                ///\n");
    printf("///                                                                         ///\n");
    printf("///                   = = = = = Excluir Agendamento = = = = =               ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe o ID do Agendamento:                    ///\n");
    scanf("%d", &id_busca); 
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");

    pausar();

    char resposta;

     do{
        arq_agendamentos = fopen("arq_agendamentos.csv", "rt");

        if (arq_agendamentos == NULL){
            printf("Erro na criacao do arquivo\n");
            return;
        }

          while (fscanf(arq_agendamentos, "%d;%12[^;];%14[^;];%9[^;];%49[^;];%99[^;];%199[^\n]\n",
                  &id_agendamento, cpf, data, hora, tipo, profissional, observacoes) == 7){
        if (id_agendamento == id_busca){
            printf("///                        Agendamento Encontrado!                        ///\n");
            printf("ID:                %d\n", id_agendamento);
            printf("CPF:               %s\n", cpf);
            printf("Data:              %s\n", data);
            printf("Hora:              %s\n", hora);
            printf("Tipo:              %s\n", tipo);
            printf("Profissional:      %s\n", profissional);
            printf("Observações:       %s\n", observacoes);

            encontrado = 1;
            break;
        }
    }
        
        if (!encontrado){
            printf("\nAgendamento não encontrado!\n");
        }

        fclose(arq_agendamentos);
        getchar();
        printf("Deseja confirmar a ação? (S/N): ");
        scanf(" %c", &resposta);

        resposta = confirmar_acao(resposta);

        if (resposta == 0){
            printf("Opção inválida! Digite apenas S ou N.\n");
        }

    } while (resposta == 0);

    if (resposta == 'S'){
        arq_agendamentos = fopen("arq_agendamentos.csv", "rt");
        arq_agendamentos_temp = fopen("arq_agendamentos_temp.csv", "wt");

        if (arq_agendamentos == NULL || arq_agendamentos_temp == NULL){
            printf("Erro na criacao do arquivo\n");
            return;
        }

        
        while (fscanf(arq_agendamentos, "%d;%12[^;];%14[^;];%9[^;];%49[^;];%99[^;];%199[^\n]\n",&id_agendamento, cpf, data, hora, tipo, profissional, observacoes) == 7) {
            if (id_agendamento != id_busca) {
                fprintf(arq_agendamentos_temp, "%d;%s;%s;%s;%s;%s;%s\n",id_agendamento, cpf, data, hora, tipo, profissional, observacoes);
            }
        }
        fclose(arq_agendamentos);
        fclose(arq_agendamentos_temp);

        remove("arq_agendamentos.csv");
        rename("arq_agendamentos_temp.csv", "arq_agendamentos.csv");

        if (!encontrado){
            printf("\nAgendamento não encontrada!\n");
        }

        printf("Agendamento Excluído com Sucesso! \n");
    } else {
            printf("Operação de Exclusão Cancelada !  \n");
    }
    pausar();
}