/*
 * Módulo de Consultas
 * Responsável pelo cadastro, busca, alteração, exclusão e listagem de consultas médicas.
 * Cada função implementa uma operação do CRUD sobre o registro de consultas.
 *
 * Autor: Wallison Dias
 * Créditos: auxílio do ChatGPT
 * Data: 2025
 */

#include "consultas.h"

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "leituras.h"
#include "uteis.h"
#include "validacoes.h"


// Menu principal do módulo de consultas
void modulo_consultas(void) {
    char opcao;

    do {
        limpar_tela();
        opcao = tela_consultas();

        switch (opcao) {
            case '1':
                cadastrar_consulta();
                break;
            case '2':
                buscar_consulta();
                break;
            case '3':
                alterar_consulta();
                break;
            case '4':
                excluir_consulta();
                break;
            case '5':
                excluir_consulta_fisica();
                break;
        }

    } while (opcao != '0');
}


// Exibe o menu de opções do módulo de consultas e retorna a opção escolhida
char tela_consultas(void) {
    char opcao;

    const char *menu = "1. Cadastrar consulta\n"
                       "2. Buscar consulta\n"
                       "3. Alterar Consulta\n"
                       "4. Excluir Consulta\n"
                       "5. Excluir Consulta (física)\n"
                       "0. Voltar ao Menu Principal\n";

    exibir_moldura_titulo("Consultas");
    exibir_moldura_conteudo(menu);

    printf("Escolha a opção desejada: ");
    scanf(" %c", &opcao);
    getchar();
    return opcao;
}


// Realiza o cadastro de uma nova consulta
void cadastrar_consulta(void) {
    FILE *arq_consulta;
    Consulta *con;

    con = (Consulta *)malloc(sizeof(Consulta));

    if (!con) {
        printf("Erro: Falha ao alocar memória para consulta.\n");
        return;
    }
    con->id_consulta = 1;

    arq_consulta = fopen("data/arq_consulta.dat", "rb");

    // Créditos: função adaptada do Gemini
    if (arq_consulta != NULL) {
        fseek(arq_consulta, 0, SEEK_END);

        long num_registros = ftell(arq_consulta) / sizeof(Consulta);
        con->id_consulta = num_registros + 1;

        fclose(arq_consulta);
    }

    limpar_tela();

    printf("\n");
    exibir_moldura_titulo("Consultas - Cadastro");

    ler_nome(con->nome);
    ler_data(con->data);
    ler_hora(con->hora);
    ler_medico(con->medico);
    ler_observacoes(con->observacoes);

    exibir_moldura_titulo("Consulta cadastrada com sucesso");

    con->status = true;

    arq_consulta = fopen("data/arq_consulta.dat", "a+b");

    if (arq_consulta == NULL) {
        printf("Erro na criação do arquivo\n");
        return;
    }

    if (fwrite(con, sizeof(Consulta), 1, arq_consulta) != 1) {
        printf("Erro ao salvar consulta.\n");
    }

    fclose(arq_consulta);
    free(con);
    pausar();
}


