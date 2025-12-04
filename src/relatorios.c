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
#include "relatorios/relatorios_pacientes.h"
#include "uteis.h"
#include "validacoes.h"


typedef struct NovoProfissional {
    Profissional dados;
    struct NovoProfissional *prox;
} NovoProfissional;


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


char tela_relatorios_dietas(void) {
    char opcao;

    const char *menu = "1. Lista Geral de Dietas\n"
                       "2. Lista de Dietas por Calorias \n"
                       "0. Voltar ao Menu Anterior\n";

    exibir_moldura_titulo("Relatórios");
    exibir_moldura_conteudo(menu);

    printf("Escolha a opção desejada: ");
    scanf(" %c", &opcao);
    getchar();

    return opcao;
}


char tela_relatorios_profissionais(void) {
    char opcao;

    const char *menu = "1. Lista Geral de Profissionais\n"
                       "2. Lista de Profissionais por Sexo \n"
                       "3. Lista de Profissionais Ordenada por Nome \n"
                       "0. Voltar ao Menu Anterior\n";

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


// Listas dietas
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


// Listas de profissionais
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


void listar_profissionais_ordenado(void) {
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
    exibir_moldura_titulo("Profissionais - Lista Geral");

    while (fread(pf, sizeof(Profissional), 1, arq_profissionais)) {
        if (pf->status == true) {
            novo = (NovoProfissional *)malloc(sizeof(NovoProfissional));
            if (!novo)
                break;
            novo->dados = *pf;
            novo->prox = NULL;

            if (lista == NULL) {
                lista = novo;
            } else if (strcasecmp(novo->dados.nome, lista->dados.nome) < 0) {
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
        pausar();
        return;
    }

    // Exibe lista ordenada
    atual = lista;
    while (atual != NULL) {
        printf("\n");
        exibir_profissional(&atual->dados);
        printf("\n════════════════════════════════════════════════════════════════════════════\n");
        atual = atual->prox;
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