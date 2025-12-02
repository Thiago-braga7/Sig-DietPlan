#ifndef PACIENTES_H
#define PACIENTES_H

typedef struct paciente Paciente;

struct paciente {
    char nome[50];
    char cpf[13];
    char tel[12];
    int idade;
    float peso;
    float altura;
    float resultado;
    int status;
};

void modulo_pacientes(void);
char tela_pacientes(void);
void cadastrar_paciente(void);
void buscar_paciente(void);
void alterar_paciente(void);
void excluir_paciente(void);
void exibir_paciente(const Paciente *pac);

#endif
