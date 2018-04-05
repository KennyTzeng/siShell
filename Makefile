CC = gcc
CFLAGS = -g -Wall

.c.o:
	$(CC) -c $< $(CFLAGS)

link: siShell.o cat.o cd.o echo.o find.o help.o id.o mkdir.o pwd.o rm.o rmdir.o
	$(CC) -o siShell $^
