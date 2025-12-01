#include <stdio.h>
#include <stdlib.h>
#include "sobre.h"
#include "validacoes.h"
#include "uteis.h"


void sobre(void) {
    const char *info =
        "Sig-DietaPlan é um sistema desenvolvido na disciplina de Programação\n"
        "da UFRN, para auxiliar no planejamento e acompanhamento de dietas.\n"
        "Ele permite:\n"
        "- Cadastro de pacientes e profissionais\n"
        "- Gestão de dietas\n"
        "- Agendamento de consultas\n"
        "- Relatórios completos\n";

    exibir_moldura_titulo("SIG-DietPlan");
    exibir_moldura_conteudo(info);

    pausar();
}


void sair(void) {
    const char *info =
        "Obrigado por utilizar o SIG-DietPlan\n"
        "Até a próxima!\n"
        "Instagram: @thiago.braga9a | @gabrieluchoa_1 | @wallisonvsdias\n"
        "GitHub: Thiago-braga7 | GabrielUchoa17 | wallisonvsdias\n";

    limpar_tela();
    exibir_moldura_conteudo(info);
}