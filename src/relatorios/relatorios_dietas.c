#include "relatorios/relatorios_dietas.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dietas.h"
#include "uteis.h"

typedef struct DietaNode {
    Dieta dieta;
    struct DietaNode *prox;
} DietaNode;

void relatorios_dietas(void) {
    char opcao;

    do {
        limpar_tela();
        opcao = tela_relatorios_dietas();

        switch (opcao) {
            case '1':
                listar_dietas();
                break;
            case '2':
                listar_dietas_calorias();
                break;
            case '3':
                listar_dietas_ordenado_nome();
                break;
        }
    } while (opcao != '0');
}

char tela_relatorios_dietas(void) {
    char opcao;

    const char *menu = "1. Lista Geral de Dietas\n"
                       "2. Lista de Dietas por Calorias \n"
                       "3. Lista de Dietas Ordenada por Nome \n"
                       "0. Voltar ao Menu Anterior\n";

    exibir_moldura_titulo("Relatórios de Dietas");
    exibir_moldura_conteudo(menu);

    printf("Escolha a opção desejada: ");
    scanf(" %c", &opcao);
    limpar_buffer_entrada();

    return opcao;
}

void listar_dietas(void) {
    FILE *arq_dietas;
    Dieta *dt;

    dt = (Dieta *)malloc(sizeof(Dieta));

    arq_dietas = fopen("data/arq_dietas.dat", "rb");
    if (arq_dietas == NULL) {
        exibir_moldura_titulo("Nenhuma dieta cadastrada ainda");
        free(dt);
        return;
    }

    limpar_tela();
    exibir_moldura_titulo("Dietas - Lista Geral");
    printf("║ %-3s ║ %-20s ║ %-10s ║ %-31s \n", "ID", "Nome da Dieta", "Calorias", "Refeições");
    exibir_linha_separadora();

    bool encontrado = false;
    while (fread(dt, sizeof(Dieta), 1, arq_dietas)) {
        if (dt->status == true) {
            encontrado = true;
            printf("║ %-3d ║ %-20s ║ %-10.2f ║ %-31.31s \n",
                   dt->id_dieta,
                   dt->nome_dieta,
                   dt->calorias,
                   dt->refeicoes);
        }
    }

    if (!encontrado) {
        exibir_moldura_titulo("Nenhuma dieta ativa encontrada");
    }
    fclose(arq_dietas);
    free(dt);
    pausar();
}

void listar_dietas_calorias(void) {
    FILE *arq_dietas;
    Dieta *dt;

    dt = (Dieta *)malloc(sizeof(Dieta));
    bool encontrado = 0;

    int calorias_min;
    int calorias_max;

    limpar_tela();
    exibir_moldura_titulo("Dietas - Lista por Calorias");

    printf("Digite a quantidade mínima de calorias: ");
    scanf("%d", &calorias_min);

    printf("Digite a quantidade máxima de calorias: ");
    scanf("%d", &calorias_max);
    limpar_buffer_entrada();

    arq_dietas = fopen("data/arq_dietas.dat", "rb");
    if (arq_dietas == NULL) {
        exibir_moldura_titulo("Nenhuma dieta cadastrada ainda");
        free(dt);
        return;
    }

    printf("\n");
    printf("║ %-3s ║ %-20s ║ %-10s ║ %-31s \n", "ID", "Nome da Dieta", "Calorias", "Refeições");
    exibir_linha_separadora();

    while (fread(dt, sizeof(Dieta), 1, arq_dietas)) {
        if (dt->status) {
            if (dt->calorias >= calorias_min && dt->calorias <= calorias_max) {
                encontrado = 1;
                printf("║ %-3d ║ %-20s ║ %-10.2f ║ %-31.31s \n",
                       dt->id_dieta,
                       dt->nome_dieta,
                       dt->calorias,
                       dt->refeicoes);
            }
        }
    }

    if (!encontrado) {
        exibir_moldura_titulo("Nenhuma dieta encontrada nesse intervalo de calorias");
    }

    fclose(arq_dietas);
    free(dt);

    pausar();
}

void listar_dietas_ordenado_nome(void) {
    FILE *arq_dietas;
    Dieta dt;
    DietaNode *lista = NULL;
    DietaNode *novo, *ant, *atual;

    arq_dietas = fopen("data/arq_dietas.dat", "rb");
    if (arq_dietas == NULL) {
        exibir_moldura_titulo("Nenhuma dieta cadastrada ainda");
        pausar();
        return;
    }

    limpar_tela();
    exibir_moldura_titulo("Dietas - Lista Ordenada por Nome");

    while (fread(&dt, sizeof(Dieta), 1, arq_dietas)) {
        if (dt.status == true) {
            novo = (DietaNode *)malloc(sizeof(DietaNode));
            if (!novo) {
                // Libera memória em caso de erro
                while (lista) {
                    DietaNode *tmp = lista->prox;
                    free(lista);
                    lista = tmp;
                }
                break;
            }
            novo->dieta = dt;
            novo->prox = NULL;

            if (lista == NULL || strcmp(novo->dieta.nome_dieta, lista->dieta.nome_dieta) < 0) {
                novo->prox = lista;
                lista = novo;
            } else {
                ant = lista;
                atual = lista->prox;
                while (atual != NULL
                       && strcmp(atual->dieta.nome_dieta, novo->dieta.nome_dieta) < 0) {
                    ant = atual;
                    atual = atual->prox;
                }
                ant->prox = novo;
                novo->prox = atual;
            }
        }
    }
    fclose(arq_dietas);

    if (lista == NULL) {
        exibir_moldura_titulo("Nenhuma dieta ativa encontrada");
    } else {
        printf("║ %-3s ║ %-25s ║ %-10s ║ %-47s\n", "ID", "Nome da Dieta", "Calorias", "Refeições");
        exibir_linha_separadora();
        atual = lista;
        while (atual != NULL) {
            printf("║ %-3d ║ %-25s ║ %-10.2f ║ %-47.47s\n",
                   atual->dieta.id_dieta,
                   atual->dieta.nome_dieta,
                   atual->dieta.calorias,
                   atual->dieta.refeicoes);
            atual = atual->prox;
        }
    }

    // Libera memória da lista
    atual = lista;
    while (atual != NULL) {
        DietaNode *tmp = atual->prox;
        free(atual);
        atual = tmp;
    }

    pausar();
}