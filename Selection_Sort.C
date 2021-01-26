#include<stdio.h>
#include<conio.h>
#define SIZE 20

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void)
{
    int size,i,j,list[SIZE];

    printf("Enter the size of the list: ");
    scanf("%d",&size);

    printf("Enter %d integer value: ",size);
    for(i=0; i<size; i++)
    {
        scanf("%d",&list[i]);
    }

    for(i=0; i<size; i++){
        for(j=i+1; j<size; j++){
            if(list[i] > list[j]){
                swap(&list[i],&list[j]);
            }
        }
    }

    printf("List after sort is: ");
    for(i=0; i<size; i++){
        printf("%d  ",list[i]);
    }
}