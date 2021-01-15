#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"

/*
NAME: capitaliseString
PURPOSE: capitalises a String
IMPORTS: char input[]
EXPORTS: void
ASSERTIONS:
	PRE: the string might not have been capiatlised
	POST: the string has been capitalised
REMARKS: THis submodule has been included in my assignment for semester 1, year 2020 and final exam of semester 1, year 2020.
*/

void capitaliseString( char input[] )
{
  	char c;
  	int k;
  	for( k=0; k<( strlen( input ) ); k++ )
  	{
    		c = input[k];
    		if( (c >= 'a' && c <= 'z') )
    		{
      			input[k] = input[k] - ALPHA;    
    		}
    		else
    		{
      			input[k] = input[k];  
    		}
  	}
 
}





House copyDetails( House p, Node *current )
{
	p.price = current->price;
	p.bed = current->bed;
	p.bath = current->bath;
	strcpy( p.address, current->address );
	strcpy( p.surburb, current->surburb );

	return p;
}





/*
NAME: addNode
PURPOSE: adds node to linked list
IMPORTS: Node **head, House hh
EXPORTS: void
ASSERTIONS:
	PRE: linked list may or may not contain anything.
	POST: a node has been added to the linked list
REMARKS: none.
*/
void addNode( Node **head, House hh )
{
	Node* new = ( Node* )malloc( sizeof( Node ) );
	House* house;
	Node* temp;

	new -> v = &hh;
	house = new -> v;
	new -> bed = house -> bed;
	new -> bath = house -> bath;
	new -> price = house -> price;
	strcpy( new->address, house->address );
	strcpy( new->surburb, house->surburb );
	new -> next = NULL;
	temp = *head;
  
	if( *head == NULL )
	{
		*head = new;
	}
	else
	{
		while( temp -> next != NULL )
		{
			temp = temp -> next;
		}
		temp -> next = new;
	}
  
}





/*
NAME: readFile
PURPOSE: reads a file and extracts information to pass on to a linked list.
IMPORTS: char* filename
EXPORTS: Node* head
ASSERTIONS:
	PRE: file has not been read.
	POST: file is read and linked list contains information.
REMARKS: none.
*/

Node* readFile( char *filename )
{
	FILE *read;
	char input[LIMITR];
	House h;
	char *token;
	Node *head;
		
	head = (  Node* )malloc( sizeof( Node ) );
	read = fopen( filename, "r" );
	if( read == NULL)
	{
  		fprintf(stderr, "THIS FILE CANNOT BE OPENED OR READ!!\n");
  		head = NULL;
	}
	else
	{
  		while( fgets( input, LIMITR, read ) )
  		{
    			token = strtok( input, "," );
    			h.bed = atoi( token );
			token = strtok( NULL, "," );
    			h.bath = atoi( token );
			token = strtok( NULL, "," );
    			h.price = atoi( token );
    			token = strtok( NULL, "\n" );
    			capitaliseString( token );
    			strcpy( h.address, token );

			strcpy( input, h.address );
			token = strtok( input, " " );
			token = strtok( NULL, " " );
			token = strtok( NULL, " " );
			token = strtok( NULL, "\n" );
			strcpy( h.surburb, token ); 
                        
			addNode( &head, h );
 		}
	}
	fclose( read );
	return head;
}





/*
NAME: printNode
PURPOSE: prints the information saved in the Linked list.
IMPORTS: Node *head
EXPORTS: void
ASSERTIONS:
	PRE: Linked list's information has not been printed.
	POST: if linked list contains information, it is printed. if not, a message is outputted.
REMARKS: none.
*/

void printNode( Node *head )
{
	Node *temp;
	temp = head;
	printf( "\n" );
	temp = temp -> next;
  
	if( temp == NULL )
	{
		printf( "The list is empty.\nSorry could not find anything fitting your search specifications.\n" );
	}

	while( temp != NULL )
	{
		printf( "from List:\n" );
		printf( "bed = %d, bath = %d, price = %d, address = %s.\n", temp->bed, temp->bath, temp->price, temp->address );
    		temp = temp-> next;
	}
  
}





/*
NAME: filterByPrice
PURPOSE: Filers the price of the houses according to the maximum price.
IMPORTS: Node* head, int limit
EXPORTS: Node*
ASSERTIONS:
	PRE: Linked list has not been filtered according to the price.
	POST: Linked list has been filtered according to the price.
REMARKS: none.
*/

Node* filterByPrice( Node* head, int limit )
{
	Node *headF;
	Node *current;
	House house;

	current = head;
	headF = ( Node* )malloc( sizeof( Node ) );
	current = current -> next;

	while( current != NULL )
	{
		if( ( current->price) <= limit ) /*if it is within the range*/
		{
			house = copyDetails( house, current );
			addNode( &headF, house );
    		}
    		/*now p has data from the node current*/

	current = current -> next;
  	}

  	return headF;
}





/*
NAME: flashSale
PURPOSE: Filers the surburb of the houses according to the selected surburb.
IMPORTS: Node* head 
EXPORTS: void
ASSERTIONS:
	PRE: Linked list prices have not been halved.
	POST: Linked list prices have been halved.
REMARKS: none.
*/

void flashSale( Node* head )
{
	Node *current;
	current = head;
	current = current -> next;

	while( current != NULL )
	{
		current->price = current->price >> 1;
		/*price has been halved*/
		current = current -> next;
	}
}






/*
NAME: filterBySurburb
PURPOSE: Filers the surburb of the houses according to the selected surburb.
IMPORTS: Node* head, char city[SUB]
EXPORTS: Node*
ASSERTIONS:
	PRE: Linked list has not been filtered according to the surburb.
	POST: Linked list has been filtered according to the surburb.
REMARKS: none.
*/

Node* filterBySurburb( Node* head, char city[SUB] )
{
	Node *headF;
	Node *current;
	House house;

	current = head;
	headF = ( Node* )malloc( sizeof( Node ) );
	current = current -> next;

	while( current != NULL )
	{
		if( strstr( current->address, city ) && ( strcmp( current->surburb, city)==0 ) ) 
		{
			house = copyDetails( house, current );
			addNode( &headF, house );
    		}
    		/*now p has data from the node current*/

     	current = current -> next;
  	}

  	return headF;
}





/*
NAME: writeFile
PURPOSE: writes information of the linked list into file in the format provided.
IMPORTS: Node* head, char* filename 
EXPORTS: void
ASSERTIONS:
	PRE: File might be empty.
	POST: File contains information of linked list that has been filtered.
REMARKS: none.
*/
void writeFile( Node *head, char *filename )
{
	FILE *file;
	Node *temp;
	temp = head;
	temp = temp -> next;

	file = fopen( filename, "w" );
	while( temp != NULL )
	{
		fprintf( file,"%d,%d,%d,%s.\n", temp->bed, temp->bath, temp->price, temp->address) ;
		temp = temp -> next;
	}
	fclose( file );
}






