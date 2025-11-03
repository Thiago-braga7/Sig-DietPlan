# SIG DietPlan - Sistema de Gestão de Planos Alimentares

## Descrição do Projeto

Este projeto é um sistema de gestão desenvolvido para controle de planos alimentares, criado como parte da avaliação da disciplina de Programação na UFRN (Universidade Federal do Rio Grande do Norte).

O sistema permite o gerenciamento de usuários, perfis alimentares, planos de dieta e refeições, facilitando o acompanhamento nutricional e o planejamento alimentar.

---

## Estrutura, Modularização e Compilação

O projeto está organizado de forma modular, com cada funcionalidade principal separada em arquivos e pastas específicas, facilitando o desenvolvimento e a manutenção do código.

### Compilação do Projeto no Linux

1. No VSCode, instale a extensão chamada **"Makefile Tools"**.
2. Use o Makefile através do comando `make rebuild`.
3. Após finalizar o programa, utilize o comando `make clean` para limpar os arquivos.

### Compilação do Projeto no Windows

Este guia explica como configurar o ambiente e compilar o projeto no Windows utilizando o **MSYS2**.

#### Pré-requisitos

- Ter o MSYS2 e o GCC instalados.

#### Instalação do MSYS2 e do Make

1. Baixe e instale o MSYS2: https://www.msys2.org.
   - O MSYS2 emula um terminal Linux (UNIX) no Windows, permitindo a utilização de ferramentas como make e gcc.
2. Atualize os pacotes do MSYS2:
   ```sh
   pacman -Syu
   ```
3. Instale o make:
   ```sh
   pacman -S make
   ```

#### Configuração do GCC

1. Verifique a instalação do GCC:
   ```sh
   gcc --version
   ```
2. Caso não esteja instalado:
   ```sh
   pacman -S mingw-w64-x86_64-gcc
   ```
3. Verifique o PATH:
   ```sh
   echo $PATH
   ```
4. Se necessário, adicione o caminho do GCC:
   ```sh
   export PATH=$PATH:/mingw64/bin
   ```
5. Reinicie o terminal para aplicar as alterações.

#### Compilação do Projeto

- Navegue até o diretório do projeto e execute:
  ```sh
  make run
  ```

Seguindo estas etapas, você conseguirá compilar e executar o projeto corretamente no Windows utilizando o MSYS2.

---

## Tecnologias Utilizadas

- **Linguagem:** C
- **IDE:** Visual Studio Code (VSCode)

---

## Funcionalidades Principais

- **Gestão de Clientes:** Cadastro e gerenciamento de perfis alimentares.
- **Gestão de Planos de Dieta:** Criação, atualização e exclusão de planos alimentares personalizados.
- **Gestão de Refeições:** Registro de refeições diárias e semanais.
- **Relatórios:** Geração de relatórios nutricionais e acompanhamento do progresso dos usuários.

---

> **Projeto desenvolvido para fins acadêmicos — todos os direitos reservados.**
