#include <stdio.h>
#include <stdlib.h>
#include "alimentos.h"

void moduloAlimentos(void) {
    char opcao;
    do {
        opcao = alimentos();
        switch(opcao) {
            case '1': cadastrar_alimento(); break;
            case '2': buscar_alimento(); break;
            case '3': alterar_alimento(); break;
            case '4': excluir_alimento(); break;
            
        }
    } while (opcao != '0');  
}


char alimentos(void){
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
    return opcao;
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
void excluir_alimento(void){
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                               Alimentos                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = = Excluir Alimento da Dieta = = = = =           ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe o nome do Alimento:                     ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                           Excluindo Alimento                            ///\n");
    printf("///                                                                         ///\n");
    printf("///                            Informações do Alimento                      ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Nome do Alimento:                                ///\n");
    printf("///                         Tipo(Fruta, Carne):                             ///\n");
    printf("///                         Calorias(kcal):                                 ///\n");
    printf("///                         Proteínas:                                      ///\n");
    printf("///                         Carboidratos:                                   ///\n");
    printf("///                         Gorduras:                                       ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                      Deseja excluir este alimento?(S/N):                ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}