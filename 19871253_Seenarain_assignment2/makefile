CC	=	gcc
EXEC	=	program
CFLAGS	=	-std=c89 -ansi -Werror -std=c89 -Wall -pedantic
OBJ	=	main.o	file.o	lines.o	match.o	linkedList.o

$(EXEC)	:	$(OBJ)
	$(CC)	$(OBJ) newSleep.o	-o 	$(EXEC)

main.o 	:	main.c	file.h	lines.h	newSleep.h	match.h	linkedList.h
	$(CC)	$(CFLAGS)	main.c	-c

file.o 	:	file.c	file.h
	$(CC)	$(CFLAGS)	file.c	-c

lines.o :	lines.c	lines.h newSleep.h
	$(CC)	$(CFLAGS)	lines.c	-c

newSleep.o :	newSleep.c	newSleep.h
	$(CC)	$(CFLAGS)	newSleep.c	-c

match.o	:	match.c	match.h
	$(CC)	$(CFLAGS)	match.c	-c

linkedList.o	:	linkedList.c	linkedList.h
	$(CC)	$(CFLAGS)	linkedList.c	-c

clean:
	rm	-f	$(EXEC)	$(OBJ)	