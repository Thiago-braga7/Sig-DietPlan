/*
 * Módulo de Pacientes
 * Responsável pelo cadastro, busca, alteração, exclusão e listagem de pacientes.
 * Cada função implementa uma operação do CRUD sobre o registro de pacientes.
 *
 * Autor: Wallison Dias
 * Créditos: auxílio do ChatGPT
 * Data: 2025
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#include "pacientes.h"
#include "validacoes.h"
#include "leituras.h"
#include "uteis.h"


// Menu principal do módulo de pacientes
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
        }
    } while (opcao != '0');  
}



// Exibe o menu de opções do módulo de pacientes e retorna a opção escolhida
char tela_pacientes(void){
    char opcao;

    const char *menu =
        "1. Cadastrar Paciente\n"
        "2. Buscar Paciente\n"
        "3. Alterar dados do paciente\n"
        "4. Excluir paciente\n"
        "0. Voltar ao menu principal\n";

    limpar_tela();
    exibir_moldura_titulo("Pacientes");
    exibir_moldura_conteudo(menu);
    printf("Escolha a opção desejada: ");
    scanf(" %c", &opcao);
    getchar();
    pausar();
    
    return opcao;
}



// Realiza o cadastro de um novo paciente
void cadastrar_paciente(void){
    FILE *arq_paciente;
    Paciente* pac;
    pac = (Paciente*)malloc(sizeof(Paciente));

    limpar_tela();
    printf("\n");
    exibir_moldura_titulo("Pacientes - Cadastro");
    
    ler_nome(pac->nome);
    ler_cpf(pac->cpf);
    ler_tel(pac->tel);
    ler_idade(pac->idade);
    ler_peso(&pac->peso);
    ler_altura(&pac->altura);

    pac->status = true;

    arq_paciente = fopen("data/arq_pacientes.dat", "ab");    

    if (arq_paciente == NULL) {
        printf("Erro na criação do arquivo!\n");
        free(pac);
        return;
    }

    fwrite(pac, sizeof(Paciente), 1, arq_paciente);
    fclose(arq_paciente);
    free(pac);

    printf("Paciente cadastrado com sucesso!\n");

    pausar();
}



// Busca e exibe um paciente pelo CPF
void buscar_paciente(void){
    FILE * arq_paciente;
    Paciente * pac;

    char cpf_busca[13];
    bool encontrado;

    pac = (Paciente*) malloc(sizeof(Paciente));

    limpar_tela();
    printf("\n");
    exibir_moldura_titulo("Pacientes - Busca");
    
    ler_cpf(cpf_busca);
    pausar();

    encontrado = false;

    arq_paciente = fopen("data/arq_pacientes.dat", "rb");

    if (arq_paciente == NULL){
        printf("Erro na abertura do arquivo!\n");
        return;
    }

    while (fread(pac, sizeof(Paciente), 1, arq_paciente)) {
        if (strcmp(pac->cpf, cpf_busca) == 0 && pac->status == true) {
            printf("Paciente encontrado!\n");
            exibir_paciente(pac);

            encontrado = true;
            break;
        }
    }

    if (encontrado == false) {
        printf("\nPaciente não encontrado!\n");
    }

    fclose(arq_paciente);
    free(pac);
    getchar();
}

 

// Permite alterar os dados de um paciente existente
void alterar_paciente(void){
    FILE * arq_paciente;
    FILE *arq_paciente_temp;

    Paciente * pac;
    char cpf_busca[13];
    bool encontrado;
    char opcao;
    char continuar;

    pac = (Paciente*) malloc(sizeof(Paciente));

    limpar_tela();
    printf("\n");
    exibir_moldura_titulo("Pacientes - Alteração");
    ler_cpf(cpf_busca);

    encontrado = false;

    arq_paciente = fopen("data/arq_pacientes.dat", "rb");
    arq_paciente_temp = fopen("data/arq_pacientes_temp.dat", "wb");


    if (arq_paciente == NULL || arq_paciente_temp == NULL){
        printf("Erro na abertura do arquivo!\n");
        return;
    }

    while (fread(pac, sizeof(Paciente), 1, arq_paciente)) {
        if (strcmp(pac->cpf, cpf_busca) == 0 && pac->status == true) {
            encontrado = true;

            do{
                limpar_tela();
                printf("Paciente encontrado\n");
                exibir_paciente(pac);

                const char *menu_alt =
                    "\nQual campo deseja alterar?\n"
                    "1. Nome\n"
                    "2. CPF\n"
                    "3. Telefone\n"
                    "4. Idade\n"
                    "5. Peso\n"
                    "6. Altura\n"
                    "Escolha uma opção: ";

                exibir_moldura_conteudo(menu_alt);
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
                
                printf("\n");
                printf("Dados Atualizados:\n");
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
        printf("Paciente Alterado com sucesso!\n");
    } else {
        remove("data/arq_pacientes_temp.dat");
        printf("Paciente não encontrado!\n");
    }
    free(pac);
    pausar();
}

        
   
// Marca um paciente como excluído logicamente (status = false)
void excluir_paciente(void){
    FILE *arq_paciente;
    Paciente *pac;

    char cpf_busca[13];
    bool encontrado;
    char resposta;

    limpar_tela();

    printf("\n");
    exibir_moldura_titulo("Pacientes - Exclusão");
    ler_cpf(cpf_busca);

    encontrado = false;

    pac = malloc(sizeof(Paciente));
    if (pac == NULL) {
        printf("Erro de alocação de memória!\n");
        return;
    }

    arq_paciente = fopen("data/arq_pacientes.dat", "r+b");

    if (arq_paciente == NULL){
        printf("Erro na abertura do arquivo!\n");
        return;
    }

        while (fread(pac, sizeof(Paciente), 1, arq_paciente)) {
            if (strcmp(pac->cpf, cpf_busca) == 0 && pac->status == true) {
                printf("Paciente encontrado\n");
                exibir_paciente(pac);

                encontrado = true;
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
                pac->status = false;
                fseek(arq_paciente, (-1)*sizeof(Paciente), SEEK_CUR);
                fwrite(pac, sizeof(Paciente), 1, arq_paciente);
                printf("Paciente excluído com sucesso!\n");
            } else {
                printf("Operação de exclusão cancelada!\n");
            }
            break;
        }
    
    if (encontrado == false){
        exibir_moldura_titulo("Erro: paciente inexistente");
    }
    
    fclose(arq_paciente);
    free(pac);
    pausar();
}



// Exibe os dados de um paciente formatados
void exibir_paciente(const Paciente * pac){
    if (pac == NULL) {
        exibir_moldura_titulo("Erro: paciente inexistente");
        return;
    }

    printf("Nome: %s\n", pac->nome);
    printf("CPF: %s\n", pac->cpf);
    printf("Telefone: %s\n", pac->tel);
    printf("Idade: %s\n", pac->idade);
    printf("Peso: %.2f\n", pac->peso);
    printf("Altura: %.2f\n", pac->altura);
}