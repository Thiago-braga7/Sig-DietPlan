#include <stdio.h>
#include <stdlib.h>
#include "agendamentos.h"
#include "validacoes.h"
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
            case '5': listar_agendamentos(); break;
            case '6': excluir_agendamento_fisico(); break;
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
    printf("///                    5. Listar Agendamentos                               ///\n");
    printf("///                    6. Excluir Agendamento(Físico)                       ///\n");
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
    arq_agendamentos = fopen("data/arq_agendamentos.dat", "rb");
    
     // Crédito: Função adaptada do gemini;
    if (arq_agendamentos != NULL){
        
        fseek(arq_agendamentos, 0, SEEK_END);  
        
        long num_registros = ftell(arq_agendamentos) / sizeof(Agendamento);
        
        ag->id_agendamento = num_registros + 1;
        
        fclose(arq_agendamentos);
    }
    int valido;

    limpar_tela();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                             Agendamentos                                ///\n");
    printf("///                                                                         ///\n");
    printf("///                   = = = = = Cadastrar Agendamento = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///                         CPF do Paciente:                                ///\n");
    scanf("%s", ag->cpf); 
    getchar();
    do{
        printf("///                         Data (DDMMAAAA):                                ///\n");
        scanf("%s", ag->data); 
        getchar();

        valido = valida_data(ag->data);

        if(valido == 0){
            printf("Data inválida! Digite novamente! \n");
        }
    } while (valido == 0);
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
    
    arq_agendamentos = fopen("data/arq_agendamentos.dat", "a+b");
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
    FILE * arq_agendamentos;
    Agendamento * ag;
    int id_busca;
    int encontrado;

    ag = (Agendamento*)malloc(sizeof(Agendamento));

    limpar_tela();
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
    encontrado = False;
    arq_agendamentos = fopen("data/arq_agendamentos.dat", "rb");

    if (arq_agendamentos == NULL){
        printf("Erro na criação do arquivo\n");
        return;
    }

    while(fread(ag, sizeof(Agendamento), 1, arq_agendamentos)){
        if ((ag->id_agendamento == id_busca) && (ag->status == True)){
            printf("///                        Agendamento Encontrado!                        ///\n");
            printf("ID:                %d\n", ag->id_agendamento);
            printf("CPF:               %s\n", ag->cpf);
            printf("Data:              %s\n", ag->data);
            printf("Hora:              %s\n", ag->hora);
            printf("Tipo:              %s\n", ag->tipo);
            printf("Profissional:      %s\n", ag->profissional);
            printf("Observações:       %s\n", ag->observacoes);

           encontrado = True;
           break;
        }
    }
    if (encontrado == False){
        printf("\nAgendamento não encontrado!\n");
    }

    fclose(arq_agendamentos);
    free(ag);
    pausar();
}

