#include<stdio.h>
#include<stdlib.h>

void selectionSort(int *Arr, int iLen)
{
    int i = 0, j = 0, iMinIndex = 0, iTemp = 0;

    for(i = 0; i < iLen - 1; i++)
    {
        iMinIndex = i;

        for(j = i + 1; j < iLen; j++)
        {
            if(Arr[j] < Arr[iMinIndex])
            {
                iMinIndex = j;
            }
        }
        
        if(iMinIndex != i)                                  //if smallest number sapdla ch nahi tr ugichch swap kashala karaycha mhnun hi condition takli ahe
        {
            Arr[i] = Arr[i] + Arr[iMinIndex];
            Arr[iMinIndex] = Arr[i] - Arr[iMinIndex];       //swap logic
            Arr[i] = Arr[i] - Arr[iMinIndex];
        }
    }
}

int main(void)
{
    int *Arr = NULL;
    int iSize = 0, i = 0;

    printf("Enter the number of elements : \n");
    scanf("%d", &iSize);

    Arr = (int *)malloc(sizeof(int) * iSize);

    printf("Enter the data : \n");
    for(i = 0; i < iSize; i++)
    {
        scanf("%d", &Arr[i]);
    }

    selectionSort(Arr, iSize);

    printf("Sorted array is : \n");
    for(i = 0; i < iSize; i++)
    {
        printf("%d ", Arr[i]);
    }

    return 0;
}