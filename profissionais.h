typedef struct profissional Profissional;

struct profissional {
    int id_profissional;
    char nome[100];
    char cpf[13];
    char email[30];
    char tel[11];
    char crn[12];
};

void modulo_profissionais(void);
char tela_profissionais(void);
void cadastrar_profissional(void);
void buscar_profissional(void);
void alterar_profissional(void);
void excluir_profissional(void);