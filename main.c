#include <stdio.h>
#include <stdlib.h> 

void menu_principal(void); 
void consumo_alimentos(void);
void consumo_agua(void);


int main(void){
    menu_principal();
    consumo_alimentos();
    consumo_agua();
    
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
    printf("///                      0. Sair                                            ///\n");
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




