#ifndef SEQQUEUE_H_INCLUDED
#define SEQQUEUE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

//順序隊列結構體
typedef struct SEQQUEUE{
    void* data[MAX_SIZE];
    int size;
}SeqQueue;

//初始化
SeqQueue* Init_SeqQueue();

//入隊
void Push_SeqQueue(SeqQueue* queue, void* data);

//返回隊頭元素
void* Front_SeqQueue(SeqQueue* queue);

//出隊
void Pop_SeqQueue(SeqQueue* queue);

//返回隊尾的元素
void* Back_SeqQueue(SeqQueue* queue);

//返回大小
int Size_SeqQueue(SeqQueue* queue);

//清空隊列
void Clear_SeqQueue(SeqQueue* queue);

//銷毀
void Free_SeqQueue(SeqQueue* queue);

#endif // SEQQUEUE_H_INCLUDED
