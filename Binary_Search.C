#include<stdio.h>
#include<conio.h>

int main()
{
    int size,first,last,middle,sElement;
    int i,list[15];
    printf("Enter the size of the array: ");
    scanf("%d",&size);

    printf("Enter the element in array: ");
    for(i=0; i<size; i++)
    {
        scanf("%d",&list[i]);
    }

    printf("Enter the value you want to search: ");
    scanf("%d",&sElement);

    first = 0;
    last = size - 1;
    middle = (first+last)/2;

    while(first <= last){
        if(list[middle] < sElement)
        {
            first = middle + 1;
        }
        else if(list[middle] == sElement){
            printf("Element found at %d index.\n",middle+1);
            break;
        }
        else{
            last = middle - 1;
        }
        middle = (first+last)/2;
    }
    if(first > last)
    {
        printf("Element not found in the list\n");
    }
}