#include <stdio.h>
#include <stdlib.h>
#include "consultas.h"
#include "util.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"




void modulo_consultas(void) {
    char opcao;
    do {
        limpar_tela();
        opcao = consultas();
        switch(opcao) {
            case '1': cadastrar_consulta(); break;
            // case '2': buscar_consulta(); break;
            // case '3': alterar_consulta(); break;
            // case '4': excluir_consulta(); break;
        }
    } while (opcao != '0');  
}


char consultas(void){
    char opcao;
    printf("\n");
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                    = = = = =   Consultas   = = = = =                    ///\n");
    printf("///                                                                         ///\n");
    printf("///                    1. Cadastrar Consulta                                ///\n");
    printf("///                    2. Buscar Consulta                                   ///\n");
    printf("///                    3. Alterar Consulta                                  ///\n");
    printf("///                    4. Excluir Consulta                                  ///\n");
    printf("///                    0. Voltar ao Menu Principal                          ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                      Escolha a opção desejada:                          ///\n"RESET);
    scanf("%c", &opcao);
    getchar();
    return opcao;
}



void cadastrar_consulta(void){
    char nome[100], data[15], hora[10];
    char medico[100], observacoes[200];
    limpar_tela();

    printf("\n");
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                    = = = = =   Consultas   = = = = =                    ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = =  Cadastrar Consulta = = = = =                 ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Nome do Usuário:                                ///\n");
    scanf("%s", nome);
    getchar();
    printf("///                         Data da Consulta (DD/MM/AAAA):                  ///\n");
    scanf("%s", data);
    getchar();
    printf("///                         Hora da Consulta (HH:MM):                       ///\n");
    scanf("%s", hora);
    getchar();
    printf("///                         Nome do Médico:                                  ///\n");
    scanf("%s", medico);
    getchar();
    printf("///                         Observações:                                    ///\n");
    scanf("%s", observacoes);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                    Consulta cadastrada com sucesso!                     ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n"RESET);
}