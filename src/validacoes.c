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
      !isdigit(crn[9]) || !isdigit(crn[10])) {
        return 0;
      }      
  return 1;
}

// função validar telefone
// Créditos : Função adaptada de(Flávius Gorgônio) Projeto Língua Solta 2020.2;
int valida_telefone(char *fone){
  if(strlen(fone) != 11){
    return 0;
  }

  int len = strlen(fone);
  
  for (int i = 0; i < len; i++){
    if(!isdigit(fone[i])){
      return 0;
    };
  }
  return 1;
};

int valida_idade(char *digito){ 
  int len = strlen(digito);
  
  if(strlen(digito) == 0){ 
    return 0; 
  } 
  for(int i = 0; i < len; i++){
     if(!isdigit(digito[i])){ 
      return 0; 
    } 
  }
  // Créditos: Peguei essa parte do Gemini, o atoi converte string em um número inteiro. Da biblioteca stdlib
  int idade = atoi(digito);

  if((idade) > 0 && (idade <= 130)){
    return 1;
  } else{
    return 0;
  }

}

int valida_mes(char * mes){
  int len = strlen(mes);
  if(strlen(mes) == 0){
    return 0;
  }

  for(int i = 0; i < len; i++){
     if(!isdigit(mes[i])){ 
      return 0; 
    } 
  }
  int mes_digitado = atoi(mes);
  
  if((mes_digitado) >= 1 && (mes_digitado <= 12)){
    return 1;
  } else{
    return 0;
  }
}

int ano_bissexto(int ano){
  if(ano % 400 == 0){
    return 1;
  } else if((ano % 4 == 0) && (ano % 100 != 0)){
    return 1;
  } else{
    return 0;
  }
}
