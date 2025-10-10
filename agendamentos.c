#include <stdio.h>
#include <stdlib.h>
#include "agendamentos.h"
#include "util.h"
#include <string.h>
#define True 1
#define False 0




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
    FILE * arq_agendamentos;
    Agendamento * ag;
    
    ag = (Agendamento*)malloc(sizeof(Agendamento));

    ag->id_agendamento = 1;
     arq_agendamentos = fopen("arq_agendamentos.dat", "rb");
    
     // Crédito: Função adaptada do gemini;
    if (arq_agendamentos != NULL){
        
        fseek(arq_agendamentos, 0, SEEK_END);  
        
        long num_registros = ftell(arq_agendamentos) / sizeof(Agendamento);
        
        ag->id_agendamento = num_registros + 1;
        
        fclose(arq_agendamentos);
    }

    limpar_tela();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                             Agendamentos                                ///\n");
    printf("///                                                                         ///\n");
    printf("///                   = = = = = Cadastrar Agendamento = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///                         CPF do Paciente:                                ///\n");
    scanf("%s", ag->cpf); 
    getchar();
    printf("///                         Data (DD/MM/AAAA):                              ///\n");
    scanf("%s", ag->data); 
    getchar();
    printf("///                         Hora (HH:MM):                                   ///\n");
    scanf("%s", ag->hora); 
    getchar();
    printf("///                         Tipo de Agendamento:                            ///\n");
    scanf("%50[^\n]", ag->tipo); 
    getchar();
    printf("///                         Profissional Responsável:                       ///\n");
    scanf("%100[^\n]", ag->profissional); 
    getchar();
    printf("///                         Observações:                                    ///\n");
    scanf("%200[^\n]", ag->observacoes); 
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                  Agendamento Cadastrado com Sucesso !                   ///\n");
    printf("///                        ID gerado: %02d                                    ///\n", ag->id_agendamento);
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    
    ag->status = True;
    
    arq_agendamentos = fopen("arq_agendamentos.dat", "a+b");
    if (arq_agendamentos == NULL) {
        printf("Erro na criação do arquivo\n");
        return;
    }
    
    fwrite(ag, sizeof(Agendamento), 1, arq_agendamentos);
    fclose(arq_agendamentos);
    free(ag);
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
    FILE *arq_agendamentos;
    FILE *arq_agendamentos_temp;

    Agendamento ag;
    int id_busca;
    int encontrado = 0;
    char opcao;
    char continuar = 'S';
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
   
    arq_agendamentos = fopen("arq_agendamentos.csv", "rt");
    arq_agendamentos_temp = fopen("arq_agendamentos_temp.csv", "wt");

    if (arq_agendamentos == NULL || arq_agendamentos_temp == NULL){
        printf("Erro na criacao do arquivo\n");
        return;
    }

    while (fscanf(arq_agendamentos, "%d;%12[^;];%14[^;];%9[^;];%49[^;];%99[^;];%199[^\n]\n", &ag.id_agendamento, ag.cpf, ag.data, ag.hora, ag.tipo, ag.profissional, ag.observacoes) == 7) {
        if (ag.id_agendamento == id_busca){
            encontrado = 1;
            do{
                printf("\n    Dados atuais do agendamento    \n");
                printf("ID:              %d\n", ag.id_agendamento);
                printf("CPF do Paciente: %s\n", ag.cpf);
                printf("Data:            %s\n", ag.data);
                printf("Hora:            %s\n", ag.hora);
                printf("Tipo:            %s\n", ag.tipo);
                printf("Profissional:    %s\n", ag.profissional);
                printf("Observações:     %s\n", ag.observacoes);

                printf("\nQual campo deseja alterar?\n");
                printf("1. CPF do Paciente\n");
                printf("2. Data\n");
                printf("3. Hora\n");
                printf("4. Tipo\n");
                printf("5. Profissional\n");
                printf("6. Observações\n");
                printf("Escolha uma opção: ");
                scanf(" %c", &opcao);
                getchar();

                switch (opcao){
                    case '1':
                        printf("Novo CPF: ");
                        scanf("%13s", ag.cpf);
                        getchar();
                        break;
                    case '2':
                        printf("Nova Data (DD/MM/AAAA): ");
                        scanf("%15s", ag.data);
                        getchar();
                        break;
                    case '3':
                        printf("Nova Hora (HH:MM): ");
                        scanf("%10s", ag.hora);
                        getchar();
                        break;
                    case '4':
                        printf("Novo Tipo: ");
                        scanf("%50[^\n]", ag.tipo);
                        getchar();
                        break;
                    case '5':
                        printf("Novo Profissional: ");
                        scanf("%100[^\n]", ag.profissional);
                        getchar();
                        break;
                    case '6':
                        printf("Novas Observações: ");
                        scanf("%200[^\n]", ag.observacoes);
                        getchar();
                        break;
                    default:
                        printf("Opção inválida!\n");
                        break;
                }

                printf("\n    Dados atualizados    \n");
                printf("ID:              %d\n", ag.id_agendamento);
                printf("CPF do Paciente: %s\n", ag.cpf);
                printf("Data:            %s\n", ag.data);
                printf("Hora:            %s\n", ag.hora);
                printf("Tipo:            %s\n", ag.tipo);
                printf("Profissional:    %s\n", ag.profissional);
                printf("Observações:     %s\n", ag.observacoes);

                printf("\nDeseja alterar outro campo? (S/N): ");
                scanf(" %c", &continuar);
                continuar = confirmar_acao(continuar); 
            } while (continuar == 'S');
        }

        fprintf(arq_agendamentos_temp, "%d;%s;%s;%s;%s;%s;%s\n",ag.id_agendamento, ag.cpf, ag.data, ag.hora, ag.tipo, ag.profissional, ag.observacoes);
    }

    fclose(arq_agendamentos);
    fclose(arq_agendamentos_temp);

    if (encontrado){
        remove("arq_agendamentos.csv");
        rename("arq_agendamentos_temp.csv", "arq_agendamentos.csv");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                Agendamento alterado com sucesso!                        ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
    } else {
        remove("arq_agendamentos_temp.csv");
        printf("\nAgendamento não encontrado!\n");
    }
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