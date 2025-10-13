#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pacientes.h"
#include "util.h"
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

    arq_paciente = fopen("arq_paciente.dat", "ab");    

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
    FILE* arq_paciente;
    Paciente pac;

    char cpf_busca[13];
    int encontrado = 0;

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

    arq_paciente = fopen("arq_paciente.csv", "rt");

    if (arq_paciente == NULL){
        printf("Erro na criacao do arquivo\n");
        return;
     }

    while (fscanf(arq_paciente, "%[^;];%[^;];%[^;];%d;%f;%f\n", pac.nome, pac.cpf, pac.tel, &pac.idade, &pac.peso, &pac.altura) == 6) {
        if (strcmp(pac.cpf, cpf_busca) == 0) {
            printf("Paciente encontrado\n");
            printf("Nome: %s\n", pac.nome);
            printf("CPF: %s\n", pac.cpf);
            printf("Telefone: %s\n", pac.tel);
            printf("Idade: %d\n", pac.idade);
            printf("Peso: %.2f kg\n", pac.peso);
            printf("Altura: %.2f m\n", pac.altura);
            encontrado = 1;
            break;
        }
    }
    
    if (!encontrado) {
        printf("\nPaciente não encontrado!\n");
    }

    fclose(arq_paciente);
    getchar();
}

 
void alterar_paciente(void){
    // FILE *arq_paciente;
    // FILE *arq_paciente_temp;

    Paciente pac;
    char cpf_busca[13];
    int encontrado = 0;
    char opcao;
    char continuar = 'S';


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

    arq_paciente = fopen("arq_paciente.csv", "rt");
    arq_paciente_temp = fopen("arq_paciente_temp.csv", "wt");

    if (arq_paciente == NULL || arq_paciente_temp == NULL){
        printf("Erro na criacao do arquivo\n");
        return;
    }

    while (fscanf(arq_paciente, "%[^;];%[^;];%[^;];%d;%f;%f\n", pac.nome, pac.cpf, pac.tel, &pac.idade, &pac.peso, &pac.altura) == 6) {
        if(strcmp(pac.cpf, cpf_busca) == 0){
            encontrado = 1;
            do{
                printf("\n    Dados atuais do paciente    \n");
                printf("Nome: %s\n", pac.nome);
                printf("CPF: %s\n", pac.cpf);
                printf("Telefone: %s\n", pac.tel);
                printf("Idade: %d\n", pac.idade);
                printf("Peso: %.2f kg\n", pac.peso);
                printf("Altura: %.2f m\n", pac.altura);

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
                        scanf("%s", pac.nome);
                        getchar();
                        break;
                    case '2':
                        printf("Novo CPF: ");
                        scanf("%s", pac.cpf);
                        getchar();
                        break;
                    case '3':
                        printf("Novo telefone: ");
                        scanf("%s", pac.tel);
                        getchar();
                        break;
                    case '4':
                        printf("Nova idade: ");
                        scanf("%d", &pac.idade);
                        getchar();
                        break;
                    case '5':
                        printf("Novo peso: ");
                        scanf("%f", &pac.peso);
                        getchar();
                        break;
                    case '6':
                        printf("Nova altura: ");
                        scanf("%f", &pac.altura);
                        getchar();
                        break;
                    default:
                        printf("Opção inválida!\n");
                        break;
                }
                printf("\n    Dados atualizados    \n");
                printf("Nome: %s\n", pac.nome);
                printf("CPF: %s\n", pac.cpf);
                printf("Telefone: %s\n", pac.tel);
                printf("Idade: %d\n", pac.idade);
                printf("Peso: %.2f kg\n", pac.peso);
                printf("Altura: %.2f m\n", pac.altura);

                printf("\nDeseja alterar outro campo? (S/N): ");
                scanf(" %c", &continuar);
                continuar = confirmar_acao(continuar);
            } while (continuar == 'S');
        }
        fprintf(arq_paciente_temp, "%s;%s;%s;%d;%f;%f\n", pac.nome, pac.cpf, pac.tel, pac.idade, pac.peso, pac.altura);
    }
    fclose(arq_paciente);
    fclose(arq_paciente_temp);

    if (encontrado){
        remove("arq_paciente.csv");
        rename("arq_paciente_temp.csv", "arq_paciente.csv");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                    Dieta Alterada com sucesso!                          ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
    } else {
        remove("arq_paciente_temp.csv");
        printf("\nDieta não encontrada!\n");
    }
    pausar();

}

        
   
void excluir_paciente(void){
    FILE *arq_paciente;
    FILE *arq_paciente_temp;

    Paciente pac;
    char cpf_busca[13];
    int encontrado = 0;

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



    char resposta;

    // Busca e exibe paciente
    do {
        arq_paciente = fopen("arq_paciente.csv", "rt");

        if (arq_paciente == NULL){
            printf("Erro na criacao do arquivo\n");
            return;
        }

        while (fscanf(arq_paciente, "%[^;];%[^;];%[^;];%d;%f;%f\n", pac.nome, pac.cpf, pac.tel, &pac.idade, &pac.peso, &pac.altura) == 6) {
            if (strcmp(pac.cpf, cpf_busca) == 0) {
                printf("Paciente encontrado\n");
                printf("Nome: %s\n", pac.nome);
                printf("CPF: %s\n", pac.cpf);
                printf("Telefone: %s\n", pac.tel);
                printf("Idade: %d\n", pac.idade);
                printf("Peso: %.2f kg\n", pac.peso);
                printf("Altura: %.2f m\n", pac.altura);
                encontrado = 1;
                break;
            }
        }
        
        if (!encontrado) {
            printf("\nPaciente não encontrado!\n");
        }

        fclose(arq_paciente);
        getchar();
        printf("Deseja confirmar a ação? (S/N): ");
        scanf(" %c", &resposta);

        resposta = confirmar_acao(resposta); 

        if (resposta == 0) {  
            printf("Opção inválida! Digite apenas S ou N.\n");
        }

    } while (resposta == 0); 

    // Exclui caso a resposta seja "S"
    if (resposta == 'S') {
        arq_paciente = fopen("arq_paciente.csv", "rt");
        arq_paciente_temp = fopen("arq_paciente_temp.csv", "wt");

        if (arq_paciente == NULL || arq_paciente_temp == NULL){
            printf("Erro na criacao do arquivo\n");
            return;
        }

        while (fscanf(arq_paciente, "%[^;];%[^;];%[^;];%d;%f;%f\n", pac.nome, pac.cpf, pac.tel, &pac.idade, &pac.peso, &pac.altura) == 6) {
            if(strcmp(pac.cpf, cpf_busca) != 0) {
                fprintf(arq_paciente_temp, "%s;%s;%s;%d;%.2f;%.2f\n", pac.nome, pac.cpf, pac.tel, pac.idade, pac.peso, pac.altura);
            }
        }
        
        fclose(arq_paciente);
        fclose(arq_paciente_temp);

        remove("arq_paciente.csv");
        rename("arq_paciente_temp.csv", "arq_paciente.csv");

        if (!encontrado) {
            printf("\nPaciente não encontrado!\n");
        }

        printf("Paciente Excluído com Sucesso!    \n");

    } else {
            printf("Operação de Exclusão Cancelada !  \n");
    }
    pausar();
}


void listar_paciente(void) {
    FILE *arq_paciente;
    Paciente* pac;

    pac = (Paciente*)malloc(sizeof(Paciente));
    int encontrado = 0;

    arq_paciente = fopen("arq_paciente.dat", "rb");    
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