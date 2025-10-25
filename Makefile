# Compilador e opções
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

# Pastas
SRCDIR = src
INCDIR = include
BUILDDIR = build
DATADIR = data

# Nome do executável final
TARGET = $(BUILDDIR)/sig-dietplan

# Lista automática de todos os .c dentro de src/
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(SRC:$(SRCDIR)/%.c=$(BUILDDIR)/%.o)



# REGRAS

# Gera o executável
all: $(TARGET)

# Linkagem final
$(TARGET): $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $^

# Compilação dos .c para .o
$(BUILDDIR)/%.o: $(SRCDIR)/%.c | $(BUILDDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Cria a pasta build automaticamente se não existir
$(BUILDDIR):
	@mkdir -p $(BUILDDIR)


# Remove objetos e binário
clean:
	@rm -rf $(BUILDDIR)

# Recompila e executa
rebuild: clean run

# Executa o programa
run: all
	@$(TARGET)

# Evita conflitos com nomes de arquivos
.PHONY: all clean rebuild run

# Feito com auxílio do ChatGPT