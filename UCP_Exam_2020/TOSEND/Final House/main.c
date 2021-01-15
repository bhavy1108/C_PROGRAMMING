#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"

int main( int argc, char** argv ) {
  
	Node *head;
	Node *temp;
	int limit;
	char city[SUB];
	int choice;
	time_t secs;
	FILE* file1;
	
	secs = time(NULL);
	srand(secs);
	/*head = ( Node*) malloc ( sizeof( Node ) );*/

	if( argc < 3 )
	{
		printf( "Too little arguments. Please run the program with only 2 files.\n" );
	
	}
	else if(argc > 3)
	{
		printf( "Too many arguments. Please run the program with only 2 files.\n" );
	}
	else
	{

		file1 = fopen(argv[1], "r");
		if(file1 == NULL)
		{
			fprintf(stderr, "THIS FILE CANNOT BE OPENED OR READ!!\n");
		}
		else
		{

			head = ( Node*) malloc ( sizeof( Node ) );
  			head = readFile( argv[1] ); 	

			if( ((rand() % 1001)/1000) >= 0.75)
			{
				flashSale(head);
				printf("Flash Sale is on!!!\nOur prices have been halved.\n");
			}

		
			choice = -1;
			printf( "\nChoose:\n1 >> Filter by Price.\n2 >> Filter by Surburb.\nSo, your choice is: " );
  			scanf( "%d",&choice );

  			if( choice < 1 || choice >= 3 )
  			{
    				do{
      					printf( "\nWrong choice! Your new choice is: " );
      					scanf( "%d",&choice );
    				}while( choice < 1 || choice > 3 );
  			}

  			switch( choice )
  			{
   				case 1:
    
					printf( "\nEnter the maximum price: " );
  					scanf( "%d", &limit );
  					head = filterByPrice( head, limit );
  					printNode( head );
					writeFile( head, argv[2] );   
    
    				break;

    				case 2:
    
      					printf( "\nEnter the surburb: " );
  					scanf( "%s", city );
  					capitaliseString( city );
  					head = filterBySurburb( head, city );
  					printNode( head );
					writeFile( head, argv[2] );    
	
   				break;
  
   				default:
		
					printf("This will never happen.\n");
				break;
  			}
  	
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
