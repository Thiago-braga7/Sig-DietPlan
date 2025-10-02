#include <stdio.h>
#include <stdlib.h>
#include "profissionais.h"
#include "util.h"
#include <string.h>




void modulo_profissionais(void) {
    char opcao;
    do {
        limpar_tela();
        opcao = tela_profissionais();
        switch(opcao) {
            // case '1': cadastrar_profissional(); break;
            // case '2': buscar_profissional(); break;
            // case '3': alterar_profissional(); break;
            // case '4': excluir_profissional(); break;
        }
    } while (opcao != '0');  
}

char tela_profissionais(void){
    char opcao;
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                  = = = = =  Agendamentos  = = = = =                     ///\n");
    printf("///                                                                         ///\n");
    printf("///                    1. Cadastrar Agendamento                             ///\n");
    printf("///                    2. Buscar Agendamento                                ///\n");
    printf("///                    3. Alterar Agendamento                               ///\n");
    printf("///                    4. Excluir Agendamento                               ///\n");
    printf("///                    0. Voltar ao Menu Principal                          ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                      Escolha a opção desejada:                          ///\n");
    scanf("%c", &opcao);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    return opcao;
}