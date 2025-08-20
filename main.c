#include <stdio.h>
#include <stdlib.h> 


void bem_vindo(void);
void menu_principal(void);
void usuarios(void); 
void alimentos(void);
void cardapio(void);
void consumo_alimentos(void);
void consumo_agua(void);
void relatorios(void);
void sair(void);
void cadastrar_usuario(void);
void buscar_usuario(void);
void alterar_usuario(void);
void excluir_usuario(void);
void cadastrar_alimento(void);
void buscar_alimento(void);
void alterar_alimento(void);

int main(void){
    bem_vindo();
    menu_principal();
    usuarios();
    alimentos();
    cardapio();
    consumo_alimentos();
    consumo_agua();
    relatorios();
    sair();
    cadastrar_usuario();
    buscar_usuario();
    alterar_usuario();
    excluir_usuario();
    cadastrar_alimento();
    buscar_alimento();
    alterar_alimento();

    
}

void bem_vindo(void) {
    char nome[50];
    char genero;

    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                           SIG-DietPlan                                  ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");

    printf("\nInforme seu nome: ");
    scanf("%[^\n]", nome);  

    printf("Informe seu gênero (M = Masculino, F = Feminino, N = Prefiro não informar): ");
    scanf(" %c", &genero);

    if (genero == 'M' || genero == 'm') {
        printf("\nBem-vindo 😁, %s!\n", nome);
    } else if (genero == 'F' || genero == 'f') {
        printf("\nBem-vinda 😁, %s!\n", nome);
    } else {
        printf("\nBem-vindo(a) 😁, %s!\n", nome);
    }

    printf("Sig-DietaPlan é um sistema desenvolvido na disciplina de Programação da UFRN\n");
    printf("para auxiliar no planejamento e acompanhamento de dietas.\n");
    printf("\n");
    printf("Ele permite:\n");
    printf("- Cadastro de usuários;\n");
    printf("- Gestão de alimentos e valores nutricionais;\n");
    printf("- Registro de consumos diários;\n");
    printf("- Planejamento de refeições personalizadas.\n");
    printf("\n");

    
    printf("Estamos felizes em ter você no SIG-DietPlan! 😊👍\n\n");
    printf("Gerencie sua saúde de forma prática: cadastre usuários, registre alimentos, acompanhe a quantidade de água ingerida e controle suas calorias diárias!");
    printf("\n");
}



void menu_principal(void){
    char opcao;
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                 Centro de Ensino Superior do Seridó                     ///\n");
    printf("///               Departamento de Computação e Tecnologia                   ///\n");
    printf("///                  Disciplina DCT1106 -- Programação                      ///\n");
    printf("///               Projeto Sistema de Planejamento de Dietas                 ///\n");
    printf("///                           SIG-DietPlan                                  ///\n");
    printf("///         Criado por @thiagobraga9a e gabrieluchoa_1 -- desde Ago, 2025   ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = Planejamento de Dietas = = = = =                   ///\n");
    printf("///                                                                         ///\n");
    printf("///                      1. Usuários                                        ///\n");
    printf("///                      2. Alimentos                                       ///\n");
    printf("///                      3. Cardápio                                        ///\n");
    printf("///                      4. Consumo Diário(Alimentos)                       ///\n");
    printf("///                      5. Consumo Diário(Água)                            ///\n");
    printf("///                      6. Relatórios                                      ///\n");
    printf("///                      0. Voltar ao Menu Principal                        ///\n");
    printf("///                                                                         ///\n");
    printf("///                      Escolha a opção desejada: ");
    scanf("%c", &opcao);
    getchar();
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void usuarios(void){
    char opcao;
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                    = = = = =   Usuários   = = = = =                     ///\n");
    printf("///                                                                         ///\n");
    printf("///                    1. Cadastrar Usuário                                 ///\n");
    printf("///                    2. Buscar Usuário                                    ///\n");
    printf("///                    3. Alterar Dados do Usuário                          ///\n");
    printf("///                    4. Excluir Usuário                                   ///\n");
    printf("///                    0. Voltar ao Menu Principal                          ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                      Escolha a opção desejada: ");
    scanf("%c", &opcao);
    getchar();
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); 
}

