#include <stdio.h>
#include <stdlib.h>
#include "sobre.h"
#include "util.h"





#define RESET   "\033[0m"
#define RED     "\033[31m"
#define CYAN    "\033[36m"






// créditos:Text Art

void sobre(void){
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

    
   
    printf(CYAN"====================================================\n\n"RESET);

    
    pausar();
}
void sair(void){
    printf("\n");
    printf(CYAN"/////////////////////////////////////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf(RED"                                                                                                                 \n");            
    printf("█▀█ █▄▄ █▀█ █ █▀▀ ▄▀█ █▀▄ █▀█   █▀█ █▀█ █▀█   █░█ █▀ ▄▀█ █▀█   █▀█   █▀ █ █▀▀ ▄▄ █▀▄ █ █▀▀ ▀█▀ █▀█ █░░ ▄▀█ █▄░█ █\n");
    printf("█▄█ █▄█ █▀▄ █ █▄█ █▀█ █▄▀ █▄█   █▀▀ █▄█ █▀▄   █▄█ ▄█ █▀█ █▀▄   █▄█   ▄█ █ █▄█ ░░ █▄▀ █ ██▄ ░█░ █▀▀ █▄▄ █▀█ █░▀█ ▄\n"RESET);
    printf("                                                                                                                 \n");
    printf(CYAN"///                         Até a proxima!                                                                      ///\n");
    printf("///             📷 Instagram: @thiago.braga9a | @gabrieluchoa_1                                                ///\n");
    printf("///         🐙 GitHub: github.com/Thiago-braga7 | github.com/GabrielUchoa17                                    ///\n");
    printf("///                                                                                                            ///\n");
    printf("//////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n"RESET);
}
