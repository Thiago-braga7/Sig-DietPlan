#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>



// Funcões Criadas por Thiago


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
    printf("\nPressione ENTER para continuar...");
    getchar();
    getchar();
}

// créditos: Flavius Gorgônio

// int validar_telefone(const char *telefone) {
//     int len = strlen(telefone);

    
//     if (len != 10) {
//         return 0;
//     }

    
//     for (int i = 0; i < len; i++) {
//         if (!isdigit(telefone[i])) {
//             return 0;
//         }
//     }

//     return 1; 
// }