#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define RESET   "\033[0m"
#define RED     "\033[31m"


char ler_genero(void) {
    char genero;
    do {
        printf("Informe seu gênero (M = Masculino, F = Feminino, N = Prefiro não informar): ");
        scanf(" %c", &genero);
        genero = toupper(genero);

        if (genero != 'M' && genero != 'F' && genero != 'N') {
            printf("Opção inválida! Digite apenas M, F ou N.\n");
        }
    } while (genero != 'M' && genero != 'F' && genero != 'N');

    return genero;
}

char confirmar_acao(void) {
    char confirmacao;

    do {
        printf("Deseja confirmar a ação? (S/N): ");
        scanf(" %c", &confirmacao);  
        getchar(); 
        confirmacao = toupper(confirmacao);

        if (confirmacao != 'S' && confirmacao != 'N') {
            printf("Opção inválida! Digite apenas S ou N.\n");
        }
    } while (confirmacao != 'S' && confirmacao != 'N');
    return confirmacao;
}

void limpar_tela(void){
    system("clear||cls");
}
void pausar(void) {
    printf("\nPressione ENTER para continuar...");
    getchar();
    getchar();
}

float imc(float peso, float altura) {
    if (altura <= 0) {
        return -1.0f; 
    }
    return peso / (altura * altura);
}

float calcular_quantidade_agua(float peso, char genero){
     if(genero == 'M') {
        return peso * 0.04;    
    } else if(genero == 'F') {
        return peso * 0.035;   
    } else {
        return peso * 0.0375;  
    }

}

void faixa_peso_ideal(float altura) {
    if (altura <= 0) {
        printf("Altura inválida!\n");
        return;
    }

    float peso_min = 18.5 * altura * altura;
    float peso_max = 24.9 * altura * altura;

    printf("Peso ideal para sua altura: entre %.1fkg e %.1fkg\n", peso_min, peso_max);
}
void classificar_bf(char sexo, float bf) {
    sexo = toupper(sexo);

    if (sexo != 'M' && sexo != 'F') {
        printf("Sexo inválido!\n");
        return;
    }

    printf("\nSeu percentual de gordura é: %.1f%%\n", bf);

    if (sexo == 'M') {
        if (bf < 6) {
            printf("Classificação: Muito abaixo do ideal\n");
        } else if (bf <= 13) {
            printf("Classificação: Atleta\n");
        } else if (bf <= 17) {
            printf("Classificação: Fitness\n");
        } else if (bf <= 24) {
            printf("Classificação: Normal\n");
        } else if (bf <= 29) {
            printf("Classificação: Acima do ideal\n");
        } else {
            printf("Classificação: Obeso\n");
        }
    } else if (sexo == 'F') {
        if (bf < 14) {
            printf("Classificação: Muito abaixo do ideal\n");
        } else if (bf <= 20) {
            printf("Classificação: Atleta\n");
        } else if (bf <= 24) {
            printf("Classificação: Fitness\n");
        } else if (bf <= 31) {
            printf("Classificação: Normal\n");
        } else if (bf <= 37) {
            printf("Classificação: Acima do ideal\n");
        } else {
            printf("Classificação: Obesa\n");
        }
    }
}

void logo(void){
    printf("\n");
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("░█▀▀▀█ ▀█▀ ░█▀▀█ ── ░█▀▀▄ ─▀─ █▀▀ ▀▀█▀▀ ░█▀▀█ █── █▀▀█ █▀▀▄ \n");
    printf("─▀▀▀▄▄ ░█─ ░█─▄▄ ▀▀ ░█─░█ ▀█▀ █▀▀ ──█── ░█▄▄█ █── █▄▄█ █──█ \n");
    printf("░█▄▄▄█ ▄█▄ ░█▄▄█ ── ░█▄▄▀ ▀▀▀ ▀▀▀ ──▀── ░█─── ▀▀▀ ▀──▀ ▀──▀ \n");                                                                                       
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n"RESET);
}

void mensagem_boas_vindas(const char *nome, char genero){
    if (genero == 'M') {
        printf("\nBem-vindo 😁, %s!\n", nome);
    } else if (genero == 'F') {
        printf("\nBem-vinda 😁, %s!\n", nome);
    } else {
        printf("\nBem-vindo(a) 😁, %s!\n", nome);
    }
    pausar();
}
float ler_peso(void) {
    float peso;
    do {
        printf("Informe seu peso (Kg): ");
        scanf("%f", &peso);
        getchar();
        if (peso <= 0) {
            printf("Peso inválido! Digite um valor maior que 0.\n");
        }
    } while (peso <= 0);
    return peso;
}

