#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define CYAN "\x1B[36m"


char ler_genero(void) {
    char genero;
    do {
        
        printf(CYAN"Informe seu gênero (M = Masculino, F = Feminino, N = Prefiro não informar): "RESET);
        scanf(" %c", &genero);
        genero = toupper(genero);

        if (genero != 'M' && genero != 'F' && genero != 'N') {
            printf(CYAN"Opção inválida! Digite apenas M, F ou N.\n"RESET);
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


void classificação_imc(float resultado){

if (resultado < 18.5) {
    printf(RED"| >> < 18.5       |   Abaixo do peso       |       ~7%%      << |\n"RESET);
    printf("|    18.5-24.9    |   Peso normal          |      ~38%%      |\n");
    printf("|    25-29.9      |   Sobrepeso            |      ~35%%      |\n");
    printf("|    30-34.9      |   Obesidade grau I     |      ~12%%      |\n");
    printf("|    35-39.9      |   Obesidade grau II    |       ~5%%      |\n");
    printf("|     >=40        |   Obesidade grau III   |       ~3%%      |\n");
} else if (resultado < 24.9) {
    printf("|    < 18.5       |   Abaixo do peso       |       ~7%%      |\n");
    printf(RED"| >> 18.5-24.9    |   Peso normal          |      ~38%%      << |\n"RESET);
    printf("|    25-29.9      |   Sobrepeso            |      ~35%%      |\n");
    printf("|    30-34.9      |   Obesidade grau I     |      ~12%%      |\n");
    printf("|    35-39.9      |   Obesidade grau II    |       ~5%%      |\n");
    printf("|     >=40        |   Obesidade grau III   |       ~3%%      |\n");
} else if (resultado < 29.9) {
    printf("|    < 18.5       |   Abaixo do peso       |       ~7%%      |\n");
    printf("|    18.5-24.9    |   Peso normal          |      ~38%%      |\n");
    printf(RED"| >> 25-29.9      |   Sobrepeso            |      ~35%%      << |\n"RESET);
    printf("|    30-34.9      |   Obesidade grau I     |      ~12%%      |\n");
    printf("|    35-39.9      |   Obesidade grau II    |       ~5%%      |\n");
    printf("|     >=40        |   Obesidade grau III   |       ~3%%      |\n");
} else if (resultado < 34.9) {
    printf("|    < 18.5       |   Abaixo do peso       |       ~7%%      |\n");
    printf("|    18.5-24.9    |   Peso normal          |      ~38%%      |\n");
    printf("|    25-29.9      |   Sobrepeso            |      ~35%%      |\n");
    printf(RED"| >> 30-34.9      |   Obesidade grau I     |      ~12%%      << |\n"RESET);
    printf("|    35-39.9      |   Obesidade grau II    |       ~5%%      |\n");
    printf("|     >=40        |   Obesidade grau III   |       ~3%%      |\n");
} else if (resultado < 39.9) {
    printf("|    < 18.5       |   Abaixo do peso       |       ~7%%      |\n");
    printf("|    18.5-24.9    |   Peso normal          |      ~38%%      |\n");
    printf("|    25-29.9      |   Sobrepeso            |      ~35%%      |\n");
    printf("|    30-34.9      |   Obesidade grau I     |      ~12%%      |\n");
    printf(RED"| >> 35-39.9      |   Obesidade grau II    |       ~5%%      << |\n"RESET);
    printf("|     >=40        |   Obesidade grau III   |       ~3%%      |\n");
} else {
    printf("|    < 18.5       |   Abaixo do peso       |       ~7%%      |\n");
    printf("|    18.5-24.9    |   Peso normal          |      ~38%%      |\n");
    printf("|    25-29.9      |   Sobrepeso            |      ~35%%      |\n");
    printf("|    30-34.9      |   Obesidade grau I     |      ~12%%      |\n");
    printf("|    35-39.9      |   Obesidade grau II    |       ~5%%      |\n");
    printf(RED"| >>   >=40       |   Obesidade grau III   |       ~3%%      << |\n"RESET);
    printf("-------------------------------------------------------------\n");
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
    printf("\n"); // peguei do textart as formatações diferentes
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
        printf(RED"\n🅱 🅴 🅼 - 🆅 🅸 🅽 🅳 🅾  😁, %s!\n"RESET, nome);
    } else if (genero == 'F') {
        printf(RED"\n🅱 🅴 🅼 - 🆅 🅸 🅽 🅳 🅰  😁, %s!\n"RESET, nome);
    } else {
        printf(RED"\n🅱 🅴 🅼 - 🆅 🅸 🅽 🅳 🅾 ( 🅰 )  😁, %s!\n"RESET, nome);
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

// chat gpt 5
bool palavra_valida(const char *palavra) {
    int tamanho = strlen(palavra);
    if(tamanho < 2) return false; 

    char primeira = palavra[0];
    bool todos_iguais = true;

    for(int i = 0; i < tamanho; i++) {
        char c = palavra[i];

        if(!isalpha(c)) return false; 

        if(c != primeira) todos_iguais = false;
    }

    if(todos_iguais) return false; 

    return true;
}


bool validar_nome(const char *nome) {
    char copia[100];
    strcpy(copia, nome);

    char *palavra = strtok(copia, " "); 
    while(palavra != NULL) {
        if(!palavra_valida(palavra)) return false;
        palavra = strtok(NULL, " ");
    }

    return true;
}


//Chat GPT 5


int validar_cpf(const char *cpf) {
    int i, j, soma, resto, digito1, digito2;
    char numeros[12];

    
    int k = 0;
    for (i = 0; cpf[i] != '\0'; i++) {
        if (isdigit(cpf[i])) {
            numeros[k++] = cpf[i];
        }
    }
    numeros[k] = '\0';

    if (strlen(numeros) != 11) {
        return 0;
    }

    
    int todos_iguais = 1;
    for (i = 1; i < 11; i++) {
        if (numeros[i] != numeros[0]) {
            todos_iguais = 0;
            break;
        }
    }
    if (todos_iguais) {
        return 0;
    }

    soma = 0;
    for (i = 0, j = 10; i < 9; i++, j--) {
        soma += (numeros[i] - '0') * j;
    }
    resto = soma % 11;
    digito1 = (resto < 2) ? 0 : 11 - resto;

    soma = 0;
    for (i = 0, j = 11; i < 10; i++, j--) {
        soma += (numeros[i] - '0') * j;
    }
    resto = soma % 11;
    digito2 = (resto < 2) ? 0 : 11 - resto;

    
    if ((numeros[9] - '0') == digito1 && (numeros[10] - '0') == digito2) {
        return 1; 
    } else {
        return 0; 
}
}




// chat gpt 5

int validar_telefone(const char *telefone) {
    int len = strlen(telefone);

    
    if (len != 10 && len != 11) {
        return 0;
    }

    
    for (int i = 0; i < len; i++) {
        if (!isdigit(telefone[i])) {
            return 0;
        }
    }

    return 1; 
}



int validar_idade(int idade) {
    return (idade >= 0 && idade <= 120);
}

int validar_peso(float peso) {
    return (peso >= 0 && peso <= 700);
}
int validar_altura(float altura) {
    return (altura >= 0.5 && altura <= 2.50);
}
int validar_bf(float bf) {
    return (bf >= 0 && bf <= 100);
}
