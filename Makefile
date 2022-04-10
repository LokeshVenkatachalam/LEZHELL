CC = gcc
CFLAGS = -Wall
FILES = lezhell.c cd.c pwd.c echo.c ls.c pinfo.c function.c piping.c jobs.c fg.c bg.c

default:
	$(CC) $(CFLAGS) $(FILES) -o lezhell
	./lezhell

com:
	$(CC) $(CFLAGS) $(FILES) -o lezhell

run:
	./lezhell

dbg:
	$(CC) $(CFLAGS) -g $(FILES) -o lezhell
	gdb lezhell

