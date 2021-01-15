
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "lines.h"

/*This function counts the number of characters*/
int countChar(char lines[][150],int numLines)
{
   int i , j;
   int count = 0;


   for (i=0; i < numLines; i++)
   {
         for (j=0; j< strlen(lines[i]); j++)
            {
               count++;
            }
   }
   return count;   
}

/*
** This function will display the input.c output in the terminal
** It calls the method countCharc whereby provides the number of characters 
** which thus used by the for loop to display the output of the input.c
** 
*/

void findBracketAndDisplay(char lines[][150],int numLines)
{
   int i , j, k;
   int numChars;
   int index = 0;
   numChars = countChar(lines, numLines);
   
    

   for(k =0; k< numChars; k++)
   {
      system("clear");
      for (i=0; i < numLines; i++)
      {
         for (j=0; j< strlen(lines[i]); j++)
         {
            /* bracket verification */
           /* balanced (listing ,sym , counter);*/
            printf("%c",lines[i][j]);
            index++;
         }
         if( k < index && k > (index - strlen(lines[i])))
         {
            /* trying to implement the arrow*/
            for(j=0; j< k - (index - strlen(lines[i])); j++)
            {
               printf(" ");
                   
            }
            
            printf("^\n");
         }
      }
       
      sleep(1);
      
    }
     
}
