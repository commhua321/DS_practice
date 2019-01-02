#include <iostream>
using namespace std;
#include <time.h>
#include <sys/timeb.h>
#define MAX 10

void PrintArray(int arr[], int len){
    for(int i = 0 ; i < len ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int* CreateArray(){

    srand((unsigned int)time(NULL));
    int* arr = (int*)malloc(sizeof(int) * MAX);
    for(int i = 0 ; i < MAX ; i++){
        arr[i] = rand() % MAX;
    }
    return arr;
}

//�q�p��j
void Merge(int arr[], int i_start, int j_end, int mid, int* temp){

    int a_start = i_start;
    int a_end = mid;
    int b_start = mid + 1;
    int b_end = j_end;

    //��ܻ��U�Ŷ����h�֭Ӥ���
    int length = 0;

    //�X�֨�Ӧ��ǧǦC
    while(a_start <= a_end && b_start <= b_end){

        if(arr[a_start] < arr[b_start]){
            temp[length] = arr[a_start];
            length++;
            a_start++;
        }
        else{
            temp[length] = arr[b_start];
            length++;
            b_start++;
        }
    }

    //
    while(a_start <= a_end){
        temp[length] = arr[a_start];
        length++;
        a_start++;
    }
    //
    while(b_start <= b_end){
        temp[length] = arr[b_start];
        length++;
        b_start++;
    }

    //���U�Ŷ��ƾ��л\���Ŷ�
    for(int i = 0 ; i < length ; i++){
        arr[i_start + i] = temp[i];
    }
}


void MergeSort(int arr[], int i_start, int j_end, int* temp){

    if(i_start >= j_end){
        return;
    }

    int mid = (i_start + j_end) / 2;
    //����
    //���b��
    MergeSort(arr, i_start, mid, temp);
    //�k�b��
    MergeSort(arr, mid + 1, j_end, temp);
    //�X��
    Merge(arr, i_start, j_end, mid, temp);


}


int main()
{
    int* myArr = CreateArray();
    PrintArray(myArr, MAX);
    //���U�Ŷ�
    int* temp = (int*)malloc(sizeof(int) * MAX);
    MergeSort(myArr, 0, MAX - 1, temp);
    PrintArray(myArr, MAX);

    free(temp);
    free(myArr);

    return 0;
}
