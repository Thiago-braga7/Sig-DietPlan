#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define CYAN "\x1B[36m"








char ler_genero(char genero) {
    genero = toupper(genero);  

    if (genero == 'M' || genero == 'F' || genero == 'N') {
        return genero; 
    }

    return 0; 
}

char confirmar_acao(char valor) {
    valor = toupper(valor);  

    if (valor == 'S' || valor == 'N') {
        return valor; 
    }

    return 0; 
}

void limpar_tela(void){
    system("clear||cls");
}
void pausar(void) {
    printf(CYAN"\nPressione ENTER para continuar..."RESET);
    getchar();
    getchar();
}

float imc(float peso, float altura) {
    if (altura <= 0) {
        return 0; 
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

float validar_peso(float peso) {
    if (peso > 0) {      
        return peso;
    }
    return 0;             
}


float peso_ideal_min(float altura) {
    if (altura <= 0) {
        return 0;  
    }
    return 18.5f * altura * altura;
}

float peso_ideal_max(float altura) {
    if (altura <= 0) {
        return 0;  
    }
    return 24.9f * altura * altura;
}


void classificação_imc(float resultado){

if (resultado < 18.5) {
    printf(RED"-------------------------------------------------------------\n"RESET);
    printf(CYAN"| >> < 18.5       |   Abaixo do peso       |       ~7%%      << |\n"RESET);
    printf(RED"|    18.5-24.9    |   Peso normal          |      ~38%%      |\n");
    printf("|    25-29.9      |   Sobrepeso            |      ~35%%      |\n");
    printf("|    30-34.9      |   Obesidade grau I     |      ~12%%      |\n");
    printf("|    35-39.9      |   Obesidade grau II    |       ~5%%      |\n");
    printf("|     >=40        |   Obesidade grau III   |       ~3%%      |\n"RESET);
} else if (resultado < 24.9) {
    printf(RED"|    < 18.5       |   Abaixo do peso       |       ~7%%      |\n"RESET);
    printf(CYAN"| >> 18.5-24.9    |   Peso normal          |      ~38%%      << |\n"RESET);
    printf(RED"|    25-29.9      |   Sobrepeso            |      ~35%%      |\n");
    printf("|    30-34.9      |   Obesidade grau I     |      ~12%%      |\n");
    printf("|    35-39.9      |   Obesidade grau II    |       ~5%%      |\n");
    printf("|     >=40        |   Obesidade grau III   |       ~3%%      |\n"RESET);
} else if (resultado < 29.9) {
    printf(RED"|    < 18.5       |   Abaixo do peso       |       ~7%%      |\n");
    printf("|    18.5-24.9    |   Peso normal          |      ~38%%      |\n"RESET);
    printf(CYAN"| >> 25-29.9      |   Sobrepeso            |      ~35%%      << |\n"RESET);
    printf(RED"|    30-34.9      |   Obesidade grau I     |      ~12%%      |\n");
    printf("|    35-39.9      |   Obesidade grau II    |       ~5%%      |\n");
    printf("|     >=40        |   Obesidade grau III   |       ~3%%      |\n"RESET);
} else if (resultado < 34.9) {
    printf(RED"|    < 18.5       |   Abaixo do peso       |       ~7%%      |\n");
    printf("|    18.5-24.9    |   Peso normal          |      ~38%%      |\n");
    printf("|    25-29.9      |   Sobrepeso            |      ~35%%      |\n"RESET);
    printf(CYAN"| >> 30-34.9      |   Obesidade grau I     |      ~12%%      << |\n");
    printf("|    35-39.9      |   Obesidade grau II    |       ~5%%      |\n");
    printf("|     >=40        |   Obesidade grau III   |       ~3%%      |\n"RESET);
} else if (resultado < 39.9) {
    printf(RED"|    < 18.5       |   Abaixo do peso       |       ~7%%      |\n");
    printf("|    18.5-24.9    |   Peso normal          |      ~38%%      |\n");
    printf("|    25-29.9      |   Sobrepeso            |      ~35%%      |\n");
    printf("|    30-34.9      |   Obesidade grau I     |      ~12%%      |\n"RESET);
    printf(CYAN"| >> 35-39.9      |   Obesidade grau II    |       ~5%%      << |\n"RESET);
    printf(RED"|     >=40        |   Obesidade grau III   |       ~3%%      |\n"RESET);
} else {
    printf(RED"|    < 18.5       |   Abaixo do peso       |       ~7%%      |\n");
    printf("|    18.5-24.9    |   Peso normal          |      ~38%%      |\n");
    printf("|    25-29.9      |   Sobrepeso            |      ~35%%      |\n");
    printf("|    30-34.9      |   Obesidade grau I     |      ~12%%      |\n");
    printf("|    35-39.9      |   Obesidade grau II    |       ~5%%      |\n"RESET);
    printf(CYAN"| >>   >=40       |   Obesidade grau III   |       ~3%%      << |\n"RESET);
    printf(RED"-------------------------------------------------------------\n"RESET);
}
}

void classificar_bf(char genero, float bf) {

    

    printf(RED"\nSeu percentual de gordura é: %.1f%%\n"RESET, bf);


    printf(RED"-------------------------------------------------------------\n"RESET);

    if (genero == 'M') {
        if (bf < 6) {
            printf(CYAN"| >>   < 6        |   Muito abaixo do ideal   << |\n"RESET);
            printf(RED "|    6-13         |   Atleta                     |\n");
            printf("|    14-17        |   Fitness                    |\n");
            printf("|    18-24        |   Normal                     |\n");
            printf("|    25-29        |   Acima do ideal             |\n");
            printf("|    >=30         |   Obeso                      |\n"RESET);
        } else if (bf <= 13) {
            printf(RED "|    < 6          |   Muito abaixo do ideal      |\n"RESET);
            printf(CYAN"| >> 6-13         |   Atleta                  << |\n"RESET);
            printf(RED "|    14-17        |   Fitness                    |\n");
            printf("|    18-24        |   Normal                     |\n");
            printf("|    25-29        |   Acima do ideal             |\n");
            printf("|    >=30         |   Obeso                      |\n"RESET);
        } else if (bf <= 17) {
            printf(RED "|    < 6          |   Muito abaixo do ideal      |\n");
            printf("|    6-13         |   Atleta                     |\n"RESET);
            printf(CYAN"| >> 14-17        |   Fitness                 << |\n"RESET);
            printf(RED "|    18-24        |   Normal                     |\n");
            printf("|    25-29        |   Acima do ideal             |\n");
            printf("|    >=30         |   Obeso                      |\n"RESET);
        } else if (bf <= 24) {
            printf(RED "|    < 6          |   Muito abaixo do ideal      |\n");
            printf("|    6-13         |   Atleta                     |\n");
            printf("|    14-17        |   Fitness                    |\n"RESET);
            printf(CYAN"| >> 18-24        |   Normal                  << |\n"RESET);
            printf(RED "|    25-29        |   Acima do ideal             |\n");
            printf("|    >=30         |   Obeso                      |\n"RESET);
        } else if (bf <= 29) {
            printf(RED "|    < 6          |   Muito abaixo do ideal      |\n");
            printf("|    6-13         |   Atleta                     |\n");
            printf("|    14-17        |   Fitness                    |\n");
            printf("|    18-24        |   Normal                     |\n"RESET);
            printf(CYAN"| >> 25-29        |   Acima do ideal          << |\n"RESET);
            printf(RED "|    >=30         |   Obeso                      |\n"RESET);
        } else {
            printf(RED "|    < 6          |   Muito abaixo do ideal      |\n");
            printf("|    6-13         |   Atleta                     |\n");
            printf("|    14-17        |   Fitness                    |\n");
            printf("|    18-24        |   Normal                     |\n");
            printf("|    25-29        |   Acima do ideal             |\n"RESET);
            printf(CYAN"| >> >=30         |   Obeso                   << |\n"RESET);
        }
    } 
    else if (genero == 'F') {
        if (bf < 14) {
            printf(CYAN"| >>   < 14       |   Muito abaixo do ideal   << |\n"RESET);
            printf(RED "|    14-20        |   Atleta                     |\n");
            printf("|    21-24        |   Fitness                    |\n");
            printf("|    25-31        |   Normal                     |\n");
            printf("|    32-37        |   Acima do ideal             |\n");
            printf("|    >=38         |   Obesa                      |\n"RESET);
        } else if (bf <= 20) {
            printf(RED "|    < 14         |   Muito abaixo do ideal      |\n"RESET);
            printf(CYAN"| >> 14-20        |   Atleta                  << |\n"RESET);
            printf(RED "|    21-24        |   Fitness                    |\n");
            printf("|    25-31        |   Normal                     |\n");
            printf("|    32-37        |   Acima do ideal             |\n");
            printf("|    >=38         |   Obesa                      |\n"RESET);
        } else if (bf <= 24) {
            printf(RED "|    < 14         |   Muito abaixo do ideal      |\n");
            printf("|    14-20        |   Atleta                     |\n"RESET);
            printf(CYAN"| >> 21-24        |   Fitness                 << |\n"RESET);
            printf(RED "|    25-31        |   Normal                     |\n");
            printf("|    32-37        |   Acima do ideal             |\n");
            printf("|    >=38         |   Obesa                      |\n"RESET);
        } else if (bf <= 31) {
            printf(RED "|    < 14         |   Muito abaixo do ideal      |\n");
            printf("|    14-20        |   Atleta                     |\n");
            printf("|    21-24        |   Fitness                    |\n"RESET);
            printf(CYAN"| >> 25-31        |   Normal                  << |\n"RESET);
            printf(RED "|    32-37        |   Acima do ideal             |\n");
            printf("|    >=38         |   Obesa                      |\n"RESET);
        } else if (bf <= 37) {
            printf(RED "|    < 14         |   Muito abaixo do ideal      |\n");
            printf("|    14-20        |   Atleta                     |\n");
            printf("|    21-24        |   Fitness                    |\n");
            printf("|    25-31        |   Normal                     |\n"RESET);
            printf(CYAN"| >> 32-37        |   Acima do ideal          << |\n"RESET);
            printf(RED "|    >=38         |   Obesa                      |\n"RESET);
        } else {
            printf(RED "|    < 14         |   Muito abaixo do ideal      |\n");
            printf("|    14-20        |   Atleta                     |\n");
            printf("|    21-24        |   Fitness                    |\n");
            printf("|    25-31        |   Normal                     |\n");
            printf("|    32-37        |   Acima do ideal             |\n"RESET);
            printf(CYAN"| >> >=38         |   Obesa                   << |\n"RESET);
        }
    }

    printf(RED"-------------------------------------------------------------\n"RESET);
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
        if (isdigit((unsigned char)cpf[i])) {
            if (k >= 11) { 
                
                return 0;
            }
            numeros[k++] = cpf[i];
        }
    }
    numeros[k] = '\0';

    
    if (k != 11) {
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

    
    if (len != 10) {
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

int validar_altura(float altura) {
    return (altura >= 0.5 && altura <= 2.50);
}
int validar_bf(float bf) {
    return (bf >= 0 && bf <= 100);
}
