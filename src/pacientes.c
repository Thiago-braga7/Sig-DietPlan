#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "pacientes.h"
#include "validacoes.h"
#include "leituras.h"

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
    
    ler_nome(pac->nome);
    ler_cpf(pac->cpf);
    ler_tel(pac->tel);
    ler_idade(pac->idade);
    ler_peso(&pac->peso);
    ler_altura(&pac->altura);

    pac->status = True;

    arq_paciente = fopen("data/arq_pacientes.dat", "ab");    

    if (arq_paciente == NULL) {
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                    Erro na criação do arquivo!                          ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");

        free(pac);
        return;
    }

    fwrite(pac, sizeof(Paciente), 1, arq_paciente);
    fclose(arq_paciente);
    free(pac);

    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                    Paciente Cadastrado com Sucesso!                    ///\n");
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
    
    ler_cpf(cpf_busca);
    pausar();

    encontrado = False;

    arq_paciente = fopen("data/arq_pacientes.dat", "rb");

    if (arq_paciente == NULL){
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                    Erro na abertura do arquivo!                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        return;
    }

    while (fread(pac, sizeof(Paciente), 1, arq_paciente)) {
        if (strcmp(pac->cpf, cpf_busca) == 0 && pac->status == True) {
            printf("///////////////////////////////////////////////////////////////////////////////\n");
            printf("///                         Paciente Encontrado!                           ///\n");
            printf("///////////////////////////////////////////////////////////////////////////////\n");
            exibir_paciente(pac);

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
    ler_cpf(cpf_busca);

    encontrado = False;

    arq_paciente = fopen("data/arq_pacientes.dat", "rb");
    arq_paciente_temp = fopen("data/arq_pacientes_temp.dat", "wb");


    if (arq_paciente == NULL || arq_paciente_temp == NULL){
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                    Erro na abertura do arquivo!                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        return;
    }

    while (fread(pac, sizeof(Paciente), 1, arq_paciente)) {
        if (strcmp(pac->cpf, cpf_busca) == 0 && pac->status == True) {
            encontrado = True;

            do{
                limpar_tela();
                printf("Paciente encontrado\n");
                exibir_paciente(pac);

                printf("///////////////////////////////////////////////////////////////////////////////\n");
                printf("///                         Qual campo deseja alterar?                     ///\n");
                printf("///                                                                         ///\n");
                printf("///                         1. Nome                                         ///\n");
                printf("///                         2. CPF                                          ///\n");
                printf("///                         3. Telefone                                     ///\n");
                printf("///                         4. Idade                                        ///\n");
                printf("///                         5. Peso                                         ///\n");
                printf("///                         6. Altura                                       ///\n");
                printf("///                                                                         ///\n");
                printf("///                         Escolha uma opção: ");
                scanf(" %c", &opcao);
                getchar();

                switch (opcao) {
                    case '1':
                        ler_nome(pac->nome);
                        break;
                    case '2':
                        ler_cpf(pac->cpf);
                        break;
                    case '3':
                        ler_tel(pac->tel);                        
                        break;
                    case '4':
                        ler_idade(pac->idade);
                        break;
                    case '5':
                        ler_peso(&pac->peso);
                        break;
                    case '6':
                        ler_altura(&pac->altura);
                        break;
                    default:
                        printf("Opção inválida!\n");
                        break;
                }
                
                printf("///////////////////////////////////////////////////////////////////////////////\n");
                printf("///                         Dados Atualizados:                            ///\n");
                printf("///////////////////////////////////////////////////////////////////////////////\n");
                exibir_paciente(pac);

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
        rename("data/arq_pacientes_temp.dat", "data/arq_pacientes.dat");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                    Paciente Alterado com sucesso!                          ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
    } else {
        remove("data/arq_pacientes_temp.dat");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                    Paciente não encontrado!                                ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
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
    ler_cpf(cpf_busca);

    encontrado = False;

    pac = malloc(sizeof(Paciente));
    if (pac == NULL) {
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                    Erro de alocação de memória!                        ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        return;
    }

    arq_paciente = fopen("data/arq_pacientes.dat", "r+b");

    if (arq_paciente == NULL){
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                    Erro na abertura do arquivo!                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        return;
    }

        while (fread(pac, sizeof(Paciente), 1, arq_paciente)) {
            if (strcmp(pac->cpf, cpf_busca) == 0 && pac->status == True) {
                printf("Paciente encontrado\n");
                exibir_paciente(pac);

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
                printf("///////////////////////////////////////////////////////////////////////////////\n");
                printf("///                    Paciente excluído com sucesso!                     ///\n");
                printf("///////////////////////////////////////////////////////////////////////////////\n");
            } else {
                printf("///////////////////////////////////////////////////////////////////////////////\n");
                printf("///                    Operação de exclusão cancelada!                     ///\n");
                printf("///////////////////////////////////////////////////////////////////////////////\n");
            }
            break;
        }
    
    if (encontrado == False){
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                    Paciente não encontrado!                             ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
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

    limpar_tela();
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                               Pacientes                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = = Lista de Pacientes = = = = =                  ///\n");
    printf("///                                                                         ///\n");

    arq_paciente = fopen("data/arq_pacientes.dat", "rb");    
    if (arq_paciente == NULL) {
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                    Nenhum paciente cadastrado ainda!                    ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        free(pac);
        return;
    }

    while (fread(pac, sizeof(Paciente), 1, arq_paciente)){
        if (pac->status) {
            encontrado = 1;
            exibir_paciente(pac);
            printf("///////////////////////////////////////////////////////////////////////////////\n");
        }
    }

    if (!encontrado) {
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                    Nenhum paciente ativo encontrado!                    ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
    }

    fclose(arq_paciente);
    free(pac);

    pausar();
}



void exibir_paciente(const Paciente * pac){
    if (pac == NULL) {
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                    Erro: paciente inexistente!                          ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        return;
    }

    printf("Nome: %s\n", pac->nome);
    printf("CPF: %s\n", pac->cpf);
    printf("Telefone: %s\n", pac->tel);
    printf("Idade: %s\n", pac->idade);
    printf("Peso: %.2f\n", pac->peso);
    printf("Altura: %.2f\n", pac->altura);
}