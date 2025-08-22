#include <stdio.h>
#include <stdlib.h> 
#include "usuarios.h"
#include "alimentos.h"
#include "refeicoes.h"





void bem_vindo(void);
void menu_principal(void);




void consumo_alimentos(void);
void cadastrar_consumoAlimentos(void);

void consumo_agua(void);
void relatorios(void);
void sair(void);



int main(void){
    char opcao;
    bem_vindo();

    do {
        menu_principal();
        printf("Escolha uma opção: ");
        scanf(" %c", &opcao);
        getchar();

        switch(opcao){
            case '1': usuarios(); break;
            case '2': alimentos(); break;
            case '3': refeicoes(); break;
            case '4': consumo_alimentos(); break;
            case '5': consumo_agua(); break;
            case '6': relatorios(); break;
            case '0': sair(); break;
            
        }
    } while(opcao != '0');

    return 0;
}

void bem_vindo(void) {
    char nome[50];
    char genero;

    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                           SIG-DietPlan                                  ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");

    printf("\nInforme seu nome: ");
    scanf("%[^\n]", nome);  

    printf("Informe seu gênero (M = Masculino, F = Feminino, N = Prefiro não informar): ");
    scanf(" %c", &genero);

    if (genero == 'M' || genero == 'm') {
        printf("\nBem-vindo 😁, %s!\n", nome);
    } else if (genero == 'F' || genero == 'f') {
        printf("\nBem-vinda 😁, %s!\n", nome);
    } else {
        printf("\nBem-vindo(a) 😁, %s!\n", nome);
    }

    printf("Sig-DietaPlan é um sistema desenvolvido na disciplina de Programação da UFRN\n");
    printf("para auxiliar no planejamento e acompanhamento de dietas.\n");
    printf("\n");
    printf("Ele permite:\n");
    printf("- Cadastro de usuários;\n");
    printf("- Gestão de alimentos e valores nutricionais;\n");
    printf("- Registro de consumos diários;\n");
    printf("- Planejamento de refeições personalizadas.\n");
    printf("\n");

    
    printf("Estamos felizes em ter você no SIG-DietPlan! 😊👍\n\n");
    printf("Gerencie sua saúde de forma prática: cadastre usuários, registre alimentos, acompanhe a quantidade de água ingerida e controle suas calorias diárias!");
    printf("\n");
}



void menu_principal(void){
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                 Centro de Ensino Superior do Seridó                     ///\n");
    printf("///               Departamento de Computação e Tecnologia                   ///\n");
    printf("///                  Disciplina DCT1106 -- Programação                      ///\n");
    printf("///               Projeto Sistema de Planejamento de Dietas                 ///\n");
    printf("///                           SIG-DietPlan                                  ///\n");
    printf("///         Criado por @thiagobraga9a e gabrieluchoa_1 -- desde Ago, 2025   ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = Planejamento de Dietas = = = = =                   ///\n");
    printf("///                                                                         ///\n");
    printf("///                      1. Usuários                                        ///\n");
    printf("///                      2. Alimentos                                       ///\n");
    printf("///                      3. Refeições                                       ///\n");
    printf("///                      4. Consumo Diário(Alimentos)                       ///\n");
    printf("///                      5. Consumo Diário(Água)                            ///\n");
    printf("///                      6. Relatórios                                      ///\n");
    printf("///                      0. Sair                                            ///\n");
    printf("///                                                                         ///\n");
    getchar();
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
}





void consumo_alimentos(void){
    char opcao;
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                    = = = = =  Consumo Diário(Alimentos)  = = = = =      ///\n");
    printf("///                                                                         ///\n");
    printf("///                    1. Registrar Consumo de Alimentos                    ///\n");
    printf("///                    2. Consultar Consumo(Dia) de Alimentos               ///\n");
    printf("///                    3. Alterar Registro de Consumo de Alimentos          ///\n");
    printf("///                    4. Excluir Registro de Consumo de Alimentos          ///\n");
    printf("///                    0. Voltar ao Menu Principal                          ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                      Escolha a opção desejada: ");
    scanf("%c", &opcao);
    getchar();
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
}

void cadastrar_consumoAlimentos(void){
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                               Consumo Alimentos                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                 = = = = =  Cadastrar Consumo de Alimentos = = = = =     ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Informe o Alimento:                             ///\n");
    printf("///                         Quantidade(kcal):                               ///\n");
    printf("///                         Informe a data (DD/MM/AAAA):                    ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
   
}

void consumo_agua(void){
    char opcao;
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                    = = = = =  Consumo Diário(Água)  = = = = =           ///\n");
    printf("///                                                                         ///\n");
    printf("///                    1. Registrar Consumo de Água                         ///\n");
    printf("///                    2. Consultar Consumo(Dia) de Água                    ///\n");
    printf("///                    3. Alterar Registro de Consumo de Água               ///\n");
    printf("///                    4. Excluir Registro de Consumo de Água               ///\n");
    printf("///                    0. Voltar ao Menu Principal                          ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                      Escolha a opção desejada: ");
    scanf("%c", &opcao);
    getchar();
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
}


void relatorios(void){
    char opcao;
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                    = = = = =  Relatórios  = = = = =                     ///\n");
    printf("///                                                                         ///\n");
    printf("///                    1. Alimentos mais Consumidos                         ///\n");
    printf("///                    2. Total de Calorias(Dia)                            ///\n");
    printf("///                    3. Meta Diária de Calorias                           ///\n");
    printf("///                    4. Meta Diária de Água                               ///\n");
    printf("///                    5. Excluir Registro de Consumo                       ///\n");
    printf("///                    0. Voltar ao Menu Principal                          ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                      Escolha a opção desejada: ");
    scanf("%c", &opcao);
    getchar();
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
}
void sair(void){
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                 Obrigado por usar o SIG-DietPlan!                       ///\n");
    printf("///                         Até a proxima!                                  ///\n");
    printf("///              📷 Instagram: @thiago.braga9a e gabrieluchoa_1             ///\n");
    printf("///              🐙 GitHub: github.com/Thiago-braga7                        ///\n");
    printf("///                         github/GabrielUchoa17                           ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");

}

