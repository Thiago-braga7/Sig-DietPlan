#include <stdio.h>
#include <string.h>
#include "validacoes.h"



void ler_nome(char *nome) {
    int valido = 0;

    do{
        printf("///                                 Nome:                                   ///\n");
        scanf(" %50s", nome); 
        getchar();

        valido = validar_nome(nome);

        if(valido == 0){
            printf("Nome inválido! Digite novamente! \n");
        }
    } while (valido == 0);
}


void ler_cpf(char *cpf) {
    int valido = 0;

    do{
        printf("///                        CPF (Apenas números):                       ///\n");
        scanf(" %s", cpf); 
        getchar();

        valido = validar_cpf(cpf);

        if(valido == 0){
            printf("CPF inválido! Digite novamente! \n");
        }
    } while (valido == 0);
}


void ler_tel(char *tel) {
    int valido = 0;
    
    do{
        printf("///                         Telefone (Apenas números):                      ///\n");
        scanf(" %11s", tel); 
        getchar();

        valido = valida_telefone(tel);

        if(valido == 0){
            printf("Telefone inválido! Digite novamente! \n");
        }
    } while (valido == 0);
}


void ler_idade(char *idade) {
    int valido = 0;

    do{
        printf("///                         Idade:                                          ///\n");
        scanf("%s", idade); 
        getchar();

        valido = valida_idade(idade);

        if(valido == 0){
            printf("Idade inválida! Digite novamente! \n");
        }
    } while (valido == 0);
}


void ler_peso(float peso) {
    int valido = 0;

    do{
        printf("///                       Peso (kg):                                      ///\n");
        scanf("%f", &peso); 
        getchar();

        valido = validar_peso(peso);

        if(valido == 0){
            printf("Peso inválido! Digite novamente! \n");
        }
    } while (valido == 0);
}


void ler_altura(float altura) {
    int valido = 0;
    
    do{
        printf("///                      Altura (m):                                     ///\n");
        scanf("%f", &altura); 
        getchar();

        valido = validar_altura(altura);

        if(valido == 0){
            printf("Altura inválida! Digite novamente! \n");
        }
    } while (valido == 0);
}

void ler_data(char *data){
    int valido = 0;
    do{
        printf("///                         Data (DDMMAAAA):                                ///\n");
        scanf("%s", data); 
        getchar();

        valido = valida_data(data);

        if(valido == 0){
            printf("Data inválida! Digite novamente! \n");
        }
    } while (valido == 0);
}

void ler_hora(char *hora){
    int valido = 0;
    do{
        printf("///                         Hora de Atendimento(08:00 - 18:00):            ///\n");
        scanf("%s", hora); 
        getchar();

        valido = validar_hora(hora);

        if(valido == 0){
            printf("Hora inválida! Digite novamente! \n");
        }
    } while (valido == 0);
}

void ler_tipo(char *tipo){
    int valido = 0;
    do{
        printf("///                         Tipo de Agendamento:                            ///\n");
        scanf(" %50[^\n]", tipo); 
        getchar();

        valido = validar_nome(tipo);

        if(valido == 0){
            printf("Texto inválido! Digite novamente! \n");
        }
    } while (valido == 0);
}


void ler_profissional(char *profissional){
    int valido = 0;
     do{
        printf("///                         Profissional Responsável:                       ///\n");
        scanf(" %50[^\n]", profissional); 
        getchar();

        valido = validar_nome(profissional);

        if(valido == 0){
            printf("Nome inválido! Digite novamente! \n");
        }
    } while (valido == 0);
}

void ler_observacoes(char *observacoes){
    int valido = 0;
    do{
        printf("///                         Observações:                                      ///\n");
        scanf("%200[^\n]", observacoes); 
        getchar();

        valido = validar_observacao(observacoes);

        if(valido == 0){
            printf("Texto Digitado inválido! Digite novamente! \n");
        }
    } while (valido == 0);
}

void ler_medico(char *medico){
    int valido = 0;
    do{
        printf("///                         Nome do Médico:                                  ///\n");
        scanf(" %50s", medico); 
        getchar();

        valido = validar_nome(medico);

        if(valido == 0){
            printf("Nome inválido! Digite novamente! \n");
        }
    } while (valido == 0);
}

void ler_dieta(char *nome_dieta){
    int valido = 0;
    do{
        printf("///                         Nome da Dieta:                                  ///\n");
        scanf(" %50s", nome_dieta); 
        getchar();

        valido = validar_nome(nome_dieta);

        if(valido == 0){
            printf("Nome inválido! Digite novamente! \n");
        }
    } while (valido == 0);
}

void ler_calorias(float calorias){
    int valido = 0;
    do{
        printf("///                         Total de Calorias:                              ///\n");
        scanf("%f", &calorias);
        getchar();

        valido = validar_calorias(calorias);

        if(valido == 0){
            printf("Calorias inválidas! Digite novamente! \n");
        }
    } while (valido == 0);
}

void ler_refeicoes(char *refeicoes){
    int valido = 0;
    do{
        printf("///                         Refeições (breve descrição):                    ///\n");
        scanf("%200[^\n]", refeicoes);
        getchar();

        valido = validar_observacao(refeicoes);

        if(valido == 0){
            printf("Texto Digitado inválido! Digite novamente! \n");
        }
    } while (valido == 0);
}

void ler_crn(char *crn){
    int valido = 0;
     do{
        printf("///                         CRN(Formato: CRN-X/XXXXX ):                     ///\n");
        scanf(" %11s", crn);
        getchar();
        valido = valida_crn(crn);

        if (valido == 0){
            printf("CRN inválido! Digite novamente! \n");
        }

    } while (valido == 0);
}
