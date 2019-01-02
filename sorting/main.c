#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/timeb.h>

#define MAX 30000


long getSystemTime(){

    struct timeb tb;
    ftime(&tb);
    return tb.time * 1000 + tb.millitm;

}




//交換函數
void Swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int flag = 0;//表示沒有排序好
//冒泡排序
void BubbleSort(int arr[], int length){
    for(int i = 0 ; i < length && flag == 0 ; i++){
        flag = 1;//認為已經排序好
        for(int j = length - 1 ; j > i; j--){
            if(arr[j - 1] < arr[j]){
                flag = 0;
                Swap(&arr[j - 1], &arr[j]);
            }
        }
    }
}

//選擇排序
void SelectSort(int arr[], int length){

    //選擇排序記錄最小值的index來減少交換次數
    for(int i = 0 ; i < length ; i++){
        int min = i;
        for(int j = i + 1 ; j < length ; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        if(min != i){
            Swap(&arr[min], &arr[i]);
        }




    }
}


void InsertSort(int arr[], int length){

    int j;
    for(int i = 1 ; i < length ; i++){
        if(arr[i] < arr[i - 1]){
            int temp = arr[i];
            for(j = i - 1 ; j >= 0 && temp < arr[j] ; j--){
                arr[j + 1] = arr[j];
            }
            arr[j + 1] = temp;
        }
    }
}

//從小到大
void ShellSort(int arr[], int length){

    int increasement = length;
    int i, j, k;
    do{
        //確定分組的增量
        increasement = increasement / 3 + 1;
        for(i = 0 ; i < increasement ; i++){
            for(j = i + increasement ; j < length ; j += increasement){


                if(arr[j] < arr[j - increasement]){
                    int temp = arr[j];
                    for(k = j - increasement ; k >= 0 && temp < arr[k] ; k -= increasement){
                        arr[k + increasement] = arr[k];
                    }
                    arr[k + increasement] = temp;
                }
            }

        }

    }while(increasement > 1);

}


//打印函數
void PrintArray(int arr[], int length){
    for(int i = 0 ; i < length ; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}



int main()
{
    int arr[MAX];
    int arr2[MAX];
    int arr3[MAX];
    int arr4[MAX];

    srand((unsigned int)time(NULL));
    for(int i = 0 ; i < MAX ; i++){
        int randNum = rand() % MAX;
        arr[i] = randNum;
        arr2[i] = randNum;
        arr3[i] = randNum;
        arr4[i] = randNum;
    }


    //printf("排序前:\n");
    //PrintArray(arr, MAX);
    long t_start = getSystemTime();
    BubbleSort(arr, MAX);
    long t_end = getSystemTime();
    printf("冒泡排序%d個元素，所需時間:%ld\n", MAX, t_end - t_start);
    //printf("排序後\n");
    //PrintArray(arr, MAX);


    t_start = getSystemTime();
    SelectSort(arr2, MAX);
    t_end = getSystemTime();
    printf("選擇排序%d個元素，所需時間:%ld\n", MAX, t_end - t_start);


    t_start = getSystemTime();
    InsertSort(arr3, MAX);
    t_end = getSystemTime();
    printf("插入排序%d個元素，所需時間:%ld\n", MAX, t_end - t_start);

    t_start = getSystemTime();
    ShellSort(arr4, MAX);
    t_end = getSystemTime();
    printf("希爾排序%d個元素，所需時間:%ld\n", MAX, t_end - t_start);

    return 0;
}
