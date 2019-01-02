#include <iostream>

using namespace std;

void PrintArray(int arr[], int len){
    for(int i = 0 ; i < len ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

//е硉逼
void Quicksort(int arr[], int i_start, int j_end){

    int i = i_start;
    int j = j_end;
    //膀非计
    int temp = arr[i_start];
    if(i < j){
        while(i < j){

            //眖オтゑ膀非计
            while(i < j && arr[j] >= temp){
                j--;
            }

            //恶
            if(i < j){
                arr[i] = arr[j];
                i++;
            }

            //眖オтゑ膀非计计
            while(i < j && arr[i] < temp){
                i++;
            }

            //恶
            if(i < j){
                arr[j] = arr[i];
                j--;
            }

        }

        //р膀非计i竚
        arr[i] = temp;
        //癸オ场だ秈︽е硉逼
        Quicksort(arr, i_start, i - 1);
        //癸场だ秈︽е硉逼
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
