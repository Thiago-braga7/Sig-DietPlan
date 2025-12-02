#ifndef DIETAS_H
#define DIETAS_H

typedef struct dieta Dieta;

struct dieta {
    int id_dieta;
    char nome_dieta[50];
    float calorias;
    char refeicoes[200];
    int status;
};

void modulo_dietas(void);
char tela_dietas(void);
void cadastrar_dieta(void);
void buscar_dieta(void);
void alterar_dieta(void);
void excluir_dieta(void);
void excluir_dieta_fisica(void);
void exibir_dieta(const Dieta *dt);

#endif