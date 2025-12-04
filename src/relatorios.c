#include "relatorios.h"

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "agendamentos.h"
#include "consultas.h"
#include "dietas.h"
#include "leituras.h"
#include "pacientes.h"
#include "profissionais.h"
#include "relatorios/relatorios_agendamentos.h"
#include "relatorios/relatorios_dietas.h"
#include "relatorios/relatorios_pacientes.h"
#include "relatorios/relatorios_profissionais.h"
#include "uteis.h"
#include "validacoes.h"

// CRUDS de relatórios
void modulo_relatorios(void) {
    char opcao;

    do {
        limpar_tela();
        opcao = tela_relatorios();

        switch (opcao) {
            case '1':
                relatorios_pacientes();
                break;
            case '2':
                relatorios_dietas();
                break;
            case '3':
                relatorios_profissionais();
                break;
            case '4':
                relatorios_consultas();
                break;
            case '5':
                relatorios_agendamentos();
                break;
        }
    } while (opcao != '0');
}


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


// Telas de relatórios
char tela_relatorios(void) {
    char opcao;

    const char *menu = "1. Relatórios de Pacientes\n"
                       "2. Relatórios de Dietas\n"
                       "3. Relatórios de Profissionais\n"
                       "4. Relatórios de Consultas\n"
                       "5. Relatórios de Agendamentos\n"
                       "0. Voltar ao Menu Principal\n";

    exibir_moldura_titulo("Relatórios");
    exibir_moldura_conteudo(menu);

    printf("Escolha a opção desejada: ");
    scanf(" %c", &opcao);
    getchar();

    return opcao;
}


char tela_relatorios_consultas(void) {
    char opcao;

    const char *menu = "1. Lista Geral de Consultas\n"
                       "2. Lista de Consultas por Médico \n"
                       "0. Voltar ao Menu Anterior\n";

    exibir_moldura_titulo("Relatórios");
    exibir_moldura_conteudo(menu);

    printf("Escolha a opção desejada: ");
    printf("Escolha a opção desejada: ");
    scanf(" %c", &opcao);
    getchar();

    return opcao;
}


// Lista todas as consultas ativas
void listar_consultas(void) {
    FILE *arq_consulta;
    Consulta *con;

    con = (Consulta *)malloc(sizeof(Consulta));

    arq_consulta = fopen("data/arq_consulta.dat", "rb");

    if (arq_consulta == NULL) {
        exibir_moldura_titulo("Nenhuma consulta cadastrada ainda");
        free(con);
        return;
    }

    limpar_tela();
    exibir_moldura_titulo("Consultas - Lista Geral");

    while (fread(con, sizeof(Consulta), 1, arq_consulta)) {
        if (con->status == true) {
            printf("\n");
            exibir_consulta(con);
            printf("\n");
            printf("═══════════════════════════════════════════════════════════════════════════"
                   "═\n");
        }
    }

    fclose(arq_consulta);
    free(con);

    pausar();
}


void listar_consultas_medico(void) {
    FILE *arq_consulta;
    Consulta *con;

    con = (Consulta *)malloc(sizeof(Consulta));

    char med_busca[50];

    arq_consulta = fopen("data/arq_consulta.dat", "rb");

    printf("Digite o nome do médico: \n");
    scanf("%s", med_busca);

    if (arq_consulta == NULL) {
        exibir_moldura_titulo("Nenhuma consulta cadastrada ainda");
        free(con);
        return;
    }

    limpar_tela();
    exibir_moldura_titulo("Consultas - Lista Médico");

    while (fread(con, sizeof(Consulta), 1, arq_consulta)) {
        if (con->status == true) {
            if (strcmp(med_busca, con->medico) == 0) {
                printf("\n");
                exibir_consulta(con);
                printf("\n");
                printf("═══════════════════════════════════════════════════════════════════"
                       "═════════\n");
            }
        }
    }

    fclose(arq_consulta);
    free(con);

    pausar();
}