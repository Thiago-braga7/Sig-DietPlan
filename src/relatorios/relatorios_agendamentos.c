#include "relatorios/relatorios_agendamentos.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "agendamentos.h"
#include "pacientes.h"
#include "uteis.h"

typedef struct AgendamentoNode {
    Agendamento ag;
    struct AgendamentoNode *prox;
} AgendamentoNode;

void relatorios_agendamentos(void) {
    char opcao;

    do {
        limpar_tela();
        opcao = tela_relatorios_agendamentos();

        switch (opcao) {
            case '1':
                listar_agendamentos();
                break;
            case '2':
                listar_agendamentos_paciente();
                break;
            case '3':
                listar_agendamentos_ordenado();
                break;
        }
    } while (opcao != '0');
}

char tela_relatorios_agendamentos(void) {
    char opcao;

    const char *menu = "1. Lista Geral de Agendamentos\n"
                       "2. Lista de Agendamentos por Paciente \n"
                       "3. Lista de Agendamentos Ordenada por ID \n"
                       "0. Voltar ao Menu Anterior\n";

    exibir_moldura_titulo("Relatórios de Agendamentos");
    exibir_moldura_conteudo(menu);

    printf("Escolha a opção desejada: ");
    scanf(" %c", &opcao);
    limpar_buffer_entrada();

    return opcao;
}

void listar_agendamentos(void) {
    FILE *arq_agendamentos;
    Agendamento *ag;

    ag = (Agendamento *)malloc(sizeof(Agendamento));

    arq_agendamentos = fopen("data/arq_agendamentos.dat", "rb");
    if (arq_agendamentos == NULL) {
        exibir_moldura_titulo("Nenhum agendamento cadastrado ainda");
        free(ag);
        return;
    }

    limpar_tela();
    exibir_moldura_titulo("Agendamentos - Lista Geral");
    printf(
        "║ %-4s ║ %-12s ║ %-11s ║ %-8s ║ %-20s ║\n", "ID", "CPF", "Data", "Hora", "Profissional");
    exibir_linha_separadora();

    bool encontrado = false;
    while (fread(ag, sizeof(Agendamento), 1, arq_agendamentos)) {
        if (ag->status == true) {
            encontrado = true;
            printf("║ %-4d ║ %-12s ║ %-11s ║ %-8s ║ %-20s ║\n",
                   ag->id_agendamento,
                   ag->cpf,
                   ag->data,
                   ag->hora,
                   ag->profissional);
        }
    }

    if (!encontrado) {
        exibir_moldura_titulo("Nenhum agendamento ativo encontrado");
    }
    fclose(arq_agendamentos);
    free(ag);

    pausar();
}

void listar_agendamentos_paciente(void) {
    FILE *arq_agendamentos;
    FILE *arq_pacientes;
    Agendamento *ag;
    Paciente *pac;

    ag = (Agendamento *)malloc(sizeof(Agendamento));
    pac = (Paciente *)malloc(sizeof(Paciente));

    char cpf_busca[13];

    limpar_tela();
    exibir_moldura_titulo("Agendamentos - Lista por CPF");

    printf("Digite o CPF do paciente (Apenas Números): ");
    scanf("%s", cpf_busca);
    limpar_buffer_entrada();

    printf("║ %-30s ║ %15s ║ %11s ║ %7s ║ %10s ║ %12s ║ %14s ║\n",
           "Nome",
           "ID Agendamento",
           "Data",
           "Hora",
           "Tipo",
           "Profissional",
           "Observações");
    exibir_linha_separadora();

    arq_agendamentos = fopen("data/arq_agendamentos.dat", "rb");
    if (arq_agendamentos == NULL) {
        exibir_moldura_titulo("Nenhum agendamento cadastrado ainda");
        free(ag);
        free(pac);
        return;
    }

    bool encontrado = 0;

    while (fread(ag, sizeof(Agendamento), 1, arq_agendamentos)) {
        if (ag->status) {
            if (strcmp(ag->cpf, cpf_busca) == 0) {
                encontrado = 1;

                arq_pacientes = fopen("data/arq_pacientes.dat", "rb");

                if (arq_pacientes != NULL) {
                    while (fread(pac, sizeof(Paciente), 1, arq_pacientes)) {
                        if (pac->status && strcmp(pac->cpf, cpf_busca) == 0) {
                            break;
                        }
                    }
                    fclose(arq_pacientes);
                }

                printf("║ %-30s ║ %15d ║ %11s ║ %7s ║ %10s ║ %12s ║ %12s ║\n",
                       pac->nome,
                       ag->id_agendamento,
                       ag->data,
                       ag->hora,
                       ag->tipo,
                       ag->profissional,
                       ag->observacoes);
                exibir_linha_separadora();
            }
        }
    }

    if (!encontrado) {
        exibir_moldura_titulo("Nenhum agendamento encontrado para esse CPF");
    }

    fclose(arq_agendamentos);
    free(ag);
    free(pac);
    pausar();
}

void listar_agendamentos_ordenado(void) {
    FILE *arq;
    Agendamento ag;
    AgendamentoNode *lista = NULL;
    AgendamentoNode *novo, *ant, *atual;

    arq = fopen("data/arq_agendamentos.dat", "rb");
    if (arq == NULL) {
        exibir_moldura_titulo("Nenhum agendamento cadastrado ainda");
        pausar();
        return;
    }
    limpar_tela();
    exibir_moldura_titulo("Agendamentos - Lista Ordenada por ID");

    while (fread(&ag, sizeof(Agendamento), 1, arq)) {
        if (!ag.status)
            continue;

        novo = (AgendamentoNode *)malloc(sizeof(AgendamentoNode));
        if (!novo) {
            // Libera a lista já criada antes de sair
            atual = lista;
            while (atual) {
                AgendamentoNode *tmp = atual->prox;
                free(atual);
                atual = tmp;
            }
            fclose(arq);
            exibir_moldura_titulo("Erro: memória insuficiente");
            pausar();
            return;
        }
        novo->ag = ag;
        novo->prox = NULL;

        if (lista == NULL || novo->ag.id_agendamento < lista->ag.id_agendamento) {
            novo->prox = lista;
            lista = novo;
        } else {
            ant = lista;
            atual = lista->prox;
            while (atual != NULL && atual->ag.id_agendamento <= novo->ag.id_agendamento) {
                ant = atual;
                atual = atual->prox;
            }
            ant->prox = novo;
            novo->prox = atual;
        }
    }
    fclose(arq);

    if (lista == NULL) {
        exibir_moldura_titulo("Nenhum agendamento ativo encontrado");
    } else {
        printf("║ %-4s ║ %-12s ║ %-11s ║ %-8s ║ %-20s ║\n",
               "ID",
               "CPF",
               "Data",
               "Hora",
               "Profissional");
        exibir_linha_separadora();
        atual = lista;
        while (atual != NULL) {
            printf("║ %-4d ║ %-12s ║ %-11s ║ %-8s ║ %-20s ║\n",
                   atual->ag.id_agendamento,
                   atual->ag.cpf,
                   atual->ag.data,
                   atual->ag.hora,
                   atual->ag.profissional);
            atual = atual->prox;
        }
    }

    // Libera memória da lista
    atual = lista;
    while (atual != NULL) {
        AgendamentoNode *tmp = atual->prox;
        free(atual);
        atual = tmp;
    }
    pausar();
}