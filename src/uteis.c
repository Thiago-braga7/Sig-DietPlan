#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LARGURA 75


// Funcões criadas por Thiago
char confirmar_acao(char valor) {
    valor = toupper(valor);

    if (valor == 'S' || valor == 'N') {
        return valor;
    }

    return 0;
}


void limpar_tela(void) {
    system("clear||cls");
}


void pausar(void) {
    printf("\nPressione ENTER para continuar...");
    getchar();
}


// Conta a largura da string na tela, para não quebrar alinhamento da moldura
int largura_visual(const char *texto) {
    int largura = 0;
    unsigned char c;
    while ((c = *texto++)) {
        // Ignora bytes extras dos acentos UTF-8 (10xxxxxx)
        if ((c & 0xC0) != 0x80) {
            largura++;
        }
    }
    return largura;
}


// Moldura apenas com o título
void exibir_moldura_titulo(const char *titulo) {
    int i;

    printf("╔");
    for (i = 0; i < LARGURA; i++) {
        printf("═");
    }
    printf("╗\n");

    int titulo_len = largura_visual(titulo);
    int espacos = (LARGURA - titulo_len) / 2;

    printf("║%*s"
           "%s"
           "%*s║\n",
           espacos,
           "",
           titulo,
           LARGURA - espacos - titulo_len,
           "");
    printf("╚");

    for (i = 0; i < LARGURA; i++) {
        printf("═");
    }
    printf("╝"
           "\n");
}


// Moldura apenas com o conteúdo
void exibir_moldura_conteudo(const char *conteudo) {
    int i;

    printf("╔");
    for (i = 0; i < LARGURA; i++) {
        printf("═");
    }
    printf("╗\n");

    // Imprime o conteúdo linha por linha
    const char *p = conteudo;
    while (*p) {
        const char *inicio = p;
        int len = 0;
        while (p[len] != '\n' && p[len] != '\0') {
            len++;
        }

        char linha[256];
        strncpy(linha, inicio, len);
        linha[len] = '\0';

        int vis = largura_visual(linha);
        int espacos_finais = LARGURA - 1 - vis;  // margem direita ajustada

        printf("║ %s%*s║\n", linha, espacos_finais, "");

        p += len;
        if (*p == '\n')
            p++;
    }

    printf("╚");
    for (i = 0; i < LARGURA; i++)
        printf("═");
    printf("╝\n");
}