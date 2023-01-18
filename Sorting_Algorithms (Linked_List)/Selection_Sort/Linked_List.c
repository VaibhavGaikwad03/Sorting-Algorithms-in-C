#include"custom_header.h"
#include<malloc.h>

int countNodes(struct node *pHead)
{
    int iCount = 0;

    while(pHead != NULL)
    {
        iCount++;
        pHead = pHead->pNext;
    }

    return iCount;
}

void display(struct node *pHead)
{
    if(pHead == NULL)
    {
        printf("\nList is empty.\n");
        return;
    }

    printf("\nData from the linked list : \n");

    while(pHead != NULL)
    {
        printf("|%d|->", pHead->iData);
        pHead = pHead->pNext;
    }
    printf("NULL\n");
}

void insertFirst(struct node ** ppHead, int iNo)
{
    struct node * pNewNode = NULL;
    pNewNode = (struct node *)malloc(sizeof(struct node));

    pNewNode->iData = iNo;
    pNewNode->pNext = *ppHead;
    *ppHead = pNewNode;
}

void insertLast(struct node ** ppHead, int iNo)
{
    struct node *pNewNode = NULL;
    struct node *pTemp = NULL;

    pNewNode = (struct node *)malloc(sizeof(struct node));

    pNewNode->iData = iNo;
    pNewNode->pNext = NULL;

    if(*ppHead == NULL)
    {
        *ppHead = pNewNode;
    }
    else
    {
        pTemp = *ppHead;

        while(pTemp->pNext != NULL)
        {
            pTemp = pTemp->pNext;
        }
        pTemp->pNext = pNewNode;
    }
}

void insertAtPosition(struct node **ppHead, int iNo, int iPos)
{
    struct node *pTemp = NULL;
    struct node *pNewNode = NULL;
    int i = 0, iCount = 0;

    iCount = countNodes(*ppHead);

    if(iPos < 1 || iPos > iCount + 1)
        return;

    if(iPos == 1)
    {   
        insertFirst(ppHead, iNo);
        return;
    }
    
    pTemp = *ppHead;
    pNewNode = (struct node*)malloc(sizeof(struct node));
    pNewNode->iData = iNo;
    pNewNode->pNext = NULL;

    for(i = 1; i < iPos - 1; i++)
    {
        pTemp = pTemp->pNext;
    }
    pNewNode->pNext = pTemp->pNext;
    pTemp->pNext = pNewNode;
}

int deleteFirst(struct node **ppHead)
{
    int iDel = 0;
    struct node *pTemp = NULL;

    if(*ppHead == NULL)
    {
        return -1;
    }

    pTemp = *ppHead;
    *ppHead = (*ppHead)->pNext;
    iDel = pTemp->iData;
    pTemp->pNext = NULL;
    free(pTemp);
    pTemp = NULL;

    return iDel;
}

int deleteLast(struct node **ppHead)
{
    int iDel = 0;
    struct node *pTemp = NULL;

    if(*ppHead == NULL)
    {
        return -1;
    }

    if((*ppHead)->pNext == NULL)
    {
        iDel = (*ppHead)->iData;
        free(*ppHead);
        *ppHead = NULL;
    }
    else
    {
        pTemp = *ppHead;

        while(pTemp->pNext->pNext != NULL)
        {
            pTemp = pTemp->pNext;
        }
        iDel = pTemp->pNext->iData;
        free(pTemp->pNext);
        pTemp->pNext = NULL;
    }

    return iDel;
}

int deleteAtPosition(struct node **ppHead, int iPos)
{
    int i = 0, iDelData = 0, iCount = 0;
    struct node *pTemp1 = NULL;
    struct node *pTemp2 = NULL;

    iCount = countNodes(*ppHead);

    if(iPos < 1 || iPos > iCount)
    {
        return -1;
    }

    if(iPos == 1)
    {
        return deleteFirst(ppHead);
    }

    pTemp1 = *ppHead;

    for(i = 1; i < iPos - 1; i++)
    {
        pTemp1 = pTemp1->pNext;
    }

    pTemp2 = pTemp1->pNext;
    pTemp1->pNext = pTemp2->pNext;
    iDelData = pTemp2->iData;
    pTemp2->pNext = NULL;
    free(pTemp2);
    pTemp2 = NULL;

    return iDelData;
}

