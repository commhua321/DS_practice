#ifndef SEQSTACK_H_INCLUDED
#define SEQSTACK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

//�Ʋեh�����̪����Ǧs�x
#define MAX_SIZE 1024
#define SEQSTACK_TRUE 1
#define SEQSTACK_FALSE 0
typedef struct SEQSTACK{
    void* data[MAX_SIZE];
    int size;
}SeqStack;

//��l�ƴ�
SeqStack* Init_SeqStack();

//�J��
void Push_SeqStack(SeqStack* stack, void* data);

//��^�̳�����
void* Top_SeqStack(SeqStack* stack);

//�X��
void Pop_SeqStack(SeqStack* stack);

//�P�_�O�_����
int IsEmpty(SeqStack* stack);

//��^�̤��������Ӽ�
int Size_SeqStack(SeqStack* stack);

//�M�Ŵ�
void Clear_SeqStack(SeqStack* stack);

//�P��
void FreeSpace_SeqStack(SeqStack* stack);


#endif // SEQSTACK_H_INCLUDED
