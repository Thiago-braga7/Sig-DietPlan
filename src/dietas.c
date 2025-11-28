#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "dietas.h"
#include "validacoes.h"
#include "leituras.h"
#include "uteis.h"


void modulo_dietas(void) {
    char opcao;
    do {
        limpar_tela();
        opcao = tela_dietas();

        switch(opcao) {
            case '1':
                cadastrar_dieta();
                break;
            case '2':
                buscar_dieta();
                break;
            case '3':
                alterar_dieta();
                break;
            case '4':
                excluir_dieta();
                break;
            case '5':
                excluir_dieta_fisica();
                break;
        }
        
    } while (opcao != '0');  
}


char tela_dietas(void){
    char opcao;
    limpar_tela();

    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                     = = = = = Dietas  = = = = =                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                    1. Cadastrar Dieta                                   ///\n");
    printf("///                    2. Buscar Dieta                                      ///\n");
    printf("///                    3. Alterar Dieta                                     ///\n");
    printf("///                    4. Excluir Dieta                                     ///\n");
    printf("///                    5. Listar Dietas                                     ///\n");
    printf("///                    0. Voltar ao Menu Principal                          ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                      Escolha a opção desejada: ");
    scanf("%c", &opcao);
    getchar();
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    pausar();
    return opcao;
}


void cadastrar_dieta(void){
    FILE *arq_dietas;
    Dieta* dt;
    dt = (Dieta*)malloc(sizeof(Dieta));
    
    dt->id_dieta = 1; 
    arq_dietas = fopen("data/arq_dietas.dat", "rb"); 
    
    if (arq_dietas != NULL){
        fseek(arq_dietas, 0, SEEK_END);  
        long num_registros = ftell(arq_dietas) / sizeof(Dieta);
        dt->id_dieta = num_registros + 1;
        fclose(arq_dietas);
    }

    limpar_tela();
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                               Dietas                                    ///\n");
    printf("///                                                                         ///\n");
    printf("///                  = = = = =  Cadastrar Dieta  = = = = =                  ///\n");
    printf("///                                                                         ///\n");
    ler_dieta(dt->nome_dieta);
    ler_calorias(dt->calorias);
    ler_refeicoes(dt->refeicoes);
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                        Dieta Cadastrada com Sucesso!                    ///\n");
    printf("///                        ID gerado: %02d                                    ///\n", dt->id_dieta);
    printf("///////////////////////////////////////////////////////////////////////////////\n");

    dt->status = true;

    arq_dietas = fopen("data/arq_dietas.dat", "a+b");
    if (arq_dietas == NULL){
        printf("Erro na criação do arquivo\n");
        return;
    }
    
    fwrite(dt, sizeof(Dieta), 1, arq_dietas);
    fclose(arq_dietas);
    free(dt);
    pausar();
}


void buscar_dieta(void){
    FILE * arq_dietas;
    Dieta * dt;

    int id_busca;
    bool encontrado = false;

    dt = (Dieta*) malloc(sizeof(Dieta));
    
    limpar_tela();
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                Dietas                                   ///\n");
    printf("///                                                                         ///\n");
    printf("///                  = = = = =  Buscar Dieta  = = = = =                     ///\n");
    printf("///                                                                         ///\n");
    printf("///                        Informe o ID da Dieta:                           ///\n");
    scanf("%d", &id_busca);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    arq_dietas = fopen("data/arq_dietas.dat", "rb");

    if (arq_dietas == NULL){
        printf("Erro na criação do arquivo\n");
        return;
    }
    
    while (fread(dt, sizeof(Dieta), 1, arq_dietas)){
        if ((dt->id_dieta == id_busca) && (dt->status == true)){
            printf("///                        Dieta Encontrada!                                ///\n");
            exibir_dieta(dt);
            encontrado = true;
            break;
        }
    }

    if (encontrado == false){
        printf("\nDieta não encontrada!\n");
    }

    fclose(arq_dietas);
    free(dt);
    pausar();
}


void alterar_dieta(void){
    FILE *arq_dietas;
    FILE *arq_dietas_temp;
    Dieta * dt;

    int id_busca;
    char opcao;
    char continuar;
    bool encontrado = false;

    dt = (Dieta*) malloc(sizeof(Dieta));
    
    limpar_tela();
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                Dietas                                   ///\n");
    printf("///                                                                         ///\n");
    printf("///                  = = = = =  Alterar Dieta  = = = = =                    ///\n");
    printf("///                                                                         ///\n");
    printf("///                        Informe o ID da Dieta:                           ///\n");
    scanf("%d", &id_busca);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");

    arq_dietas = fopen("data/arq_dietas.dat", "rb");
    arq_dietas_temp = fopen("data/arq_dietas_temp.dat", "wb");

    if (arq_dietas == NULL || arq_dietas_temp == NULL){
        printf("Erro na criaçao do arquivo\n");
        return;
    }

    while(fread(dt, sizeof(Dieta), 1, arq_dietas)){
        if((dt->id_dieta == id_busca) && (dt->status == true)){
            encontrado = true;

            do{
                limpar_tela();
                exibir_moldura_titulo("Dados atuais da dieta");
                exibir_dieta(dt);

                printf("\nQual campo deseja alterar?\n");
                printf("1. Nome da Dieta\n");
                printf("2. Total de Calorias\n");
                printf("3. Refeições\n");
                printf("Escolha uma opção: ");
                scanf(" %c", &opcao);
                getchar();

                switch (opcao) {
                    case '1':
                        validar_nome(dt->nome_dieta);
                        break;
                    case '2':
                        validar_calorias(dt->calorias);
                        break;
                    case '3':
                        validar_observacao(dt->refeicoes);
                        break;
                    default:
                        printf("Opção inválida!\n");
                        break;
                }

                printf("\nDados atualizados\n");
                exibir_dieta(dt);

                printf("\nDeseja alterar outro campo? (S/N): ");
                scanf(" %c", &continuar);
                getchar();
                continuar = confirmar_acao(continuar);

                if(continuar == 0){
                    printf("Opção inválida! Digite apenas S ou N.\n");
                }
                
            } while(continuar == 'S');
        }
        fwrite(dt, sizeof(Dieta), 1, arq_dietas_temp);
    }  
    fclose(arq_dietas);
    fclose(arq_dietas_temp);  

    if(encontrado == true){
        remove("data/arq_dietas.dat");
        rename("data/arq_dietas_temp.dat", "data/arq_dietas.dat");
        printf("\nDieta alterada com sucesso!\n");

    } else{
        remove("data/arq_dietas_temp.dat");
        printf("\nDieta não encontrada!\n");
    }

    free(dt);
    pausar();
}


