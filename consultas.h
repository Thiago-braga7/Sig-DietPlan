typedef struct consulta Consulta;

struct consulta {
    int id_consulta;
    char nome[50];
    char data[12];
    char hora[7];
    char medico[50];
    char observacoes[200];
    int status;
};

void modulo_consultas(void);
char tela_consultas(void);
void cadastrar_consulta(void);
void buscar_consulta(void);
void alterar_consulta(void);
void excluir_consulta(void);
