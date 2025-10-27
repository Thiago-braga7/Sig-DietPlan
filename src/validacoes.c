#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>


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
  
  if (crn[0] != 'C' || crn[1] != 'R' || crn[2] != 'N' ||
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
  
  int idade = atoi(digito);

  if((idade) > 0 && (idade <= 130)){
    return 1;
  } else{
    return 0;
  }

}

int valida_mes(char *mes){
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

// Créditos : Função adaptada de(Flávius Gorgônio) Projeto Língua Solta 2020.2;
int valida_dia(int dia, int mes, int ano){
  if((dia < 1) || (mes < 1) || (mes > 12)){
    return 0;
  }
  int max_dias;
  if ((mes == 4) || (mes == 6) || (mes == 9) || (mes == 11)){
    max_dias = 30;
  } else if (mes == 2){
      if(ano_bissexto(ano)){
        max_dias = 29;
      } else{
        max_dias = 28;
      }
  } else{
    max_dias = 31;
  }
  if(dia > max_dias){
    return 0;
  }
  return 1;
}

// Créditos: Gemini. Peguei essa função para saber o ano atual;
/* Explicação: Conta os segundos desde 1970 até a data atual, converte para a data atual, subtrai com 1900(por
causa do tm_year), aí depois somamos novamente com 1900 para termos o ano atual.
*/
int ano_atual() {
    time_t segundos_atuais = time(NULL);           // Pega o tempo atual em segundos desde 01/01/1970
    struct tm *data_atual = localtime(&segundos_atuais); // Converte para a data_atual/hora local (estrutura tm)
    return data_atual->tm_year + 1900;         // tm_year é anos desde 1900, então somamos 1900 para obter o ano real
}

// Essa função foi criada para validar apenas o ano atual e (ano atual + 1)
int valida_ano(int ano){
  int atual = ano_atual();

  if((ano == atual) || (ano == atual + 1)){
    return 1;
  } else{
    return 0;
  }
}

// Créditos : Função adaptada de(Flávius Gorgônio) Projeto Língua Solta 2020.2;
int valida_data(char *data){
   int len, dia, mes, ano;
  len = strlen(data);
  if(len != 8){
    return 0;
  }
  for (int i = 0; i < len; i++){
    if (!isdigit(data[i])) {
      return 0;
    }
  }
  dia = (data[0] - '0') * 10 + (data[1] - '0');
  mes = (data[2] - '0') * 10 + (data[3] - '0');
  ano = (data[4] - '0') * 1000 + (data[5] - '0') * 100 + 
        (data[6] - '0') * 10 + (data[7] - '0');

  if (!valida_dia(dia, mes, ano)){
    return 0;
  }
  if(!valida_ano(ano)){
    return 0;
  }

  // Créditos: Função Adaptada do Gemini
  // Verifica se a data já passou;
  time_t segundos_atuais = time(NULL);
  struct tm *data_atual = localtime(&segundos_atuais); 
  int dia_atual = data_atual->tm_mday;
  int mes_atual = data_atual->tm_mon + 1; // pega os meses de 0 a 11;
  int ano_atual_val = data_atual->tm_year + 1900; 

  if(ano == ano_atual_val){
    if(mes < mes_atual){
      return 0;
    } else if((mes == mes_atual) && (dia < dia_atual)){
      return 0;
    }
  }

  return 1; 
}

int validar_hora(const char *hora){
  if(strlen(hora) != 5){
    return 0;
  }
  int i;
  for(i = 0; i < 5; i++){
    if(i == 2){
      if(hora[i] != ':'){
        return 0;
      }
    } else {
        if(!isdigit(hora[i])){
          return 0;
      }
    }
  }
  int horas = (hora[0] - '0') * 10 + (hora[1] - '0');
  int minutos = (hora[3] - '0') * 10 + (hora[4] - '0');

  if(horas < 0 || horas > 23 || minutos < 0 || minutos > 59){
    return 0;
  }
  // Horário de Atendimento 08:00 - 18:00)
  if(horas < 8 || horas > 18 || (horas == 18 && minutos > 0)){
    return 0;
  }
  return 1;
}

int validar_calorias(float calorias){
  if(calorias > 0.0 && calorias < 10000.0){
        return 1; 
    }
    return 0; 
}