void excluir_dieta(void){
    FILE * arq_dietas;
    Dieta * dt;

    int id_busca;
    char resposta;
    bool encontrado = false;

    dt = (Dieta*) malloc(sizeof(Dieta));

    limpar_tela();
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                               Dietas                                    ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = = Excluir Dieta = = = = =                       ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe o ID da Dieta:                          ///\n");
    scanf("%d", &id_busca);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    
    arq_dietas = fopen("data/arq_dietas.dat", "r+b");
    
    if (arq_dietas == NULL){
        printf("Erro na criação do arquivo\n");
        return;
    }

    while(fread(dt, sizeof(Dieta),1, arq_dietas)){
        if((dt->id_dieta == id_busca) && (dt->status == true)){
            printf("///                        Dieta Encontrada!                                ///\n");
            exibir_dieta(dt);
            encontrado = true;

            do {
                printf("\nDeseja realmente excluir esta dieta? (S/N): ");
                scanf(" %c", &resposta);
                resposta = confirmar_acao(resposta);
                
                if(resposta == 0){
                    printf("Opção inválida! Digite apenas S ou N.\n");
                }

            } while(resposta == 0);

            if (resposta == 'S') {
                dt->status = false;
                fseek(arq_dietas, (-1)*sizeof(Dieta), SEEK_CUR);
                fwrite(dt, sizeof(Dieta), 1, arq_dietas);
                printf("\nDieta excluída com sucesso!\n");

            } else {
                printf("\nOperação de exclusão cancelada.\n");
            }
            break;
        }
    }
    if (encontrado == false){
        printf("\nDieta não encontrada!\n");
    }
    fclose(arq_dietas);
    free(dt);
    pausar();
}


void excluir_dieta_fisica(void) {
    FILE * arq_dietas;
    FILE * arq_dietas_temp;
    Dieta * dt;

    int id_busca;
    char resposta;
    bool encontrado = false;
    bool excluida = false;

    dt = (Dieta*) malloc(sizeof(Dieta));

    limpar_tela();
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                               Dietas                                    ///\n");
    printf("///                                                                         ///\n");
    printf("///              = = = = = Exclusão Física de Dieta = = = = =               ///\n");
    printf("///                                                                         ///\n");
    printf("///                    Informe o ID da Dieta: ");
    scanf("%d", &id_busca);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    
    arq_dietas = fopen("data/arq_dietas.dat", "rb");
    arq_dietas_temp = fopen("data/arq_dietas_temp.dat", "wb");

    if (arq_dietas == NULL || arq_dietas_temp == NULL) {
        printf("Erro ao abrir arquivos!\n");
        return;
    }

    while (fread(dt, sizeof(Dieta), 1, arq_dietas)) {
        if (dt->id_dieta == id_busca) {
            printf("///                        Dieta Encontrada!                                ///\n");
            exibir_dieta(dt);
            encontrado = true;

            if (dt->status == true) {
                printf("Status: Ativa \n");

            } else {
                printf("Status: Inativa \n");
            }

            if (dt->status == false) {
                do {
                    printf("\nDeseja realmente excluir esta dieta (fisicamente)? (S/N): ");
                    scanf(" %c", &resposta);
                    resposta = confirmar_acao(resposta);

                    if (resposta == 0) {
                        printf("Opção inválida! Digite apenas S ou N.\n");
                    }

                } while (resposta == 0);

                if (resposta == 'S') {
                    printf("\nDieta excluída com sucesso!\n");
                    excluida = true;

                } else {
                    printf("\nOperação cancelada. A dieta foi mantida.\n");
                    fwrite(dt, sizeof(Dieta), 1, arq_dietas_temp);
                }

            } else {
                printf("\nA dieta está ativa, portanto não pode ser excluída fisicamente.\n");
                fwrite(dt, sizeof(Dieta), 1, arq_dietas_temp);
            }

        } else {
            fwrite(dt, sizeof(Dieta), 1, arq_dietas_temp);
        }
    }

    fclose(arq_dietas);
    fclose(arq_dietas_temp);
    free(dt);

    remove("data/arq_dietas.dat");
    rename("data/arq_dietas_temp.dat", "data/arq_dietas.dat");

    if (encontrado == false) {
        printf("\nDieta não encontrada!\n");

    } else if (excluida == true) {
        printf("\nExclusão física concluída!\n");
    }

    pausar(); 
}


void exibir_dieta(const Dieta * dt){
    if (dt == NULL) {
        printf("Erro: dieta inexistente!\n");
        return;
    }

    printf("ID da Dieta:       %d\n", dt->id_dieta);
    printf("Nome da Dieta:     %s\n", dt->nome_dieta);
    printf("Total de Calorias: %.2f kcal\n", dt->calorias);
    printf("Refeições:         %s\n", dt->refeicoes);
}
