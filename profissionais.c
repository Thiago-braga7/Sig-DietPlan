#include <stdio.h>
#include <stdlib.h>
#include "profissionais.h"
#include "validacoes.h"
#include <string.h>
#define True 1
#define False 0



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
            case '5': listar_profissionais(); break;
        }
    } while (opcao != '0');  
}

char tela_profissionais(void){
    char opcao;
    limpar_tela();
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                  = = = = =  Profissionais  = = = = =                    ///\n");
    printf("///                                                                         ///\n");
    printf("///                    1. Cadastrar Profissional                            ///\n");
    printf("///                    2. Buscar Profissional                               ///\n");
    printf("///                    3. Alterar Profissional                              ///\n");
    printf("///                    4. Excluir Profissional                              ///\n");
    printf("///                    5. Listar Profissionais                              ///\n");
    printf("///                    0. Voltar ao Menu Principal                          ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                      Escolha a opção desejada:                          ///\n");
    scanf("%c", &opcao);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    return opcao;
}

void cadastrar_profissional(void){
    FILE * arq_profissionais;
    Profissional * pf;
    
    pf = (Profissional*)malloc(sizeof(Profissional));

    pf->id_profissional = 1;
    arq_profissionais = fopen("arq_profissionais.dat", "rb");
    
     // Crédito: Função adaptada do gemini;
    if (arq_profissionais != NULL){
        
        fseek(arq_profissionais, 0, SEEK_END);  
        
        long num_registros = ftell(arq_profissionais) / sizeof(Profissional);
        
        pf->id_profissional = num_registros + 1;
        
        fclose(arq_profissionais);
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
    scanf("%100[^\n]", pf->nome); 
    getchar();
    printf("///                         CPF (Apenas números):                           ///\n");
    scanf("%s", pf->cpf); 
    getchar();
    printf("///                         E-mail:                                         ///\n");
    scanf("%s", pf->email); 
    getchar();    
    printf("///                         Telefone (Apenas números):                      ///\n");
    scanf("%11[^\n]", pf->tel); 
    getchar();
    printf("///                         CRN:                                            ///\n");
    scanf("%s", pf->crn); 
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("                    Profissional Cadastrado com Sucesso!                       \n");
    printf("///                        ID gerado: %02d                                    ///\n", pf->id_profissional);
    printf("///////////////////////////////////////////////////////////////////////////////\n");

    pf->status = True;

    arq_profissionais = fopen("arq_profissionais.dat", "a+b");
    if (arq_profissionais == NULL) {
        printf("Erro na criação do arquivo\n");
        return;
    }
    
    fwrite(pf, sizeof(Profissional), 1, arq_profissionais);
    fclose(arq_profissionais);
    free(pf);
    pausar();
}


void buscar_profissional(void){
    FILE * arq_profissionais;
    Profissional * pf;
    int id_busca;
    int encontrado;

    pf = (Profissional*) malloc(sizeof(Profissional));

    limpar_tela();
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
    encontrado = False;
    arq_profissionais = fopen("arq_profissionais.dat", "rb");

    if (arq_profissionais == NULL){
        printf("Erro na criação do arquivo\n");
        return;
    }
    while(fread(pf, sizeof(Profissional), 1, arq_profissionais)){
        if ((pf->id_profissional == id_busca) && (pf->status == True)){
            printf("///                        Profissional Encontrado!                         ///\n");
            printf("ID:         %d\n", pf->id_profissional);
            printf("Nome:       %s\n", pf->nome);
            printf("CPF:        %s\n", pf->cpf);
            printf("E-mail:     %s\n", pf->email);
            printf("Telefone:   %s\n", pf->tel);
            printf("CRN:        %s\n", pf->crn);
            encontrado = True;
            break;
        }
    }
    if (encontrado == False){
        printf("\nProfissional não encontrado!\n");
    }

    fclose(arq_profissionais);
    free(pf);
    pausar();
}
void alterar_profissional(void){
    FILE * arq_profissionais;
    FILE * arq_profissionais_temp;

    Profissional * pf;
    int id_busca;
    int encontrado;
    char opcao;
    char continuar;

    pf = (Profissional*) malloc(sizeof(Profissional));

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
    encontrado = False;

    arq_profissionais = fopen("arq_profissionais.dat", "rb");
    arq_profissionais_temp = fopen("arq_profissionais_temp.dat", "wb");

    if (arq_profissionais == NULL || arq_profissionais_temp == NULL){
        printf("Erro na criação do arquivo\n");
        return;
    }

     while (fread(pf, sizeof(Profissional), 1, arq_profissionais)){
        if((pf->id_profissional == id_busca) && (pf->status == True)){
            encontrado = True;

             do{
                limpar_tela();
                printf("\n    Dados atuais do profissional    \n");
                printf("ID:              %d\n", pf->id_profissional);
                printf("Nome:            %s\n", pf->nome);
                printf("CPF:             %s\n", pf->cpf);
                printf("Email:           %s\n", pf->email);
                printf("Telefone:        %s\n", pf->tel);
                printf("CRN:             %s\n", pf->crn);

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
                        scanf("%100[^\n]", pf->nome);
                        getchar();
                        break;
                    case '2':
                        printf("Novo CPF: ");
                        scanf("%13s", pf->cpf);
                        getchar();
                        break;
                    case '3':
                        printf("Novo Email: ");
                        scanf("%30s", pf->email);
                        getchar();
                        break;
                    case '4':
                        printf("Novo Telefone: ");
                        scanf("%11[^\n]", pf->tel);
                        getchar();
                        break;
                    case '5':
                        printf("Novo CRN: ");
                        scanf("%12s", pf->crn);
                        getchar();
                        break;
                    default:
                        printf("Opção inválida!\n");
                        break;
                }

                printf("\n    Dados atualizados   \n");
                printf("ID:              %d\n", pf->id_profissional);
                printf("Nome:            %s\n", pf->nome);
                printf("CPF:             %s\n", pf->cpf);
                printf("Email:           %s\n", pf->email);
                printf("Telefone:        %s\n", pf->tel);
                printf("CRN:             %s\n", pf->crn);

                printf("\nDeseja alterar outro campo? (S/N): ");
                scanf(" %c", &continuar);
                getchar();
                continuar = confirmar_acao(continuar);
                if(continuar == 0){
                    printf("Opção inválida! Digite apenas S ou N.\n");
                }
            } while (continuar == 'S');
        }
        fwrite(pf, sizeof(Profissional), 1, arq_profissionais_temp);
    }

    fclose(arq_profissionais);
    fclose(arq_profissionais_temp);

    if (encontrado == True){
        remove("arq_profissionais.dat");
        rename("arq_profissionais_temp.dat", "arq_profissionais.dat");
        printf("///                    Paciente alterado com sucesso!                       ///\n");
    } else {
        remove("arq_profissionais_temp.dat");
        printf("\nProfissional não encontrado!\n");
    }
    free(pf);
    pausar();
}

 void excluir_profissional(void){
    FILE *arq_profissionais;
    Profissional * pf;
    int id_busca;
    int encontrado;
    char resposta;

    pf = (Profissional*) malloc(sizeof(Profissional));

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
    encontrado = False;
    pausar();

    arq_profissionais = fopen("arq_profissionais.dat", "r+b");
    
    if (arq_profissionais == NULL){
        printf("Erro na criação do arquivo\n");
        return;
    }

    while(fread(pf, sizeof(Profissional),1, arq_profissionais)){
        if((pf->id_profissional == id_busca) && (pf->status == True)){
            printf("///                        Profissional Encontrado!                       ///\n");
            printf("ID:                 %d\n", pf->id_profissional);
            printf("Nome:               %s\n", pf->nome);
            printf("CPF:                %s\n", pf->cpf);
            printf("E-mail:             %s\n", pf->email);
            printf("Telefone:           %s\n", pf->tel);
            printf("CRN:                %s\n", pf->crn);
            encontrado = True;

        do {
            printf("\nDeseja realmente excluir este Profissional? (S/N): ");
            scanf(" %c", &resposta);
            resposta = confirmar_acao(resposta);
            
            if(resposta == 0){
                printf("Opção inválida! Digite apenas S ou N.\n");
            }
        } while(resposta == 0);
        if (resposta == 'S'){
            pf->status = False;
            fseek(arq_profissionais, (-1)*sizeof(Profissional), SEEK_CUR);
            fwrite(pf, sizeof(Profissional), 1, arq_profissionais);
            printf("\nProfissional excluído com sucesso!\n");
        } else{
            printf("\nOperação de exclusão cancelada.\n");
        }
        break;
    }
}
    if (encontrado == False){
        printf("\nProfissional não encontrado!\n");
    }
    fclose(arq_profissionais);
    free(pf);
    pausar();
}

void listar_profissionais(void) {
    FILE * arq_profissionais;
    Profissional * pf;

    pf = (Profissional*) malloc(sizeof(Profissional));
    
    arq_profissionais = fopen("arq_profissionais.dat", "rb");
    if (arq_profissionais == NULL) {
        printf("Nenhum Profissional cadastrado ainda.\n");
        free(pf);
        return;
    }

    limpar_tela();
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                               Profissionais                             ///\n");
    printf("///                                                                         ///\n");
    printf("///                  = = = = =  Listar Profissionais  = = = = =             ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    while(fread(pf, sizeof(Profissional), 1, arq_profissionais)){
        if (pf->status == True){
            printf("ID:         %d\n", pf->id_profissional);
            printf("Nome:       %s\n", pf->nome);
            printf("CPF:        %s\n", pf->cpf);
            printf("E-mail:     %s\n", pf->email);
            printf("Telefone:   %s\n", pf->tel);
            printf("CRN:        %s\n", pf->crn);
            printf("--------------------------------------------------\n");
        }
    }

    fclose(arq_profissionais);
    free(pf);

    pausar();
}
