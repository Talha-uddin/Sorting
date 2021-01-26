#include<stdio.h>
#include<conio.h>


void Adjust(int Heap_of_Numbers[],int i)
{
    int j,copy,number;
    int reference = 1;

    number = Heap_of_Numbers[0];
    while(2*i <= number && reference == 1)
    {
        j = 2 * i;
        if(j + 1 <= number && Heap_of_Numbers[j+1] > Heap_of_Numbers[j]){
            j = j + 1;
            if(Heap_of_Numbers[j] < Heap_of_Numbers[i]){
                reference = 0;
            }
            else{
                copy = Heap_of_Numbers[i];
                Heap_of_Numbers[i] = Heap_of_Numbers[j];
                Heap_of_Numbers[j] = copy;
                i = j;
            }
        }
    }
}

void Make_Heap(int heap[])
{
    int i;
    int Number_of_Elements;

    Number_of_Elements = heap[0];
    for(i=Number_of_Elements / 2; i>=1; i--){
        Adjust(heap,i);
    }
}

int main(void)
{
    int heap[30];
    int size;
    int i,lastElement,copyVariable;

    printf("Enter number of elements present in the Unsorted Array: ");
    scanf("%d",&size);

    printf("Enter the Member of array one by one: ");
    for(i=1; i<size; i++){
        scanf("%d",&heap[i]);
    }

    heap[0] = size;
    Make_Heap(heap);

    while(heap[0] > 1)
    {
        lastElement = heap[0];
        copyVariable = heap[1];
        heap[1] = heap[lastElement];
        heap[lastElement] = copyVariable;
        heap[0]--;
        Adjust(heap,1);
    }
    printf("Sorted Array: ");
    for(i=0; i<size; i++){
        printf("%d",&heap[i]);
    }
}
