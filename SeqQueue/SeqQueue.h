#ifndef SEQQUEUE_H_INCLUDED
#define SEQQUEUE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

//���Ƕ��C���c��
typedef struct SEQQUEUE{
    void* data[MAX_SIZE];
    int size;
}SeqQueue;

//��l��
SeqQueue* Init_SeqQueue();

//�J��
void Push_SeqQueue(SeqQueue* queue, void* data);

//��^���Y����
void* Front_SeqQueue(SeqQueue* queue);

//�X��
void Pop_SeqQueue(SeqQueue* queue);

//��^����������
void* Back_SeqQueue(SeqQueue* queue);

//��^�j�p
int Size_SeqQueue(SeqQueue* queue);

//�M�Ŷ��C
void Clear_SeqQueue(SeqQueue* queue);

//�P��
void Free_SeqQueue(SeqQueue* queue);

#endif // SEQQUEUE_H_INCLUDED
