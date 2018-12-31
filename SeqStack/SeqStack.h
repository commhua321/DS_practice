#ifndef SEQSTACK_H_INCLUDED
#define SEQSTACK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

//數組去模擬棧的順序存儲
#define MAX_SIZE 1024
#define SEQSTACK_TRUE 1
#define SEQSTACK_FALSE 0
typedef struct SEQSTACK{
    void* data[MAX_SIZE];
    int size;
}SeqStack;

//初始化棧
SeqStack* Init_SeqStack();

//入棧
void Push_SeqStack(SeqStack* stack, void* data);

//返回棧頂元素
void* Top_SeqStack(SeqStack* stack);

//出棧
void Pop_SeqStack(SeqStack* stack);

//判斷是否為空
int IsEmpty(SeqStack* stack);

//返回棧中元素的個數
int Size_SeqStack(SeqStack* stack);

//清空棧
void Clear_SeqStack(SeqStack* stack);

//銷毀
void FreeSpace_SeqStack(SeqStack* stack);


#endif // SEQSTACK_H_INCLUDED
