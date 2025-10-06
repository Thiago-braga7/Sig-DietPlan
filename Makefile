CC = gcc
CFLAGS = -Wall -g -I.

EXECUTAVEL = programa
FONTES = main.c pacientes.c dietas.c profissionais.c  consultas.c agendamentos.c relatorios.c util.c sobre.c
OBJETOS = $(FONTES:.c=.o)

.PHONY: all clean

all: $(EXECUTAVEL)

$(EXECUTAVEL): $(OBJETOS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJETOS) $(EXECUTAVEL)