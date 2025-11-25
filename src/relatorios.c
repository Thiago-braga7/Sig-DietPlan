#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "relatorios.h"
#include "pacientes.h"
#include "dietas.h"
#include "profissionais.h"
#include "consultas.h"
#include "agendamentos.h"
#include "uteis.h"
#include "validacoes.h"
#include "leituras.h"




void modulo_relatorios(void) {
    char opcao;

    do {
        limpar_tela();
        opcao = tela_relatorios();

        switch(opcao) {
            case '1':
                listar_pacientes();
                break;
            case '2':
                listar_dietas();
                break;
            case '3':
                listar_profissionais();
                break;
            case '4':
                listar_consultas();
                break;
            case '5':
                listar_agendamentos();
                break;
            case '6':
                listar_pacientes_idade();
                break;
            case '7':
                listar_consultas_medico();
                break;
            case '8':
                listar_dietas_calorias();
                break;
            case '9':
                listar_agendamentos_paciente();
                break;
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
        "6. Lista de Pacientes por Idade\n"
        "7. Lista de Consultas por Médico\n"
        "8. Lista de Dietas por Calorias\n"
        "9. Lista de Agendamentos por Paciente\n"
        "0. Voltar ao Menu Principal";

    exibir_moldura_titulo("Relatórios");
    exibir_moldura_conteudo(menu);

    printf("Escolha a opção desejada: ");
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
    
    printf("║ %-30s ║ %-12s ║ %-7s ║ %-6s ║ %-6s ║\n", "Nome", "CPF", "Idade", "Peso", "Altura");
    printf("═════════════════════════════════════════════════════════════════════════════\n");

    arq_paciente = fopen("data/arq_pacientes.dat", "rb");    
    if (arq_paciente == NULL) {
        exibir_moldura_titulo("Nenhum paciente cadastrado ainda");
        free(pac);
        return;
    }

    while (fread(pac, sizeof(Paciente), 1, arq_paciente)){
        if (pac->status) {
            encontrado = 1;
            printf("║ %-30s ║ %-12s ║ %7d ║ %6.2f ║ %6.2f ║\n",
                pac->nome, pac->cpf, pac->idade, pac->peso, pac->altura);
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



void listar_consultas_medico(void) {
    FILE *arq_consulta;
    Consulta* con;

    con = (Consulta*) malloc(sizeof(Consulta));

    char med_busca[50];
    
    arq_consulta = fopen("data/arq_consulta.dat", "rb");

    printf("Digite o nome do médico: \n");
    scanf("%s", med_busca);

    if (arq_consulta == NULL) {
        exibir_moldura_titulo("Nenhuma consulta cadastrada ainda");
        free(con);
        return;
    }

    limpar_tela();
    exibir_moldura_titulo("Consultas - Lista Médico");

    while (fread(con, sizeof(Consulta), 1, arq_consulta)) {
        if (con->status == true) {  
            if (strcmp(med_busca, con->medico) == 0) {
                printf("\n");
                exibir_consulta(con);
                printf("\n");
                printf("════════════════════════════════════════════════════════════════════════════\n");  
            }             
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



void listar_dietas_calorias(void) {
    FILE *arq_dietas;
    Dieta* dt;

    dt = (Dieta*) malloc(sizeof(Dieta));
    bool encontrado = 0;

    int calorias_min;
    int calorias_max;

    limpar_tela();
    exibir_moldura_titulo("Dietas - Lista por Calorias");
    
    printf("Digite a quantidade mínima de calorias: ");
    scanf("%d", &calorias_min);

    printf("Digite a quantidade máxima de calorias: ");
    scanf("%d", &calorias_max);

    arq_dietas = fopen("data/arq_dietas.dat", "rb");    
    if (arq_dietas == NULL) {
        exibir_moldura_titulo("Nenhuma dieta cadastrada ainda");
        free(dt);
        return;
    }

    while (fread(dt, sizeof(Dieta), 1, arq_dietas)){
        if (dt->status) {
            if (dt->calorias >= calorias_min && dt->calorias <= calorias_max) {
                encontrado = 1;
                printf("\n");
                exibir_dieta(dt);
                printf("\n");
                printf("════════════════════════════════════════════════════════════════════════════\n");
            }
        }
    }

    if (!encontrado) {
        exibir_moldura_titulo("Nenhuma dieta encontrada nesse intervalo de calorias");
    }

    fclose(arq_dietas);
    free(dt);

    pausar();
}


void listar_agendamentos_paciente(void) {
    FILE *arq_agendamentos;
    FILE *arq_pacientes;
    Agendamento *ag;
    Paciente *pac;

    ag = (Agendamento*) malloc(sizeof(Agendamento));
    pac = (Paciente*) malloc(sizeof(Paciente));

    char cpf_busca[13];

    limpar_tela();
    exibir_moldura_titulo("Agendamentos - Lista por CPF");

    printf("Digite o CPF do paciente (Apenas Números): ");
    scanf("%s", cpf_busca);
    getchar();

    printf("║ %-30s ║ %15s ║ %11s ║ %7s ║ %10s ║ %12s ║ %14s ║\n", "Nome", "ID Agendamento", "Data", "Hora", "Tipo", "Profissional", "Observações");
    printf("═════════════════════════════════════════════════════════════════════════════\n");

    arq_agendamentos = fopen("data/arq_agendamentos.dat", "rb");    
    if (arq_agendamentos == NULL) {
        exibir_moldura_titulo("Nenhum agendamento cadastrado ainda");
        free(ag);
        return;
    }

    bool encontrado = 0;

    while (fread(ag, sizeof(Agendamento), 1, arq_agendamentos)){
        if (ag->status) {
            if (strcmp(ag->cpf, cpf_busca) == 0) {
                encontrado = 1;

                arq_pacientes = fopen("data/arq_pacientes.dat", "rb");
                
                if (arq_pacientes != NULL) {
                    while (fread(pac, sizeof(Paciente), 1, arq_pacientes)) {
                        if (pac->status && strcmp(pac->cpf, cpf_busca) == 0) {
                            break;
                        }
                    }
                    fclose(arq_pacientes);
                }

                printf("║ %-30s ║ %15d ║ %11s ║ %7s ║ %10s ║ %12s ║ %12s ║\n",
                pac->nome, ag->id_agendamento, ag->data, ag->hora, ag->tipo, ag->profissional, ag->observacoes);
                printf("════════════════════════════════════════════════════════════════════════════\n");
            }
        }
    }

    if (!encontrado) {
        exibir_moldura_titulo("Nenhum agendamento encontrado para esse CPF");
    }

    fclose(arq_agendamentos);
    free(ag);
    pausar();
}



void listar_profissionais_sexo(void) {
    FILE *arq;
    Profissional *pf;
    char sexo_busca;
    bool encontrado = false;

    pf = (Profissional*) malloc(sizeof(Profissional));
    if (!pf) return;

    limpar_tela();
    exibir_moldura_titulo("Profissionais - Lista por Sexo");

    printf("Digite o sexo para buscar (M/F/O): ");
    scanf(" %c", &sexo_busca);
    sexo_busca = toupper((unsigned char)sexo_busca);
    while (getchar() != '\n');

    arq = fopen("data/arq_profissionais.dat", "rb");
    if (arq == NULL) {
        exibir_moldura_titulo("Nenhum profissional cadastrado ainda");
        free(pf);
        return;
    }

    while (fread(pf, sizeof(Profissional), 1, arq)) {
        if (pf->status && pf->sexo == sexo_busca) {
            encontrado = true;
            printf("\n");
            exibir_profissional(pf);
            printf("\n════════════════════════════════════════════════════════════════════════════\n");
        }
    }

    if (!encontrado) {
        exibir_moldura_titulo("Nenhum profissional encontrado para esse sexo");
    }

    fclose(arq);
    free(pf);
    pausar();
}