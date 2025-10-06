#include <stdio.h>
#include <stdlib.h>
#include "dietas.h"
#include "util.h"
#include <string.h>


typedef struct dieta Dieta;

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
    Dieta dt;

    dt.id_dieta = 1;

    arq_dietas = fopen("arq_dietas.csv", "rt");
    if (arq_dietas != NULL)
    {
        char linha[512];
        while (fgets(linha, sizeof(linha), arq_dietas) != NULL)
        {
            dt.id_dieta++;
        }
        fclose(arq_dietas);
    }

    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                               Dietas                                    ///\n");
    printf("///                                                                         ///\n");
    printf("///                  = = = = =  Cadastrar Dieta  = = = = =                  ///\n");
    printf("///                                                                         ///\n");
    printf("///                         CPF do Usuário:                                 ///\n");
    scanf("%s", dt.cpf);
    getchar();
    printf("///                         Nome da Dieta:                                  ///\n");
    scanf("%50[^\n]", dt.nome_dieta);
    getchar();
    printf("///                         Total de Calorias por dia:                      ///\n");
    scanf("%d", &dt.calorias);
    getchar();
    printf("///                         Refeições (breve descrição):                    ///\n");
    scanf("%200[^\n]", dt.refeicoes);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                        Dieta Cadastrada com Sucesso!                    ///\n");
    printf("///                        ID gerado: %02d                                    ///\n", dt.id_dieta);
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    pausar();

    arq_dietas = fopen("arq_dietas.csv", "at");
    if (arq_dietas == NULL)
    {
        printf("\t\t\t<<< ERRO: Não foi possível abrir o arquivo! >>>\n");
        printf("\t\t\t<<< Pressione ENTER para continuar... >>>\n");
        getchar();
        return;
    }
    fprintf(arq_dietas, "%d;", dt.id_dieta);
    fprintf(arq_dietas, "%s;", dt.cpf);
    fprintf(arq_dietas, "%s;", dt.nome_dieta);
    fprintf(arq_dietas, "%d;", dt.calorias);
    fprintf(arq_dietas, "%s\n", dt.refeicoes);
    fclose(arq_dietas);
    pausar();
}

void buscar_dieta(void){
    FILE *arq_dietas;

    Dieta dt;
    int id_busca;
    int encontrado = 0;

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

    arq_dietas = fopen("arq_dietas.csv", "rt");

    if (arq_dietas == NULL)
    {
        printf("Erro na criacao do arquivo\n");
        return;
    }
    while (fscanf(arq_dietas, "%d;%12[^;];%49[^;];%d;%199[^\n]\n",
                  &dt.id_dieta, dt.cpf, dt.nome_dieta, &dt.calorias, dt.refeicoes) == 5)
    {
        if (dt.id_dieta == id_busca)
        {
            printf("///                        Dieta Encontrada!                              ///\n");
            printf("ID da Dieta:       %d\n", dt.id_dieta);
            printf("CPF do Usuário:    %s\n", dt.cpf);
            printf("Nome da Dieta:     %s\n", dt.nome_dieta);
            printf("Total de Calorias: %d kcal\n", dt.calorias);
            printf("Refeições:         %s\n", dt.refeicoes);

            encontrado = 1;
            break;
        }
    }
    if (!encontrado){
        printf("\nDieta não encontrado!\n");
    }

    fclose(arq_dietas);
    getchar();
}


void alterar_dieta(void){
    // Dieta dt;
    Dieta nova_dt;
    int id_busca;
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
    printf("///                        Novos Dados da Dieta                             ///\n");
    printf("///                                                                         ///\n");
    printf("///                         CPF do Usuário:                                 ///\n");
    scanf("%s", nova_dt.cpf);
    getchar();
    printf("///                         Nome da Dieta:                                  ///\n");
    scanf("%50[^\n]", nova_dt.nome_dieta);
    getchar();
    printf("///                         Total de Calorias por dia:                      ///\n");
    scanf("%d", &nova_dt.calorias);
    getchar();
    printf("///                         Refeições (breve descrição):                    ///\n");
    scanf("%200[^\n]", nova_dt.refeicoes);
    getchar();

    nova_dt.id_dieta = id_busca;
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                    Dieta Alterada com sucesso!                          ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    pausar();
}

void excluir_dieta(void){

    FILE *arq_dietas;
    FILE *arq_dietas_temp;
    Dieta dt;
    int id_busca;
    int encontrado = 0;
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

    pausar();
    char resposta;

    do{
        arq_dietas = fopen("arq_dietas.csv", "rt");

        if (arq_dietas == NULL){
            printf("Erro na criacao do arquivo\n");
            return;
        }

        while (fscanf(arq_dietas, "%d;%12[^;];%49[^;];%d;%199[^\n]\n",&dt.id_dieta, dt.cpf, dt.nome_dieta, &dt.calorias, dt.refeicoes) == 5){
            if (dt.id_dieta == id_busca)
            {
                printf("///                        Dieta Encontrada!                              ///\n");
                printf("ID da Dieta:       %d\n", dt.id_dieta);
                printf("CPF do Usuário:    %s\n", dt.cpf);
                printf("Nome da Dieta:     %s\n", dt.nome_dieta);
                printf("Total de Calorias: %d kcal\n", dt.calorias);
                printf("Refeições:         %s\n", dt.refeicoes);

                encontrado = 1;
                break;
            }
        }
        if (!encontrado){
            printf("\nDieta não encontrada!\n");
        }

        fclose(arq_dietas);
        getchar();
        printf("Deseja confirmar a ação? (S/N): ");
        scanf(" %c", &resposta);

        resposta = confirmar_acao(resposta);

        if (resposta == 0){
            printf("Opção inválida! Digite apenas S ou N.\n");
        }

    } while (resposta == 0);

    if (resposta == 'S'){
        arq_dietas = fopen("arq_dietas.csv", "rt");
        arq_dietas_temp = fopen("arq_dietas_temp.csv", "wt");

        if (arq_dietas == NULL || arq_dietas_temp == NULL){
            printf("Erro na criacao do arquivo\n");
            return;
        }

        while (fscanf(arq_dietas, "%d;%12[^;];%49[^;];%d;%199[^\n]\n",&dt.id_dieta, dt.cpf, dt.nome_dieta, &dt.calorias, dt.refeicoes) == 5){
            if(dt.id_dieta != id_busca){
                fprintf(arq_dietas_temp, "%d;%s;%s;%d;%s\n", dt.id_dieta, dt.cpf, dt.nome_dieta, dt.calorias, dt.refeicoes);
            }
        }
        fclose(arq_dietas);
        fclose(arq_dietas_temp);

        remove("arq_dietas.csv");
        rename("arq_dietas_temp.csv", "arq_dietas.csv");

        if (!encontrado){
            printf("\nDieta não encontrada!\n");
        }

        printf("Dieta Excluída com Sucesso! \n");
    } else {
            printf("Operação de Exclusão Cancelada !  \n");
    }
    pausar();
}