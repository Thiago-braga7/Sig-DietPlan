#include "agendamentos.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "leituras.h"
#include "uteis.h"
#include "validacoes.h"


void modulo_agendamentos(void) {
    char opcao;

    do {
        limpar_tela();
        opcao = tela_agendamentos();

        switch (opcao) {
            case '1':
                cadastrar_agendamento();
                break;
            case '2':
                buscar_agendamento();
                break;
            case '3':
                alterar_agendamento();
                break;
            case '4':
                excluir_agendamento();
                break;
            case '5':
                excluir_agendamento_fisico();
                break;
        }

    } while (opcao != '0');
}


char tela_agendamentos(void) {
    char opcao;

    const char *menu = "1. Cadastrar agendamento\n"
                       "2. Buscar agendamento\n"
                       "3. Alterar agendamento\n"
                       "4. Excluir agendamento\n"
                       "5. Excluir agendamento (físico)\n"
                       "0. Voltar ao Menu Principal";

    exibir_moldura_titulo("Agendamentos");
    exibir_moldura_conteudo(menu);

    printf("Escolha a opção desejada: ");
    scanf(" %c", &opcao);
    limpar_buffer_entrada();

    return opcao;
}


void cadastrar_agendamento(void) {
    FILE *arq_agendamentos;
    Agendamento *ag;

    ag = (Agendamento *)malloc(sizeof(Agendamento));

    ag->id_agendamento = 1;
    arq_agendamentos = fopen("data/arq_agendamentos.dat", "rb");

    // Créditos: função adaptada do Gemini
    if (arq_agendamentos != NULL) {
        fseek(arq_agendamentos, 0, SEEK_END);

        long num_registros = ftell(arq_agendamentos) / sizeof(Agendamento);
        ag->id_agendamento = num_registros + 1;

        fclose(arq_agendamentos);
    }

    limpar_tela();
    exibir_moldura_titulo("Agendamentos - Cadastro");

    ler_cpf(ag->cpf);
    ler_data(ag->data);
    ler_hora(ag->hora);
    ler_tipo(ag->tipo);
    ler_profissional(ag->profissional);
    ler_observacoes(ag->observacoes);

    ag->status = true;

    arq_agendamentos = fopen("data/arq_agendamentos.dat", "a+b");

    if (arq_agendamentos == NULL) {
        exibir_moldura_titulo("Erro na criação do arquivo");
        free(ag);
        return;
    }

    fwrite(ag, sizeof(Agendamento), 1, arq_agendamentos);
    fclose(arq_agendamentos);

    exibir_moldura_titulo("Agendamento cadastrado com sucesso");
    printf("\nID gerado: %02d\n", ag->id_agendamento);
    free(ag);
    pausar();
}


void buscar_agendamento(void) {
    FILE *arq_agendamentos;
    Agendamento *ag;

    int id_busca;
    bool encontrado = false;

    ag = (Agendamento *)malloc(sizeof(Agendamento));

    limpar_tela();
    exibir_moldura_titulo("Agendamentos - Busca");
    printf("Informe o ID do Agendamento: ");
    scanf("%d", &id_busca);
    limpar_buffer_entrada();

    arq_agendamentos = fopen("data/arq_agendamentos.dat", "rb");

    if (arq_agendamentos == NULL) {
        exibir_moldura_titulo("Erro na abertura do arquivo");
        return;
    }

    while (fread(ag, sizeof(Agendamento), 1, arq_agendamentos)) {
        if ((ag->id_agendamento == id_busca) && (ag->status == true)) {
            exibir_moldura_titulo("Agendamento encontrado");
            exibir_agendamento(ag);
            encontrado = true;
            break;
        }
    }

    if (encontrado == false) {
        exibir_moldura_titulo("Agendamento não encontrado!");
    }

    fclose(arq_agendamentos);
    free(ag);
    pausar();
}


