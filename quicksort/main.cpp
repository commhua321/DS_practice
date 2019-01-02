#include <iostream>

using namespace std;

void PrintArray(int arr[], int len){
    for(int i = 0 ; i < len ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

//�ֳt�Ƨ�
void Quicksort(int arr[], int i_start, int j_end){

    int i = i_start;
    int j = j_end;
    //��Ǽ�
    int temp = arr[i_start];
    if(i < j){
        while(i < j){

            //�q�k�V���h����ǼƤp��
            while(i < j && arr[j] >= temp){
                j--;
            }

            //��|
            if(i < j){
                arr[i] = arr[j];
                i++;
            }

            //�q���V�k�A����ǼƤj����
            while(i < j && arr[i] < temp){
                i++;
            }

            //��|
            if(i < j){
                arr[j] = arr[i];
                j--;
            }

        }

        //���ǼƩ��i��m
        arr[i] = temp;
        //�索�b�����i��ֳt�Ƨ�
        Quicksort(arr, i_start, i - 1);
        //��k�b�����i��ֳt�Ƨ�
        Quicksort(arr, i + 1, j_end);
    }



}



int main()
{

    int myArr[] = {4, 2, 8, 0, 5, 7, 1, 3, 9};
    int len = sizeof(myArr) / sizeof(int);
    PrintArray(myArr, len);
    Quicksort(myArr, 0, len - 1);
    PrintArray(myArr, len);


    return 0;
}
