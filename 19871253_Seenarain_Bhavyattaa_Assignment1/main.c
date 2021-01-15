#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> 
#include "colours.h"
#define INDEX 2

/* main function to compile the program along with the command line arg*/
int main(int argc , char** argv) 
{    
     int lengthstr , oldLength, newLength;
      char* str;
      char* old;
      char* newS;
      char* oldSentence;
      
         int u = 0;
         int v = 0;
         int w= 0;
         
         int flag = 0, commence , end ;
         str = (char*)malloc(sizeof(char));
         old = (char*)malloc(sizeof(char));
         newS = (char*)malloc(sizeof(char));
         oldSentence = (char*)malloc(sizeof(char));

         str = argv[1];
         oldSentence = argv[1];
         old = argv[2];
         newS = argv[3];
         
         lengthstr = strlen(str);
         oldLength = strlen(old);
         newLength = strlen(newS);
         
         
         
    printf("%s \n\n",  str);
    system("clear");
    printf("\nreplace : %s --> %s\n", argv[2], argv[3] );
    red();
    printf("%s\n", str);
    
    sleep(3);
    
    /* for loop to swap word by replace word  */   
    for(u = 0; u <lengthstr; u++)
    {
         
      flag = 0;
           
      commence = u;
           
      for(v = 0; str[u] == old[v]; v++, u++ )
           

               if(v == oldLength - 1)
               
               
                  flag = 1;
                  end = u;
                  
               
               
               
               if(flag == 0)
               
                  u-= v;
                  
               
              
               else
               {
               
                  for(v = commence; v < lengthstr; v++)
                  {
                  
                    for(w = commence; w < lengthstr; w++)
                    str[w] = str[w +1 ];
                    lengthstr--;
                    u--;
                      
                 }
           
                 for( v = commence; v < commence + newLength; v++ )
                 {
                 
                    for(w = lengthstr; w >= v; w--)
                    str[w+1] = str[w];
                    str[v] = newS[v - commence];
                    lengthstr++;
                    u++;
                 
                 }  
                 
                /* printf("this : no match\n");*/
                /* system("clear");
                 printf("tea : match \n");*/
                 system("clear");    
               }       


   }
   green();
   printf("%s\n",str);
   
   /* conditional compilation */
    #ifdef INDEX
           
                printf("all defined");
                printf(" position of substring found in string");
                
     #endif
     
   /* free malloc */    
   free(str);
   free(old);
   free( newS);
   free(oldSentence);
             
   return 0;
}
