#include <iostream>

using namespace std;

void PrintArray(int arr[], int len){
    for(int i = 0 ; i < len ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void MySwap(int arr[], int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}



/*
    @param myArr 帶調整的數組
    @param index 帶調整的結點的下標
    @param len 數組的長度
*/
void HeapAdjust(int arr[], int index, int len){

    //先保存當前結點的下標
    int i_max = index;
    //保存左右孩子的數組下標
    int lchild = index * 2 + 1;
    int rchild = index * 2 + 2;

    if(lchild < len && arr[lchild] > arr[i_max]){
        i_max = lchild;
    }

    if(rchild < len && arr[rchild] > arr[i_max]){
        i_max = rchild;
    }

    if(i_max != index){
        MySwap(arr, i_max, index);
        HeapAdjust(arr, i_max, len);
    }

}

void HeapSort(int myArr[], int len){

    //初始化堆
    for(int i = len / 2 - 1 ; i >= 0 ; i--){

        HeapAdjust(myArr, i, len);
    }
    cout << myArr[0] << endl;

    //交換堆頂元素和最後一個元素
    for(int i = len - 1 ; i >= 0 ; i--){
        MySwap(myArr, 0, i);
        HeapAdjust(myArr, 0, i);

    }
}


int main()
{
    int myArr[] = {4, 2, 8, 0, 5, 7, 1, 3, 9};
    int len = sizeof(myArr) / sizeof(int);
    PrintArray(myArr, len);
    HeapSort(myArr, len);
    PrintArray(myArr, len);

    return 0;
}
