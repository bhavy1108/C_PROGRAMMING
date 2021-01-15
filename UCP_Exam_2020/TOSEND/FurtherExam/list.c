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
      			input[k] = input[k] - 32;    
    		}
    		else
    		{
      			input[k] = input[k];  
    		}
  	}
 
}


/*
NAME: average
PURPOSE: calculates average of 3 marks.
IMPORTS: int maths, int science, int english
EXPORTS: int a
ASSERTIONS:
	PRE: obtains 3 marks
	POST: returns an average of the three
REMARKS: none.
*/

int average( int maths, int science, int english)
{
	int a;
	a = ( maths + science + english) / THREE;
	return a;
}






/*
NAME: addNode
PURPOSE: adds node to a linkedlist
IMPORTS: Node **head, Student s
EXPORTS: void
ASSERTIONS:
	PRE: linkedlist may be empty
	POST: adds a node to a linkedlist
REMARKS: none.
*/

void addNode( Node **head, Student s)
{
	Node* new = ( Node* )malloc( sizeof( Node ) );
	Student *student;
	Node *temp;

	new -> v = &s;
	student = new -> v;
	strcpy( new->name, student->name );
	new -> math = student -> math; 
	new -> eng = student -> eng; 
	new -> sci = student -> sci;
	new -> avg = student -> avg;
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

Node* readFile( char* filename )
{
	FILE* read;
	char input[LIMITR];
	Student s;
	char* token;
	Node* head;
		
	head = (  Node* )malloc( sizeof( Node ) );
	read = fopen( filename, "r" );
	if( read == NULL)
	{
  		fprintf( stderr, "THIS FILE CANNOT BE OPENED AND READ!!\n" );
		head = NULL;
	}
	else
	{
  		while( fgets( input, LIMITR, read ) && strlen( input ) != 0 && strcmp( input, "\n" ) != 0)
  		{
    			token = strtok( input, "," );
    			strcpy( s.name, input );
			token = strtok( NULL, "," );
    			s.math = atoi( token );
			token = strtok( NULL, "," );
    			s.sci = atoi( token );
    			token = strtok( NULL, "\n" );
    			s.eng = atoi( token );
    			s.avg = average( s.math, s.sci, s.eng);                     
			addNode( &head, s);
                        
		}
	}
	fclose( read );
	return head;
}






/*
NAME: markToGrade
PURPOSE: converts mark to a grade(char)
IMPORTS: int mark
EXPORTS: char c
ASSERTIONS:
	PRE: mark is obtained.
	POST: mark is converted to grade.
REMARKS: none.
*/

char markToGrade( int mark )
{
	char c; 

	if( mark >= 90 )
	{
		c = 'A';
	}
	else if( mark >= 80 && mark < 90)
	{
		c = 'B';
	}
	else if( mark >= 70 && mark < 80)
	{
		c = 'C';
	}
	else if( mark >= 60 && mark < 70)
	{
		c = 'D';
	}
	else if( mark >= 50 && mark < 60)
	{
		c = 'E';
	}
	else if( mark >= 0 && mark < 50)
	{
		c = 'F';
	}
	else
	{
		c = '?';
	}

	return c;
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

void writeFile( Node* head, char* filename )
{
	FILE *file;
	Node *temp;
	char m; /*math grade in char*/
	char s;
	char e;
	char a;
	int av;

	temp = head;
	temp = temp -> next;

	file = fopen( filename, "w" );
	while( temp != NULL )
	{
		m = markToGrade( temp -> math );
		s = markToGrade( temp -> sci );
		e = markToGrade( temp -> eng );

		av = average( temp -> math, temp -> sci, temp -> eng);
		a = markToGrade( av );

		fprintf( file,"%s,%c,%c,%c,%c\n", temp -> name, m, s, e, a );

		temp = temp -> next;
	}
	fclose( file );
}






/*
NAME: systemGlitch
PURPOSE: 
IMPORTS: Node *head
EXPORTS: void
ASSERTIONS:
	PRE: marks are equal to input file
	POST: marks are either halved or doubled compared to input file
REMARKS: none.
*/

void systemGlitch(Node *head)
{
	Node *current;
	time_t secs;
	int av;
	
	secs = ( time(NULL) );
	srand(secs);
	current = head;
	current = current -> next;

	while( current != NULL )
	{
		if( ( rand() % TWO ) == ONE )
		{
			current -> math = current -> math >> ONE;
			current -> sci = current -> sci >> ONE;
			current -> eng = current -> eng >> ONE;
			av = average( current -> math, current -> sci, current -> eng);
			current -> avg = av >> ONE;		
		        /*marks have been halved*/
			current = current->next;
		}
		else
		{
			current -> math = current -> math << ONE;
			current -> sci = current -> sci << ONE;
			current -> eng = current -> eng << ONE;
			av = average( current -> math, current -> sci, current -> eng);
			current -> avg = av << ONE;
			/*marks have been doubled*/
			current = current->next;
		}
		
	}
}



