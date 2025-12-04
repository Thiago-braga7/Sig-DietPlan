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
#include "relatorios/relatorios_consultas.h"
#include "relatorios/relatorios_dietas.h"
#include "relatorios/relatorios_pacientes.h"
#include "relatorios/relatorios_profissionais.h"
#include "uteis.h"
#include "validacoes.h"


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