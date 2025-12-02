#include "profissionais.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "leituras.h"
#include "uteis.h"
#define True 1
#define False 0

void modulo_profissionais(void) {
    char opcao;
    do {
        limpar_tela();
        opcao = tela_profissionais();
        switch (opcao) {
            case '1':
                cadastrar_profissional();
                break;
            case '2':
                buscar_profissional();
                break;
            case '3':
                alterar_profissional();
                break;
            case '4':
                excluir_profissional();
                break;
        }
    } while (opcao != '0');
}

char tela_profissionais(void) {
    char opcao;
    const char *menu =
        "1. Cadastrar Profissional\n"
        "2. Buscar Profissional\n"
        "3. Alterar Dados do Profissional\n"
        "4. Excluir Profissional\n"
        "0. Voltar ao menu principal\n";

    limpar_tela();
    exibir_moldura_titulo("Profissionais");
    exibir_moldura_conteudo(menu);
    printf("Escolha a opção desejada: ");
    scanf(" %c", &opcao);
    getchar();
    pausar();
    return opcao;
}

void cadastrar_profissional(void) {
    FILE *arq_profissionais;
    Profissional *pf;

    pf = (Profissional *)malloc(sizeof(Profissional));

    pf->id_profissional = 1;
    arq_profissionais = fopen("data/arq_profissionais.dat", "rb");

    if (arq_profissionais != NULL) {
        fseek(arq_profissionais, 0, SEEK_END);
        long num_registros = ftell(arq_profissionais) / sizeof(Profissional);
        pf->id_profissional = num_registros + 1;
        fclose(arq_profissionais);
    }

    limpar_tela();
    printf("\n");
    exibir_moldura_titulo("Cadastro - Profissionais");
    ler_nome(pf->nome);
    ler_cpf(pf->cpf);
    ler_tel(pf->tel);
    ler_crn(pf->crn);
    do {
        printf("///                         Sexo (M/F/O):                                 ///\n");
        scanf(" %c", &pf->sexo);
        getchar();
        pf->sexo = toupper(pf->sexo);
        if (pf->sexo != 'M' && pf->sexo != 'F' && pf->sexo != 'O') {
            printf("Sexo inválido! Digite novamente! \n");
        }
    } while (pf->sexo != 'M' && pf->sexo != 'F' && pf->sexo != 'O');
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("                    Profissional Cadastrado com Sucesso!                       \n");
    printf("///                        ID gerado: %02d                                    ///\n",
           pf->id_profissional);
    printf("///////////////////////////////////////////////////////////////////////////////\n");

    pf->status = True;

    arq_profissionais = fopen("data/arq_profissionais.dat", "a+b");
    if (arq_profissionais == NULL) {
        printf("Erro na criação do arquivo\n");
        return;
    }

    fwrite(pf, sizeof(Profissional), 1, arq_profissionais);
    fclose(arq_profissionais);
    free(pf);
    pausar();
}


void buscar_profissional(void) {
    FILE *arq_profissionais;
    Profissional *pf;
    int id_busca;
    int encontrado;

    pf = (Profissional *)malloc(sizeof(Profissional));

    limpar_tela();
    printf("\n");
    exibir_moldura_titulo("Busca - Profissionais");
    printf("Informe o ID do Profissional: \n");
    scanf("%d", &id_busca);
    getchar();

    encontrado = False;
    arq_profissionais = fopen("data/arq_profissionais.dat", "rb");

    if (arq_profissionais == NULL) {
        printf("Erro na abertura do arquivo\n");
        return;
    }
    while(fread(pf, sizeof(Profissional), 1, arq_profissionais)){
        if ((pf->id_profissional == id_busca) && (pf->status == True)){
            printf("Profissional Encontrado!\n");
            exibir_profissional(pf);
            encontrado = True;
            break;
        }
    }
    if (encontrado == False) {
        printf("\nProfissional não encontrado!\n");
    }

    fclose(arq_profissionais);
    free(pf);
    pausar();
}

