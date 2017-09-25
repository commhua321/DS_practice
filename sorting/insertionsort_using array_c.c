#include <stdio.h>
#include <stdlib.h>
void Insertionsort(int *arr, int size){
    for(int i = 1 ; i < size ; i++) {
        int key = arr[i];
        int j = i - 1;

        while(arr[j] > key && j >= 0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void printarray(int *arr, int size) {
    printf("array: ");
    for(int i = 0 ; i < size ; i ++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main()
{
    int array[7] = { 1 , 9 , 6 , 54 , 12 , 4 , 7};
    printarray(array,7);
    Insertionsort(array,7);
    printarray(array,7);
    return 0;
}
