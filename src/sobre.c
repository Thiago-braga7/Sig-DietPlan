#include <stdio.h>
#include <stdlib.h>
#include "sobre.h"
#include "validacoes.h"



// créditos:Text Art

void sobre(void){
    printf("====================================================\n");
    printf("                  Sig - DietPlan                    \n");
    printf("====================================================\n");
    printf("Sig-DietaPlan é um sistema desenvolvido na disciplina de Programação da UFRN,\n");
    printf("para auxiliar no planejamento e acompanhamento de dietas.\n\n");    
    printf("Ele permite:\n");
    printf("  • Cadastro de usuários\n");
    printf("  • Gestão dieta\n");
    printf("  • Registro de consumos diários\n");
    printf("  • Agendamento de consultas\n\n");
    printf("====================================================\n\n");
    pausar();
}
void sair(void){
    limpar_tela();
    printf("\n");
    printf("//////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                   Obrigado por utilizar o Sig - DietPlan                               ///\n");            
    printf("///                                            Até a proxima!                                              ///\n");
    printf("///                          📷 Instagram: @thiago.braga9a | @gabrieluchoa_1 | @wallisonvsdias             ///\n");
    printf("///          🐙 GitHub: github.com/Thiago-braga7 | github.com/GabrielUchoa17 | github.com/wallisonvsdias   ///\n");
    printf("///                                                                                                        ///\n");
    printf("//////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
}
