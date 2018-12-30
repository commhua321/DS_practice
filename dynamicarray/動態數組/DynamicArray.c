

#include "DynamicArray.h"


//��l��
Dynamic_Array* Init_Array(){
    //�ӽФ��s
    Dynamic_Array* myArray = (Dynamic_Array*)malloc(sizeof(Dynamic_Array));
    //��l��
    myArray -> size = 0;
    myArray -> capacity = 30;
    myArray -> pAddr = (int*)malloc(sizeof(int) * myArray -> capacity);
    return myArray;
}

//���J
void PushBack_Array(Dynamic_Array* arr, int value){
    if(arr == NULL){
        return;
    }
    //�P�_�Ŷ��O�_����
    if(arr -> size == arr -> capacity){

        //�Ĥ@�B�A�ӽФ@����j�����s�Ŷ��A�s�Ŷ��O�ªŶ����⭿
        int* newSpace = (int*)malloc(sizeof(int) * arr -> capacity * 2);
        //�ĤG�B�A�����ƾڨ�s�Ŷ�
        memcpy(newSpace, arr -> pAddr, arr -> capacity * sizeof(int));
        //�ĤT�B�A�����ªŶ������s
        free(arr -> pAddr);

        //��s�e�q
        arr -> capacity = arr -> capacity * 2;
        arr -> pAddr = newSpace;
    }

    //���J�s����
    arr -> pAddr[arr -> size] = value;
    arr -> size++;
}

//�ھڦ�m�R��
void RemoveByPos_Array(Dynamic_Array* arr, int pos){
    if(arr == NULL){
        return;
    }

    //�P�_��m�O�_����
    if(pos < 0 || pos >= arr -> size){
        return;
    }

    //�R������
    for(int i = pos ; i < arr -> size - 1; i++){
        arr -> pAddr[i] = arr -> pAddr[i + 1];
    }
    arr -> size--;
}

//�ھڭȧR��value�Ĥ@���X�{����m
void RemoveByValue_Array(Dynamic_Array* arr, int value){
    if(arr == NULL){
        return;
    }

    //���Ȫ���m
    int pos = Find_Array(arr, value);

    //�ھڦ�m�R��
    RemoveByPos_Array(arr, pos);

}

//�d��
int Find_Array(Dynamic_Array* arr, int value){
    if(arr == NULL){
        return -1;
    }

    //���Ȫ���m
    int pos = -1;
    for(int i = 0 ; i < arr -> size ; i++){
        if(arr -> pAddr[i] == value){
            pos = i;
            break;
        }
    }
    return pos;
}

//���L
void Print_Array(Dynamic_Array* arr){
    if(arr == NULL){
        return;
    }
    for(int i = 0 ; i < arr -> size ; i++){
        printf("%d ", arr -> pAddr[i]);
    }
    printf("\n");
}

//����ʺA�Ʋժ����s
void FreeSpace_Array(Dynamic_Array* arr){
    if(arr == NULL){
        return;
    }

    if(arr -> pAddr != NULL){
        free(arr -> pAddr);
    }
    free(arr);
}

//�M�żƲ�
void Clear_Array(Dynamic_Array* arr){
    if(arr == NULL){
        return;
    }
    //pAddr -> �Ŷ�
    arr -> size = 0;
}

//��o�ʺA�Ʋծe�q
int Capacity_Array(Dynamic_Array* arr){
    if(arr == NULL){
        return -1;
    }
    return arr -> capacity;
}

//��o�ʺA�ƾڷ�e�����Ӽ�
int Size_Array(Dynamic_Array* arr){
    if(arr == NULL){
        return -1;
    }
    return arr -> size;
}

//�ھڦ�m��o�Y�Ӧ�m����
int At_Array(Dynamic_Array* arr, int pos){

    return arr -> pAddr[pos];
}
