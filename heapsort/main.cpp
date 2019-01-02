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
    @param myArr �a�վ㪺�Ʋ�
    @param index �a�վ㪺���I���U��
    @param len �Ʋժ�����
*/
void HeapAdjust(int arr[], int index, int len){

    //���O�s��e���I���U��
    int i_max = index;
    //�O�s���k�Ĥl���ƲդU��
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

    //��l�ư�
    for(int i = len / 2 - 1 ; i >= 0 ; i--){

        HeapAdjust(myArr, i, len);
    }
    cout << myArr[0] << endl;

    //�洫�ﳻ�����M�̫�@�Ӥ���
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
