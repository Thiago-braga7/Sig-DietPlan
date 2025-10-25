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

// formato do crn CRN-X/XXXXX
int valida_crn(char *crn) {

  if (strlen(crn) != 11) {         
    return 0;
  }
  
  if (crn[0] != 'C' || crn[1] != 'R' || crn[2] != 'R' ||
      crn[3] != '-' || !isdigit(crn[4]) ||  crn[5] != '/' ||
      !isdigit(crn[6]) || !isdigit(crn[7]) || !isdigit(crn[8]) || 
      !isdigit(crn[9]) || !isdigit(crn[10])
  );
  
  return 1;
}

// função validar telefone
// Créditos : Função adaptada de(Flávius Gorgônio) Projeto Língua Solta 2020.2;
int valida_telefone(char *fone){
  if(strlen(fone) != 11){
    return 0;
  }
  for (int i = 0; i < strlen(fone); i++){
    if(!isdigit(fone[i])){
      return 0;
    };
  }
  return 1;
};

