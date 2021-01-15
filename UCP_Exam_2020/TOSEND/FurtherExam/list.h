#ifndef LIST_H
#define LIST_H

#define NAM 51 /*Name limit*/
#define LIMITR 200 /*READ limit*/
#define ONE 1 /*READ limit*/
#define TWO 2 /*READ limit*/
#define THREE 3 /*READ limit*/

typedef struct Marks
{
	int math;
	int sci;
	int eng;
  	int avg; /*for the average*/
  
}Marks;

typedef struct Student
{
	char name[NAM];
	int math;
	int sci;
	int eng;
  	int avg;
  	Marks marking;
}Student;

typedef struct Node
{
  	void* v;
  	int math;
	int sci;
	int eng;
  	int avg;
	char name[NAM];
	Marks marking;	
	struct Node* next;
}Node;


int average( int maths, int science, int english);
void addNode( Node **head, Student s);
Node* readFile( char *filename );
char markToGrade( int mark );
void writeFile( Node* head, char* filename );
void systemGlitch( Node *head);


#endif


