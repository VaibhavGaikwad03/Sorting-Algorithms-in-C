#include<stdio.h>

typedef int BOOL;

#define TRUE 1
#define FALSE 0

struct node
{
    int iData;
    struct node *pNext;
};

int countNodes(struct node *);
void display(struct node *);
void insertFirst(struct node **, int);
void insertLast(struct node **, int);
void insertAtPosition(struct node **, int, int);
int deleteFirst(struct node **);
int deleteLast(struct node **);
int deleteAtPosition(struct node **, int);
int searchFirstOccurrence(struct node *, int);
int searchLastOccurrence(struct node *, int);
int searchAllOccurrences(struct node *, int);
void concatList(struct node **, struct node **);
void concatAtPosition(struct node **, struct node **, int);
void physicalReverse(struct node **);
void reverseDisplay(struct node *);
void deleteAll(struct node **);
