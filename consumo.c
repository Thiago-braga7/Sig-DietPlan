#include <stdio.h>
#include <stdlib.h>
#include "consumo.h"
#include "util.h"


#define RED    "\x1b[31m"
#define RESET  "\x1b[0m"
#define CYAN    "\033[36m"


void modulo_consumo(void) {
    char opcao;
    do {
        opcao = tela_consumo();
        switch(opcao) {
            case '1': cadastrar_consumo(); break;
            case '2': buscar_consumo(); break;
            case '3': alterar_consumo(); break;
            case '4': excluir_consumo(); break;
            case '5': quantidade_agua(); break;
        }
    } while(opcao != '0');
}



char tela_consumo(void){
    char opcao;
    limpar_tela();

    printf("\n");
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             = = = = =  Consumo Diário (Alimentos e Água) = = = = =      ///\n");
    printf("///                                                                         ///\n");
    printf("///                    1. Cadastrar Consumo                                 ///\n");
    printf("///                    2. Buscar Consumo                                    ///\n");
    printf("///                    3. Alterar Consumo                                   ///\n");
    printf("///                    4. Excluir Consumo                                   ///\n");
    printf("///                    5. Quantidade de Água p/Dia                          ///\n");
    printf("///                    0. Voltar ao Menu Principal                          ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                      Escolha a opção desejada: ");
    scanf("%c", &opcao);
    getchar();
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n"RESET);
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    return opcao;
}

void cadastrar_consumo(void){
    int tipo;
    limpar_tela();
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             = = = = =  Consumo Diário (Alimentos e Água) = = = = =      ///\n");
    printf("///             Escolha o tipo de consumo(1-Alimentos ou 2 - Água):         ///\n");
    scanf("%d", &tipo);
    getchar();

    if(tipo == 1){
        char alimento[100], data[15];
        float quantidade;
        limpar_tela();

        printf("\n");
        printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                               Consumo Alimentos                         ///\n");
        printf("///                                                                         ///\n");
        printf("///                 = = = = =  Cadastrar Consumo de Alimentos = = = = =     ///\n");
        printf("///                                                                         ///\n");
        printf("///                                                                         ///\n");
        printf("///                         Informe o Alimento:                             ///\n");
        scanf("%s", alimento); 
        getchar();
        printf("///                         Quantidade(kcal):                               ///\n");
        scanf("%f", &quantidade);
        getchar();
        printf("///                         Informe a data (DD/MM/AAAA):                    ///\n");
        scanf("%s", data); 
        getchar();
        printf("///////////////////////////////////////////////////////////////////////////////\n"RESET);
        printf("\n");
        pausar();
        }
    else if(tipo == 2){
        int quantidade_agua;
        char data[15];
        limpar_tela();

        printf("\n");
        printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                               Consumo Água                              ///\n");
        printf("///                                                                         ///\n");
        printf("///                 = = = = =  Cadastrar Consumo de Água = = = = =          ///\n");
        printf("///                                                                         ///\n");
        printf("///                                                                         ///\n");
        printf("///                         Informe a quantidade (ml):                      ///\n");
        scanf("%d", &quantidade_agua);
        getchar();
        printf("///                         Informe a data (DD/MM/AAAA):                    ///\n");
        scanf("%s", data);
        getchar();
        printf("///////////////////////////////////////////////////////////////////////////////\n"RESET);
        printf("\n");
        pausar();
    }
    else {
        printf("Opção inválida!\n");
    }
    pausar();
}

