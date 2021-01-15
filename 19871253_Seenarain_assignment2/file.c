#include <stdio.h>
#include <string.h>
#include "file.h"

/*
** Method read is used to read in file1
** That is  it checks first if the file is null 
** if not thus reading input.c
*/
int read(char* file, char lines[][150] )
{
    FILE* file1;
    char read[150];
    int numLines = 0;

    file1 = fopen(file, "r");

    if(file1 == NULL)
    {
        printf("The file 1 can not be opened. Try another file.\n");
    }
    else
    {
        
       /* read from input.c */
       while(fgets(read, 150, file1)!= NULL)
       {
           strcpy(lines[numLines], read);
           numLines++;
         
       }  
       if (ferror(file1))
        {
            
            printf("Error in reading from file : file.c\n");
        
        }
       fclose(file1);

    }
   
    return numLines;
}

