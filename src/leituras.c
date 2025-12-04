#include "leituras.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "uteis.h"
#include "validacoes.h"


void ler_nome(char *nome) {
    int valido = 0;

    do {
        printf("Nome: \n");
        scanf(" %50s", nome);
        limpar_buffer_entrada();

        valido = validar_nome(nome);

        if (valido == 0) {
            exibir_moldura_titulo("Nome inválido! Digite novamente!");
        }

    } while (valido == 0);
}


void ler_cpf(char *cpf) {
    int valido = 0;

    do {
        printf("CPF (Apenas números): \n");
        scanf(" %s", cpf);
        limpar_buffer_entrada();

        valido = validar_cpf(cpf);

        if (valido == 0) {
            exibir_moldura_titulo("CPF inválido! Digite novamente!");
        }

    } while (valido == 0);
}


void ler_tel(char *tel) {
    int valido = 0;

    do {
        printf("Telefone (Apenas números):  \n");
        scanf(" %11s", tel);
        limpar_buffer_entrada();

        valido = validar_telefone(tel);

        if (valido == 0) {
            exibir_moldura_titulo("Telefone inválido! Digite novamente!");
        }

    } while (valido == 0);
}


void ler_idade(int *idade) {
    int valido = 0;

    do {
        printf("Idade: \n");
        scanf("%d", idade);
        limpar_buffer_entrada();

        valido = validar_idade(*idade);

        if (valido == 0) {
            exibir_moldura_titulo("Idade inválida! Digite novamente!");
        }

    } while (valido == 0);
}


void ler_peso(float *peso) {
    int valido = 0;

    do {
        printf("Peso (kg): \n");
        scanf("%f", peso);
        limpar_buffer_entrada();

        valido = validar_peso(*peso);

        if (valido == 0) {
            exibir_moldura_titulo("Peso inválido! Digite novamente!");
        }

    } while (valido == 0);
}


void ler_altura(float *altura) {
    int valido = 0;

    do {
        printf("Altura (m): \n");
        scanf("%f", altura);
        limpar_buffer_entrada();

        valido = validar_altura(*altura);

        if (valido == 0) {
            exibir_moldura_titulo("Altura inválida! Digite novamente!");
        }

    } while (valido == 0);
}


void ler_data(char *data) {
    int valido = 0;
    do {
        printf("Data (DD/MM/AAAA):  \n");
        scanf("%10s", data);
        limpar_buffer_entrada();

        valido = validar_data(data);

        if (valido == 0) {
            exibir_moldura_titulo("Data inválida! Digite novamente!");
        }

    } while (valido == 0);
}


void ler_hora(char *hora) {
    int valido = 0;
    do {
        printf("Hora de Atendimento(08:00 - 18:00): \n");
        scanf("%s", hora);
        limpar_buffer_entrada();

        valido = validar_hora(hora);

        if (valido == 0) {
            exibir_moldura_titulo("Hora inválida! Digite novamente!");
        }

    } while (valido == 0);
}


void ler_tipo(char *tipo) {
    int valido = 0;
    do {
        printf("Tipo de Agendamento: \n");
        scanf(" %50[^\n]", tipo);
        limpar_buffer_entrada();

        valido = validar_nome(tipo);

        if (valido == 0) {
            exibir_moldura_titulo("Texto inválido! Digite novamente!");
        }

    } while (valido == 0);
}


void ler_profissional(char *profissional) {
    int valido = 0;
    do {
        printf("Profissional Responsável: \n");
        scanf(" %50[^\n]", profissional);
        limpar_buffer_entrada();

        valido = validar_nome(profissional);

        if (valido == 0) {
            exibir_moldura_titulo("Nome inválido! Digite novamente!");
        }

    } while (valido == 0);
}


void ler_observacoes(char *observacoes) {
    int valido = 0;
    do {
        printf("Observações: \n");
        scanf("%200[^\n]", observacoes);
        limpar_buffer_entrada();

        valido = validar_observacao(observacoes);

        if (valido == 0) {
            exibir_moldura_titulo("Texto Digitado inválido! Digite novamente!");
        }

    } while (valido == 0);
}


void ler_medico(char *medico) {
    int valido = 0;
    do {
        printf("Nome do Médico: \n");
        scanf(" %50s", medico);
        limpar_buffer_entrada();

        valido = validar_nome(medico);

        if (valido == 0) {
            exibir_moldura_titulo("Nome inválido! Digite novamente!");
        }

    } while (valido == 0);
}


void ler_dieta(char *nome_dieta) {
    int valido = 0;
    do {
        printf("Nome da Dieta: \n");
        scanf(" %50s", nome_dieta);
        limpar_buffer_entrada();

        valido = validar_nome(nome_dieta);

        if (valido == 0) {
            exibir_moldura_titulo("Nome inválido! Digite novamente!");
        }

    } while (valido == 0);
}


void ler_calorias(float calorias) {
    int valido;
    do {
        printf("Total de Calorias: \n");
        scanf("%f", &calorias);
        limpar_buffer_entrada();

        valido = validar_calorias(calorias);

        if (valido == 0) {
            exibir_moldura_titulo("Calorias inválidas! Digite novamente!");
        }

    } while (valido == 0);
}


void ler_refeicoes(char *refeicoes) {
    int valido = 0;
    do {
        printf("Refeições (breve descrição): \n");
        scanf("%200[^\n]", refeicoes);
        limpar_buffer_entrada();

        valido = validar_observacao(refeicoes);

        if (valido == 0) {
            exibir_moldura_titulo("Texto Digitado inválido! Digite novamente!");
        }

    } while (valido == 0);
}


void ler_crn(char *crn) {
    int valido = 0;
    do {
        printf("CRN(Formato: CRN-X/XXXXX ): \n");
        scanf(" %11s", crn);
        limpar_buffer_entrada();
        valido = validar_crn(crn);

        if (valido == 0) {
            exibir_moldura_titulo("CRN inválido! Digite novamente!");
        }

    } while (valido == 0);
}


void ler_sexo(char *sexo) {
    int valido = 0;
    do {
        printf("Sexo(M/F/O): \n");
        scanf(" %c", sexo);
        limpar_buffer_entrada();
        *sexo = toupper(*sexo);
        valido = validar_sexo(*sexo);

        if (valido == 0) {
            exibir_moldura_titulo("Sexo inválido! Digite novamente!");
        }
    } while (valido == 0);
}