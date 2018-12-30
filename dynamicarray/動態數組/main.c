#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DynamicArray.h"

void test(){

    //初始化動態數組
    Dynamic_Array* myArray = Init_Array();
    //打印容量
    printf("數組容量: %d\n", Capacity_Array(myArray));
    printf("數組大小: %d\n", Size_Array(myArray));
    //插入元素
    for(int i = 0 ; i < 10 ; i++){
        PushBack_Array(myArray, i);
    }
    printf("數組容量: %d\n", Capacity_Array(myArray));
    printf("數組大小: %d\n", Size_Array(myArray));
    //打印
    Print_Array(myArray);

    //刪除
    RemoveByPos_Array(myArray, 0);
    RemoveByValue_Array(myArray, 27);
    //打印
    Print_Array(myArray);

    //查找5個位置
    int pos = Find_Array(myArray, 5);
    printf("5查找到: pos:%d %d\n", pos, At_Array(myArray, pos));

    //銷毀
    FreeSpace_Array(myArray);
}



int main()
{
    test();
    return 0;
}
