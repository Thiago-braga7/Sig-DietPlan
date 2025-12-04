#include "profissionais.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "leituras.h"
#include "uteis.h"
#include "validacoes.h"


void modulo_profissionais(void) {
    char opcao;
    do {
        limpar_tela();
        opcao = tela_profissionais();
        switch (opcao) {
            case '1':
                cadastrar_profissional();
                break;
            case '2':
                buscar_profissional();
                break;
            case '3':
                alterar_profissional();
                break;
            case '4':
                excluir_profissional();
                break;
        }
    } while (opcao != '0');
}


char tela_profissionais(void) {
    char opcao;
    const char *menu = "1. Cadastrar Profissional\n"
                       "2. Buscar Profissional\n"
                       "3. Alterar Dados do Profissional\n"
                       "4. Excluir Profissional\n"
                       "0. Voltar ao menu principal\n";

    limpar_tela();
    exibir_moldura_titulo("Profissionais");
    exibir_moldura_conteudo(menu);
    printf("Escolha a opção desejada: ");
    scanf(" %c", &opcao);
    limpar_buffer_entrada();
    return opcao;
}


void cadastrar_profissional(void) {
    FILE *arq_profissionais;
    Profissional *pf;

    pf = (Profissional *)malloc(sizeof(Profissional));

    pf->id_profissional = 1;
    arq_profissionais = fopen("data/arq_profissionais.dat", "rb");

    if (arq_profissionais != NULL) {
        fseek(arq_profissionais, 0, SEEK_END);
        long num_registros = ftell(arq_profissionais) / sizeof(Profissional);
        pf->id_profissional = num_registros + 1;
        fclose(arq_profissionais);
    }

    limpar_tela();
    exibir_moldura_titulo("Cadastro - Profissionais");
    ler_nome(pf->nome);
    ler_cpf(pf->cpf);
    ler_tel(pf->tel);
    ler_crn(pf->crn);
    ler_sexo(&pf->sexo);
    pf->status = true;

    arq_profissionais = fopen("data/arq_profissionais.dat", "a+b");
    if (arq_profissionais == NULL) {
        exibir_moldura_titulo("Erro na abertura do arquivo");
        free(pf);
        return;
    }

    exibir_moldura_titulo("Profissional Cadastrado com Sucesso!");
    printf("\nID gerado: %02d\n", pf->id_profissional);

    fwrite(pf, sizeof(Profissional), 1, arq_profissionais);
    fclose(arq_profissionais);
    free(pf);
    pausar();
}


void buscar_profissional(void) {
    FILE *arq_profissionais;
    Profissional *pf;
    int id_busca;
    int encontrado;

    pf = (Profissional *)malloc(sizeof(Profissional));

    limpar_tela();
    exibir_moldura_titulo("Busca - Profissionais");
    printf("Informe o ID do Profissional: ");
    scanf("%d", &id_busca);
    limpar_buffer_entrada();

    encontrado = false;
    arq_profissionais = fopen("data/arq_profissionais.dat", "rb");

    if (arq_profissionais == NULL) {
        exibir_moldura_titulo("Erro na abertura do arquivo");
        free(pf);
        return;
    }
    while (fread(pf, sizeof(Profissional), 1, arq_profissionais)) {
        if ((pf->id_profissional == id_busca) && (pf->status == true)) {
            exibir_moldura_titulo("Profissional Encontrado!");
            exibir_profissional(pf);
            encontrado = true;
            break;
        }
    }
    if (encontrado == false) {
        exibir_moldura_titulo("Profissional não encontrado!");
    }

    fclose(arq_profissionais);
    free(pf);
    pausar();
}