void alterar_agendamento(void) {
    FILE *arq_agendamentos;
    FILE *arq_agendamentos_temp;

    Agendamento *ag;

    int id_busca;
    char opcao;
    char continuar;
    bool encontrado = false;

    ag = (Agendamento *)malloc(sizeof(Agendamento));

    limpar_tela();
    exibir_moldura_titulo("Agendamentos - Alteração");
    printf("Informe o ID do Agendamento: ");
    scanf("%d", &id_busca);
    limpar_buffer_entrada();

    arq_agendamentos = fopen("data/arq_agendamentos.dat", "rb");
    arq_agendamentos_temp = fopen("data/arq_agendamentos_temp.dat", "wb");

    if (arq_agendamentos == NULL || arq_agendamentos_temp == NULL) {
        exibir_moldura_titulo("Erro na criação do arquivo");
        free(ag);
        return;
    }

    while (fread(ag, sizeof(Agendamento), 1, arq_agendamentos)) {
        if ((ag->id_agendamento == id_busca) && (ag->status == true)) {
            encontrado = true;
            do {
                limpar_tela();
                exibir_moldura_titulo("Agendamento - Dados Atuais");
                exibir_agendamento(ag);

                const char *menu_alt = "\nQual campo deseja alterar?\n"
                                       "1. CPF\n"
                                       "2. Data\n"
                                       "3. Hora\n"
                                       "4. Tipo\n"
                                       "5. Profissional\n"
                                       "6. Observações\n";

                exibir_moldura_conteudo(menu_alt);

                printf("Escolha uma opção: ");
                scanf(" %c", &opcao);
                limpar_buffer_entrada();

                switch (opcao) {
                    case '1':
                        ler_cpf(ag->cpf);
                        break;
                    case '2':
                        ler_data(ag->data);
                        break;
                    case '3':
                        ler_hora(ag->hora);
                        break;
                    case '4':
                        ler_tipo(ag->tipo);
                        break;
                    case '5':
                        ler_profissional(ag->profissional);
                        break;
                    case '6':
                        ler_observacoes(ag->observacoes);
                        break;

                    default:
                        exibir_moldura_titulo("Opção inválida!");
                        break;
                }

                exibir_moldura_titulo("Dados atualizados");
                exibir_agendamento(ag);

                printf("\nDeseja alterar outro campo? (S/N): ");
                scanf(" %c", &continuar);
                limpar_buffer_entrada();

                if (continuar == 0) {
                    exibir_moldura_titulo("Opção inválida! Digite apenas S ou N.");
                }

            } while (continuar == 'S');
        }

        fwrite(ag, sizeof(Agendamento), 1, arq_agendamentos_temp);
    }

    fclose(arq_agendamentos);
    fclose(arq_agendamentos_temp);

    if (encontrado == true) {
        remove("data/arq_agendamentos.dat");
        rename("data/arq_agendamentos_temp.dat", "data/arq_agendamentos.dat");
        exibir_moldura_titulo("Agendamento alterado com sucesso!");

    } else {
        remove("data/arq_agendamentos_temp.dat");
        exibir_moldura_titulo("Agendamento não encontrado!");
    }

    free(ag);
    pausar();
}


void excluir_agendamento(void) {
    FILE *arq_agendamentos;
    Agendamento *ag;

    int id_busca;
    char resposta;
    bool encontrado = false;

    ag = (Agendamento *)malloc(sizeof(Agendamento));

    limpar_tela();
    exibir_moldura_titulo("Agendamentos - Exclusão");
    printf("Informe o ID do Agendamento: ");
    scanf("%d", &id_busca);
    limpar_buffer_entrada();

    arq_agendamentos = fopen("data/arq_agendamentos.dat", "r+b");

    if (arq_agendamentos == NULL) {
        exibir_moldura_titulo("Erro na criação do arquivo");
        return;
    }

    while (fread(ag, sizeof(Agendamento), 1, arq_agendamentos)) {
        if ((ag->id_agendamento == id_busca) && (ag->status == true)) {
            exibir_moldura_titulo("Agendamento encontrado!");
            exibir_agendamento(ag);
            encontrado = true;

            do {
                printf("\nDeseja realmente excluir este Agendamento? (S/N): ");
                scanf(" %c", &resposta);
                limpar_buffer_entrada();

                if (resposta == 0) {
                    exibir_moldura_titulo("Opção inválida! Digite apenas S ou N.");
                }

            } while (resposta == 0);

            if (resposta == 'S') {
                ag->status = false;
                fseek(arq_agendamentos, (-1) * sizeof(Agendamento), SEEK_CUR);
                fwrite(ag, sizeof(Agendamento), 1, arq_agendamentos);
                exibir_moldura_titulo("Agendamento excluído com sucesso!");

            } else {
                exibir_moldura_titulo("Operação de exclusão cancelada.");
            }

            break;
        }
    }

    if (encontrado == false) {
        exibir_moldura_titulo("Agendamento não encontrado!");
    }

    fclose(arq_agendamentos);
    free(ag);
    pausar();
}


