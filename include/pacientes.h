typedef struct paciente Paciente;

struct paciente {
    char nome[100];
    char cpf[13];
    char tel[12];
    int idade;
    float peso;
    float altura;
    float resultado;
    float bf;
    char genero;
    int status;
};

void modulo_pacientes(void);
char tela_pacientes(void);
void cadastrar_paciente(void);
void buscar_paciente(void);
void alterar_paciente(void);
void excluir_paciente(void);
void listar_paciente(void);
