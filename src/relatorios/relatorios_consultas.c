#include "relatorios/relatorios_consultas.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "consultas.h"
#include "uteis.h"

// Protótipos de funções estáticas
static char tela_relatorios_consultas(void);
static void listar_consultas(void);
static void listar_consultas_medico(void);

void relatorios_consultas(void) {
    char opcao;

    do {
        limpar_tela();
        opcao = tela_relatorios_consultas();

        switch (opcao) {
            case '1':
                listar_consultas();
                break;
            case '2':
                listar_consultas_medico();
                break;
        }
    } while (opcao != '0');
}

static char tela_relatorios_consultas(void) {
    char opcao;

    const char *menu = "1. Lista Geral de Consultas\n"
                       "2. Lista de Consultas por Médico \n"
                       "0. Voltar ao Menu Anterior\n";

    exibir_moldura_titulo("Relatórios de Consultas");
    exibir_moldura_conteudo(menu);

    printf("Escolha a opção desejada: ");
    scanf(" %c", &opcao);
    getchar();

    return opcao;
}

static void listar_consultas(void) {
    FILE *arq_consulta;
    Consulta *con;
    bool encontrado = false;

    con = (Consulta *)malloc(sizeof(Consulta));

    arq_consulta = fopen("data/arq_consulta.dat", "rb");

    if (arq_consulta == NULL) {
        exibir_moldura_titulo("Nenhuma consulta cadastrada ainda");
        free(con);
        pausar();
        return;
    }

    limpar_tela();
    exibir_moldura_titulo("Consultas - Lista Geral");

    while (fread(con, sizeof(Consulta), 1, arq_consulta)) {
        if (con->status == true) {
            encontrado = true;
            printf("\n");
            exibir_consulta(con);
            printf("\n");
            printf("═══════════════════════════════════════════════════════════════════════════"
                   "═\n");
        }
    }

    if (!encontrado) {
        exibir_moldura_titulo("Nenhuma consulta ativa encontrada");
    }

    fclose(arq_consulta);
    free(con);

    pausar();
}

static void listar_consultas_medico(void) {
    FILE *arq_consulta;
    Consulta *con;
    bool encontrado = false;

    con = (Consulta *)malloc(sizeof(Consulta));

    char med_busca[50];

    limpar_tela();
    exibir_moldura_titulo("Consultas - Lista por Médico");

    printf("Digite o nome do médico: ");
    scanf("%49[^\n]", med_busca);
    getchar();

    arq_consulta = fopen("data/arq_consulta.dat", "rb");

    if (arq_consulta == NULL) {
        exibir_moldura_titulo("Nenhuma consulta cadastrada ainda");
        free(con);
        pausar();
        return;
    }

    while (fread(con, sizeof(Consulta), 1, arq_consulta)) {
        if (con->status == true && strcmp(med_busca, con->medico) == 0) {
            encontrado = true;
            printf("\n");
            exibir_consulta(con);
            printf(
                "\n════════════════════════════════════════════════════════════════════════════\n");
        }
    }

    if (!encontrado) {
        exibir_moldura_titulo("Nenhuma consulta encontrada para este médico");
    }

    fclose(arq_consulta);
    free(con);

    pausar();
}