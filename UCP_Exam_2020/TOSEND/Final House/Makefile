CC	=	gcc
EXEC	=	main
CFLAGS	=	-ansi -Wall -Werror -pedantic -std=c89

OBJ	=	main.o list.o

$(EXEC)	:	$(OBJ)
	$(CC)	$(OBJ)	-o	$(EXEC)

main.o :	main.c 
	$(CC)	$(CFLAGS)	main.c -c

list.o	:	list.c
	$(CC)	$(CFLAGS)	list.c -c



clean:
	rm	-f	$(EXEC)	$(OBJ)
run:
	./$(EXEC) input.txt output.txt
