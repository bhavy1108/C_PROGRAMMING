#ifndef LIST_H
#define LIST_H

#define ADD 101 /*address limit*/
#define SUB 30 /*sub limit*/
#define ALPHA 32 /*for character change*/
#define LIMITR 200 /*READ limit*/


typedef struct House
{
	int bed;
	int bath;
	int price;
  	char address[ADD];
  	char surburb[SUB];
  
}House;

typedef struct Node
{
  	void* v;
  	int bed;
  	int bath;
  	int price;
  	char address[ADD];
  	char surburb[SUB];
  	struct Node* next;
}Node;


void capitaliseString( char input[] );
House copyDetails( House p, Node *current );
void addNode( Node **head, House hh );
Node* readFile( char *filename );
void printNode( Node *head );
Node* filterByPrice( Node *head, int limit );
void flashSale( Node *head );
Node* filterBySurburb( Node *head, char city[SUB] );
void writeFile( Node *head, char *filename );

#endif

