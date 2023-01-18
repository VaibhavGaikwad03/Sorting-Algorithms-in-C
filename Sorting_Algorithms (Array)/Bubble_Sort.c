#include<stdio.h>
#include<stdlib.h>

void swap(int *iValue1, int *iValue2)
{
    *iValue1 = *iValue1 + *iValue2;
    *iValue2 = *iValue1 - *iValue2;
    *iValue1 = *iValue1 - *iValue2;
}

void bubbleSort(int *Arr, int iLen)
{
    int iCnt1 = 0, iCnt2 = 0, iNo_of_Swaps = 0;

    for(iCnt1 = 1; iCnt1 < iLen; iCnt1++)
    {
        for(iCnt2 = 0; iCnt2 < iLen - iCnt1; iCnt2++)
        {
            if(Arr[iCnt2] > Arr[iCnt2 + 1])
            {
                swap(&Arr[iCnt2], &Arr[iCnt2 + 1]);
                ++iNo_of_Swaps;
            }
        }
        if(iNo_of_Swaps == 0)
            break;
    }
}

int main(void)
{
    int *Arr = NULL;
    int iSize = 0, iCnt = 0;

    printf("Enter the number of elements : \n");
    scanf("%d", &iSize);

    Arr = (int *)malloc(sizeof(int) * iSize);


    printf("Enter the data : \n");
    for(iCnt = 0; iCnt < iSize; iCnt++)
        scanf("%d", &Arr[iCnt]);

    bubbleSort(Arr, iSize);

    printf("Data after sorting is : \n");

    for(iCnt = 0; iCnt <  iSize; iCnt++)
        printf("%d ", Arr[iCnt]);

    return 0;
}