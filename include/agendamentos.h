#ifndef AGENDAMENTOS_H
#define AGENDAMENTOS_H

typedef struct agendamento Agendamento;

struct agendamento {
    int id_agendamento;
    char cpf[13];
    char data[15];
    char hora[10];
    char tipo[50];
    char profissional[50];
    char observacoes[200];
    int status;
};

void modulo_agendamentos(void);
char tela_agendamentos(void);
void cadastrar_agendamento(void);
void buscar_agendamento(void);
void alterar_agendamento(void);
void excluir_agendamento(void);
void listar_agendamentos(void);
void excluir_agendamento_fisico(void);
void exibir_agendamento(const Agendamento * ag);

#endif