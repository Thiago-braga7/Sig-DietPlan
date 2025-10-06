#include <stdio.h>
#include <stdlib.h>
#include "profissionais.h"
#include "util.h"
#include <string.h>



void modulo_profissionais(void) {
    char opcao;
    do {
        limpar_tela();
        opcao = tela_profissionais();
        switch(opcao) {
            case '1': cadastrar_profissional(); break;
            case '2': buscar_profissional(); break;
            case '3': alterar_profissional(); break;
            case '4': excluir_profissional(); break;
        }
    } while (opcao != '0');  
}

char tela_profissionais(void){
    char opcao;
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                  = = = = =  Profissionais  = = = = =                    ///\n");
    printf("///                                                                         ///\n");
    printf("///                    1. Cadastrar Profissional                            ///\n");
    printf("///                    2. Buscar Profissional                               ///\n");
    printf("///                    3. Alterar Profissional                              ///\n");
    printf("///                    4. Excluir Profissional                              ///\n");
    printf("///                    0. Voltar ao Menu Principal                          ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                      Escolha a opção desejada:                          ///\n");
    scanf("%c", &opcao);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    return opcao;
}

void cadastrar_profissional(void){
    FILE *arq_profissional;
    Profissional pf;

    pf.id_profissional = 1;

    arq_profissional = fopen("arq_profissional.csv", "rt");
    if (arq_profissional != NULL)
    {
        char linha[512];
        while (fgets(linha, sizeof(linha), arq_profissional) != NULL)
        {
            pf.id_profissional++;
        }
        fclose(arq_profissional);
    }
    

    limpar_tela();
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                Profissional                             ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = =  Cadastrar Profissional = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Nome:                                           ///\n");
    scanf("%100[^\n]", pf.nome); 
    getchar();
    printf("///                         CPF (Apenas números):                           ///\n");
    scanf("%s", pf.cpf); 
    getchar();
    printf("///                         E-mail:                                         ///\n");
    scanf("%s", pf.email); 
    getchar();    
    printf("///                         Telefone (Apenas números):                      ///\n");
    scanf("%11[^\n]", pf.tel); 
    getchar();
    printf("///                         CRN:                                            ///\n");
    scanf("%s", pf.crn); 
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("                    Profissional Cadastrado com Sucesso!                       \n");
    printf("///                        ID gerado: %02d                                    ///\n", pf.id_profissional);
    printf("///////////////////////////////////////////////////////////////////////////////\n");

    arq_profissional = fopen("arq_profissional.csv", "at");

    if (arq_profissional == NULL) {
        printf("Erro na criacao do arquivo\n");
        return;
    }
    fprintf(arq_profissional, "%d;", pf.id_profissional);
    fprintf(arq_profissional, "%s;", pf.nome);
    fprintf(arq_profissional, "%s;", pf.cpf);
    fprintf(arq_profissional, "%s;", pf.email);
    fprintf(arq_profissional, "%s;", pf.tel);
    fprintf(arq_profissional, "%s\n", pf.crn);
    
    fclose(arq_profissional);
    pausar();
}


