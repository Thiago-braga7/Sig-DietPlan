#include "relatorios/relatorios_profissionais.h"

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "profissionais.h"
#include "uteis.h"

typedef struct NovoProfissional {
    Profissional dados;
    struct NovoProfissional *prox;
} NovoProfissional;

// Função principal do módulo
void relatorios_profissionais(void) {
    char opcao;

    do {
        limpar_tela();
        opcao = tela_relatorios_profissionais();

        switch (opcao) {
            case '1':
                listar_profissionais();
                break;
            case '2':
                listar_profissionais_sexo();
                break;
            case '3':
                listar_profissionais_ordenado();
                break;
        }
    } while (opcao != '0');
}

char tela_relatorios_profissionais(void) {
    char opcao;

    const char *menu = "1. Lista Geral de Profissionais\n"
                       "2. Lista de Profissionais por Sexo \n"
                       "3. Lista de Profissionais Ordenada por Nome \n"
                       "0. Voltar ao Menu Anterior\n";

    exibir_moldura_titulo("Relatórios de Profissionais");
    exibir_moldura_conteudo(menu);

    printf("Escolha a opção desejada: ");
    scanf(" %c", &opcao);
    limpar_buffer_entrada();

    return opcao;
}

void listar_profissionais(void) {
    FILE *arq_profissionais;
    Profissional *pf;

    pf = (Profissional *)malloc(sizeof(Profissional));

    arq_profissionais = fopen("data/arq_profissionais.dat", "rb");
    if (arq_profissionais == NULL) {
        exibir_moldura_titulo("Nenhum profissional cadastrado ainda");
        free(pf);
        return;
    }

    limpar_tela();
    exibir_moldura_titulo("Profissionais - Lista Geral");
    printf("║ %-4s ║ %-30s ║ %-12s ║ %-12s ║ %-4s ║\n", "ID", "Nome", "CPF", "CRN", "Sexo");
    printf("══════════════════════════════════════════════════════════════════════════════════\n");

    bool encontrado = false;
    while (fread(pf, sizeof(Profissional), 1, arq_profissionais)) {
        if (pf->status == true) {
            encontrado = true;
            printf("║ %-4d ║ %-30s ║ %-12s ║ %-12s ║ %-4c ║\n",
                   pf->id_profissional,
                   pf->nome,
                   pf->cpf,
                   pf->crn,
                   pf->sexo);
        }
    }
    if (!encontrado) {
        exibir_moldura_titulo("Nenhum profissional ativo encontrado");
    }

    fclose(arq_profissionais);
    free(pf);

    pausar();
}

void listar_profissionais_ordenado(void) {
    FILE *arq_profissionais;
    Profissional pf;
    NovoProfissional *lista = NULL;
    NovoProfissional *novo, *ant, *atual;

    arq_profissionais = fopen("data/arq_profissionais.dat", "rb");
    if (arq_profissionais == NULL) {
        exibir_moldura_titulo("Nenhum profissional cadastrado ainda");
        return;
    }
    limpar_tela();
    exibir_moldura_titulo("Profissionais - Lista Ordenada por Nome");

    while (fread(&pf, sizeof(Profissional), 1, arq_profissionais)) {
        if (pf.status == true) {
            novo = (NovoProfissional *)malloc(sizeof(NovoProfissional));
            if (!novo)
                break;
            novo->dados = pf;
            novo->prox = NULL;

            if (lista == NULL || strcasecmp(novo->dados.nome, lista->dados.nome) < 0) {
                novo->prox = lista;
                lista = novo;
            } else {
                ant = lista;
                atual = lista->prox;
                while (atual != NULL && strcasecmp(atual->dados.nome, novo->dados.nome) < 0) {
                    ant = atual;
                    atual = atual->prox;
                }
                ant->prox = novo;
                novo->prox = atual;
            }
        }
    }
    fclose(arq_profissionais);

    if (lista == NULL) {
        exibir_moldura_titulo("Nenhum profissional ativo encontrado");
    } else {
        printf("║ %-4s ║ %-30s ║ %-12s ║ %-12s ║ %-4s ║\n", "ID", "Nome", "CPF", "CRN", "Sexo");
        printf(
            "══════════════════════════════════════════════════════════════════════════════════\n");
        atual = lista;
        while (atual != NULL) {
            printf("║ %-4d ║ %-30s ║ %-12s ║ %-12s ║ %-4c ║\n",
                   atual->dados.id_profissional,
                   atual->dados.nome,
                   atual->dados.cpf,
                   atual->dados.crn,
                   atual->dados.sexo);
            atual = atual->prox;
        }
    }

    // Libera memória da lista
    atual = lista;
    while (atual != NULL) {
        NovoProfissional *tmp = atual->prox;
        free(atual);
        atual = tmp;
    }

    pausar();
}

void listar_profissionais_sexo(void) {
    FILE *arq;
    Profissional *pf;
    char sexo_busca;
    bool encontrado = false;

    pf = (Profissional *)malloc(sizeof(Profissional));
    if (!pf)
        return;

    limpar_tela();
    exibir_moldura_titulo("Profissionais - Lista por Sexo");

    printf("Digite o sexo para buscar (M/F/O): ");
    scanf(" %c", &sexo_busca);
    sexo_busca = toupper((unsigned char)sexo_busca);
    limpar_buffer_entrada();

    arq = fopen("data/arq_profissionais.dat", "rb");
    if (arq == NULL) {
        exibir_moldura_titulo("Nenhum profissional cadastrado ainda");
        free(pf);
        return;
    }

    printf("\n");
    printf("║ %-4s ║ %-30s ║ %-12s ║ %-12s ║ %-4s ║\n", "ID", "Nome", "CPF", "CRN", "Sexo");
    printf("══════════════════════════════════════════════════════════════════════════════════\n");

    while (fread(pf, sizeof(Profissional), 1, arq)) {
        if (pf->status && pf->sexo == sexo_busca) {
            encontrado = true;
            printf("║ %-4d ║ %-30s ║ %-12s ║ %-12s ║ %-4c ║\n",
                   pf->id_profissional,
                   pf->nome,
                   pf->cpf,
                   pf->crn,
                   pf->sexo);
        }
    }

    if (!encontrado) {
        exibir_moldura_titulo("Nenhum profissional encontrado para esse sexo");
    }

    fclose(arq);
    free(pf);
    pausar();
}