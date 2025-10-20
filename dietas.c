#include <stdio.h>
#include <stdlib.h>
#include "dietas.h"
#include "validacoes.h"
#include <string.h>
#define True 1
#define False 0


void modulo_dietas(void) {
    char opcao;
    do {
        limpar_tela();
        opcao = tela_dietas();
        switch(opcao) {
            case '1': cadastrar_dieta(); break;
            case '2': buscar_dieta(); break;
            case '3': alterar_dieta(); break;
            case '4': excluir_dieta(); break;
            case '5': listar_dietas(); break;
            // case '6': excluir_dieta_fisica(); break;
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
    // printf("///                    6. Excluir Dieta(Físico)                             ///\n");
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
    arq_dietas = fopen("arq_dietas.dat", "rb"); 
    
    // Créditos: Função adaptada do gemini;
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
    printf("///                         CPF do Usuário:                                 ///\n");
    scanf("%s", dt->cpf);
    getchar();
    printf("///                         Nome da Dieta:                                  ///\n");
    scanf("%50[^\n]", dt->nome_dieta);
    getchar();
    printf("///                         Total de Calorias por dia:                      ///\n");
    scanf("%d", &dt->calorias);
    getchar();
    printf("///                         Refeições (breve descrição):                    ///\n");
    scanf("%200[^\n]", dt->refeicoes);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                        Dieta Cadastrada com Sucesso!                    ///\n");
    printf("///                        ID gerado: %02d                                    ///\n", dt->id_dieta);
    printf("///////////////////////////////////////////////////////////////////////////////\n");

    dt->status = True;

    arq_dietas = fopen("arq_dietas.dat", "a+b");
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
    int encontrado;

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
    encontrado = False;
    arq_dietas = fopen("arq_dietas.dat", "rb");

    if (arq_dietas == NULL){
        printf("Erro na criação do arquivo\n");
        return;
    }
    while (fread(dt, sizeof(Dieta), 1, arq_dietas)){
        if ((dt->id_dieta == id_busca) && (dt->status == True)){
            printf("///                        Dieta Encontrada!                                ///\n");
            printf("ID da Dieta:       %d\n", dt->id_dieta);
            printf("CPF do Usuário:    %s\n", dt->cpf);
            printf("Nome da Dieta:     %s\n", dt->nome_dieta);
            printf("Total de Calorias: %d kcal\n", dt->calorias);
            printf("Refeições:         %s\n", dt->refeicoes);
            encontrado = True;
            break;
        }
    }
    if (encontrado == False){
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
    int encontrado;
    char opcao;
    char continuar;

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
    encontrado = False;

    arq_dietas = fopen("arq_dietas.dat", "rb");
    arq_dietas_temp = fopen("arq_dietas_temp.dat", "wb");

    if (arq_dietas == NULL || arq_dietas_temp == NULL){
        printf("Erro na criaçao do arquivo\n");
        return;
    }

    while(fread(dt, sizeof(Dieta), 1, arq_dietas)){
        if((dt->id_dieta == id_busca) && (dt->status == True)){
            encontrado = True;

            do{
                limpar_tela();
                printf("\n    Dados atuais da dieta    \n");
                printf("ID da Dieta:       %d\n", dt->id_dieta);
                printf("CPF do Usuário:    %s\n", dt->cpf);
                printf("Nome da Dieta:     %s\n", dt->nome_dieta);
                printf("Total de Calorias: %d kcal\n", dt->calorias);
                printf("Refeições:         %s\n", dt->refeicoes);

                printf("\nQual campo deseja alterar?\n");
                printf("1. CPF do Usuário\n");
                printf("2. Nome da Dieta\n");
                printf("3. Total de Calorias\n");
                printf("4. Refeições\n");
                printf("Escolha uma opção: ");
                scanf(" %c", &opcao);
                getchar();

                switch (opcao) {
                    case '1':
                        printf("Novo CPF: ");
                        scanf("%12s", dt->cpf);
                        getchar();
                        break;
                    case '2':
                        printf("Novo Nome da Dieta: ");
                        scanf("%50[^\n]", dt->nome_dieta);
                        getchar();
                        break;
                    case '3':
                        printf("Novo Total de Calorias: ");
                        scanf("%d", &dt->calorias);
                        getchar();
                        break;
                    case '4':
                        printf("Nova descrição das Refeições: ");
                        scanf("%200[^\n]", dt->refeicoes);
                        getchar();
                        break;
                    default:
                        printf("Opção inválida!\n");
                        break;
                }
                printf("\n    Dados atualizados   \n");
                printf("ID da Dieta:       %d\n", dt->id_dieta);
                printf("CPF do Usuário:    %s\n", dt->cpf);
                printf("Nome da Dieta:     %s\n", dt->nome_dieta);
                printf("Total de Calorias: %d kcal\n", dt->calorias);
                printf("Refeições:         %s\n", dt->refeicoes);

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

    if(encontrado == True){
        remove("arq_dietas.dat");
        rename("arq_dietas_temp.dat", "arq_dietas.dat");
        printf("\nDieta alterada com sucesso!\n");
    } else{
        remove("arq_dietas_temp.dat");
        printf("\nDieta não encontrada!\n");
    }
    free(dt);
    pausar();
}

void excluir_dieta(void){

    FILE * arq_dietas;
    Dieta * dt;
    int id_busca;
    int encontrado;
    char resposta;

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
    encontrado = False;
    

    arq_dietas = fopen("arq_dietas.dat", "r+b");
    
    if (arq_dietas == NULL){
        printf("Erro na criação do arquivo\n");
        return;
    }

    while(fread(dt, sizeof(Dieta),1, arq_dietas)){
        if((dt->id_dieta == id_busca) && (dt->status == True)){
            printf("///                        Dieta Encontrada!                                ///\n");
            printf("ID da Dieta:       %d\n", dt->id_dieta);
            printf("CPF do Usuário:    %s\n", dt->cpf);
            printf("Nome da Dieta:     %s\n", dt->nome_dieta);
            printf("Total de Calorias: %d kcal\n", dt->calorias);
            printf("Refeições:         %s\n", dt->refeicoes);
            encontrado = True;

            do {
                printf("\nDeseja realmente excluir esta dieta? (S/N): ");
                scanf(" %c", &resposta);
                resposta = confirmar_acao(resposta);
                
                if(resposta == 0){
                    printf("Opção inválida! Digite apenas S ou N.\n");
                }
            } while(resposta == 0);
            if (resposta == 'S'){
                dt->status = False;
                fseek(arq_dietas, (-1)*sizeof(Dieta), SEEK_CUR);
                fwrite(dt, sizeof(Dieta), 1, arq_dietas);
                printf("\nDieta excluída com sucesso!\n");
            } else{
                printf("\nOperação de exclusão cancelada.\n");
            }
            break;
        }
    }
    if (encontrado == False){
        printf("\nDieta não encontrada!\n");
    }
    fclose(arq_dietas);
    free(dt);
    pausar();
}

void listar_dietas(void) {
    FILE *arq_dietas;
    Dieta* dt;

    dt = (Dieta*) malloc(sizeof(Dieta));
    
    arq_dietas = fopen("arq_dietas.dat", "rb");
    if (arq_dietas == NULL) {
        printf("Nenhuma dieta cadastrada ainda.\n");
        free(dt);
        return;
    }

    limpar_tela();
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                               Dietas                                    ///\n");
    printf("///                                                                         ///\n");
    printf("///                  = = = = =  Listar Dietas  = = = = =                    ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    while (fread(dt, sizeof(Dieta), 1, arq_dietas)) {
        if (dt->status == True) {  
            printf("ID: %d\n", dt->id_dieta);
            printf("CPF: %s\n", dt->cpf);
            printf("Nome da Dieta: %s\n", dt->nome_dieta);
            printf("Calorias/dia: %d\n", dt->calorias);
            printf("Refeições: %s\n", dt->refeicoes);
            printf("--------------------------------------------------\n");
        }
    }

    fclose(arq_dietas);
    free(dt);

    pausar();
}

// void excluir_dieta_fisica(void) {
//     FILE * arq_dietas;
//     FILE * arq_dietas_temp;
//     Dieta * dt;
//     int id_busca;
//     int encontrado;
//     int excluida;
//     char resposta;

//     dt = (Dieta*) malloc(sizeof(Dieta));

//     limpar_tela();
//     printf("\n");
//     printf("///////////////////////////////////////////////////////////////////////////////\n");
//     printf("///                               Dietas                                    ///\n");
//     printf("///                                                                         ///\n");
//     printf("///              = = = = = Exclusão Física de Dieta = = = = =               ///\n");
//     printf("///                                                                         ///\n");
//     printf("///                    Informe o ID da Dieta: ");
//     scanf("%d", &id_busca);
//     getchar();
//     printf("///////////////////////////////////////////////////////////////////////////////\n");
//     encontrado = False;
//     excluida = False;
    
//     arq_dietas = fopen("arq_dietas.dat", "rb");
//     arq_dietas_temp = fopen("arq_dietas_temp.dat", "wb");

//     if (arq_dietas == NULL || arq_dietas_temp == NULL) {
//         printf("Erro ao abrir arquivos!\n");
//         return;
//     }

//     while (fread(dt, sizeof(Dieta), 1, arq_dietas)) {
//         if (dt->id_dieta == id_busca) {
//             printf("///                        Dieta Encontrada!                                ///\n");
//             printf("ID da Dieta:       %d\n", dt->id_dieta);
//             printf("CPF do Usuário:    %s\n", dt->cpf);
//             printf("Nome da Dieta:     %s\n", dt->nome_dieta);
//             printf("Total de Calorias: %d kcal\n", dt->calorias);
//             printf("Refeições:         %s\n", dt->refeicoes);
//             encontrado = True;

//             if (dt->status == True) {
//                 printf("Status: Ativa \n");
//             } else {
//                 printf("Status: Inativa \n");
//             }

//             if (dt->status == False) {
//                 do {
//                     printf("\nDeseja realmente excluir esta dieta (fisicamente)? (S/N): ");
//                     scanf(" %c", &resposta);
//                     resposta = confirmar_acao(resposta);

//                     if (resposta == 0) {
//                         printf("Opção inválida! Digite apenas S ou N.\n");
//                     }
//                 } while (resposta == 0);

//                 if (resposta == 'S') {
//                     printf("\nDieta excluída com sucesso!\n");
//                     excluida = True;
//                 } else {
//                     printf("\nOperação cancelada. A dieta foi mantida.\n");
//                     fwrite(dt, sizeof(Dieta), 1, arq_dietas_temp);
//                 }
//             } else {
//                 printf("\nA dieta está ativa, portanto não pode ser excluída fisicamente.\n");
//                 fwrite(dt, sizeof(Dieta), 1, arq_dietas_temp);
//             }
//         } else {
//             fwrite(dt, sizeof(Dieta), 1, arq_dietas_temp);
//         }
//     }

//     fclose(arq_dietas);
//     fclose(arq_dietas_temp);
//     free(dt);

//     remove("arq_dietas.dat");
//     rename("arq_dietas_temp.dat", "arq_dietas.dat");

//     if (encontrado == False) {
//         printf("\nDieta não encontrada!\n");
//     } else if (excluida == True) {
//         printf("\nExclusão física concluída!\n");
//     }

//     pausar();
// }

