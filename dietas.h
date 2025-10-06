typedef struct dieta Dieta;

struct dieta {
    int id_dieta;
    char cpf[13];
    char nome_dieta[50];
    int calorias;
    char refeicoes[200];
};

void modulo_dietas(void);
char tela_dietas(void);
void cadastrar_dieta(void);
void buscar_dieta(void);
void alterar_dieta(void);
void excluir_dieta(void);