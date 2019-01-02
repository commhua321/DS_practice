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




//�洫���
void Swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int flag = 0;//��ܨS���ƧǦn
//�_�w�Ƨ�
void BubbleSort(int arr[], int length){
    for(int i = 0 ; i < length && flag == 0 ; i++){
        flag = 1;//�{���w�g�ƧǦn
        for(int j = length - 1 ; j > i; j--){
            if(arr[j - 1] < arr[j]){
                flag = 0;
                Swap(&arr[j - 1], &arr[j]);
            }
        }
    }
}

//��ܱƧ�
void SelectSort(int arr[], int length){

    //��ܱƧǰO���̤p�Ȫ�index�Ӵ�֥洫����
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

//�q�p��j
void ShellSort(int arr[], int length){

    int increasement = length;
    int i, j, k;
    do{
        //�T�w���ժ��W�q
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


//���L���
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


    //printf("�Ƨǫe:\n");
    //PrintArray(arr, MAX);
    long t_start = getSystemTime();
    BubbleSort(arr, MAX);
    long t_end = getSystemTime();
    printf("�_�w�Ƨ�%d�Ӥ����A�һݮɶ�:%ld\n", MAX, t_end - t_start);
    //printf("�Ƨǫ�\n");
    //PrintArray(arr, MAX);


    t_start = getSystemTime();
    SelectSort(arr2, MAX);
    t_end = getSystemTime();
    printf("��ܱƧ�%d�Ӥ����A�һݮɶ�:%ld\n", MAX, t_end - t_start);


    t_start = getSystemTime();
    InsertSort(arr3, MAX);
    t_end = getSystemTime();
    printf("���J�Ƨ�%d�Ӥ����A�һݮɶ�:%ld\n", MAX, t_end - t_start);

    t_start = getSystemTime();
    ShellSort(arr4, MAX);
    t_end = getSystemTime();
    printf("�ƺ��Ƨ�%d�Ӥ����A�һݮɶ�:%ld\n", MAX, t_end - t_start);

    return 0;
}
