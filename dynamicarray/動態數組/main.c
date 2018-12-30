#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DynamicArray.h"

void test(){

    //��l�ưʺA�Ʋ�
    Dynamic_Array* myArray = Init_Array();
    //���L�e�q
    printf("�Ʋծe�q: %d\n", Capacity_Array(myArray));
    printf("�Ʋդj�p: %d\n", Size_Array(myArray));
    //���J����
    for(int i = 0 ; i < 10 ; i++){
        PushBack_Array(myArray, i);
    }
    printf("�Ʋծe�q: %d\n", Capacity_Array(myArray));
    printf("�Ʋդj�p: %d\n", Size_Array(myArray));
    //���L
    Print_Array(myArray);

    //�R��
    RemoveByPos_Array(myArray, 0);
    RemoveByValue_Array(myArray, 27);
    //���L
    Print_Array(myArray);

    //�d��5�Ӧ�m
    int pos = Find_Array(myArray, 5);
    printf("5�d���: pos:%d %d\n", pos, At_Array(myArray, pos));

    //�P��
    FreeSpace_Array(myArray);
}



int main()
{
    test();
    return 0;
}