void buscar_profissional(void){
    FILE *arq_profissional;
    
    Profissional pf;
    int id_busca;
    int encontrado = 0;


    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                Profissional                             ///\n");
    printf("///                                                                         ///\n");
    printf("///                  = = = = =  Buscar Profissional  = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///                       Informe o ID do Profissional:                     ///\n");
    scanf("%d", &id_busca);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");

    arq_profissional = fopen("arq_profissional.csv", "rt");

    if (arq_profissional == NULL)
    {
        printf("Erro na criacao do arquivo\n");
        return;
    }
    while (fscanf(arq_profissional, "%d;%99[^;];%12[^;];%29[^;];%10[^;];%11[^\n]\n",&pf.id_profissional, pf.nome, pf.cpf, pf.email, pf.tel, pf.crn) == 6){
        if (pf.id_profissional == id_busca)
        {
            printf("///                        Profissional Encontrado!                              ///\n");
            printf("ID:         %d\n", pf.id_profissional);
            printf("Nome:       %s\n", pf.nome);
            printf("CPF:        %s\n", pf.cpf);
            printf("E-mail:     %s\n", pf.email);
            printf("Telefone:   %s\n", pf.tel);
            printf("CRN:        %s\n", pf.crn);

            encontrado = 1;
            break;
        }
    }
    if (!encontrado){
        printf("\nProfissional não encontrado!\n");
    }

    fclose(arq_profissional);
    getchar();
}
 void alterar_profissional(void){
    FILE *arq_profissional;
    FILE *arq_profissional_temp;

    Profissional pf;
    int id_busca;
    int encontrado = 0;
    char opcao;
    char continuar = 'S';
    limpar_tela();
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                               Profissionais                             ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = = Alterar Dados do Profissional = = = = =       ///\n");
    printf("///                                                                         ///\n");
    printf("///                          Informe o ID:                                  ///\n");
    scanf("%d", &id_busca);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");

    arq_profissional = fopen("arq_profissional.csv", "rt");
    arq_profissional_temp = fopen("arq_profissional_temp.csv", "wt");

    if (arq_profissional == NULL || arq_profissional_temp == NULL){
        printf("Erro na criacao do arquivo\n");
        return;
    }

     while (fscanf(arq_profissional, "%d;%99[^;];%12[^;];%29[^;];%10[^;];%11[^\n]\n",&pf.id_profissional, pf.nome, pf.cpf, pf.email, pf.tel, pf.crn) == 6){
        if(pf.id_profissional == id_busca){
            encontrado = 1;
             do{
                printf("\n    Dados atuais do profissional    \n");
                printf("ID:              %d\n", pf.id_profissional);
                printf("Nome:            %s\n", pf.nome);
                printf("CPF:             %s\n", pf.cpf);
                printf("Email:           %s\n", pf.email);
                printf("Telefone:        %s\n", pf.tel);
                printf("CRN:             %s\n", pf.crn);

                printf("\nQual campo deseja alterar?\n");
                printf("1. Nome\n");
                printf("2. CPF\n");
                printf("3. Email\n");
                printf("4. Telefone\n");
                printf("5. CRN\n");
                printf("Escolha uma opção: ");
                scanf(" %c", &opcao);
                getchar();

                switch (opcao) {
                    case '1':
                        printf("Novo Nome: ");
                        scanf("%100[^\n]", pf.nome);
                        getchar();
                        break;
                    case '2':
                        printf("Novo CPF: ");
                        scanf("%13s", pf.cpf);
                        getchar();
                        break;
                    case '3':
                        printf("Novo Email: ");
                        scanf("%30s", pf.email);
                        getchar();
                        break;
                    case '4':
                        printf("Novo Telefone: ");
                        scanf("%11[^\n]", pf.tel);
                        getchar();
                        break;
                    case '5':
                        printf("Novo CRN: ");
                        scanf("%12s", pf.crn);
                        getchar();
                        break;
                    default:
                        printf("Opção inválida!\n");
                        break;
                }

                printf("\n    Dados atualizados   \n");
                printf("ID:              %d\n", pf.id_profissional);
                printf("Nome:            %s\n", pf.nome);
                printf("CPF:             %s\n", pf.cpf);
                printf("Email:           %s\n", pf.email);
                printf("Telefone:        %s\n", pf.tel);
                printf("CRN:             %s\n", pf.crn);

                printf("\nDeseja alterar outro campo? (S/N): ");
                scanf(" %c", &continuar);
                continuar = confirmar_acao(continuar);
            } while (continuar == 'S');
        }
        fprintf(arq_profissional_temp, "%d;%s;%s;%s;%s;%s\n",pf.id_profissional, pf.nome, pf.cpf, pf.email, pf.tel, pf.crn);
    }

    fclose(arq_profissional);
    fclose(arq_profissional_temp);

    if (encontrado){
        remove("arq_profissional.csv");
        rename("arq_profissional_temp.csv", "arq_profissional.csv");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                    Paciente alterado com sucesso!                       ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
    } else {
        remove("arq_profissional_temp.csv");
        printf("\nProfissional não encontrado!\n");
    }
    pausar();
}

    // // printf("///////////////////////////////////////////////////////////////////////////////\n");
    // // printf("\n");
    // // pausar();

 void excluir_profissional(void){

    FILE *arq_profissional;
    FILE *arq_profissional_temp;
    Profissional pf;
    int id_busca;
    int encontrado = 0;
    limpar_tela();
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                             Profissionais                               ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = = Excluir Profissional = = = = =                ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe o ID do Profissional:                   ///\n");
    scanf("%d", &id_busca);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");

    pausar();
    char resposta;

    do{
        arq_profissional = fopen("arq_profissional.csv", "rt");

        if (arq_profissional == NULL){
            printf("Erro na criacao do arquivo\n");
            return;
        }

        while (fscanf(arq_profissional, "%d;%99[^;];%12[^;];%29[^;];%10[^;];%11[^\n]\n",&pf.id_profissional, pf.nome, pf.cpf, pf.email, pf.tel, pf.crn) == 6){
            if (pf.id_profissional == id_busca)
            {
                printf("///                        Profissional Encontrado!                       ///\n");
                printf("ID:                 %d\n", pf.id_profissional);
                printf("Nome:               %s\n", pf.nome);
                printf("CPF:                %s\n", pf.cpf);
                printf("E-mail:             %s\n", pf.email);
                printf("Telefone:           %s\n", pf.tel);
                printf("CRN:                %s\n", pf.crn);

                encontrado = 1;
                break;
            }
        }

        if (!encontrado){
            printf("\nProfissional não encontrado!\n");
        }

        fclose(arq_profissional);
        getchar();
        printf("Deseja confirmar a ação? (S/N): ");
        scanf(" %c", &resposta);

        resposta = confirmar_acao(resposta);

        if (resposta == 0){
            printf("Opção inválida! Digite apenas S ou N.\n");
        }

    } while (resposta == 0);

    if (resposta == 'S'){
        arq_profissional = fopen("arq_profissional.csv", "rt");
        arq_profissional_temp = fopen("arq_profissional_temp.csv", "wt");

        if (arq_profissional == NULL || arq_profissional_temp == NULL){
            printf("Erro na criacao do arquivo\n");
            return;
        }

        while (fscanf(arq_profissional, "%d;%99[^;];%12[^;];%29[^;];%10[^;];%11[^\n]\n",&pf.id_profissional, pf.nome, pf.cpf, pf.email, pf.tel, pf.crn) == 6){
            if(pf.id_profissional != id_busca){
                fprintf(arq_profissional_temp, "%d;%s;%s;%s;%s;%s\n", pf.id_profissional, pf.nome, pf.cpf, pf.email, pf.tel, pf.crn);
            }
        }
        fclose(arq_profissional);
        fclose(arq_profissional_temp);

        remove("arq_profissional.csv");
        rename("arq_profissional_temp.csv", "arq_profissional.csv");

        if (!encontrado){
            printf("\nProfissional não encontrado!\n");
        }

        printf("Profissional Excluído com Sucesso! \n");
    } else {
            printf("Operação de Exclusão Cancelada !  \n");
    }
    pausar();
}