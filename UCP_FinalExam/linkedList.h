

typedef struct linkedListNode{
    void* data;
    struct  battle* details;
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
