#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"
#include "match.h"

/* return 1 if the bracket exists*/
int symbol_brac(char m)
{
    int answer;
    if (m == '<' || m == '{' || m ==  '[' || m == '('  || m == '>' || m == '}' || m == ']' || m == ')')
    {
        answer = 1;
    }
    return answer;
}

int matching (char m , char n)
{
    int answer = 0 ;
    
    if (m == '[' && n == ']')
    {
        answer = 1;
    }
    else if (m == '(' && n == ')')
    {
        answer = 1;
         
    }
    else if (m == '{' && n == '}')
    {
        answer = 1;

    }
    else if (m == '<' && n == '>')
    {
        answer = 1;

    }
    return answer;

}

/* when  checking for open bracket it will also select the close brac*/
char openBrac (char m)
{
    char answer;
    if (m == '(')
    {
        answer = ')';
    }
    else if (m == '{')
    {
        answer = '}';

    } 
    else if (m == '[')
    {
        answer = ']';
    }
    else if (m == '<')
    {
        answer = '>';
       
    }

    return answer;
}

 int balanced (LinkedList *listing , char sym , int counter)
 {
     bracs* b;
     int bad = 0;
     

     if (sym == '(' || sym == '[' || sym == '{' || sym == '<')
     {
         b = (bracs*)malloc (sizeof(bracs));
         b -> position = counter;
         b -> type = sym;
         insertFirst(listing, b);
        
     }
     if (sym == ')' || sym == ']' || sym == '}' || sym == '>')
     {
         if (listing-> head !=NULL)
         {
            if(matching(listing->head->bracket->type,sym)== 1)
            {
                removeFirst(listing);

            }
            else
            {
               bad = 4;
            }
            
         }
         else
         {
             bad = 5;
         }
         
     }
     return bad;
     free(b);
     
 }

 int searching  (char **file, int l )
 {
     int a ,b,counter ;
     LinkedList *s = createLinkedList();
     counter = 0;
    
    for (a = 0; a < l ; a++ )
    {
        for (b = 0; b <strlen(file[b]); b++)
        {
            balanced(s , file[a][b], counter);
            counter++;
        }
    }
    return 0;
  }
