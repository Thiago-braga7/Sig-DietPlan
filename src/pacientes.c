#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pacientes.h"
#include "validacoes.h"
#include <ctype.h>
#define True 1
#define False 0


void modulo_pacientes(void) {
    char opcao;
    do {
        limpar_tela();
        opcao = tela_pacientes();
        switch(opcao) {
            case '1': cadastrar_paciente(); break;
            case '2': buscar_paciente(); break;
            case '3': alterar_paciente(); break;
            case '4': excluir_paciente(); break;
            case '5': listar_paciente(); break;
        }
    } while (opcao != '0');  
}


char tela_pacientes(void){
    char opcao;
    limpar_tela();
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                    = = = = =   Pacientes = = = = =                      ///\n");
    printf("///                                                                         ///\n");
    printf("///                    1. Cadastrar Paciente                                ///\n");
    printf("///                    2. Buscar Paciente                                   ///\n");
    printf("///                    3. Alterar Dados do Paciente                         ///\n");
    printf("///                    4. Excluir Paciente                                  ///\n");
    printf("///                    5. Listar Paciente                                   ///\n");
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

void cadastrar_paciente(void){
    FILE *arq_paciente;
    Paciente* pac;
    pac = (Paciente*)malloc(sizeof(Paciente));

    limpar_tela();
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                Pacientes                                ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = =  Cadastrar Paciente = = = = =                 ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    
    printf("///                         Nome:                                        ///\n");
    scanf(" %[^\n]", pac->nome); 
    getchar();

    printf("///                         CPF (Apenas números):                           ///\n");
    scanf("%s", pac->cpf); 
    getchar();

    printf("///                         Telefone (Apenas números):                      ///\n");
    scanf("%s", pac->tel); 
    getchar();

    printf("///                         Idade:                                          ///\n");
    scanf("%d", &pac->idade); 
    getchar();

    printf("///                         Peso (Kg):                                      ///\n");
    scanf("%f", &pac->peso); 
    getchar();

    printf("///                         Altura (m):                                     ///\n");
    scanf("%f", &pac->altura); 
    getchar();


    pac->status = True;

    arq_paciente = fopen("data/arq_pacientes.dat", "ab");    

    if (arq_paciente == NULL) {
        printf("Erro na criacao do arquivo\n");
        free(pac);
        return;
    }

    fwrite(pac, sizeof(Paciente), 1, arq_paciente);
    fclose(arq_paciente);
    free(pac);

    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("                    Paciente Cadastrado com Sucesso!                         \n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");

    pausar();
}


void buscar_paciente(void){
    FILE * arq_paciente;
    Paciente * pac;

    char cpf_busca[13];
    int encontrado;

    pac = (Paciente*) malloc(sizeof(Paciente));

    limpar_tela();
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                               Pacientes                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = =  Buscar Paciente = = = = =                    ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe o CPF(Apenas números):                  ///\n");
    scanf("%12s", cpf_busca);
    getchar();
    pausar();

    encontrado = False;

    arq_paciente = fopen("data/arq_pacientes.dat", "rb");

    if (arq_paciente == NULL){
        printf("Erro na criacao do arquivo\n");
        return;
     }

    while (fread(pac, sizeof(Paciente), 1, arq_paciente)) {
        if (strcmp(pac->cpf, cpf_busca) == 0 && pac->status == True) {
            printf("Paciente encontrado\n");
            printf("Nome: %s\n", pac->nome);
            printf("CPF: %s\n", pac->cpf);
            printf("Telefone: %s\n", pac->tel);
            printf("Idade: %d\n", pac->idade);
            printf("Peso: %.2f kg\n", pac->peso);
            printf("Altura: %.2f m\n", pac->altura);

            encontrado = True;
            break;
        }
    }
    if (encontrado == False) {
        printf("\nPaciente não encontrado!\n");
    }

    fclose(arq_paciente);
    free(pac);
    getchar();
}

 

void alterar_paciente(void){
    FILE * arq_paciente;
    FILE *arq_paciente_temp;

    Paciente * pac;
    char cpf_busca[13];
    int encontrado;
    char opcao;
    char continuar;

    pac = (Paciente*) malloc(sizeof(Paciente));


    limpar_tela();
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                               Pacientes                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = = Alterar Dados do Paciente = = = = =           ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe o CPF(Apenas números):                  ///\n");
    scanf("%s", cpf_busca);
    getchar();

    encontrado = False;

    arq_paciente = fopen("data/arq_pacientes.dat", "rb");
    arq_paciente_temp = fopen("data/arq_pacientes.dat", "wb");


    if (arq_paciente == NULL || arq_paciente_temp == NULL){
        printf("Erro ao buscar o arquivo\n");
        return;
    }

    while (fread(pac, sizeof(Paciente), 1, arq_paciente)) {
        if (strcmp(pac->cpf, cpf_busca) == 0 && pac->status == True) {
            encontrado = True;

            do{
                limpar_tela();
                printf("Paciente encontrado\n");
                printf("Nome: %s\n", pac->nome);
                printf("CPF: %s\n", pac->cpf);
                printf("Telefone: %s\n", pac->tel);
                printf("Idade: %d\n", pac->idade);
                printf("Peso: %.2f kg\n", pac->peso);
                printf("Altura: %.2f m\n", pac->altura);

                printf("\nQual campo deseja alterar?\n");
                printf("1. Nome\n");
                printf("2. CPF\n");
                printf("3. Telefone\n");
                printf("4. Idade\n");
                printf("5. Peso\n");
                printf("6. Altura\n");
                printf("Escolha uma opção: ");
                scanf(" %c", &opcao);
                getchar();

                switch (opcao) {
                    case '1':
                        printf("Novo nome: ");
                        scanf(" %s", pac->nome);
                        getchar();
                        break;
                    case '2':
                        printf("Novo CPF: ");
                        scanf(" %s", pac->cpf);
                        getchar();
                        break;
                    case '3':
                        printf("Novo telefone: ");
                        scanf(" %s", pac->tel);
                        getchar();
                        break;
                    case '4':
                        printf("Nova idade: ");
                        scanf("%d", &pac->idade);
                        getchar();
                        break;
                    case '5':
                        printf("Novo peso: ");
                        scanf("%f", &pac->peso);
                        getchar();
                        break;
                    case '6':
                        printf("Nova altura: ");
                        scanf("%f", &pac->altura);
                        getchar();
                        break;
                    default:
                        printf("Opção inválida!\n");
                        break;
            }
            printf("\n    Dados atualizados    \n");
                printf("Nome: %s\n", pac->nome);
                printf("CPF: %s\n", pac->cpf);
                printf("Telefone: %s\n", pac->tel);
                printf("Idade: %d\n", pac->idade);
                printf("Peso: %.2f kg\n", pac->peso);
                printf("Altura: %.2f m\n", pac->altura);

                printf("\nDeseja alterar outro campo? (S/N): ");
                scanf(" %c", &continuar);
                continuar = confirmar_acao(continuar);

                if(continuar == 0){
                    printf("Opção inválida! Digite apenas S ou N.\n");
                }

            } while (continuar == 'S');
        }
        fwrite(pac, sizeof(Paciente), 1, arq_paciente_temp);
    }
    fclose(arq_paciente);
    fclose(arq_paciente_temp);

    if (encontrado){
        remove("data/arq_pacientes.dat");
        rename("data/arq_pacientes.dat", "data/arq_pacientes.dat");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                    Paciente Alterado com sucesso!                          ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
    } else {
        remove("data/arq_pacientes.dat");
        printf("\nPaciente não encontrada!\n");
    }
    free(pac);
    pausar();
}

        
   
void excluir_paciente(void){
    FILE *arq_paciente;
    Paciente *pac;

    char cpf_busca[13];
    int encontrado;
    char resposta;

    limpar_tela();

    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                Pacientes                                ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = = Excluir Paciente = = = = =                    ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe o CPF(Apenas números):                  ///\n");
    scanf("%12s", cpf_busca); 
    getchar();

    encontrado = False;

    pac = malloc(sizeof(Paciente));
    if (pac == NULL) {
        printf("Erro de alocação de memória.\n");
        return;
    }

    arq_paciente = fopen("data/arq_pacientes.dat", "r+b");

    if (arq_paciente == NULL){
        printf("Erro ao buscar do arquivo\n");
        return;
    }

        while (fread(pac, sizeof(Paciente), 1, arq_paciente)) {
            if (strcmp(pac->cpf, cpf_busca) == 0 && pac->status == True) {
                printf("Paciente encontrado\n");
                printf("Nome: %s\n", pac->nome);
                printf("CPF: %s\n", pac->cpf);
                printf("Telefone: %s\n", pac->tel);
                printf("Idade: %d\n", pac->idade);
                printf("Peso: %.2f kg\n", pac->peso);
                printf("Altura: %.2f m\n", pac->altura);

                encontrado = True;
            }

            do {
                printf("\nDeseja realmente excluir esse paciente? (S/N): ");
                scanf(" %c", &resposta);
                resposta = confirmar_acao(resposta);
                
                if(resposta == 0){
                    printf("Opção inválida! Digite apenas S ou N.\n");
                }
            } while(resposta == 0);

            if (resposta == 'S'){
                pac->status = False;
                fseek(arq_paciente, (-1)*sizeof(Paciente), SEEK_CUR);
                fwrite(pac, sizeof(Paciente), 1, arq_paciente);
                printf("\nPaciente excluído com sucesso!\n");
            } else{
                printf("\nOperação de exclusão cancelada.\n");
            }
            break;
        }
    
    if (encontrado == False){
        printf("\nPaciente não encontrada!\n");
    }
    
    fclose(arq_paciente);
    free(pac);
    pausar();
}



void listar_paciente(void) {
    FILE *arq_paciente;
    Paciente* pac;

    pac = (Paciente*)malloc(sizeof(Paciente));
    int encontrado = 0;

    arq_paciente = fopen("data/arq_pacientes.dat", "rb");    
    if (arq_paciente == NULL) {
        printf("Nenhum paciente cadastrado ainda\n");
        free(pac);
        return;
    }

    while (fread(pac, sizeof(Paciente), 1, arq_paciente)){
        if (pac->status) {
            encontrado = 1;
            printf("Nome: %s\n", pac->nome);
            printf("CPF: %s\n", pac->cpf);
            printf("Telefone: %s\n", pac->tel);
            printf("Idade: %d\n", pac->idade);
            printf("Peso: %.2f\n", pac->peso);
            printf("Altura: %.2f\n", pac->altura);
            printf("--------------------------------------------------\n");
        }
    }

    if (!encontrado) {
        printf("Nenhum paciente ativo encontrado.\n");
    }

    fclose(arq_paciente);
    free(pac);

    pausar();
}