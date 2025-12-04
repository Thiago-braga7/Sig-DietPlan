#include "relatorios/relatorios_consultas.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "consultas.h"
#include "uteis.h"

typedef struct ConsultaNode {
    Consulta consulta;
    struct ConsultaNode *prox;
} ConsultaNode;

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
            case '3':
                listar_consultas_ordenado_paciente();
                break;
        }
    } while (opcao != '0');
}

char tela_relatorios_consultas(void) {
    char opcao;

    const char *menu = "1. Lista Geral de Consultas\n"
                       "2. Lista de Consultas por Médico \n"
                       "3. Lista de Consultas Ordenada por Paciente \n"
                       "0. Voltar ao Menu Anterior\n";

    exibir_moldura_titulo("Relatórios de Consultas");
    exibir_moldura_conteudo(menu);

    printf("Escolha a opção desejada: ");
    scanf(" %c", &opcao);
    limpar_buffer_entrada();

    return opcao;
}

void listar_consultas(void) {
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
    printf("║ %-3s ║ %-22s ║ %-22s ║ %-10s ║ %-8s \n",
           "ID",
           "Nome Paciente",
           "Médico",
           "Data",
           "Hora");
    exibir_linha_separadora();

    while (fread(con, sizeof(Consulta), 1, arq_consulta)) {
        if (con->status == true) {
            encontrado = true;
            printf("║ %-3d ║ %-22s ║ %-22s ║ %-10s ║ %-8s \n",
                   con->id_consulta,
                   con->nome,
                   con->medico,
                   con->data,
                   con->hora);
        }
    }

    if (!encontrado) {
        exibir_moldura_titulo("Nenhuma consulta ativa encontrada");
    }

    fclose(arq_consulta);
    free(con);

    pausar();
}

void listar_consultas_ordenado_paciente(void) {
    FILE *arq_consulta;
    Consulta con;
    ConsultaNode *lista = NULL;
    ConsultaNode *novo, *ant, *atual;

    arq_consulta = fopen("data/arq_consulta.dat", "rb");
    if (arq_consulta == NULL) {
        exibir_moldura_titulo("Nenhuma consulta cadastrada ainda");
        pausar();
        return;
    }

    limpar_tela();
    exibir_moldura_titulo("Consultas - Lista Ordenada por Paciente");

    while (fread(&con, sizeof(Consulta), 1, arq_consulta)) {
        if (con.status == true) {
            novo = (ConsultaNode *)malloc(sizeof(ConsultaNode));
            if (!novo) {
                // Libera memória em caso de erro
                while (lista) {
                    ConsultaNode *tmp = lista->prox;
                    free(lista);
                    lista = tmp;
                }
                break;
            }
            novo->consulta = con;
            novo->prox = NULL;

            if (lista == NULL || strcmp(novo->consulta.nome, lista->consulta.nome) < 0) {
                novo->prox = lista;
                lista = novo;
            } else {
                ant = lista;
                atual = lista->prox;
                while (atual != NULL && strcmp(atual->consulta.nome, novo->consulta.nome) < 0) {
                    ant = atual;
                    atual = atual->prox;
                }
                ant->prox = novo;
                novo->prox = atual;
            }
        }
    }
    fclose(arq_consulta);

    if (lista == NULL) {
        exibir_moldura_titulo("Nenhuma consulta ativa encontrada");
    } else {
        printf("║ %-3s ║ %-22s ║ %-22s ║ %-10s ║ %-8s \n",
               "ID",
               "Nome Paciente",
               "Médico",
               "Data",
               "Hora");
        exibir_linha_separadora();
        atual = lista;
        while (atual != NULL) {
            printf("║ %-3d ║ %-22s ║ %-22s ║ %-10s ║ %-8s \n",
                   atual->consulta.id_consulta,
                   atual->consulta.nome,
                   atual->consulta.medico,
                   atual->consulta.data,
                   atual->consulta.hora);
            atual = atual->prox;
        }
    }

    // Libera memória da lista
    atual = lista;
    while (atual != NULL) {
        ConsultaNode *tmp = atual->prox;
        free(atual);
        atual = tmp;
    }

    pausar();
}

void listar_consultas_medico(void) {
    FILE *arq_consulta;
    Consulta *con;
    bool encontrado = false;

    con = (Consulta *)malloc(sizeof(Consulta));
    if (con == NULL) {
        printf("Erro de alocação de memória!\n");
        return;
    }

    char med_busca[50];

    limpar_tela();
    exibir_moldura_titulo("Consultas - Lista por Médico");

    printf("Digite o nome do médico: ");
    scanf("%49[^\n]", med_busca);
    limpar_buffer_entrada();

    arq_consulta = fopen("data/arq_consulta.dat", "rb");

    if (arq_consulta == NULL) {
        exibir_moldura_titulo("Nenhuma consulta cadastrada ainda");
        free(con);
        pausar();
        return;
    }

    printf("\n");
    printf("║ %-3s ║ %-22s ║ %-22s ║ %-10s ║ %-8s \n",
           "ID",
           "Nome Paciente",
           "Médico",
           "Data",
           "Hora");
    exibir_linha_separadora();

    while (fread(con, sizeof(Consulta), 1, arq_consulta)) {
        if (con->status == true && strcmp(med_busca, con->medico) == 0) {
            encontrado = true;
            printf("║ %-3d ║ %-22s ║ %-22s ║ %-10s ║ %-8s \n",
                   con->id_consulta,
                   con->nome,
                   con->medico,
                   con->data,
                   con->hora);
        }
    }

    if (!encontrado) {
        exibir_moldura_titulo("Nenhuma consulta encontrada para este médico");
    }

    fclose(arq_consulta);
    free(con);

    pausar();
}