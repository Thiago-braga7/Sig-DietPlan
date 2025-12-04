#include "relatorios/relatorios_profissionais.h"

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "profissionais.h"
#include "uteis.h"

// Estrutura para a lista encadeada usada na ordenação
typedef struct NovoProfissional {
    Profissional dados;
    struct NovoProfissional *prox;
} NovoProfissional;

// Protótipos de funções estáticas (visíveis apenas neste arquivo)
static char tela_relatorios_profissionais(void);
static void listar_profissionais(void);
static void listar_profissionais_sexo(void);
static void listar_profissionais_ordenado(void);

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

static char tela_relatorios_profissionais(void) {
    char opcao;

    const char *menu = "1. Lista Geral de Profissionais\n"
                       "2. Lista de Profissionais por Sexo \n"
                       "3. Lista de Profissionais Ordenada por Nome \n"
                       "0. Voltar ao Menu Anterior\n";

    exibir_moldura_titulo("Relatórios de Profissionais");
    exibir_moldura_conteudo(menu);

    printf("Escolha a opção desejada: ");
    scanf(" %c", &opcao);
    getchar();

    return opcao;
}

static void listar_profissionais(void) {
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

    while (fread(pf, sizeof(Profissional), 1, arq_profissionais)) {
        if (pf->status == true) {
            printf("\n");
            exibir_profissional(pf);
            printf("\n");
            printf("═══════════════════════════════════════════════════════════════════════════"
                   "═\n");
        }
    }

    fclose(arq_profissionais);
    free(pf);

    pausar();
}

static void listar_profissionais_ordenado(void) {
    FILE *arq_profissionais;
    Profissional *pf;
    NovoProfissional *lista = NULL;
    NovoProfissional *novo, *ant, *atual;

    pf = (Profissional *)malloc(sizeof(Profissional));
    if (!pf)
        return;

    arq_profissionais = fopen("data/arq_profissionais.dat", "rb");
    if (arq_profissionais == NULL) {
        exibir_moldura_titulo("Nenhum profissional cadastrado ainda");
        free(pf);
        return;
    }

    limpar_tela();
    exibir_moldura_titulo("Profissionais - Lista Ordenada por Nome");

    while (fread(pf, sizeof(Profissional), 1, arq_profissionais)) {
        if (pf->status == true) {
            novo = (NovoProfissional *)malloc(sizeof(NovoProfissional));
            if (!novo)
                break;
            novo->dados = *pf;
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
    free(pf);

    if (lista == NULL) {
        exibir_moldura_titulo("Nenhum profissional ativo encontrado");
    } else {
        atual = lista;
        while (atual != NULL) {
            printf("\n");
            exibir_profissional(&atual->dados);
            printf(
                "\n════════════════════════════════════════════════════════════════════════════\n");
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

static void listar_profissionais_sexo(void) {
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
    while (getchar() != '\n')
        ;

    arq = fopen("data/arq_profissionais.dat", "rb");
    if (arq == NULL) {
        exibir_moldura_titulo("Nenhum profissional cadastrado ainda");
        free(pf);
        return;
    }

    while (fread(pf, sizeof(Profissional), 1, arq)) {
        if (pf->status && pf->sexo == sexo_busca) {
            encontrado = true;
            printf("\n");
            exibir_profissional(pf);
            printf("\n═════════════════════════════════════════════════════════════════════════"
                   "═══\n");
        }
    }

    if (!encontrado) {
        exibir_moldura_titulo("Nenhum profissional encontrado para esse sexo");
    }

    fclose(arq);
    free(pf);
    pausar();
}