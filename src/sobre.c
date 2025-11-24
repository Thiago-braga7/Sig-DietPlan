#include <stdio.h>
#include <stdlib.h>
#include "sobre.h"
#include "validacoes.h"
#include "uteis.h"




void sobre(void){
    exibir_moldura_titulo("SIG-DietPlan");
    printf("Sig-DietaPlan é um sistema desenvolvido na disciplina de Programação da UFRN,\n");
    printf("para auxiliar no planejamento e acompanhamento de dietas.\n\n");    
    printf("Ele permite:\n");
    printf("• Cadastro de usuários\n");
    printf("• Gestão dieta\n");
    printf("• Registro de consumos diários\n");
    printf("• Agendamento de consultas\n\n");
    pausar();
}



void sair(void){
    const char *info =
        "Obrigado por utilizar o SIG-DietPlan\n"
        "Até a próxima!\n"
        "Instagram: @thiago.braga9a | @gabrieluchoa_1 | @wallisonvsdias\n"
        "GitHub: Thiago-braga7 | GabrielUchoa17 | wallisonvsdias\n";

    limpar_tela();
    exibir_moldura_conteudo(info);
}
