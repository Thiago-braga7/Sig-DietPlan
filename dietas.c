#include <stdio.h>
#include <stdlib.h>
#include "dietas.h"
#include "util.h"
#include <string.h>


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
    char cpf[13];
    char nome_dieta[50];
    char refeicoes[200];
    int calorias;
    int id_dieta = 1;

    arq_dietas = fopen("arq_dietas.csv", "rt");
    if (arq_dietas != NULL)
    {
        char linha[512];
        while (fgets(linha, sizeof(linha), arq_dietas) != NULL)
        {
            id_dieta++;
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
    scanf("%s", cpf);
    getchar();
    printf("///                         Nome da Dieta:                                  ///\n");
    scanf("%s", nome_dieta);
    getchar();
    printf("///                         Total de Calorias por dia:                      ///\n");
    scanf("%d", &calorias);
    getchar();
    printf("///                         Refeições (breve descrição):                    ///\n");
    scanf("%s", refeicoes);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                        Dieta Cadastrada com Sucesso!                    ///\n");
    printf("///                        ID gerado: %02d                                    ///\n", id_dieta);
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
    fprintf(arq_dietas, "%d;", id_dieta);
    fprintf(arq_dietas, "%s;", cpf);
    fprintf(arq_dietas, "%s;", nome_dieta);
    fprintf(arq_dietas, "%d;", calorias);
    fprintf(arq_dietas, "%s\n", refeicoes);
    fclose(arq_dietas);
    pausar();
}

void buscar_dieta(void){
    FILE *arq_dietas;

    char cpf[13];
    char nome_dieta[50];
    char refeicoes[200];
    int calorias;
    int id_dieta;
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
                  &id_dieta, cpf, nome_dieta, &calorias, refeicoes) == 5)
    {
        if (id_dieta == id_busca)
        {
            printf("///                        Dieta Encontrada!                              ///\n");
            printf("ID da Dieta:       %d\n", id_dieta);
            printf("CPF do Usuário:    %s\n", cpf);
            printf("Nome da Dieta:     %s\n", nome_dieta);
            printf("Total de Calorias: %d kcal\n", calorias);
            printf("Refeições:         %s\n", refeicoes);

            encontrado = 1;
            break;
        }
    }
    fclose(arq_dietas);
    
    if (encontrado == 0){
        printf("\n///               Dieta com o ID %d nao foi encontrada.                 ///\n", id_busca);
    }

    pausar();
}

void alterar_dieta(void){
    char nome_dieta[50];
    char novo_cpf[15];
    char novo_nome_dieta[50];
    char novas_refeicoes[200];
    int novas_calorias;
    limpar_tela();
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                Dietas                                   ///\n");
    printf("///                                                                         ///\n");
    printf("///                  = = = = =  Alterar Dieta  = = = = =                    ///\n");
    printf("///                                                                         ///\n");
    printf("///                        Informe o nome da Dieta:                         ///\n");
    scanf("%s", nome_dieta);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                        Novos Dados da Dieta                             ///\n");
    printf("///                                                                         ///\n");
    printf("///                         CPF do Usuário:                                 ///\n");
    scanf("%s", novo_cpf);
    getchar();
    printf("///                         Nome da Dieta:                                  ///\n");
    scanf("%s", novo_nome_dieta);
    getchar();
    printf("///                         Total de Calorias por dia:                      ///\n");
    scanf("%d", &novas_calorias);
    getchar();
    printf("///                         Refeições (breve descrição):                    ///\n");
    scanf("%s", novas_refeicoes);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                    Dieta Alterada com sucesso!                          ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    pausar();
}

void excluir_dieta(void)
{

    char nome_dieta[50];
    limpar_tela();
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                               Dietas                                    ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = = Excluir Dieta = = = = =                       ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe o nome da Dieta:                        ///\n");
    scanf("%s", nome_dieta);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                           Excluindo Dieta                               ///\n");
    printf("///                                                                         ///\n");
    printf("///                           Dados da Dieta                                ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Nome da Dieta:                                  ///\n");
    printf("///                         Total de Calorias por dia:                      ///\n");
    printf("///                         Refeições:                                      ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");

    pausar();
    char resposta;

    do
    {
        printf("Deseja confirmar a ação? (S/N): ");
        scanf(" %c", &resposta);

        resposta = confirmar_acao(resposta);

        if (resposta == 0)
        {
            printf("Opção inválida! Digite apenas S ou N.\n");
        }
    } while (resposta == 0);

    if (resposta == 'S')
    {
        printf("/// Dieta excluída com sucesso! ///\n");
    }
    else
    {
        printf("/// Operação de exclusão cancelada! ///\n");
    }

    pausar();
}
