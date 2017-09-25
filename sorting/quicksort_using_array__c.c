#include <stdio.h>
#include <stdlib.h>

/*
1. pick last element as pivot
2. partition : put all smaller elements  before pivot, and put all greater elements after pivot
3. sort elements before partition and after partition
*/

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low ; j <= high - 1; j++) {
        if(arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    i++;
    swap(&arr[i],&arr[high]);
    return i;
}

void quicksort(int *arr, int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void printarray(int *arr, int size) {
    printf("array: ");
    for(int i = 0 ; i < size ; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main()
{
    int array[7] = { 1 , 9 , 6 , 54 , 12 , 4 , 7};
    printarray(array,7);
    quicksort(array,0,6);
    printarray(array,7);
    return 0;
}