void alterar_profissional(void) {
    FILE *arq_profissionais;
    FILE *arq_profissionais_temp;

    Profissional *pf;
    int id_busca;
    int encontrado;
    char opcao;
    char continuar;
    int valido;

    pf = (Profissional *)malloc(sizeof(Profissional));

    limpar_tela();
    printf("\n");
    exibir_moldura_titulo("Alteração - Profissionais");
    printf("Informe o ID: \n");
    scanf("%d", &id_busca);
    getchar();

    encontrado = False;

    arq_profissionais = fopen("data/arq_profissionais.dat", "rb");
    arq_profissionais_temp = fopen("data/arq_profissionais_temp.dat", "wb");

    if (arq_profissionais == NULL || arq_profissionais_temp == NULL) {
        printf("Erro na abertura dos arquivos\n");
        return;
    }

    while (fread(pf, sizeof(Profissional), 1, arq_profissionais)) {
        if ((pf->id_profissional == id_busca) && (pf->status == True)) {
            encontrado = True;

            do {
                limpar_tela();
                printf("\nDados atuais do profissional\n");
                exibir_profissional(pf);

                printf("\nQual campo deseja alterar?\n");
                printf("1. Nome\n");
                printf("2. CPF\n");
                printf("3. Telefone\n");
                printf("4. CRN\n");
                printf("Escolha uma opção: ");
                scanf(" %c", &opcao);
                getchar();

                switch (opcao) {
                    case '1':
                        validar_nome(pf->nome);
                        break;
                    case '2':
                        validar_cpf(pf->cpf);
                        break;
                    case '3':
                        valida_telefone(pf->tel);
                        break;
                    case '4':
                        valida_crn(pf->crn);
                        break;
                    default:
                        printf("Opção inválida!\n");
                        break;
                }

                printf("\nDados atualizados\n");
                exibir_profissional(pf);

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

    if (encontrado == True) {
        remove("data/arq_profissionais.dat");
        rename("data/arq_profissionais_temp.dat", "data/arq_profissionais.dat");
        printf("///                    Profissional alterado com sucesso!                      ///\n");
    
    } else {
        remove("data/arq_profissionais_temp.dat");
        printf("\nProfissional não encontrado!\n");
    }
    free(pf);
    pausar();
}

void excluir_profissional(void) {
    FILE *arq_profissionais;
    Profissional *pf;
    int id_busca;
    int encontrado;
    char resposta;

    pf = (Profissional *)malloc(sizeof(Profissional));

    limpar_tela();
    printf("\n");
    exibir_moldura_titulo("Exclusão - Profissionais");
    printf("Informe o ID do Profissional: \n");
    scanf("%d", &id_busca);
    getchar();
    encontrado = False;
    pausar();

    arq_profissionais = fopen("data/arq_profissionais.dat", "r+b");

    if (arq_profissionais == NULL) {
        printf("Erro na abertura do arquivo\n");
        return;
    }

    while(fread(pf, sizeof(Profissional),1, arq_profissionais)){
        if((pf->id_profissional == id_busca) && (pf->status == True)){
            printf("Profissional Encontrado!\n");
            exibir_profissional(pf);
            encontrado = True;

            do {
                printf("\nDeseja realmente excluir este Profissional? (S/N): ");
                scanf(" %c", &resposta);
                resposta = confirmar_acao(resposta);

                if (resposta == 0) {
                    printf("Opção inválida! Digite apenas S ou N.\n");
                }
            } while (resposta == 0);

            if (resposta == 'S') {
                pf->status = False;
                fseek(arq_profissionais, (-1) * sizeof(Profissional), SEEK_CUR);
                fwrite(pf, sizeof(Profissional), 1, arq_profissionais);
                printf("\nProfissional excluído com sucesso!\n");
            } else {
                printf("\nOperação de exclusão cancelada.\n");
            }
            break;
        }
    }

    if (encontrado == False) {
        printf("\nProfissional não encontrado!\n");
    }
    fclose(arq_profissionais);
    free(pf);
    pausar();
}


void exibir_profissional(const Profissional *pf) {
    if (pf == NULL) {
        printf("Erro: profisional inexistente!\n");
        return;
    }
    printf("ID:         %d\n", pf->id_profissional);
    printf("Nome:       %s\n", pf->nome);
    printf("CPF:        %s\n", pf->cpf);
    printf("Telefone:   %s\n", pf->tel);
    printf("CRN:        %s\n", pf->crn);
    printf("Sexo:       %c\n", pf->sexo);

}