#include<stdio.h>
#include<stdlib.h>

void swap(int *piNo1, int *piNo2)
{
    *piNo1 = *piNo1 + *piNo2;
    *piNo2 = *piNo1 - *piNo2;
    *piNo1 = *piNo1 - *piNo2;
}

void selectionSort(int *pArr, int iLen)
{   
    int iCnt1 = 0, iCnt2 = 0, iMinIndex = 0;

    for(iCnt1 = 0; iCnt1 < iLen - 1; iCnt1++)
    {
        iMinIndex = iCnt1;

        for(iCnt2 = iCnt1 + 1; iCnt2 < iLen; iCnt2++)
        {
            if(pArr[iMinIndex] > pArr[iCnt2])
                iMinIndex = iCnt2;
        }
        if(iMinIndex != iCnt1)
            swap(&pArr[iCnt1], &pArr[iMinIndex]);
    }
}

int main(void)
{
    int *Arr = NULL, iSize = 0, iCnt = 0;

    printf("Enter the number of elements : \n");
    scanf("%d", &iSize);

    Arr = (int *)malloc(sizeof(int) * iSize);

    printf("Enter data into array : \n");
    for(iCnt = 0; iCnt < iSize; iCnt++)
        scanf("%d", &Arr[iCnt]);

    selectionSort(Arr, iSize);

    for(iCnt = 0; iCnt < iSize; iCnt++)
        printf("%d ", Arr[iCnt]);

    return 0;
}