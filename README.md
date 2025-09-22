# Sig-DietPlan



Descrição do Projeto

O Sig-DietaPlan é um sistema de gestão voltado para o planejamento e acompanhamento de dietas. Desenvolvido como parte da avaliação da disciplina de Programação da UFRN (Universidade Federal do Rio Grande do Norte), o sistema oferece funcionalidades completas para facilitar o gerenciamento nutricional.

Com ele, é possível:

Cadastrar e gerenciar usuários;

Controlar alimentos e seus valores nutricionais;

Registrar consumos diários;

Planejar e acompanhar refeições e dietas personalizadas.

O sistema auxilia profissionais e usuários a monitorarem hábitos alimentares, simplificando o desenvolvimento de planos nutricionais e o acompanhamento da saúde.

## ESTRUTURA, MODULARIZAÇÃO E COMPILAÇÃO:

O projeto está organizado de forma modular, com cada funcionalidade principal separada em pastas específicas, facilitando o desenvolvimento e a manutenção do código.

### Compilação do Projeto no Linux
No VSCode instale a extensão **Makefile Tools**.

Use o Makefile com:

```bash
make

E execute o programa com:
./main

Compilação do Projeto no Windows

Este guia mostra como configurar e compilar o projeto no Windows usando o MSYS2.

Pré-requisitos

MSYS2 instalado

GCC configurado

Passos

Instale o MSYS2: https://www.msys2.org
  pacman -Syu

Instale o make:
  pacman -S make

Verifique se o GCC está instalado:
  gcc --version

Se não estiver, instale:
  pacman -S mingw-w64-x86_64-gcc

Confirme o PATH:
  echo $PATH
  Se não tiver /mingw64/bin, adicione:
  export PATH=$PATH:/mingw64/bin

Compilação
  No diretório do projeto, rode:
  make run

TECNOLOGIAS UTILIZADAS
  Linguagem: C

  IDE: Visual Studio Code (VSCode)
  
