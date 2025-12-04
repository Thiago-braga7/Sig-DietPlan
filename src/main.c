#include <stdio.h>
#include <stdlib.h>

#include "agendamentos.h"
#include "consultas.h"
#include "dietas.h"
#include "pacientes.h"
#include "profissionais.h"
#include "relatorios.h"
#include "sobre.h"
#include "uteis.h"
#include "validacoes.h"


void menu_principal(void);

int main(void) {
    char opcao;

    sobre();
    do {
        menu_principal();
        printf("Escolha uma opção: ");
        scanf(" %c", &opcao);
        limpar_buffer_entrada();

        switch (opcao) {
            case '1':
                modulo_pacientes();
                break;
            case '2':
                modulo_dietas();
                break;
            case '3':
                modulo_profissionais();
                break;
            case '4':
                modulo_consultas();
                break;
            case '5':
                modulo_agendamentos();
                break;
            case '6':
                modulo_relatorios();
                break;
            case '0':
                sair();
                break;
        }
    } while (opcao != '0');

    return 0;
}


void menu_principal(void) {
    const char *cabecalho = "Universidade Federal do Rio Grande do Norte\n"
                            "Centro de Ensino Superior do Seridó\n"
                            "Departamento de Computação e Tecnologia\n"
                            "Disciplina DCT1106 -- Programação\n"
                            "Projeto Sistema de Planejamento de Dietas (SIG-DietPlan)\n"
                            "Criado por @thiagobraga9a, @gabrieluchoa_1 e @wallisonvsdias\n"
                            "Desde Agosto de 2025\n";

    const char *menu = "1. Pacientes\n"
                       "2. Dietas\n"
                       "3. Profissionais\n"
                       "4. Consultas\n"
                       "5. Agendamentos\n"
                       "6. Relatórios\n"
                       "0. Sair\n";

    limpar_tela();
    exibir_moldura_conteudo(cabecalho);
    exibir_moldura_titulo("Planejamento de Dietas");
    exibir_moldura_conteudo(menu);
}