#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

/* create node function*/
static linkedListNode* creatingNode(void* data)
{
    linkedListNode* newNode = (linkedListNode*)malloc(sizeof(linkedListNode));
    newNode ->data = data;
    newNode -> next = NULL;
    newNode ->prev = NULL;
    return newNode;
}

/* creating empty linked list*/
LinkedList* createLinkedList()
{
    LinkedList* listing = (LinkedList*)malloc (sizeof(LinkedList));
    listing-> head = NULL;
    listing-> tail = NULL;
    listing -> size = 0;
    return listing;
}

/*inserting an element at the start*/
void insertFirst(LinkedList* listing , void* entry)
{
    linkedListNode* newNode = creatingNode(entry);
    newNode -> next = listing->head;
    
    if (newNode -> next == NULL)
    {
        /* head and tail points to new node of list is empty*/
        listing -> head = newNode;
        listing -> tail = newNode;
    }
    else 
    {
        /*not empty , the pointer reconnects*/
        newNode -> prev = NULL;
        listing->head -> prev = newNode;
        listing -> head = newNode;

    }
    listing-> size++;
}

/* removing element at start*/
void* removeFirst (LinkedList* listing)
{
    void* entry = NULL;
    linkedListNode* temp = listing ->  head;

    /* receive data of the first or head node*/

    entry = listing -> head -> data;

    /* removing head*/
    listing -> head = listing -> head ->next;

    /* removing tail also */
     if(listing -> head == NULL)
     {
         listing -> tail = NULL;
     }
     else
     {
         
         listing -> head -> prev = NULL;
     }
     /* free node that has been removed */
     free(temp);
     temp  = NULL;
     listing -> size--;

     return entry;
}

 /*function to insert an element at the en of the linked list.*/

 void insertLast(LinkedList* listing , void* entry)
 {
     /* creating new node*/
     linkedListNode* newTail = creatingNode(entry);
     newTail -> prev = listing -> tail; 
 
    /*if list is not full , set head and tail to the new node*/
    if (newTail -> prev == NULL)
    {
        listing -> head = newTail;
        listing -> tail = newTail;
    }
    else
    {
        
        listing ->tail->next = newTail;
        listing -> tail = newTail; 
    }

}

/*remove an element at the end of the linked list */

void* removeLast (LinkedList* listing)
{
    void* entry;
    linkedListNode* temp = listing -> tail;

    /* receiving data of the last element */

    entry = listing ->tail->data;
     
    /* remove tail */
    listing -> tail = listing -> tail -> prev;

    if(listing-> tail == NULL)
    {
        listing -> head = NULL;
    }
    else
    {
        listing-> tail -> next = NULL;
    }
    free(temp);
    temp = NULL;
    return entry;
}

void printLinkedList (LinkedList* listing , fPrintNode funcPointer)
{
    linkedListNode* curr = listing -> head;
    /*loop through all nodes, print each item*/

    while (curr != NULL)
    {
        (*funcPointer)(curr);
        curr = curr -> next;
    }
    printf("\n");
}

void freeList (LinkedList* listing, fFreeNode functPointer)
{
    linkedListNode* curr = listing->head;
    linkedListNode* prevNode;

    /* free each node by looping from each node*/

    while (curr  != NULL)
    {
        prevNode = curr;
        curr =  curr -> next;
        (*functPointer)(prevNode);

    }
    free(listing);
    listing = NULL;
}