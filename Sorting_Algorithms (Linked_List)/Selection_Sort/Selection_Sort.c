#include"customheader.h"

void swap(struct node **ppValue1, struct node **ppValue2)
{
    int iTemp = 0;

    iTemp = (*ppValue1)->iData;
    (*ppValue1)->iData = (*ppValue2)->iData;
    (*ppValue2)->iData = iTemp;
}

void selectionSort(struct node **ppHead)
{
    struct node *pTemp1 = *ppHead;
    struct node *pTemp2 = NULL;
    struct node *pMinNode = NULL;

    while(pTemp1->pNext != NULL)
    {
        pMinNode = pTemp1;
        pTemp2 = pTemp1->pNext;

        while(pTemp2 != NULL)
        {
            if(pMinNode->iData > pTemp2->iData)
                pMinNode = pTemp2;

            pTemp2 = pTemp2->pNext;
        }
        if(pMinNode != pTemp1)
            swap(&pTemp1, &pMinNode);

        pTemp1 = pTemp1->pNext;
    }
}

int main(void)
{
    int iSize = 0, iCnt = 0, iNo = 0;
    struct node *pFirst = NULL;
    
    printf("Enter the number of elements : \n");
    scanf("%d", &iSize);

    printf("Enter the data : \n");
    for(iCnt = 1; iCnt <= iSize; iCnt++)
    {
        scanf("%d", &iNo);
        insertLast(&pFirst, iNo);
    }
    
    selectionSort(&pFirst);

    display(pFirst);

    return 0;
}