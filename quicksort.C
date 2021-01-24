#include<stdio.h>
#include<conio.h>

#define SIZE 15

void quickSort(int [SIZE],int,int);

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int list[SIZE],size,i;

    printf("Enter the Size of the list: ");
    scanf("%d",&size);

    printf("Enter %d elements in the list: ",size);
    for(i=0; i<size; i++)
    {
        scanf("%d",&list[i]);
    }

    quickSort(list,0,size-1);

    printf("After the Sort %d elements list is: ",size);
    for(i=0; i<size; i++)
    {
        printf("%d  ",list[i]);
    }
}

void quickSort(int list[SIZE], int first, int last)
{
    int pivot,i,j;
    if(first < last)
    {
        pivot = first;
        i = first;
        j = last;
        while(i < j)
        {
            while(list[i] <= list[pivot])
                i++;
            while(list[j] > list[pivot])
                j--;
                if(i<j){
                    swap(&list[i],&list[j]);
            }    
        }
        swap(&list[pivot],&list[j]);
        quickSort(list,first,j-1);
        quickSort(list,j+1,last);
    }
}