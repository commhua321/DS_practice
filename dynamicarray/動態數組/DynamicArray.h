#ifndef DYNAMICARRAY_H_INCLUDED
#define DYNAMICARRAY_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//�ʺA�Ʋյ��c��
typedef struct DYNAMICARRAY{
    int *pAddr;
    int size;
    int capacity;
}Dynamic_Array;

//�ﵲ�c��ާ@�����
//��l��
Dynamic_Array* Init_Array();
//���J
void PushBack_Array(Dynamic_Array* arr, int value);
//�ھڦ�m�R��
void RemoveByPos_Array(Dynamic_Array* arr, int pos);
//�ھڭȧR��
void RemoveByValue_Array(Dynamic_Array* arr, int value);
//�d��
int Find_Array(Dynamic_Array* arr, int value);
//���L
void Print_Array(Dynamic_Array* arr);
//����ʺA�Ʋժ����s
void FreeSpace_Array(Dynamic_Array* arr);

//�M�żƲ�
void Clear_Array(Dynamic_Array* arr);
//��o�ʺA�Ʋծe�q
int Capacity_Array(Dynamic_Array* arr);
//��o�ʺA�ƾڷ�e�����Ӽ�
int Size_Array(Dynamic_Array* arr);
//�ھڦ�m��o�Y�Ӧ�m����
int At_Array(Dynamic_Array* arr, int pos);


#endif // DYNAMICARRAY_H_INCLUDED
