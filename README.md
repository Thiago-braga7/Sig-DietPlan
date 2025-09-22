Sig-DietPlan

📝 Descrição do Projeto

O Sig-DietPlan é um sistema de gestão voltado para o planejamento e acompanhamento de dietas. Desenvolvido como parte da avaliação da disciplina de Programação da UFRN (Universidade Federal do Rio Grande do Norte), o sistema oferece funcionalidades completas para facilitar o gerenciamento nutricional.

O sistema auxilia profissionais e usuários a monitorarem hábitos alimentares, simplificando o desenvolvimento de planos nutricionais e o acompanhamento da saúde.

✨ Funcionalidades

Com ele, é possível:

    Cadastrar e gerenciar usuários;

    Controlar alimentos e seus valores nutricionais;

    Registrar consumos diários;

    Planejar e acompanhar refeições e dietas personalizadas.

📂 Estrutura, Modularização e Compilação

O projeto está organizado de forma modular, com cada funcionalidade principal separada em pastas específicas, facilitando o desenvolvimento e a manutenção do código.

🚀 Como Compilar e Executar

Compilação do Projeto no Linux

    No VSCode, instale a extensão Makefile Tools.

    Use o Makefile para compilar o projeto:
    Bash

make

Execute o programa com:
Bash

    ./main

Compilação do Projeto no Windows (com MSYS2)

Este guia mostra como configurar e compilar o projeto no Windows usando o MSYS2.

Pré-requisitos

    MSYS2 instalado.

    GCC configurado no ambiente MSYS2.

Passos

    Instale o MSYS2 a partir do site oficial: https://www.msys2.org

    Abra o terminal do MSYS2 e atualize os pacotes:
    Bash

pacman -Syu

Instale o make:
Bash

pacman -S make

Verifique se o compilador GCC está instalado:
Bash

gcc --version

Se não estiver instalado, instale o conjunto de ferramentas MinGW-w64:
Bash

pacman -S mingw-w64-x86_64-gcc

Confirme se o caminho /mingw64/bin está na variável de ambiente PATH. Você pode verificar com:
Bash

echo $PATH

Se não estiver, adicione-o temporariamente à sessão atual:
Bash

    export PATH=$PATH:/mingw64/bin

Compilação

    Navegue até o diretório do projeto no terminal MSYS2.

    Execute o comando para compilar e rodar o projeto:
    Bash

    make run

💻 Tecnologias Utilizadas

    Linguagem: C

    IDE: Visual Studio Code (VSCode)
