/*
** This enum was mainly crteated to replace the eight types of 
** brackets with a specific name
** Unfortunately, could not it accordingly
*/

typedef enum
{
    openRound = 20,
    closeRound = -19,
    openSquare = 10,
    closeSquare = -9,
     openCurly = 40,
     closeCurly = -39,
     openTri = 50,
     closeTri = -49

}brackType;

typedef struct bracs{
    char type;
    int  position;
    brackType style;
}bracs;

typedef struct linkedListNode{
    void* data;
    bracs* bracket;
    struct linkedListNode* next;
    struct linkedListNode* prev;

}linkedListNode;

typedef struct {
    int size;
     linkedListNode* head;
     linkedListNode* tail;

}LinkedList;

typedef void fPrintNode( linkedListNode* node);
typedef void fFreeNode( linkedListNode* node);

LinkedList* createLinkedList();
void insertFirst(LinkedList* listing , void* entry);
void* removeFirst (LinkedList* listing);
void insertLast(LinkedList* listing , void* entry);
void* removeLast (LinkedList* listing);
void printLinkedList (LinkedList* listing , fPrintNode funcPointer);

void freeList (LinkedList* listing, fFreeNode functPointer);