void excluir_agendamento_fisico(void) {
    FILE *arq_agendamentos;
    FILE *arq_agendamentos_temp;

    Agendamento *ag;

    int id_busca;
    char resposta;
    bool excluido = false;
    bool encontrado = false;

    ag = (Agendamento *)malloc(sizeof(Agendamento));

    limpar_tela();
    exibir_moldura_titulo("Agendamentos - Exclusão Física");

    printf("Informe o ID do Agendamento: ");
    scanf("%d", &id_busca);
    limpar_buffer_entrada();

    arq_agendamentos = fopen("data/arq_agendamentos.dat", "rb");
    arq_agendamentos_temp = fopen("data/arq_agendamentos_temp.dat", "wb");

    if (arq_agendamentos == NULL || arq_agendamentos_temp == NULL) {
        exibir_moldura_titulo("Erro ao abrir arquivos!");
        free(ag);
        return;
    }

    while (fread(ag, sizeof(Agendamento), 1, arq_agendamentos)) {
        if (ag->id_agendamento == id_busca) {
            exibir_moldura_titulo("Agendamento encontrado!");
            exibir_agendamento(ag);
            encontrado = true;

            if (ag->status == false) {
                do {
                    printf("\nDeseja realmente excluir este Agendamento (fisicamente)? (S/N): ");
                    scanf(" %c", &resposta);
                    limpar_buffer_entrada();

                    if (resposta == 0) {
                        exibir_moldura_titulo("Opção inválida! Digite apenas S ou N.");
                    }

                } while (resposta == 0);

                if (resposta == 'S') {
                    exibir_moldura_titulo("Agendamento excluído fisicamente com sucesso!");
                    excluido = true;

                } else {
                    exibir_moldura_titulo("Operação cancelada. O agendamento foi mantido.");
                    fwrite(ag, sizeof(Agendamento), 1, arq_agendamentos_temp);
                }

            } else {
                exibir_moldura_titulo(
                    "O agendamento está ativo, portanto não pode ser excluído fisicamente.");
                fwrite(ag, sizeof(Agendamento), 1, arq_agendamentos_temp);
            }

        } else {
            fwrite(ag, sizeof(Agendamento), 1, arq_agendamentos_temp);
        }
    }

    fclose(arq_agendamentos);
    fclose(arq_agendamentos_temp);
    free(ag);

    remove("data/arq_agendamentos.dat");
    rename("data/arq_agendamentos_temp.dat", "data/arq_agendamentos.dat");

    if (encontrado == false) {
        exibir_moldura_titulo("Agendamento não encontrado!");

    } else if (excluido == true) {
        exibir_moldura_titulo("Exclusão física concluída!");
    }

    pausar();
}


void exibir_agendamento(const Agendamento *ag) {
    if (ag == NULL) {
        exibir_moldura_titulo("Erro: agendamento inexistente!");
        return;
    }

    printf("ID:                %d\n", ag->id_agendamento);
    printf("CPF:               %s\n", ag->cpf);
    printf("Data:              %s\n", ag->data);
    printf("Hora:              %s\n", ag->hora);
    printf("Tipo:              %s\n", ag->tipo);
    printf("Profissional:      %s\n", ag->profissional);
    printf("Observações:       %s\n", ag->observacoes);
}