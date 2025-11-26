#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "agendamentos.h"
#include "validacoes.h"
#include "leituras.h"
#include "uteis.h"


void modulo_agendamentos(void) {
    char opcao;

    do {
        limpar_tela();
        opcao = tela_agendamentos();

        switch(opcao) {
            case '1':
                cadastrar_agendamento();
                break;
            case '2':
                buscar_agendamento();
                break;
            case '3':
                alterar_agendamento();
                break;
            case '4':
                excluir_agendamento();
                break;
            case '5':
                excluir_agendamento_fisico();
                break;
        }

    } while (opcao != '0');  
}


char tela_agendamentos(void){
    char opcao;

    const char *menu =
        "1. Cadastrar agendamento\n"
        "2. Buscar agendamento\n"
        "3. Alterar agendamento\n"
        "4. Excluir agendamento\n"
        "5. Excluir agendamento (físico)\n"
        "0. Voltar ao Menu Principal";

    exibir_moldura_titulo("Agendamentos");
    exibir_moldura_conteudo(menu);
    
    printf("Escolha a opção desejada: ");
    scanf("%c", &opcao);
    getchar();
    
    return opcao;
}


void cadastrar_agendamento(void){
    FILE * arq_agendamentos;
    Agendamento * ag;
    
    ag = (Agendamento*)malloc(sizeof(Agendamento));

    ag->id_agendamento = 1;
    arq_agendamentos = fopen("data/arq_agendamentos.dat", "rb");
    
     // Créditos: função adaptada do Gemini
    if (arq_agendamentos != NULL){
        fseek(arq_agendamentos, 0, SEEK_END);  

        long num_registros = ftell(arq_agendamentos) / sizeof(Agendamento);
        ag->id_agendamento = num_registros + 1;
        
        fclose(arq_agendamentos);
    }

    limpar_tela();
    exibir_moldura_titulo("Agendamentos - Cadastro");

    ler_cpf(ag->cpf);
    ler_data(ag->data);
    ler_hora(ag->hora);
    ler_tipo(ag->tipo);
    ler_profissional(ag->profissional);
    ler_observacoes(ag->observacoes);

    exibir_moldura_titulo("Agendamento cadastrado com sucesso");
    printf("ID gerado: %02d\n", ag->id_agendamento);
    ag->status = true;
    
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
    bool encontrado = false;

    ag = (Agendamento*)malloc(sizeof(Agendamento));

    limpar_tela();
    exibir_moldura_titulo("Agendamentos - Busca");
    printf("Informe o ID do Agendamento: ");
    scanf("%d", &id_busca);
    getchar();

    arq_agendamentos = fopen("data/arq_agendamentos.dat", "rb");

    if (arq_agendamentos == NULL){
        printf("Erro na criação do arquivo\n");
        return;
    }

    while(fread(ag, sizeof(Agendamento), 1, arq_agendamentos)){
        if ((ag->id_agendamento == id_busca) && (ag->status == true)){
            exibir_moldura_titulo("Agendamento encontrado");
            exibir_agendamento(ag);
            encontrado = true;
            break;
        }
    }

    if (encontrado == false){
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
    int valido;
    char opcao;
    char continuar;

    bool encontrado = false;

    ag = (Agendamento*)malloc(sizeof(Agendamento));

    limpar_tela();
    exibir_moldura_titulo("Agendamentos - Alteração");

    printf("Informe o ID do Agendamento: ");
    scanf("%d", &id_busca); 
    getchar();

    arq_agendamentos = fopen("data/arq_agendamentos.dat", "rb");
    arq_agendamentos_temp = fopen("data/arq_agendamentos_temp.dat", "wb");

    if (arq_agendamentos == NULL || arq_agendamentos_temp == NULL) {
        printf("Erro na criação do arquivo\n");
        return;
    }

     while (fread(ag, sizeof(Agendamento), 1, arq_agendamentos)) {
        if((ag->id_agendamento == id_busca) && (ag->status == true)){
            encontrado = true;
            do {
                limpar_tela();
                exibir_moldura_titulo("Agendamento - Dados Atuais");
                exibir_agendamento(ag);

                const char *menu_alt =
                    "\nQual campo deseja alterar?\n"
                    "1. CPF do Paciente\n"
                    "2. Data\n"
                    "3. Hora\n"
                    "4. Tipo\n"
                    "5. Profissional\n"
                    "6. Observações\n"
                    "Escolha uma opção: ";

                exibir_moldura_conteudo(menu_alt);
                scanf(" %c", &opcao);
                getchar();

                switch (opcao){
                    case '1':
                        do{
                            printf("Novo CPF do Paciente(Apenas Números):\n");
                            scanf("%s", ag->cpf); 
                            getchar();

                            valido = validar_cpf(ag->cpf);

                            if(valido == 0){
                                printf("CPF inválido! Digite novamente! \n");
                            }
                        } while (valido == 0);
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
                        do{
                            printf("Nova Hora (08:00 - 18:00): ");
                            scanf("%s", ag->hora); 
                            getchar();

                            valido = validar_hora(ag->hora);

                            if(valido == 0){
                                printf("Hora inválida! Digite novamente! \n");
                            }
                        } while (valido == 0);
                        break;
                    case '4':
                         do{
                            printf("Novo Tipo de Agendamento:\n");
                            scanf(" %50[^\n]", ag->tipo); 
                            getchar();

                            valido = validar_nome(ag->tipo);

                            if(valido == 0){
                                printf("Texto inválido! Digite novamente! \n");
                            }
                        } while (valido == 0);
                        break;
                    case '5':
                        do{
                            printf("Novo Profissional: \n");
                            scanf(" %50[^\n]", ag->profissional); 
                            getchar();

                            valido = validar_nome(ag->profissional);

                            if(valido == 0){
                                printf("Nome inválido! Digite novamente! \n");
                            }
                        } while (valido == 0);
                        break;
                    case '6':
                        do{
                            printf("Novas Observações: ");
                            scanf("%200[^\n]", ag->observacoes); 
                            getchar();

                            valido = validar_observacao(ag->observacoes);

                            if(valido == 0){
                                printf("Texto Digitado inválido! Digite novamente! \n");
                            }
                        } while (valido == 0);
                        break;
                    default:
                        printf("Opção inválida!\n");
                        break;
                }
                printf("\n    Dados atualizados    \n");
                exibir_agendamento(ag);

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

     if (encontrado == true){
        remove("data/arq_agendamentos.dat");
        rename("data/arq_agendamentos_temp.dat", "data/arq_agendamentos.dat");
        printf("Agendamento alterado com sucesso!\n");
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
    char resposta;

    bool encontrado = false;

    ag = (Agendamento*)malloc(sizeof(Agendamento));

    limpar_tela();
    exibir_moldura_titulo("Agendamentos - Exclusão");
    printf("Informe o ID do Agendamento: ");
    scanf("%d", &id_busca); 
    getchar();
    
    arq_agendamentos = fopen("data/arq_agendamentos.dat", "r+b");
    
    if (arq_agendamentos == NULL){
        printf("Erro na criação do arquivo\n");
        return;
        
    }

    while(fread(ag, sizeof(Agendamento),1, arq_agendamentos)){
        if((ag->id_agendamento == id_busca) && (ag->status == true)){
            exibir_moldura_titulo("Agendamento encontrado!");
            exibir_agendamento(ag);
            encontrado = true;

            do {
                printf("\nDeseja realmente excluir este Agendamento? (S/N): ");
                scanf(" %c", &resposta);
                resposta = confirmar_acao(resposta);
                
                if(resposta == 0){
                    printf("Opção inválida! Digite apenas S ou N.\n");
                }

            } while(resposta == 0);
        
            if (resposta == 'S'){
                ag->status = false;
                fseek(arq_agendamentos, (-1)*sizeof(Agendamento), SEEK_CUR);
                fwrite(ag, sizeof(Agendamento), 1, arq_agendamentos);
                printf("\nAgendamento excluído com sucesso!\n");

            } else {
                printf("\nOperação de exclusão cancelada.\n");
            }

            break;
        }
    }

    if (encontrado == false){
        printf("\nAgendamento não encontrado!\n");
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
    char resposta;

    bool excluido = false;
    bool encontrado = false;

    ag = (Agendamento*) malloc(sizeof(Agendamento));

    limpar_tela();
    exibir_moldura_titulo("Agendamentos - Exclusão Física");

    printf("Informe o ID do Agendamento: ");
    scanf("%d", &id_busca);
    getchar();


    arq_agendamentos = fopen("data/arq_agendamentos.dat", "rb");
    arq_agendamentos_temp = fopen("data/arq_agendamentos_temp.dat", "wb");

    if (arq_agendamentos == NULL || arq_agendamentos_temp == NULL) {
        printf("Erro ao abrir arquivos!\n");
        free(ag);
        return;
    }

    while (fread(ag, sizeof(Agendamento), 1, arq_agendamentos)) {
        if (ag->id_agendamento == id_busca) {
            printf("Agendamento encontrado!\n");
            exibir_agendamento(ag);
            encontrado = true;

            if (ag->status == false) {
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
                    excluido = true;

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

    if (encontrado == false) {
        printf("\nAgendamento não encontrado!\n");
        
    } else if (excluido == true) {
        printf("\nExclusão física concluída!\n");
    }

    pausar();
}


void exibir_agendamento(const Agendamento * ag){
    if (ag == NULL) {
        printf("Erro: agendamento inexistente!\n");
        return;
    }

    printf("ID:                %d\n", ag->id_agendamento);
    printf("CPF:               %s\n", ag->cpf);
    printf("Data:              %s\n", ag->data);
    printf("Hora:              %s\n", ag->hora);
    printf("Tipo:              %s\n", ag->tipo);
    printf("Profissional:      %s\n", ag->profissional);
    printf("Observações:       %s\n", ag->observacoes);
}