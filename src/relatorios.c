#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "relatorios.h"
#include "pacientes.h"
#include "dietas.h"
#include "validacoes.h"
#include "leituras.h"


#define RESET   "\033[0m"
#define GREEN   "\033[32m"


void modulo_relatorios(void) {
    char opcao;

    do {
        limpar_tela();
        opcao = tela_relatorios();

        switch(opcao) {
            case '1': listar_pacientes(); break;
            case '2': listar_dietas(); break;
        }
    } while (opcao != '0');  
}



char tela_relatorios(void){
    char opcao;
    printf("\n");
    printf(GREEN"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                     = = = = =   Relatórios  = = = = =                   ///\n");
    printf("///                                                                         ///\n");
    printf("///                    1. Lista geral de Pacientes                          ///\n");
    printf("///                    2. Lista geral de Dietas                             ///\n");
    printf("///                    3. Lista geral de Profissionais                      ///\n");
    printf("///                    4. Lista geral de Consultas                          ///\n");
    printf("///                    5. Lista geral de Agendamentos                       ///\n");
    printf("///                    0. Voltar ao Menu Principal                          ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                      Escolha a opção desejada: "RESET);
    scanf("%c", &opcao);
    getchar();
    return opcao;
}



// Lista todos os pacientes ativos
void listar_pacientes(void) {
    FILE *arq_paciente;
    Paciente* pac;

    pac = (Paciente*)malloc(sizeof(Paciente));
    bool encontrado = 0;

    limpar_tela();
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                               Pacientes                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = = Lista de Pacientes = = = = =                  ///\n");

    arq_paciente = fopen("data/arq_pacientes.dat", "rb");    
    if (arq_paciente == NULL) {
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                    Nenhum paciente cadastrado ainda!                    ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        free(pac);
        return;
    }

    while (fread(pac, sizeof(Paciente), 1, arq_paciente)){
        if (pac->status) {
            encontrado = 1;
            printf("\n");
            exibir_paciente(pac);
            printf("\n");
            printf("///////////////////////////////////////////////////////////////////////////////\n");
        }
    }

    if (!encontrado) {
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                    Nenhum paciente ativo encontrado!                    ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
    }

    fclose(arq_paciente);
    free(pac);

    pausar();
}



void listar_dietas(void) {
    FILE *arq_dietas;
    Dieta* dt;

    dt = (Dieta*) malloc(sizeof(Dieta));
    
    arq_dietas = fopen("data/arq_dietas.dat", "rb");
    if (arq_dietas == NULL) {
        printf("Nenhuma dieta cadastrada ainda.\n");
        free(dt);
        return;
    }

    limpar_tela();
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                               Dietas                                    ///\n");
    printf("///                                                                         ///\n");
    printf("///                  = = = = =  Listar Dietas  = = = = =                    ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    while (fread(dt, sizeof(Dieta), 1, arq_dietas)) {
        if (dt->status == true) {  
            exibir_dieta(dt);
            printf("--------------------------------------------------\n");
        }
    }

    fclose(arq_dietas);
    free(dt);
    pausar();
}