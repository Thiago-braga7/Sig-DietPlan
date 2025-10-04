#include <stdio.h>
#include <stdlib.h>
#include "agendamentos.h"
#include "util.h"
#include <string.h>


typedef struct agendamento Agendamento;

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
    Agendamento ag;
    ag.id_agendamento = 1;
    limpar_tela();

    arq_agendamentos = fopen("arq_agendamentos.csv", "rt");
    if (arq_agendamentos != NULL)
    {
        char linha[512];
        while (fgets(linha, sizeof(linha), arq_agendamentos) != NULL)
        {
            ag.id_agendamento++;
        }
        fclose(arq_agendamentos);
    }

    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                             Agendamentos                                ///\n");
    printf("///                                                                         ///\n");
    printf("///                   = = = = = Cadastrar Agendamento = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///                         CPF do Paciente:                                ///\n");
    scanf("%s", ag.cpf); 
    getchar();
    printf("///                         Data (DD/MM/AAAA):                              ///\n");
    scanf("%s", ag.data); 
    getchar();
    printf("///                         Hora (HH:MM):                                   ///\n");
    scanf("%s", ag.hora); 
    getchar();
    printf("///                         Tipo de Agendamento:                            ///\n");
    scanf("%50[^\n]", ag.tipo); 
    getchar();
    printf("///                         Profissional Responsável:                       ///\n");
    scanf("%100[^\n]", ag.profissional); 
    getchar();
    printf("///                         Observações:                                    ///\n");
    scanf("%50[^\n]", ag.observacoes); 
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                  Agendamento Cadastrado com Sucesso !                   ///\n");
    printf("///                        ID gerado: %02d                                    ///\n", ag.id_agendamento);
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    arq_agendamentos = fopen("arq_agendamentos.csv", "at");
    if (arq_agendamentos == NULL) {
        printf("Erro na criacao do arquivo\n");
        return;
    }
    fprintf(arq_agendamentos, "%d;", ag.id_agendamento);
    fprintf(arq_agendamentos, "%s;", ag.cpf);
    fprintf(arq_agendamentos, "%s;", ag.data);
    fprintf(arq_agendamentos, "%s;", ag.hora);
    fprintf(arq_agendamentos, "%s;", ag.tipo);
    fprintf(arq_agendamentos, "%s;", ag.profissional);
    fprintf(arq_agendamentos, "%s\n", ag.observacoes);

    pausar();
}
void buscar_agendamento(void){
    FILE *arq_agendamentos;
    
    Agendamento ag;
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
                  &ag.id_agendamento, ag.cpf, ag.data, ag.hora, ag.tipo, ag.profissional, ag.observacoes) == 7){
        if (ag.id_agendamento == id_busca){
            printf("///                        Agendamento Encontrado!                        ///\n");
            printf("ID:                %d\n", ag.id_agendamento);
            printf("CPF:               %s\n", ag.cpf);
            printf("Data:              %s\n", ag.data);
            printf("Hora:              %s\n", ag.hora);
            printf("Tipo:              %s\n", ag.tipo);
            printf("Profissional:      %s\n", ag.profissional);
            printf("Observações:       %s\n", ag.observacoes);

            encontrado = 1;
            break;
        }
    }
    fclose(arq_agendamentos);

    if (encontrado == 0){
        printf("\n///               Agendamento com o ID %d não foi encontrado.            ///\n", id_busca);
    }

    pausar();
}

void alterar_agendamento(void){
    // Agendamento ag;
    Agendamento nova_ag;
    int id_busca;

    limpar_tela();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                             Agendamentos                                ///\n");
    printf("///                                                                         ///\n");
    printf("///                   = = = = = Alterar Agendamento = = = = =               ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe o ID do Agendamento:                    ///\n");
    scanf("%d", &id_busca); 
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                        Novos Dados do Agendamento                       ///\n");
    printf("///                                                                         ///\n");
    printf("///                         CPF do Paciente:                                ///\n");
    scanf("%s", nova_ag.cpf); 
    getchar();
    printf("///                         Data (DD/MM/AAAA):                              ///\n");
    scanf("%s", nova_ag.data); 
    getchar();
    printf("///                         Hora (HH:MM):                                   ///\n");
    scanf("%s", nova_ag.hora); 
    getchar();
    printf("///                         Tipo:                                           ///\n");
    scanf("%50[^\n]", nova_ag.tipo); 
    getchar();
    printf("///                         Profissional:                                   ///\n");
    scanf("%100[^\n]", nova_ag.profissional); 
    getchar();
    printf("///                         Observações:                                    ///\n");
    scanf("%50[^\n]", nova_ag.observacoes); 
    getchar();
    nova_ag.id_agendamento = id_busca;
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                  Agendamento Alterado com Sucesso !                     ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    pausar();
}
void excluir_agendamento(void){
    FILE *arq_agendamentos;
    FILE *arq_agendamentos_temp;
    Agendamento ag;
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
                  &ag.id_agendamento, ag.cpf, ag.data, ag.hora, ag.tipo, ag.profissional, ag.observacoes) == 7){
        if (ag.id_agendamento == id_busca){
            printf("///                        Agendamento Encontrado!                        ///\n");
            printf("ID:                %d\n", ag.id_agendamento);
            printf("CPF:               %s\n", ag.cpf);
            printf("Data:              %s\n", ag.data);
            printf("Hora:              %s\n", ag.hora);
            printf("Tipo:              %s\n", ag.tipo);
            printf("Profissional:      %s\n", ag.profissional);
            printf("Observações:       %s\n", ag.observacoes);

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

        
        while (fscanf(arq_agendamentos, "%d;%12[^;];%14[^;];%9[^;];%49[^;];%99[^;];%199[^\n]\n",&ag.id_agendamento, ag.cpf, ag.data, ag.hora, ag.tipo, ag.profissional, ag.observacoes) == 7) {
            if (ag.id_agendamento != id_busca) {
                fprintf(arq_agendamentos_temp, "%d;%s;%s;%s;%s;%s;%s\n",ag.id_agendamento, ag.cpf, ag.data, ag.hora, ag.tipo, ag.profissional, ag.observacoes);
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