int searchFirstOccurrence(struct node *pHead, int iKey)
{
    int iCountPos = 0;

    while(pHead != NULL)
    {   
        iCountPos++;
        if(pHead->iData == iKey)
        {
            break;
        }
        pHead = pHead->pNext;
    }
    
    if(pHead == NULL)
    {
        iCountPos = 0;
    }
    
    return iCountPos;
}

int searchLastOccurrence(struct node *pHead, int iKey)
{
    int iCountPos = 0, iReturnPos = 0;

    while(pHead != NULL)
    {   
        iCountPos++;
        if(pHead->iData == iKey)
        {
            iReturnPos = iCountPos;
        }
        pHead = pHead->pNext;
    }
    return iReturnPos;
}

int searchAllOccurrences(struct node *pHead, int iKey)
{
    int iCountOcc = 0;

    while(pHead != NULL)
    {   
        if(pHead->iData == iKey)
        {
            iCountOcc++;
        }
        pHead = pHead->pNext;   
    }
    return iCountOcc;
}

void concatList(struct node **ppHead1, struct node **ppHead2)
{
    struct node *pTemp = NULL;

    if(*ppHead2 == NULL)
    {
        return;
    }
    if(*ppHead1 == NULL)
    {
        *ppHead1 = *ppHead2;
        *ppHead2 = NULL;

        return;
    }
    
    pTemp = *ppHead1;

    while(pTemp->pNext != NULL)
    {
        pTemp = pTemp->pNext;
    }
    pTemp->pNext = *ppHead2;
    *ppHead2 = NULL;
}

void concatAtPosition(struct node **ppHead1, struct node **ppHead2, int iPos)
{
    int iCount = 0, i = 0;
    struct node *pTemp1 = NULL;
    struct node *pTemp2 = NULL;

    iCount = countNodes(*ppHead1);

    if(iPos < 1 || iPos > iCount + 1)
    {
        printf("Position is Invalid\n");
        return;
    }    

    if(*ppHead2 == NULL)
        return;

    if(iPos == 1)
    {
        concatList(ppHead2, ppHead1);
        *ppHead1 = *ppHead2;
        *ppHead2 = NULL;

        return;
    }

    pTemp1 = *ppHead1;

    for(i = 1; i < iPos - 1; i++)
    {
        pTemp1 = pTemp1->pNext;
    }

    pTemp2 = *ppHead2;

    while(pTemp2->pNext != NULL)
    {
        pTemp2 = pTemp2->pNext;
    }

    pTemp2->pNext = pTemp1->pNext;
    pTemp1->pNext = *ppHead2;

    *ppHead2 = pTemp1 = pTemp2 = NULL;
}

void physicalReverse(struct node **ppHead)
{
    struct node *pPrev = NULL;
    struct node *pCurrent = *ppHead;
    struct node * pNext = NULL;

    while(pCurrent != NULL)
    {
        pNext = pCurrent->pNext;
        pCurrent->pNext = pPrev;
        pPrev = pCurrent;
        pCurrent = pNext;
    }
    *ppHead = pPrev;
}

void reverseDisplay(struct node *pHead)
{
    if(pHead == NULL)
    {
        printf("Linked List is empty!!\n");
        return;
    }

    physicalReverse(&pHead);
    display(pHead);
    physicalReverse(&pHead);
}

void deleteAll(struct node **ppHead)
{
    struct node *pTemp = *ppHead;

    while(pTemp != NULL)
    {
        *ppHead = pTemp->pNext;
        pTemp->pNext = NULL;
        free(pTemp);
        pTemp = *ppHead;
    }
}