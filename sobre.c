#include <stdio.h>
#include <stdlib.h>
#include "sobre.h"
#include "util.h"





#define RESET   "\033[0m"
#define RED     "\033[31m"
#define CYAN    "\033[36m"




void bem_vindo(void) {
    char nome[50];
    char genero;
    bool valido = false;

    logo();
   
    do {
        printf(CYAN"\nInforme seu nome: "RESET);
        scanf(" %[^\n]", nome);  

        if(validar_nome(nome)) {
            valido = true;
        } else {
            printf(CYAN"Nome inválido! Use apenas letras e espaços, palavras com no mínimo 2 letras, sem repetições absurdas.\n"RESET);
        }
    } while(!valido);

    genero = ler_genero();

    
    mensagem_boas_vindas(nome, genero);
    
}


    



void sobre(void){
    // peguei do textart a formatação diferente
    printf(CYAN"====================================================\n"RESET);
    printf(CYAN"                𝕾 𝖎 𝖌 - 𝕯 𝖎 𝖊 𝖙 𝕻 𝖑 𝖆 𝖓\n"RESET);
    printf(CYAN"====================================================\n\n"RESET);

    
    printf(CYAN"Sig-DietaPlan é um sistema desenvolvido na disciplina de Programação da UFRN,\n"RESET);
    printf(CYAN"para auxiliar no planejamento e acompanhamento de dietas.\n\n"RESET);

    
    printf(CYAN"Ele permite:\n"RESET);
    printf(CYAN"  • Cadastro de usuários\n"RESET);
    printf(CYAN"  • Gestão dieta\n"RESET);
    printf(CYAN"  • Registro de consumos diários\n"RESET);
    printf(CYAN"  • Agendamento de consultas\n\n"RESET);

    
    printf(RED"🆄 🅼 🅰   🅰 🅻 🅴 🅶 🆁 🅸 🅰  🆃 🅴 🆁  🅶 🅴 🅽 🆃 🅴  🅽 🅾  🆂 🅸 🅶 - 🅳 🅸 🅴 🆃 🅿 🅻 🅰 🅽 ❗ 😊👍\n\n"RESET);
   
    printf(CYAN"====================================================\n\n"RESET);

    
    pausar();
}
void sair(void){
    printf("\n");
    printf(CYAN"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                          ///\n");
    printf(CYAN"///                 Obrigado por usar o SIG-DietPlan!                    ///\n");
    printf("///                         Até a proxima!                                   ///\n");
    printf("///             📷 Instagram: @thiago.braga9a | @gabrieluchoa_1              ///\n");
    printf("///         🐙 GitHub: github.com/Thiago-braga7 | github.com/GabrielUchoa17  ///\n");
    printf("///                                                                          ///\n");
    printf(CYAN"///////////////////////////////////////////////////////////////////////////////\n"RESET);
}
