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
            // case '2': buscar_profissional(); break;
            // case '3': alterar_profissional(); break;
            // case '4': excluir_profissional(); break;
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
    char nome[100];
    char cpf[13];
    char email[30];
    char tel[11];
    char crn[12];
    int id_profissional = 1;

    arq_profissional = fopen("arq_profissional.csv", "rt");
    if (arq_profissional != NULL)
    {
        char linha[512];
        while (fgets(linha, sizeof(linha), arq_profissional) != NULL)
        {
            id_profissional++;
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
    scanf("%s", nome); 
    getchar();
    printf("///                         CPF (Apenas números):                           ///\n");
    scanf("%s", cpf); 
    getchar();
    printf("///                         E-mail:                                         ///\n");
    scanf("%s", email); 
    getchar();
    printf("///                         Telefone (Apenas números):                      ///\n");
    scanf("%s", tel); 
    getchar();
    printf("///                         CRN:                                            ///\n");
    scanf("%s", crn); 
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("                    Paciente Cadastrado com Sucesso!                         \n");
    printf("///                        ID gerado: %02d                                    ///\n", id_profissional);
    printf("///////////////////////////////////////////////////////////////////////////////\n");

    arq_profissional = fopen("arq_profissional.csv", "at");

    if (arq_profissional == NULL) {
        printf("Erro na criacao do arquivo\n");
        return;
    }
    fprintf(arq_profissional, "%d;", id_profissional);
    fprintf(arq_profissional, "%s;", nome);
    fprintf(arq_profissional, "%s;", cpf);
    fprintf(arq_profissional, "%s;", email);
    fprintf(arq_profissional, "%s;", tel);
    fprintf(arq_profissional, "%s;", crn);
    fclose(arq_profissional);
    pausar();
}

