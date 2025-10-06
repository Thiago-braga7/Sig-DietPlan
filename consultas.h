typedef struct consulta Consulta;

struct consulta {
    char nome[50];
    char data[10];
    char hora[6];
    char medico[50];
    char observacoes[200];
};

void modulo_consultas(void);
char tela_consultas(void);
void cadastrar_consulta(void);
void buscar_consulta(void);
void alterar_consulta(void);
void excluir_consulta(void);