void alterar_profissional(void) {
    FILE *arq_profissionais;
    FILE *arq_profissionais_temp;

    Profissional *pf;

    int id_busca;
    int encontrado;
    char opcao;
    char continuar;

    pf = (Profissional *)malloc(sizeof(Profissional));

    limpar_tela();
    exibir_moldura_titulo("Alteração - Profissionais");
    printf("Informe o ID do Profissional: ");
    scanf("%d", &id_busca);
    limpar_buffer_entrada();

    encontrado = false;

    arq_profissionais = fopen("data/arq_profissionais.dat", "rb");
    arq_profissionais_temp = fopen("data/arq_profissionais_temp.dat", "wb");

    if (arq_profissionais == NULL || arq_profissionais_temp == NULL) {
        exibir_moldura_titulo("Erro na abertura dos arquivos");
        free(pf);
        return;
    }

    while (fread(pf, sizeof(Profissional), 1, arq_profissionais)) {
        if ((pf->id_profissional == id_busca) && (pf->status == true)) {
            encontrado = true;

            do {
                limpar_tela();
                exibir_moldura_titulo("Dados atuais do profissional");
                exibir_profissional(pf);

                const char *menu_alt = "\nQual campo deseja alterar?\n"
                                       "1. Nome\n"
                                       "2. CPF\n"
                                       "3. Telefone\n"
                                       "4. CRN\n";
                exibir_moldura_conteudo(menu_alt);
                printf("Escolha uma opção: ");
                scanf(" %c", &opcao);
                limpar_buffer_entrada();

                switch (opcao) {
                    case '1':
                        ler_nome(pf->nome);
                        break;
                    case '2':
                        ler_cpf(pf->cpf);
                        break;
                    case '3':
                        ler_tel(pf->tel);
                        break;
                    case '4':
                        ler_crn(pf->crn);
                        break;
                    default:
                        exibir_moldura_titulo("Opção inválida!");
                        break;
                }

                exibir_moldura_titulo("Dados atualizados");
                exibir_profissional(pf);

                printf("\nDeseja alterar outro campo? (S/N): ");
                scanf(" %c", &continuar);
                limpar_buffer_entrada();

                if (continuar == 0) {
                    exibir_moldura_titulo("Opção inválida! Digite apenas S ou N.");
                }

            } while (continuar == 'S');
        }
        fwrite(pf, sizeof(Profissional), 1, arq_profissionais_temp);
    }

    fclose(arq_profissionais);
    fclose(arq_profissionais_temp);

    if (encontrado == true) {
        remove("data/arq_profissionais.dat");
        rename("data/arq_profissionais_temp.dat", "data/arq_profissionais.dat");
        exibir_moldura_titulo("Profissional alterado com sucesso!");

    } else {
        remove("data/arq_profissionais_temp.dat");
        exibir_moldura_titulo("Profissional não encontrado!");
    }
    free(pf);
    pausar();
}


void excluir_profissional(void) {
    FILE *arq_profissionais;
    Profissional *pf;
    int id_busca;
    int encontrado;
    char resposta;

    pf = (Profissional *)malloc(sizeof(Profissional));

    limpar_tela();
    exibir_moldura_titulo("Exclusão - Profissionais");
    printf("Informe o ID do Profissional: ");
    scanf("%d", &id_busca);
    limpar_buffer_entrada();
    encontrado = false;

    arq_profissionais = fopen("data/arq_profissionais.dat", "r+b");

    if (arq_profissionais == NULL) {
        exibir_moldura_titulo("Erro na abertura do arquivo");
        free(pf);
        return;
    }

    while (fread(pf, sizeof(Profissional), 1, arq_profissionais)) {
        if ((pf->id_profissional == id_busca) && (pf->status == true)) {
            exibir_moldura_titulo("Profissional Encontrado!");
            exibir_profissional(pf);
            encontrado = true;

            do {
                printf("\nDeseja realmente excluir este Profissional? (S/N): ");
                scanf(" %c", &resposta);
                limpar_buffer_entrada();

                if (resposta == 0) {
                    exibir_moldura_titulo("Opção inválida! Digite apenas S ou N.");
                }
            } while (resposta == 0);

            if (resposta == 'S') {
                pf->status = false;
                fseek(arq_profissionais, (-1) * sizeof(Profissional), SEEK_CUR);
                fwrite(pf, sizeof(Profissional), 1, arq_profissionais);
                exibir_moldura_titulo("Profissional excluído com sucesso!");
            } else {
                exibir_moldura_titulo("Operação de exclusão cancelada.");
            }
            break;
        }
    }

    if (encontrado == false) {
        exibir_moldura_titulo("Profissional não encontrado!");
    }
    fclose(arq_profissionais);
    free(pf);
    pausar();
}


void exibir_profissional(const Profissional *pf) {
    if (pf == NULL) {
        exibir_moldura_titulo("Erro: profisional inexistente!");
        return;
    }
    printf("ID:         %d\n", pf->id_profissional);
    printf("Nome:       %s\n", pf->nome);
    printf("CPF:        %s\n", pf->cpf);
    printf("Telefone:   %s\n", pf->tel);
    printf("CRN:        %s\n", pf->crn);
    printf("Sexo:       %c\n", pf->sexo);
}