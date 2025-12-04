#include "relatorios/relatorios_pacientes.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pacientes.h"
#include "uteis.h"
#include "validacoes.h"

typedef struct PacienteNode {
    Paciente pac;
    struct PacienteNode *prox;
} PacienteNode;

// Função principal do submódulo de relatórios de pacientes
void relatorios_pacientes(void) {
    char opcao;

    do {
        limpar_tela();
        opcao = tela_relatorios_pacientes();

        switch (opcao) {
            case '1':
                listar_pacientes();
                break;
            case '2':
                listar_pacientes_por_faixa_idade();
                break;
            case '3':
                listar_pacientes_ordenado_nome();
                break;
        }

    } while (opcao != '0');
}

char tela_relatorios_pacientes(void) {
    char opcao;

    const char *menu = "1. Lista Geral de Pacientes\n"
                       "2. Filtrar Pacientes por Faixa de Idade\n"
                       "3. Listar Pacientes em Ordem Alfabética\n"
                       "0. Voltar ao Menu Anterior\n";

    exibir_moldura_titulo("Relatórios de Pacientes");
    exibir_moldura_conteudo(menu);

    printf("Escolha a opção desejada: ");
    scanf(" %c", &opcao);
    limpar_buffer_entrada();

    return opcao;
}

void listar_pacientes(void) {
    FILE *arq_paciente;
    Paciente *pac;

    pac = (Paciente *)malloc(sizeof(Paciente));
    bool encontrado = 0;

    limpar_tela();
    exibir_moldura_titulo("Pacientes - Lista Geral");

    printf("║ %-30s ║ %-12s ║ %-7s ║ %-6s ║ %-6s ║\n", "Nome", "CPF", "Idade", "Peso", "Altura");
    printf("═════════════════════════════════════════════════════════════════════════════\n");

    arq_paciente = fopen("data/arq_pacientes.dat", "rb");
    if (arq_paciente == NULL) {
        exibir_moldura_titulo("Nenhum paciente cadastrado ainda");
        free(pac);
        return;
    }

    while (fread(pac, sizeof(Paciente), 1, arq_paciente)) {
        if (pac->status) {
            encontrado = 1;
            printf("║ %-30s ║ %-12s ║ %7d ║ %6.2f ║ %6.2f ║\n",
                   pac->nome,
                   pac->cpf,
                   pac->idade,
                   pac->peso,
                   pac->altura);
        }
    }

    if (!encontrado) {
        exibir_moldura_titulo("Nenhum paciente ativo encontrado");
    }

    fclose(arq_paciente);
    free(pac);

    pausar();
}

void listar_pacientes_ordenado_nome(void) {
    FILE *arq;
    Paciente pac;
    PacienteNode *lista = NULL;
    PacienteNode *novo, *ant, *atual;

    arq = fopen("data/arq_pacientes.dat", "rb");
    if (arq == NULL) {
        exibir_moldura_titulo("Nenhum paciente cadastrado ainda");
        pausar();
        return;
    }

    // Monta a lista ordenada
    while (fread(&pac, sizeof(Paciente), 1, arq)) {
        if (!pac.status)
            continue;

        novo = (PacienteNode *)malloc(sizeof(PacienteNode));
        if (!novo) {
            // Libera a lista já criada antes de sair
            while (lista) {
                PacienteNode *tmp = lista->prox;
                free(lista);
                lista = tmp;
            }
            fclose(arq);
            exibir_moldura_titulo("Erro: memória insuficiente");
            pausar();
            return;
        }
        novo->pac = pac;
        novo->prox = NULL;

        if (lista == NULL || strcasecmp(novo->pac.nome, lista->pac.nome) < 0) {
            novo->prox = lista;
            lista = novo;
        } else {
            ant = lista;
            atual = lista->prox;
            while (atual != NULL && strcasecmp(atual->pac.nome, novo->pac.nome) < 0) {
                ant = atual;
                atual = atual->prox;
            }
            ant->prox = novo;
            novo->prox = atual;
        }
    }
    fclose(arq);

    // Exibe a lista
    limpar_tela();
    exibir_moldura_titulo("Pacientes - Lista Ordenada por Nome");
    if (lista == NULL) {
        exibir_moldura_titulo("Nenhum paciente ativo encontrado");
    } else {
        printf(
            "║ %-30s ║ %-12s ║ %-7s ║ %-6s ║ %-6s ║\n", "Nome", "CPF", "Idade", "Peso", "Altura");
        printf("═════════════════════════════════════════════════════════════════════════════\n");
        atual = lista;
        while (atual != NULL) {
            printf("║ %-30s ║ %-12s ║ %7d ║ %6.2f ║ %6.2f ║\n",
                   atual->pac.nome,
                   atual->pac.cpf,
                   atual->pac.idade,
                   atual->pac.peso,
                   atual->pac.altura);
            atual = atual->prox;
        }
    }

    // Libera memória da lista
    while (lista != NULL) {
        PacienteNode *tmp = lista->prox;
        free(lista);
        lista = tmp;
    }

    pausar();
}

void listar_pacientes_por_faixa_idade(void) {
    FILE *arq_paciente;
    Paciente *pac;
    bool encontrado = false;
    int idade_min, idade_max;

    pac = (Paciente *)malloc(sizeof(Paciente));

    limpar_tela();
    exibir_moldura_titulo("Pacientes - Filtrar por Faixa de Idade");

    printf("Digite a idade mínima: ");
    scanf("%d", &idade_min);
    printf("Digite a idade máxima: ");
    scanf("%d", &idade_max);
    limpar_buffer_entrada();  // Limpa o buffer

    arq_paciente = fopen("data/arq_pacientes.dat", "rb");
    if (arq_paciente == NULL) {
        exibir_moldura_titulo("Nenhum paciente cadastrado ainda");
        free(pac);
        pausar();
        return;
    }

    printf("\n");
    printf("║ %-30s ║ %-12s ║ %-7s ║ %-6s ║ %-6s ║\n", "Nome", "CPF", "Idade", "Peso", "Altura");
    printf("═════════════════════════════════════════════════════════════════════════════\n");

    while (fread(pac, sizeof(Paciente), 1, arq_paciente)) {
        if (pac->status && pac->idade >= idade_min && pac->idade <= idade_max) {
            encontrado = true;
            printf("║ %-30s ║ %-12s ║ %7d ║ %6.2f ║ %6.2f ║\n",
                   pac->nome,
                   pac->cpf,
                   pac->idade,
                   pac->peso,
                   pac->altura);
        }
    }

    if (!encontrado) {
        exibir_moldura_titulo("Nenhum paciente encontrado nessa faixa de idade");
    }

    fclose(arq_paciente);
    free(pac);
    pausar();
}