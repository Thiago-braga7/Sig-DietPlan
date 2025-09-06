#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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
}

float imc(float peso, float altura) {
    if (altura <= 0) {
        printf("Altura inválida!\n");
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