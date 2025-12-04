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
    limpar_buffer_entrada();
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

    con->status = true;

    arq_consulta = fopen("data/arq_consulta.dat", "a+b");

    if (arq_consulta == NULL) {
        exibir_moldura_titulo("Erro na criação do arquivo");
        free(con);
        return;
    }

    if (fwrite(con, sizeof(Consulta), 1, arq_consulta) != 1) {
        exibir_moldura_titulo("Erro ao salvar consulta.");
    } else {
        exibir_moldura_titulo("Consulta cadastrada com sucesso");
        printf("\nID gerado: %02d\n", con->id_consulta);
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
    printf("Informe o ID da consulta: ");
    scanf("%d", &id_busca);
    limpar_buffer_entrada();

    encontrado = false;

    arq_consulta = fopen("data/arq_consulta.dat", "rb");

    if (arq_consulta == NULL) {
        exibir_moldura_titulo("Erro na criacao do arquivo");
        free(con);
        getchar();
        return;
    }

    while (fread(con, sizeof(Consulta), 1, arq_consulta)) {
        if ((id_busca == con->id_consulta) && (con->status == true)) {
            exibir_moldura_titulo("Consulta encontrada");
            exibir_consulta(con);
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        exibir_moldura_titulo("Consulta não encontrada!");
    }

    fclose(arq_consulta);
    free(con);
    pausar();
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

    limpar_tela();
    exibir_moldura_titulo("Consultas - Alteração");
    printf("Informe o ID da consulta: ");
    scanf("%d", &id_busca);
    limpar_buffer_entrada();

    encontrado = false;

    arq_consulta = fopen("data/arq_consulta.dat", "rb");
    arq_consulta_temp = fopen("data/arq_consulta_temp.dat", "wb");

    if (arq_consulta == NULL || arq_consulta_temp == NULL) {
        exibir_moldura_titulo("Erro na busca do arquivo");
        free(con);
        return;
    }

    while (fread(con, sizeof(Consulta), 1, arq_consulta)) {
        if ((id_busca == con->id_consulta) && (con->status == true)) {
            encontrado = true;
            do {
                limpar_tela();
                exibir_moldura_titulo("Dados atuais da consulta");
                exibir_consulta(con);

                const char *menu_alt = "\nQual campo deseja alterar?\n"
                                       "1. Nome\n"
                                       "2. Data\n"
                                       "3. Hora\n"
                                       "4. Médico\n"
                                       "5. Observações\n";
                exibir_moldura_conteudo(menu_alt);
                printf("Escolha uma opção: ");
                scanf(" %c", &opcao);
                limpar_buffer_entrada();

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
                        exibir_moldura_titulo("Opção inválida!");
                        break;
                }

                exibir_moldura_titulo("Dados atualizados");
                exibir_consulta(con);

                printf("\nDeseja alterar outro campo? (S/N): ");
                scanf(" %c", &continuar);
                limpar_buffer_entrada();

                if (continuar == 0) {
                    exibir_moldura_titulo("Opção inválida! Digite apenas S ou N.");
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
        exibir_moldura_titulo("Consulta alterada com sucesso!");
    } else {
        remove("data/arq_consulta_temp.dat");
        exibir_moldura_titulo("Consulta não encontrada!");
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
    exibir_moldura_titulo("Consultas - Exclusão");
    printf("Informe o ID da consulta: ");
    scanf("%d", &id_busca);
    limpar_buffer_entrada();

    encontrado = false;

    arq_consulta = fopen("data/arq_consulta.dat", "r+b");

    if (arq_consulta == NULL) {
        exibir_moldura_titulo("Erro na busca do arquivo");
        free(con);
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
                limpar_buffer_entrada();

                if (resposta == 0) {
                    exibir_moldura_titulo("Opção inválida! Digite apenas S ou N.");
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
    exibir_moldura_titulo("Consultas - Exclusão Física");
    printf("Informe o ID da Consulta: ");
    scanf("%d", &id_busca);
    limpar_buffer_entrada();

    arq_consulta = fopen("data/arq_consulta.dat", "rb");
    arq_consulta_temp = fopen("data/arq_consulta_temp.dat", "wb");

    if (arq_consulta == NULL || arq_consulta_temp == NULL) {
        exibir_moldura_titulo("Erro ao abrir arquivos!");
        free(con);
        return;
    }

    while (fread(con, sizeof(Consulta), 1, arq_consulta)) {
        if (con->id_consulta == id_busca) {
            exibir_moldura_titulo("Consulta encontrada!\n");
            exibir_consulta(con);

            encontrado = true;

            if (con->status == true) {
                exibir_moldura_titulo("Status: Ativa");

            } else {
                exibir_moldura_titulo("Status: Inativa");
            }

            if (con->status == false) {
                do {
                    printf("\nDeseja realmente excluir esta consulta (fisicamente)? (S/N): ");
                    scanf(" %c", &resposta);
                    limpar_buffer_entrada();
                    if (resposta == 0) {
                        exibir_moldura_titulo("Opção inválida! Digite apenas S ou N.");
                    }

                } while (resposta == 0);

                if (resposta == 'S') {
                    exibir_moldura_titulo("Consulta excluída com sucesso!");
                    excluida = true;

                } else {
                    exibir_moldura_titulo("Operação cancelada. A consulta foi mantida.");
                    fwrite(con, sizeof(Consulta), 1, arq_consulta_temp);
                }

            } else {
                exibir_moldura_titulo(
                    "A consulta está ativa, portanto não pode ser excluída fisicamente.");
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
        exibir_moldura_titulo("Exclusão física concluída!");
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