// Busca e exibe uma consulta pelo ID
void buscar_consulta(void) {
    FILE *arq_consulta;
    Consulta *con;

    int id_busca;
    bool encontrado;

    con = (Consulta *)malloc(sizeof(Consulta));

    limpar_tela();
    exibir_moldura_titulo("Consultas - Busca");
    scanf("%d", &id_busca);
    getchar();
    pausar();

    encontrado = false;

    arq_consulta = fopen("data/arq_consulta.dat", "rb");

    if (arq_consulta == NULL) {
        printf("Erro na criacao do arquivo\n");
        getchar();
        return;
    }

    while (fread(con, sizeof(Consulta), 1, arq_consulta)) {
        if ((id_busca == con->id_consulta) && (con->status == true)) {
            printf("Consulta encontrada\n");
            exibir_consulta(con);
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        printf("\nConsulta não encontrada!\n");
    }

    fclose(arq_consulta);
    free(con);
    getchar();
}


// Permite alterar os dados de uma consulta existente
void alterar_consulta(void) {
    FILE *arq_consulta;
    FILE *arq_consulta_temp;

    Consulta *con;

    int id_busca;
    bool encontrado;
    char opcao;
    char continuar;

    con = (Consulta *)malloc(sizeof(Consulta));

    exibir_moldura_titulo("Consultas - Alteração");
    scanf("%d", &id_busca);
    getchar();

    encontrado = false;

    arq_consulta = fopen("data/arq_consulta.dat", "rb");
    arq_consulta_temp = fopen("data/arq_consulta_temp.dat", "wb");

    if (arq_consulta == NULL || arq_consulta_temp == NULL) {
        printf("Erro na busca do arquivo\n");
        return;
    }

    while (fread(con, sizeof(Consulta), 1, arq_consulta)) {
        if ((id_busca == con->id_consulta) && (con->status == true)) {
            encontrado = true;
            do {
                limpar_tela();
                printf("\nDados atuais da consulta\n");
                exibir_consulta(con);

                printf("\nQual campo deseja alterar?\n");
                printf("1. Nome\n");
                printf("2. Data\n");
                printf("3. Hora\n");
                printf("4. Médico\n");
                printf("5. Observações\n");
                printf("Escolha uma opção: ");
                scanf(" %c", &opcao);
                getchar();

                switch (opcao) {
                    case '1':
                        ler_nome(con->nome);
                        break;
                    case '2':
                        ler_data(con->data);
                        break;
                    case '3':
                        ler_hora(con->hora);
                        break;
                    case '4':
                        ler_medico(con->medico);
                        break;
                    case '5':
                        ler_observacoes(con->observacoes);
                        break;
                    default:
                        printf("Opção inválida!\n");
                        break;
                }

                printf("\nDados atualizados\n");
                exibir_consulta(con);

                printf("\nDeseja alterar outro campo? (S/N): ");
                scanf(" %c", &continuar);
                getchar();
                continuar = confirmar_acao(continuar);

                if (continuar == 0) {
                    printf("Opção inválida! Digite apenas S ou N.\n");
                }
            } while (continuar == 'S');
        }
        fwrite(con, sizeof(Consulta), 1, arq_consulta_temp);
    }

    fclose(arq_consulta);
    fclose(arq_consulta_temp);

    if (encontrado == true) {
        remove("data/arq_consulta.dat");
        rename("data/arq_consulta_temp.dat", "data/arq_consulta.dat");
        printf("\nConsulta alterada com sucesso!\n");
    } else {
        remove("data/arq_consulta_temp.dat");
        printf("\nConsulta não encontrada!\n");
    }
    free(con);
    pausar();
}


// Marca uma consulta como excluída logicamente (status = false)
void excluir_consulta(void) {
    FILE *arq_consulta;
    Consulta *con;

    int id_busca;
    bool encontrado;
    char resposta;

    con = (Consulta *)malloc(sizeof(Consulta));

    limpar_tela();
    printf("\n");
    exibir_moldura_titulo("Consultas - Exclusão");
    printf("Informe o ID da consulta: ");
    scanf("%d", &id_busca);
    getchar();

    encontrado = false;

    arq_consulta = fopen("data/arq_consulta.dat", "r+b");

    if (arq_consulta == NULL) {
        printf("Erro na busca do arquivo\n");
        return;
    }

    while (fread(con, sizeof(Consulta), 1, arq_consulta)) {
        if ((id_busca == con->id_consulta) && (con->status == true)) {
            exibir_moldura_titulo("Consulta encontrada!\n");
            exibir_consulta(con);
            encontrado = true;

            do {
                printf("\nDeseja realmente excluir esta consulta? (S/N): ");
                scanf(" %c", &resposta);
                resposta = confirmar_acao(resposta);

                if (resposta == 0) {
                    printf("Opção inválida! Digite apenas S ou N.\n");
                }
            } while (resposta == 0);

            if (resposta == 'S') {
                con->status = false;
                fseek(arq_consulta, (-1) * sizeof(Consulta), SEEK_CUR);
                fwrite(con, sizeof(Consulta), 1, arq_consulta);
                exibir_moldura_titulo("Consulta excluída com sucesso!\n");
            } else {
                exibir_moldura_titulo("Operação de exclusão cancelada!\n");
            }
            break;
        }
    }

    if (encontrado == false) {
        exibir_moldura_titulo("Consulta não encontrada!\n");
    }

    fclose(arq_consulta);
    free(con);
    pausar();
}


// Exclui fisicamente uma consulta inativa do arquivo
void excluir_consulta_fisica(void) {
    FILE *arq_consulta;
    FILE *arq_consulta_temp;

    Consulta *con;
    con = (Consulta *)malloc(sizeof(Consulta));

    int id_busca;
    char resposta;
    bool encontrado = false;
    bool excluida = false;

    limpar_tela();
    printf("\n");
    exibir_moldura_titulo("Consultas - Exclusão Física");
    printf("Informe o ID da Consulta: ");
    scanf("%d", &id_busca);
    getchar();

    arq_consulta = fopen("data/arq_consulta.dat", "rb");
    arq_consulta_temp = fopen("data/arq_consulta_temp.dat", "wb");

    if (arq_consulta == NULL || arq_consulta_temp == NULL) {
        printf("Erro ao abrir arquivos!\n");
        return;
    }

    while (fread(con, sizeof(Consulta), 1, arq_consulta)) {
        if (con->id_consulta == id_busca) {
            exibir_moldura_titulo("Consulta encontrada!\n");
            exibir_consulta(con);

            encontrado = true;

            if (con->status == true) {
                printf("Status: Ativa \n");

            } else {
                printf("Status: Inativa \n");
            }

            if (con->status == false) {
                do {
                    printf("\nDeseja realmente excluir esta consulta (fisicamente)? (S/N): ");
                    scanf(" %c", &resposta);
                    resposta = confirmar_acao(resposta);

                    if (resposta == 0) {
                        printf("Opção inválida! Digite apenas S ou N.\n");
                    }

                } while (resposta == 0);

                if (resposta == 'S') {
                    exibir_moldura_titulo("Consulta excluída com sucesso!\n");
                    excluida = true;

                } else {
                    printf("\nOperação cancelada. A consulta foi mantida.\n");
                    fwrite(con, sizeof(Consulta), 1, arq_consulta_temp);
                }

            } else {
                printf("\nA consulta está ativa, portanto não pode ser excluída fisicamente.\n");
                fwrite(con, sizeof(Consulta), 1, arq_consulta_temp);
            }

        } else {
            fwrite(con, sizeof(Consulta), 1, arq_consulta_temp);
        }
    }

    fclose(arq_consulta);
    fclose(arq_consulta_temp);
    free(con);

    remove("data/arq_consulta.dat");
    rename("data/arq_consulta_temp.dat", "data/arq_consulta.dat");

    if (encontrado == false) {
        exibir_moldura_titulo("Consulta não encontrada!\n");

    } else if (excluida == true) {
        exibir_moldura_titulo("Consulta excluída com sucesso!\n");
    }

    pausar();
}


// Exibe os dados de uma consulta formatados
void exibir_consulta(const Consulta *con) {
    if (con == NULL) {
        exibir_moldura_titulo("Erro: consulta inexistente!\n");
        return;
    }

    printf("ID da consulta: %d\n", con->id_consulta);
    printf("Nome: %s\n", con->nome);
    printf("Data: %s\n", con->data);
    printf("Hora: %s\n", con->hora);
    printf("Médico: %s\n", con->medico);
    printf("Observações: %s\n", con->observacoes);
}