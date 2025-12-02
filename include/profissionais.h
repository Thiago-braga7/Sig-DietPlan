#ifndef PROFISSIONAIS_H
#define PROFISSIONAIS_H

typedef struct profissional Profissional;

struct profissional {
    int id_profissional;
    char nome[50];
    char cpf[13];
    char tel[12];
    char crn[12];
    int status;
};

void modulo_profissionais(void);
char tela_profissionais(void);
void cadastrar_profissional(void);
void buscar_profissional(void);
void alterar_profissional(void);
void excluir_profissional(void);
void exibir_profissional(const Profissional *pf);

#endif