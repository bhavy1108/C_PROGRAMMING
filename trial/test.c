#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct People
{
    int hp;
    int atk;
    int def;
    int med;
    char name[49];
}People;

typedef struct Nodes
{
    int hp;
    int atk;
    int def;
    int med;
    char name[49];
    void* first;
    struct Nodes* next;
}Nodes;


void addNodes( Nodes **headptr, People p)
{
	Nodes* new = ( Nodes* )malloc( sizeof( Nodes ) );
	People *people;
	Nodes *temporary;

	new -> first = &p;
	people = new -> first;
	strcpy( new->name, people->name );
	new -> hp = people -> hp; 
	new -> atk = people -> atk;
	new -> def = people -> def;
	new -> med = people -> med;
	new -> next = NULL;
	temporary = *headptr;
  
	if( *headptr == NULL )
	{
		*headptr = new;
	}
	else
	{
		while( temporary -> next != NULL )
		{
			temporary = temporary -> next;
		}
		temporary -> next = new;
	}
  
}


People FileHero(char* filename)
{
	FILE* file;
	char max[100];	
	char* tok;
	People p;
	
	file = fopen( filename, "r" );
	if( file == NULL)
	{
  		printf("File Not Found!");
  	}
	else
	{
  		fgets( max, 100, file );
  		
			/*HP, ATK, DEF, MED, Name
			 20,6,3,1,Arlen*/
  		tok = strtok(max, ",");
		p.hp = atoi(tok);
		tok = strtok( NULL, "," );
		p.atk = atoi(tok);
		tok = strtok( NULL, "," );
		p.def = atoi(tok);
		tok = strtok( NULL, "," );
		p.med = atoi(tok);
		tok = strtok( NULL, "," );
		strcpy( p.name, tok);
	}
	fclose(file);
	return p;
}


Nodes* file1(char* filename)
{
	FILE* file;
	char max[100];	
	char* tok;
	People p;
	Nodes* headptr;
	headptr = (  Nodes* )malloc( sizeof( Nodes ) );
	file = fopen( filename, "r" );
	if( file == NULL)
	{
		printf("File Not Found!");
	}
	else
	{
		while( fgets( max, 100, file ) && strlen( max ) != 0 && strcmp( max, "\n" ) != 0)
		{
			/*HP, ATK, DEF, MED, Name
			 20,6,3,1,Arlen*/
			tok = strtok(max, ",");
			p.hp = atoi(tok);
			tok = strtok( NULL, "," );
			p.atk = atoi(tok);
			tok = strtok( NULL, "," );
			p.def = atoi(tok);
			tok = strtok( NULL, "," );
			p.med = atoi(tok);
			tok = strtok( NULL, "\n" );
			strcpy( p.name, tok);

			//printf("med: %d", p.med);
			addNodes( &headptr, p);
	       
	        }
          }
          fclose(file);
          return headptr;
}

  void Hero_print(People p)
  {
	/*printf("HERO NAME: %s		hp: %d, atk: %d, def: %d, med: %d", p.name, p.hp, p.atk, p.def, p.med);*/
	
	 printf("Hero :\n");
        printf("%s\t", p.name);
        printf("HP:%d\t", p.hp);
        printf("ATK:%d\t", p.atk);
        printf("DEF:%d\t", p.def);
        printf("MED:%d\t", p.med);
        printf("\n");
        printf("\n");		
	
   }

  void List_print( Nodes *headptr )
  {
  
	Nodes *temporary;
	temporary = headptr;
	printf( "\n" );
	temporary = temporary -> next;
  
	if( temporary == NULL )
	{
		printf( "Empty list");
	}
	else
	{
		printf("Enemies:\n");
		while( temporary != NULL )
		{
		
		/*printf("%s -------> hp: %d, atk: %d, def: %d\n", temporary->name, temporary->hp, temporary->atk, temporary->def);*/
		
		
		 printf("Enemies :\n");
                 printf("%s\t",temporary->name);
                 printf("HP:%d\t", temporary->hp);
                 printf("ATK:%d\t", temporary->atk);
                 printf("DEF:%d\t", temporary->def);
                 printf("\n");
      
    		temporary = temporary-> next;
    		
		}
	}
}	

int main(int argc, char *argv[]) 
{
	FILE* file_1;
	FILE* file_2;

        Nodes *headptr;
	People hero;

	/* Opening and accessing the hero.txt file */
	file_1 = fopen(argv[1], "r");
	hero = FileHero(argv[1]);
	Hero_print(hero);

	/* Opening and accessing the enemies.txt file */
	file_2 = fopen(argv[2], "r");
	headptr = (  Nodes* )malloc( sizeof( Nodes ) );

	/*load the linkedlist with enemies.txt */
	headptr = file1(argv[2]);

	/* output  the enemy from the list */
	List_print(headptr);
	return 0;
}

