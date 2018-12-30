#ifndef DYNAMICARRAY_H_INCLUDED
#define DYNAMICARRAY_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//動態數組結構體
typedef struct DYNAMICARRAY{
    int *pAddr;
    int size;
    int capacity;
}Dynamic_Array;

//對結構體操作的函數
//初始化
Dynamic_Array* Init_Array();
//插入
void PushBack_Array(Dynamic_Array* arr, int value);
//根據位置刪除
void RemoveByPos_Array(Dynamic_Array* arr, int pos);
//根據值刪除
void RemoveByValue_Array(Dynamic_Array* arr, int value);
//查找
int Find_Array(Dynamic_Array* arr, int value);
//打印
void Print_Array(Dynamic_Array* arr);
//釋放動態數組的內存
void FreeSpace_Array(Dynamic_Array* arr);

//清空數組
void Clear_Array(Dynamic_Array* arr);
//獲得動態數組容量
int Capacity_Array(Dynamic_Array* arr);
//獲得動態數據當前元素個數
int Size_Array(Dynamic_Array* arr);
//根據位置獲得某個位置元素
int At_Array(Dynamic_Array* arr, int pos);


#endif // DYNAMICARRAY_H_INCLUDED
