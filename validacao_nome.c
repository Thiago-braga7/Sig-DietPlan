#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// chat gpt
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