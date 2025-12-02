#ifndef VALIDACOES_H
#define VALIDACOES_H

char confirmar_acao(char);
void limpar_tela(void);
void pausar(void);
int valida_crn(char *);
int valida_telefone(char *);
int valida_idade(int *);
int valida_mes(char *);
int ano_bissexto(int);
int ano_atual(int);
int valida_data(char *);
int validar_hora(const char *);
int validar_calorias(float);
int validar_nome(char *);
int validar_cpf(char *);
int validar_peso(float);
int validar_altura(float);
int validar_observacao(const char *);

#endif