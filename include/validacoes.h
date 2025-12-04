#ifndef VALIDACOES_H
#define VALIDACOES_H

int validar_crn(char *);
int validar_telefone(char *);
int validar_idade(int *);
int validar_mes(char *);
int ano_bissexto(int);
int ano_atual(int);
int validar_data(char *);
int validar_hora(const char *);
int validar_calorias(float);
int validar_nome(char *);
int validar_cpf(char *);
int validar_peso(float);
int validar_altura(float);
int validar_observacao(const char *);
int validar_sexo(char);

#endif