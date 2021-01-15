CC      =       gcc
EXEC    =       program
     
   
OBJ     =       main.o colours.o 
   
$(EXEC) :       $(OBJ)
	$(CC)   $(OBJ)  -o      $(EXEC)
   
main.o  :       main.c  colours.h
	$(CC)         main.c  -c
  
colours.o   :     colours.c   colours.h 
	$(CC)       colours.c   -c
  
clean:
	rm      -f      $(EXEC) $(OBJ)
 

