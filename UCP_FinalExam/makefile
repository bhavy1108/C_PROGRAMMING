CC	=	gcc
CFLAGS	=	-Wall	-ansi	-pedantic	-Werror	-std=c89	-g 
OBJ	=	main.o	file.o	
EXEC	=	program

$(EXEC)	:	$(OBJ)
	$(CC)	$(OBJ)	-o	$(EXEC)

main.o	:	main.c	struct.h
	$(CC)	main.c	-c	$(CFLAGS)

file.O	:	file.c	struct.h
	$(CC)	file.c	-c	$(CFLAGS)

clean	:
	rm	-f	$(EXEC)	$(OBJ)

run	:
	./$(EXEC)	hero.txt	enemies.txt

runVal	:
	valgrind	--leak--check=full	--track-origins=yes	./$(EXEC)	hero.tx	enemies.txt