void alterar_agendamento(void){
    FILE * arq_agendamentos;
    FILE * arq_agendamentos_temp;

    Agendamento * ag;
    int id_busca;
    int encontrado;
    char opcao;
    char continuar;
    int valido;

    ag = (Agendamento*)malloc(sizeof(Agendamento));

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
    encontrado = False;

    
    arq_agendamentos = fopen("data/arq_agendamentos.dat", "rb");
    arq_agendamentos_temp = fopen("data/arq_agendamentos_temp.dat", "wb");

    if (arq_agendamentos == NULL || arq_agendamentos_temp == NULL){
        printf("Erro na criação do arquivo\n");
        return;
    }


     while (fread(ag, sizeof(Agendamento), 1, arq_agendamentos)){
        if((ag->id_agendamento == id_busca) && (ag->status == True)){
            encontrado = True;
            do{
                limpar_tela();
                printf("\n    Dados atuais do agendamento    \n");
                printf("ID:              %d\n", ag->id_agendamento);
                printf("CPF do Paciente: %s\n", ag->cpf);
                printf("Data:            %s\n", ag->data);
                printf("Hora:            %s\n", ag->hora);
                printf("Tipo:            %s\n", ag->tipo);
                printf("Profissional:    %s\n", ag->profissional);
                printf("Observações:     %s\n", ag->observacoes);

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
                        scanf("%13s", ag->cpf);
                        getchar();
                        break;
                    case '2':
                        do{
                            printf("Nova Data (DDMMAAAA): ");
                            scanf("%s", ag->data);
                            getchar();

                            valido = valida_data(ag->data);

                            if(valido == 0){
                                printf("Data inválida! Digite novamente! \n");
                            }
                        } while (valido == 0);
                        break;
                    case '3':
                        printf("Nova Hora (HH:MM): ");
                        scanf("%10s", ag->hora);
                        getchar();
                        break;
                    case '4':
                        printf("Novo Tipo: ");
                        scanf("%50[^\n]", ag->tipo);
                        getchar();
                        break;
                    case '5':
                        printf("Novo Profissional: ");
                        scanf("%100[^\n]", ag->profissional);
                        getchar();
                        break;
                    case '6':
                        printf("Novas Observações: ");
                        scanf("%200[^\n]", ag->observacoes);
                        getchar();
                        break;
                    default:
                        printf("Opção inválida!\n");
                        break;
                }
                printf("\n    Dados atualizados    \n");
                printf("ID:              %d\n", ag->id_agendamento);
                printf("CPF do Paciente: %s\n", ag->cpf);
                printf("Data:            %s\n", ag->data);
                printf("Hora:            %s\n", ag->hora);
                printf("Tipo:            %s\n", ag->tipo);
                printf("Profissional:    %s\n", ag->profissional);
                printf("Observações:     %s\n", ag->observacoes);

                printf("\nDeseja alterar outro campo? (S/N): ");
                scanf(" %c", &continuar);
                continuar = confirmar_acao(continuar); 
                if(continuar == 0){
                    printf("Opção inválida! Digite apenas S ou N.\n");
                }
            } while (continuar == 'S');
        }
        fwrite(ag, sizeof(Agendamento), 1, arq_agendamentos_temp);
    }

    fclose(arq_agendamentos);
    fclose(arq_agendamentos_temp);

     if (encontrado == True){
        remove("data/arq_agendamentos.dat");
        rename("data/arq_agendamentos_temp.dat", "data/arq_agendamentos.dat");
        printf("///                    Paciente alterado com sucesso!                       ///\n");
    } else {
        remove("data/arq_agendamentos_temp.dat");
        printf("\nAgendamento não encontrado!\n");
    }
    free(ag);
    pausar();
}
void excluir_agendamento(void){
    FILE * arq_agendamentos;
    Agendamento * ag;
    int id_busca;
    int encontrado;
    char resposta;

    ag = (Agendamento*)malloc(sizeof(Agendamento));

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
    encontrado = False;
    
    arq_agendamentos = fopen("data/arq_agendamentos.dat", "r+b");
    
    if (arq_agendamentos == NULL){
        printf("Erro na criação do arquivo\n");
        return;
        
    }

    while(fread(ag, sizeof(Agendamento),1, arq_agendamentos)){
        if((ag->id_agendamento == id_busca) && (ag->status == True)){
            printf("///                        Agendamemto Encontrado!                       ///\n");
            printf("ID:                %d\n", ag->id_agendamento);
            printf("CPF:               %s\n", ag->cpf);
            printf("Data:              %s\n", ag->data);
            printf("Hora:              %s\n", ag->hora);
            printf("Tipo:              %s\n", ag->tipo);
            printf("Profissional:      %s\n", ag->profissional);
            printf("Observações:       %s\n", ag->observacoes);
            encontrado = True;

        do {
            printf("\nDeseja realmente excluir este Agendamento? (S/N): ");
            scanf(" %c", &resposta);
            resposta = confirmar_acao(resposta);
            
            if(resposta == 0){
                printf("Opção inválida! Digite apenas S ou N.\n");
            }
        } while(resposta == 0);
          if (resposta == 'S'){
                ag->status = False;
                fseek(arq_agendamentos, (-1)*sizeof(Agendamento), SEEK_CUR);
                fwrite(ag, sizeof(Agendamento), 1, arq_agendamentos);
                printf("\nAgendamento excluído com sucesso!\n");
            } else{
                printf("\nOperação de exclusão cancelada.\n");
            }
            break;
        }
    }
    if (encontrado == False){
        printf("\nAgendamento não encontrado!\n");
    }
    fclose(arq_agendamentos);
    free(ag);
    pausar();
}
void listar_agendamentos(void){
    FILE * arq_agendamentos;
    Agendamento * ag;

    ag = (Agendamento*) malloc(sizeof(Agendamento));
    
    arq_agendamentos = fopen("data/arq_agendamentos.dat", "rb");
    if (arq_agendamentos == NULL) {
        printf("Nenhum Agendamento cadastrado ainda.\n");
        free(ag);
        return;
    }

    limpar_tela();
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                               Agendamentos                              ///\n");
    printf("///                                                                         ///\n");
    printf("///                  = = = = =  Listar Agendamentos  = = = = =              ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    while(fread(ag, sizeof(Agendamento), 1, arq_agendamentos)){
        if (ag->status == True){
            printf("ID:                %d\n", ag->id_agendamento);
            printf("CPF:               %s\n", ag->cpf);
            printf("Data:              %s\n", ag->data);
            printf("Hora:              %s\n", ag->hora);
            printf("Tipo:              %s\n", ag->tipo);
            printf("Profissional:      %s\n", ag->profissional);
            printf("Observações:       %s\n", ag->observacoes);
            printf("--------------------------------------------------\n");
        }
    }

    fclose(arq_agendamentos);
    free(ag);

    pausar();
}
void excluir_agendamento_fisico(void) {
    FILE *arq_agendamentos;
    FILE *arq_agendamentos_temp;
    Agendamento *ag;
    int id_busca;
    int encontrado;
    int excluido;
    char resposta;

    ag = (Agendamento*) malloc(sizeof(Agendamento));

    limpar_tela();
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                             Agendamentos                                ///\n");
    printf("///                                                                         ///\n");
    printf("///              = = = = = Exclusão Física de Agendamento = = = = =         ///\n");
    printf("///                                                                         ///\n");
    printf("///                    Informe o ID do Agendamento: ");
    scanf("%d", &id_busca);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");

    encontrado = False;
    excluido = False;

    arq_agendamentos = fopen("data/arq_agendamentos.dat", "rb");
    arq_agendamentos_temp = fopen("data/arq_agendamentos_temp.dat", "wb");

    if (arq_agendamentos == NULL || arq_agendamentos_temp == NULL) {
        printf("Erro ao abrir arquivos!\n");
        free(ag);
        return;
    }

    while (fread(ag, sizeof(Agendamento), 1, arq_agendamentos)) {
        if (ag->id_agendamento == id_busca) {
            printf("///                        Agendamento Encontrado!                          ///\n");
            printf("ID:                %d\n", ag->id_agendamento);
            printf("CPF:               %s\n", ag->cpf);
            printf("Data:              %s\n", ag->data);
            printf("Hora:              %s\n", ag->hora);
            printf("Tipo:              %s\n", ag->tipo);
            printf("Profissional:      %s\n", ag->profissional);
            printf("Observações:       %s\n", ag->observacoes);
            encontrado = True;

            if (ag->status == False) {
                do {
                    printf("\nDeseja realmente excluir este Agendamento (fisicamente)? (S/N): ");
                    scanf(" %c", &resposta);
                    resposta = confirmar_acao(resposta);

                    if (resposta == 0) {
                        printf("Opção inválida! Digite apenas S ou N.\n");
                    }
                } while (resposta == 0);

                if (resposta == 'S') {
                    printf("\nAgendamento excluído fisicamente com sucesso!\n");
                    excluido = True;
                } else {
                    printf("\nOperação cancelada. O agendamento foi mantido.\n");
                    fwrite(ag, sizeof(Agendamento), 1, arq_agendamentos_temp);
                }
            } else {
                printf("\nO agendamento está ativo, portanto não pode ser excluído fisicamente.\n");
                fwrite(ag, sizeof(Agendamento), 1, arq_agendamentos_temp);
            }
        } else {
            fwrite(ag, sizeof(Agendamento), 1, arq_agendamentos_temp);
        }
    }

    fclose(arq_agendamentos);
    fclose(arq_agendamentos_temp);
    free(ag);

    remove("data/arq_agendamentos.dat");
    rename("data/arq_agendamentos_temp.dat", "data/arq_agendamentos.dat");

    if (encontrado == False) {
        printf("\nAgendamento não encontrado!\n");
    } else if (excluido == True) {
        printf("\nExclusão física concluída!\n");
    }

    pausar();
}
