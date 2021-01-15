#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
    int hp;
    int atk;
    int def;
    int med;
    char name[49];
    void* one;
    struct Node* next;
}Node;

typedef struct Person{
    int hp;
    int atk;
    int def;
    int med;
    char name[49];

}Person;


void addNode( Node **head, Person p)
{
Node* new = ( Node* )malloc( sizeof( Node ) );
Person *person;
Node *temp;

new -> one = &p;
person = new -> one;
strcpy( new->name, person->name );
new -> hp = person -> hp;
new -> atk = person -> atk;
new -> def = person -> def;
new -> med = person -> med;
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


Person readHero(char* filename)
{
FILE* read;
char input[100];
char* token;
Person p;

read = fopen( filename, "r" );
if( read == NULL)
{
  printf("Insert another file.\n");

}
else
{
  fgets( input, 100, read );
 
/*HP, ATK, DEF, MED, Name
 20,6,3,1,Arlen*/
    token = strtok(input, ",");
p.hp = atoi(token);
token = strtok( NULL, "," );
p.atk = atoi(token);
token = strtok( NULL, "," );
p.def = atoi(token);
token = strtok( NULL, "," );
p.med = atoi(token);
token = strtok( NULL, "," );
strcpy( p.name, token);



}
fclose(read);
return p;
}




Node* read1(char* filename)
{
FILE* read;
char input[100];
char* token;
Person p;
Node* head;
head = (  Node* )malloc( sizeof( Node ) );
read = fopen( filename, "r" );
if( read == NULL)
{
      printf("Insert another file.\n");
}
else
{

  while( fgets( input, 100, read ) && strlen( input ) != 0 && strcmp( input, "\n" ) != 0)
  {
/*HP, ATK, DEF, MED, Name
20,6,3,1,Arlen*/
    token = strtok(input, ",");
p.hp = atoi(token);
token = strtok( NULL, "," );
p.atk = atoi(token);
token = strtok( NULL, "," );
p.def = atoi(token);
token = strtok( NULL, "," );
p.med = atoi(token);
token = strtok( NULL, "\n" );
strcpy( p.name, token);

/*printf("med: %d", p.med);*/
addNode( &head, p);
  }

}


fclose(read);
return head;
}

void printHero(Person p)
{
printf("HERO NAME: %s hp: %d, atk: %d, def: %d, med: %d", p.name, p.hp, p.atk, p.def, p.med);
}

void printList( Node *head )
{
Node *temp;
temp = head;
printf( "\n" );
temp = temp -> next;
 
if( temp == NULL )
{
printf( "The list is empty");
}
else
{
printf("Enemies:\n");
while( temp != NULL )
{

printf("%s -------> hp: %d, atk: %d, def: %d\n", temp->name, temp->hp, temp->atk, temp->def);
    temp = temp-> next;
}
 
}
}


int main(int argc, char *argv[])
{
    FILE* f1;
FILE* f2;
Node *head;
Person hero;

/*opening the hero txt*/
f1 = fopen(argv[1], "r");
hero = readHero(argv[1]);
printHero(hero);


/*reading enemy.txt*/
f2 = fopen(argv[2], "r");
head = (  Node* )malloc( sizeof( Node ) );

/*loading the linkedlist with enemy.txt*/
        head = read1(argv[2]);

/*printing the enemy from the list*/
printList(head);
return 0;
}

	

