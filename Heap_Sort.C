#include<stdio.h>
#include<conio.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int array[], int n,int i)
{
    int max = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    if(leftChild < n && array[leftChild] > array[max]){
        max = leftChild;
    }

    if(rightChild < n && array[rightChild] > array[max])
    {
        max = rightChild;
    }

    if(max != i){
        swap(&array[i],&array[max]);
        heapify(array, n , max);
    }
}

void HeapSort(int array[], int n)
{
    for(int i=n/2-1; i>=0; i--){
        heapify(array,n,i);
    }

    for(int i=n-1; i>=0; i--){
        swap(&array[0],&array[i]);

        heapify(array,i,0);
    }

}

void display(int array[],int n)
{
    for(int i=0; i<n; i++)
        printf("%d ",array[i]);
    printf("\n");
}

int main()
{
    int array[20];
    int size;

    printf("Enter the Size of Sort: ");
    scanf("%d",&size);

    printf("Enter the element for the sort: ");
    for(int i=0; i<size; i++){
        scanf("%d",&array[i]);
    }
    //int array[] = {11,34,9,5,16,10};
    //int n = sizeof(array) / sizeof(array[0]);

    printf("Original array: ");
    display(array,size);
    HeapSort(array,size);

    printf("Sorted array: ");
    display(array,size);
}