void buscar_consumo(void){
    int tipo;
    limpar_tela();
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             = = = = =  Consumo Diário (Alimentos e Água) = = = = =      ///\n");
    printf("///             Escolha o tipo de consumo(1-Alimentos ou 2 - Água):         ///\n");
    scanf("%d", &tipo);
    getchar();

    if(tipo == 1){
        char data[15];
        limpar_tela();

        printf("\n");
        printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                               Consumo Alimentos                         ///\n");
        printf("///                                                                         ///\n");
        printf("///                 = = = = =  Buscar Consumo de Alimentos = = = = =        ///\n");
        printf("///                                                                         ///\n");
        printf("///                                                                         ///\n");
        printf("///                         Informe a data (DD/MM/AAAA):                    ///\n");
        scanf("%s", data);
        getchar();
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                     Registro de Consumo no dia (DD/MM/AAAA)             ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n"RESET);
        printf("\n");
        pausar();
        }
    else if(tipo == 2){
        char data[15];
        limpar_tela();

        printf("\n");
        printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                               Consumo Água                              ///\n");
        printf("///                                                                         ///\n");
        printf("///                 = = = = =  Buscar Consumo de Água = = = = =             ///\n");
        printf("///                                                                         ///\n");
        printf("///                                                                         ///\n");
        printf("///                         Informe a data (DD/MM/AAAA):                    ///\n");
        scanf("%s", data);
        getchar();
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                     Registro de Consumo (Água) no dia (DD/MM/AAAA)      ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n"RESET);
        printf("\n");
        pausar();
    }
    else {
        printf("Opção inválida!\n");
    }
    pausar();
}
void alterar_consumo(void){
    int tipo;
    limpar_tela();
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             = = = = =  Consumo Diário (Alimentos e Água) = = = = =      ///\n");
    printf("///             Escolha o tipo de consumo(1-Alimentos ou 2 - Água):         ///\n");
    scanf("%d", &tipo);
    getchar();

    if(tipo == 1){
        char data[15], alimento[100], nova_data[15];
        float nova_quantidade;
        limpar_tela();

        printf("\n");
        printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                               Consumo Alimentos                         ///\n");
        printf("///                                                                         ///\n");
        printf("///                 = = = = =  Alterar Consumo de Alimentos = = = = =       ///\n");
        printf("///                                                                         ///\n");
        printf("///                                                                         ///\n");
        printf("///                         Informe a data (DD/MM/AAAA):                    ///\n");
        scanf("%s", data);
        getchar();
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                     Registro de Consumo no dia (DD/MM/AAAA)             ///\n");
        printf("///                                                                         ///\n");
        printf("///                     Qual alimento deseja alterar? (número):             ///\n");
        int opcao_alimento;
        scanf("%d", &opcao_alimento);
        getchar();
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                     Novas Informações Consumo de Alimentos              ///\n");
        printf("///                                                                         ///\n");
        printf("///                         Informe o Alimento:                             ///\n");
        scanf("%s", alimento);
        getchar();
        printf("///                         Quantidade(kcal):                               ///\n");
        scanf("%f", &nova_quantidade);
        getchar();
        printf("///                         Informe a data (DD/MM/AAAA):                    ///\n"RESET);
        scanf("%s", nova_data);
        getchar();
        printf("\n");
        pausar();
        }
    else if(tipo == 2){
        char data[15];
        int nova_quantidade_agua;
        char nova_data[15];
        limpar_tela();
        
        printf("\n");
        printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                               Consumo Água                              ///\n");
        printf("///                                                                         ///\n");
        printf("///                 = = = = =  Alterar Consumo de Água = = = = =            ///\n");
        printf("///                                                                         ///\n");
        printf("///                                                                         ///\n");
        printf("///                         Informe a data (DD/MM/AAAA):                    ///\n");
        scanf("%s", data);
        getchar();
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                     Registro de Consumo(Água) no dia (DD/MM/AAAA)       ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                     Novas Informações Consumo de Água                   ///\n");
        printf("///                                                                         ///\n");
        printf("///                         Informe a quantidade (ml):                      ///\n");
        scanf("%d", &nova_quantidade_agua);
        getchar();
        printf("///                         Informe a data (DD/MM/AAAA):                    ///\n");
        scanf("%s", nova_data);
        getchar();
        printf("///////////////////////////////////////////////////////////////////////////////\n"RESET);
        printf("\n");
        pausar();
    }
    else {
        printf("Opção inválida!\n");
    }
    pausar();
}
void excluir_consumo(void){
    int tipo;
    limpar_tela();
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             = = = = =  Consumo Diário (Alimentos e Água) = = = = =      ///\n");
    printf("///             Escolha o tipo de consumo(1-Alimentos ou 2 - Água):         ///\n");
    scanf("%d", &tipo);
    getchar();

    if(tipo == 1){
        char data[15], alimento[100];
        limpar_tela();

        printf("\n");
        printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                               Consumo Alimentos                         ///\n");
        printf("///                                                                         ///\n");
        printf("///                 = = = = =  Excluir Consumo de Alimentos = = = = =       ///\n");
        printf("///                                                                         ///\n");
        printf("///                                                                         ///\n");
        printf("///                         Informe a data (DD/MM/AAAA):                    ///\n");
        scanf("%s", data);
        getchar();
        printf("///                         Informe o Alimento:                             ///\n");
        scanf("%s", alimento);
        getchar();
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                       Informações Consumo de Alimentos                  ///\n");
        printf("///                                                                         ///\n");
        printf("///                         Alimento:                                       ///\n");
        printf("///                         Quantidade(kcal):                               ///\n");
        printf("///                         Data(DD/MM/AAAA):                               ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        char resposta;

        do {
            printf(RED"Deseja confirmar a ação? (S/N): "RESET);
            scanf(" %c", &resposta);

            resposta = confirmar_acao(resposta); 

            if (resposta == 0) {  
                printf(RED"Opção inválida! Digite apenas S ou N.\n"RESET);
            }
        } while (resposta == 0); 

        if (resposta == 'S') {
            printf(RED"/// Consumo de Alimentos excluído com sucesso! ///\n");
        } else {
            printf(RED"/// Operação de exclusão cancelada! ///\n");
    }
    pausar();

        }
        
    else if(tipo == 2){
        char data[15];
        limpar_tela();

        printf("\n");
        printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                               Consumo Água                              ///\n");
        printf("///                                                                         ///\n");
        printf("///                 = = = = =  Excluir Consumo de Água = = = = =            ///\n");
        printf("///                                                                         ///\n");
        printf("///                                                                         ///\n");
        printf("///                         Informe a data (DD/MM/AAAA):                    ///\n");
        scanf("%s", data);
        getchar();
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                       Informações Consumo de Água                       ///\n");
        printf("///                                                                         ///\n");
        printf("///                         Quantidade Água(ml):                            ///\n");
        printf("///                         Data(DD/MM/AAAA):                               ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        char resposta;

        do {
            printf(RED"Deseja confirmar a ação? (S/N): "RESET);
            scanf(" %c", &resposta);

            resposta = confirmar_acao(resposta); 

            if (resposta == 0) {  
                printf(RED"Opção inválida! Digite apenas S ou N.\n"RESET);
            }
        } while (resposta == 0); 

        if (resposta == 'S') {
            printf(RED"/// Consumo de Água excluído com sucesso! ///\n");
        } else {
            printf(RED"/// Operação de exclusão cancelada! ///\n");
    }
    pausar();

}
}

void quantidade_agua(void){
    char genero;
    float peso, agua;

    limpar_tela();
    printf("\n");
    printf(RED"///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                               Consumo Água                              ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = =  Quantidade de Água p/Dia = = = = =           ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n"RESET);

    
    do {
        printf(CYAN"Informe seu gênero (M = Masculino, F = Feminino, N = Prefiro não informar): "RESET);
        scanf(" %c", &genero);

        genero = ler_genero(genero); 

        if (genero == 0) {
            printf(CYAN"Opção inválida! Digite apenas M, F ou N.\n"RESET);
        }
    } while (genero == 0);

    do {
        printf("Informe seu peso (Kg): ");
        scanf("%f", &peso);
        getchar();

        peso = validar_peso(peso);  

        if (peso <= 0) {
            printf("Peso inválido! Digite um valor maior que 0.\n");
        }
    } while (peso <= 0);

    
    agua = calcular_quantidade_agua(peso, genero);

    printf("\nVocê deve consumir aproximadamente: %.2f L de água por dia.\n", agua);
    pausar(); 
}