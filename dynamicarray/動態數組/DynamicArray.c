

#include "DynamicArray.h"


//初始化
Dynamic_Array* Init_Array(){
    //申請內存
    Dynamic_Array* myArray = (Dynamic_Array*)malloc(sizeof(Dynamic_Array));
    //初始化
    myArray -> size = 0;
    myArray -> capacity = 30;
    myArray -> pAddr = (int*)malloc(sizeof(int) * myArray -> capacity);
    return myArray;
}

//插入
void PushBack_Array(Dynamic_Array* arr, int value){
    if(arr == NULL){
        return;
    }
    //判斷空間是否足夠
    if(arr -> size == arr -> capacity){

        //第一步，申請一塊更大的內存空間，新空間是舊空間的兩倍
        int* newSpace = (int*)malloc(sizeof(int) * arr -> capacity * 2);
        //第二步，拷貝數據到新空間
        memcpy(newSpace, arr -> pAddr, arr -> capacity * sizeof(int));
        //第三步，釋放舊空間的內存
        free(arr -> pAddr);

        //更新容量
        arr -> capacity = arr -> capacity * 2;
        arr -> pAddr = newSpace;
    }

    //插入新元素
    arr -> pAddr[arr -> size] = value;
    arr -> size++;
}

//根據位置刪除
void RemoveByPos_Array(Dynamic_Array* arr, int pos){
    if(arr == NULL){
        return;
    }

    //判斷位置是否有效
    if(pos < 0 || pos >= arr -> size){
        return;
    }

    //刪除元素
    for(int i = pos ; i < arr -> size - 1; i++){
        arr -> pAddr[i] = arr -> pAddr[i + 1];
    }
    arr -> size--;
}

//根據值刪除value第一次出現的位置
void RemoveByValue_Array(Dynamic_Array* arr, int value){
    if(arr == NULL){
        return;
    }

    //找到值的位置
    int pos = Find_Array(arr, value);

    //根據位置刪除
    RemoveByPos_Array(arr, pos);

}

//查找
int Find_Array(Dynamic_Array* arr, int value){
    if(arr == NULL){
        return -1;
    }

    //找到值的位置
    int pos = -1;
    for(int i = 0 ; i < arr -> size ; i++){
        if(arr -> pAddr[i] == value){
            pos = i;
            break;
        }
    }
    return pos;
}

//打印
void Print_Array(Dynamic_Array* arr){
    if(arr == NULL){
        return;
    }
    for(int i = 0 ; i < arr -> size ; i++){
        printf("%d ", arr -> pAddr[i]);
    }
    printf("\n");
}

//釋放動態數組的內存
void FreeSpace_Array(Dynamic_Array* arr){
    if(arr == NULL){
        return;
    }

    if(arr -> pAddr != NULL){
        free(arr -> pAddr);
    }
    free(arr);
}

//清空數組
void Clear_Array(Dynamic_Array* arr){
    if(arr == NULL){
        return;
    }
    //pAddr -> 空間
    arr -> size = 0;
}

//獲得動態數組容量
int Capacity_Array(Dynamic_Array* arr){
    if(arr == NULL){
        return -1;
    }
    return arr -> capacity;
}

//獲得動態數據當前元素個數
int Size_Array(Dynamic_Array* arr){
    if(arr == NULL){
        return -1;
    }
    return arr -> size;
}

//根據位置獲得某個位置元素
int At_Array(Dynamic_Array* arr, int pos){

    return arr -> pAddr[pos];
}