void alimentos(void){
    char opcao;
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                    = = = = =   Alimentos   = = = = =                    ///\n");
    printf("///                                                                         ///\n");
    printf("///                    1. Cadastrar Alimento na Dieta                       ///\n");
    printf("///                    2. Buscar Alimento na Dieta                          ///\n");
    printf("///                    3. Alterar Alimento da Dieta                         ///\n");
    printf("///                    4. Excluir Alimento da Dieta                         ///\n");
    printf("///                    0. Voltar ao Menu Principal                          ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                      Escolha a opção desejada: ");
    scanf("%c", &opcao);
    getchar();
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}
void cardapio(void){
    char opcao;
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                    = = = = =   Cardápio   = = = = =                     ///\n");
    printf("///                                                                         ///\n");
    printf("///                    1. Cadastrar Refeição                                ///\n");
    printf("///                    2. Buscar Refeição                                   ///\n");
    printf("///                    3. Alterar Dados da Refeição                         ///\n");
    printf("///                    4. Excluir Refeição                                  ///\n");
    printf("///                    5. Listar Refeições do Usuário                       ///\n");
    printf("///                    0. Voltar ao Menu Principal                          ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                      Escolha a opção desejada: ");
    scanf("%c", &opcao);
    getchar();
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void consumo_alimentos(void){
    char opcao;
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                    = = = = =  Consumo Diário(Alimentos)  = = = = =      ///\n");
    printf("///                                                                         ///\n");
    printf("///                    1. Registrar Consumo de Alimentos                    ///\n");
    printf("///                    2. Consultar Consumo(Dia) de Alimentos               ///\n");
    printf("///                    3. Alterar Registro de Consumo de Alimentos          ///\n");
    printf("///                    4. Excluir Registro de Consumo de Alimentos          ///\n");
    printf("///                    0. Voltar ao Menu Principal                          ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                      Escolha a opção desejada: ");
    scanf("%c", &opcao);
    getchar();
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


void consumo_agua(void){
    char opcao;
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                    = = = = =  Consumo Diário(Água)  = = = = =           ///\n");
    printf("///                                                                         ///\n");
    printf("///                    1. Registrar Consumo de Água                         ///\n");
    printf("///                    2. Consultar Consumo(Dia) de Água                    ///\n");
    printf("///                    3. Alterar Registro de Consumo de Água               ///\n");
    printf("///                    4. Excluir Registro de Consumo de Água               ///\n");
    printf("///                    0. Voltar ao Menu Principal                          ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                      Escolha a opção desejada: ");
    scanf("%c", &opcao);
    getchar();
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


void relatorios(void){
    char opcao;
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                    = = = = =  Relatórios  = = = = =                     ///\n");
    printf("///                                                                         ///\n");
    printf("///                    1. Alimentos mais Consumidos                         ///\n");
    printf("///                    2. Total de Calorias(Dia)                            ///\n");
    printf("///                    3. Meta Diária de Calorias                           ///\n");
    printf("///                    4. Meta Diária de Água                               ///\n");
    printf("///                    5. Excluir Registro de Consumo                       ///\n");
    printf("///                    0. Voltar ao Menu Principal                          ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                      Escolha a opção desejada: ");
    scanf("%c", &opcao);
    getchar();
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}
void sair(void){
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                 Obrigado por usar o SIG-DietPlan!                       ///\n");
    printf("///                         Até a proxima!                                  ///\n");
    printf("///              📷 Instagram: @thiago.braga9a e gabrieluchoa_1             ///\n");
    printf("///              🐙 GitHub: github.com/Thiago-braga7                        ///\n");
    printf("///                         github/GabrielUchoa17                           ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");

}
void cadastrar_usuario(void){
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                               Usuários                                  ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = =  Cadastrar Usuário = = = = =                  ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Nome Completo:                                  ///\n");
    printf("///                         CPF(Apenas números):                            ///\n");
    printf("///                         Telefone(Apenas números):                       ///\n");
    printf("///                         Idade:                                          ///\n");
    printf("///                         Peso(Kg):                                       ///\n");
    printf("///                         Altura(m):                                      ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void buscar_usuario(void){
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                               Usuários                                  ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = =  Buscar Usuário = = = = =                     ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe o CPF(Apenas números):                  ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                        Informações do Usuário                           ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Nome Completo:                                  ///\n");
    printf("///                         CPF:                                            ///\n");
    printf("///                         Telefone:                                       ///\n");
    printf("///                         Idade:                                          ///\n");
    printf("///                         Peso(Kg):                                       ///\n");
    printf("///                         Altura(m):                                      ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}
void alterar_usuario(void){
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                               Usuários                                  ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = = Alterar Dados do Usuário = = = = =            ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe o CPF(Apenas números):                  ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                        Novos Dados do Usuário                           ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Nome Completo:                                  ///\n");
    printf("///                         CPF:                                            ///\n");
    printf("///                         Telefone:                                       ///\n");
    printf("///                         Idade:                                          ///\n");
    printf("///                         Peso(Kg):                                       ///\n");
    printf("///                         Altura(m):                                      ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}
void excluir_usuario(void){
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                               Usuários                                  ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = = Excluir Usuário = = = = =                     ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe o CPF(Apenas números):                  ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                           Excluindo Usuário                             ///\n");
    printf("///                                                                         ///\n");
    printf("///                            Dados do Usuário                             ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Nome Completo:                                  ///\n");
    printf("///                         CPF:                                            ///\n");
    printf("///                         Telefone:                                       ///\n");
    printf("///                         Idade:                                          ///\n");
    printf("///                         Peso(Kg):                                       ///\n");
    printf("///                         Altura(m):                                      ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                      Deseja excluir este usuário?(S/N):                  ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}
void cadastrar_alimento(void){
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                               Alimentos                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = =  Cadastrar Alimento na Dieta  = = = = =       ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Nome do Alimento:                                ///\n");
    printf("///                         Tipo(Fruta, Carne):                             ///\n");
    printf("///                         Calorias(kcal):                                 ///\n");
    printf("///                         Proteínas:                                      ///\n");
    printf("///                         Carboidratos:                                   ///\n");
    printf("///                         Gorduras:                                       ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}
void buscar_alimento(void){
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                               Alimentos                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = =  Buscar Alimento na Dieta= = = = =            ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe o nome do Alimento:                     ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                        Informações do Alimento                          ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Nome do Alimento:                                ///\n");
    printf("///                         Tipo(Fruta, Carne):                             ///\n");
    printf("///                         Calorias(kcal):                                 ///\n");
    printf("///                         Proteínas:                                      ///\n");
    printf("///                         Carboidratos:                                   ///\n");
    printf("///                         Gorduras:                                       ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}
void alterar_alimento(void){
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                               Alimentos                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = = Alterar Alimento na Dieta = = = = =           ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe o nome do Alimento:                     ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                        Novas Informações do ALimento                    ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Nome do Alimento:                                ///\n");
    printf("///                         Tipo(Fruta, Carne):                             ///\n");
    printf("///                         Calorias(kcal):                                 ///\n");
    printf("///                         Proteínas:                                      ///\n");
    printf("///                         Carboidratos:                                   ///\n");
    printf("///                         Gorduras:                                       ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}