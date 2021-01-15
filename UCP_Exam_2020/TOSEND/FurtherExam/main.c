#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"

int main( int argc, char** argv ) 
{
  	Node *head;
	Node *temp;
	time_t seconds;
	FILE* file1;

	if( argc < THREE )
	{
		printf( "Too little arguments. Please run the program with only 2 files.\n" );
	
	}
	else if(argc > THREE )
	{
		printf( "Too many arguments. Please run the program with only 2 files.\n" );
	}
	else
	{

		file1 = fopen(argv[1], "r");
		if(file1 == NULL)
		{
			fprintf(stderr, "THIS FILE CANNOT BE OPENED AND READ!!\n");
		}
		else
		{	
			head = (  Node* )malloc( sizeof( Node ) );
			head = readFile(argv[1]);

			seconds = time(NULL);
			srand(seconds);
			if ( rand()% TWO == ONE)
			{
				printf("▒▒▒▒\n");
				systemGlitch(head);
			}

			writeFile(head, argv[2]);
			printf("All information is in file %s.\n", argv[2]);
			printf("Bye!\n");

			while ( head != NULL )
  			{
				temp = head;
				head = head -> next;
				free( temp );
  			}
	
		}
	}
	return 0;
}
