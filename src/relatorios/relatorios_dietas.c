#include "relatorios/relatorios_dietas.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "dietas.h"
#include "uteis.h"

// Protótipos de funções estáticas
static char tela_relatorios_dietas(void);
static void listar_dietas(void);
static void listar_dietas_calorias(void);

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
        }
    } while (opcao != '0');
}

static char tela_relatorios_dietas(void) {
    char opcao;

    const char *menu = "1. Lista Geral de Dietas\n"
                       "2. Lista de Dietas por Calorias \n"
                       "0. Voltar ao Menu Anterior\n";

    exibir_moldura_titulo("Relatórios de Dietas");
    exibir_moldura_conteudo(menu);

    printf("Escolha a opção desejada: ");
    scanf(" %c", &opcao);
    getchar();

    return opcao;
}

static void listar_dietas(void) {
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

    while (fread(dt, sizeof(Dieta), 1, arq_dietas)) {
        if (dt->status == true) {
            printf("\n");
            exibir_dieta(dt);
            printf("\n");
            printf("═══════════════════════════════════════════════════════════════════════════"
                   "═\n");
        }
    }

    fclose(arq_dietas);
    free(dt);
    pausar();
}

static void listar_dietas_calorias(void) {
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

    arq_dietas = fopen("data/arq_dietas.dat", "rb");
    if (arq_dietas == NULL) {
        exibir_moldura_titulo("Nenhuma dieta cadastrada ainda");
        free(dt);
        return;
    }

    while (fread(dt, sizeof(Dieta), 1, arq_dietas)) {
        if (dt->status) {
            if (dt->calorias >= calorias_min && dt->calorias <= calorias_max) {
                encontrado = 1;
                printf("\n");
                exibir_dieta(dt);
                printf("\n");
                printf("═══════════════════════════════════════════════════════════════════════"
                       "═════\n");
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