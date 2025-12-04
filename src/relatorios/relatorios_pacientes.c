#include "relatorios/relatorios_pacientes.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "pacientes.h"
#include "uteis.h"
#include "validacoes.h"

// Funções static são visíveis apenas dentro deste arquivo.
static char tela_relatorios_pacientes(void);
static void listar_pacientes(void);
static void listar_pacientes_idade(void);

// Função principal do submódulo de relatórios de pacientes
void relatorios_pacientes(void) {
    char opcao;

    do {
        limpar_tela();
        opcao = tela_relatorios_pacientes();

        switch (opcao) {
            case '1':
                listar_pacientes();
                break;
            case '2':
                listar_pacientes_idade();
                break;
        }

    } while (opcao != '0');
}

static char tela_relatorios_pacientes(void) {
    char opcao;

    const char *menu = "1. Lista Geral de Pacientes\n"
                       "2. Lista de Pacientes por Idade \n"
                       "0. Voltar ao Menu Anterior\n";

    exibir_moldura_titulo("Relatórios de Pacientes");
    exibir_moldura_conteudo(menu);

    printf("Escolha a opção desejada: ");
    scanf(" %c", &opcao);
    getchar();

    return opcao;
}

static void listar_pacientes(void) {
    FILE *arq_paciente;
    Paciente *pac;

    pac = (Paciente *)malloc(sizeof(Paciente));
    bool encontrado = 0;

    limpar_tela();
    exibir_moldura_titulo("Pacientes - Lista Geral");

    printf("║ %-30s ║ %-12s ║ %-7s ║ %-6s ║ %-6s ║\n", "Nome", "CPF", "Idade", "Peso", "Altura");
    printf("═════════════════════════════════════════════════════════════════════════════\n");

    arq_paciente = fopen("data/arq_pacientes.dat", "rb");
    if (arq_paciente == NULL) {
        exibir_moldura_titulo("Nenhum paciente cadastrado ainda");
        free(pac);
        return;
    }

    while (fread(pac, sizeof(Paciente), 1, arq_paciente)) {
        if (pac->status) {
            encontrado = 1;
            printf("║ %-30s ║ %-12s ║ %7d ║ %6.2f ║ %6.2f ║\n",
                   pac->nome,
                   pac->cpf,
                   pac->idade,
                   pac->peso,
                   pac->altura);
        }
    }

    if (!encontrado) {
        exibir_moldura_titulo("Nenhum paciente ativo encontrado");
    }

    fclose(arq_paciente);
    free(pac);

    pausar();
}

static void listar_pacientes_idade(void) {
    // Implementação da função...
    // (O código original desta função pode ser copiado para cá)
    exibir_moldura_titulo("Função 'Listar por Idade' ainda não implementada neste exemplo.");
    pausar();
}