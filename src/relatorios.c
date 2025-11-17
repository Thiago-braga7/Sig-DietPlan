#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "relatorios.h"
#include "pacientes.h"
#include "dietas.h"
#include "profissionais.h"
#include "consultas.h"
#include "agendamentos.h"
#include "uteis.h"
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
            case '3': listar_profissionais(); break;
            case '4': listar_consultas(); break;
            case '5': listar_agendamentos(); break;
            case '6': listar_pacientes_idade(); break;
        }
    } while (opcao != '0');  
}



char tela_relatorios(void) {
    char opcao;

    const char *menu =
        "1. Lista geral de Pacientes\n"
        "2. Lista geral de Dietas\n"
        "3. Lista geral de Profissionais\n"
        "4. Lista geral de Consultas\n"
        "5. Lista geral de Agendamentos\n"
        "6. Lista geral de Pacientes - Idade\n"
        "0. Voltar ao Menu Principal";

    exibir_moldura_titulo("Relatórios");
    exibir_moldura_conteudo(menu);

    printf("║ Escolha a opção desejada: ");
    scanf(" %c", &opcao);
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
    exibir_moldura_titulo("Pacientes - Lista Geral");
    

    arq_paciente = fopen("data/arq_pacientes.dat", "rb");    
    if (arq_paciente == NULL) {
        exibir_moldura_titulo("Nenhum paciente cadastrado ainda");
        free(pac);
        return;
    }

    while (fread(pac, sizeof(Paciente), 1, arq_paciente)){
        if (pac->status) {
            encontrado = 1;
            printf("\n");
            exibir_paciente(pac);
            printf("\n");
            printf("════════════════════════════════════════════════════════════════════════════\n");
        }
    }

    if (!encontrado) {
        exibir_moldura_titulo("Nenhum paciente ativo encontrado");
    }

    fclose(arq_paciente);
    free(pac);

    pausar();
}



void listar_pacientes_idade(void) {
    FILE *arq_paciente;
    Paciente* pac;

    pac = (Paciente*)malloc(sizeof(Paciente));
    bool encontrado = 0;

    int idade_min;
    int idade_max;

    limpar_tela();
    exibir_moldura_titulo("Pacientes - Lista por idade");
    
    printf("Digite a idade mínima:");
    scanf("%d", &idade_min);

    printf("Digite a idade máxima:");
    scanf("%d", &idade_max);

    arq_paciente = fopen("data/arq_pacientes.dat", "rb");    
    if (arq_paciente == NULL) {
        exibir_moldura_titulo("Nenhum paciente cadastrado ainda");
        free(pac);
        return;
    }

    while (fread(pac, sizeof(Paciente), 1, arq_paciente)){
        if (pac->status) {
            if (pac->idade >= idade_min && pac->idade <= idade_max) {
                encontrado = 1;
                printf("\n");
                exibir_paciente(pac);
                printf("\n");
                printf("════════════════════════════════════════════════════════════════════════════\n");
            }
        }
    }

    if (!encontrado) {
        exibir_moldura_titulo("Nenhum paciente ativo encontrado");
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
        exibir_moldura_titulo("Nenhuma dieta cadastrada ainda");
        free(dt);
        return;
    }

    limpar_tela();
    exibir_moldura_titulo("Dietas - Lista Geral");

    while (fread(dt, sizeof(Dieta), 1, arq_dietas)) {
        if (dt->status == true) {
            printf("\n");
            exibir_dieta(dt);
            printf("\n");
            printf("════════════════════════════════════════════════════════════════════════════\n");
        }
    }

    fclose(arq_dietas);
    free(dt);
    pausar();
}



void listar_profissionais(void) {
    FILE * arq_profissionais;
    Profissional * pf;

    pf = (Profissional*) malloc(sizeof(Profissional));
    
    arq_profissionais = fopen("data/arq_profissionais.dat", "rb");
    if (arq_profissionais == NULL) {
        exibir_moldura_titulo("Nenhum profissional cadastrado ainda");
        free(pf);
        return;
    }

    limpar_tela();
    exibir_moldura_titulo("Profissionais - Lista Geral");

    while(fread(pf, sizeof(Profissional), 1, arq_profissionais)){
        if (pf->status == true){
            printf("\n");
            exibir_profissional(pf);
            printf("\n");
            printf("════════════════════════════════════════════════════════════════════════════\n");            
        }
    }

    fclose(arq_profissionais);
    free(pf);

    pausar();
}



// Lista todas as consultas ativas
void listar_consultas(void){
    FILE *arq_consulta;
    Consulta* con;

    con = (Consulta*) malloc(sizeof(Consulta));
    
    arq_consulta = fopen("data/arq_consulta.dat", "rb");

    if (arq_consulta == NULL) {
        exibir_moldura_titulo("Nenhuma consulta cadastrada ainda");
        free(con);
        return;
    }

    limpar_tela();
    exibir_moldura_titulo("Consultas - Lista Geral");

    while (fread(con, sizeof(Consulta), 1, arq_consulta)) {
        if (con->status == true) {  
            printf("\n");
            exibir_consulta(con);
            printf("\n");
            printf("════════════════════════════════════════════════════════════════════════════\n");   
        }
    }

    fclose(arq_consulta);
    free(con);

    pausar();
}



void listar_agendamentos(void){
    FILE * arq_agendamentos;
    Agendamento * ag;

    ag = (Agendamento*) malloc(sizeof(Agendamento));
    
    arq_agendamentos = fopen("data/arq_agendamentos.dat", "rb");
    if (arq_agendamentos == NULL) {
        exibir_moldura_titulo("Nenhum agendamento cadastrado ainda");
        free(ag);
        return;
    }

    limpar_tela();
    exibir_moldura_titulo("Agendamentos - Lista Geral");

    while(fread(ag, sizeof(Agendamento), 1, arq_agendamentos)){
        if (ag->status == true){
            printf("\n");
            exibir_agendamento(ag);
            printf("\n");
            printf("════════════════════════════════════════════════════════════════════════════\n");   
        }
    }

    fclose(arq_agendamentos);
    free(ag);

    pausar();
}