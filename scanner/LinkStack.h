#ifndef LINKSTACK_H_INCLUDED
#define LINKSTACK_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

//鏈式棧的結點
typedef struct LINKNODE{
    struct LINKNODE* next;
}LinkNode;

//鏈式棧
typedef struct LINKSTACK{
    LinkNode head;
    int size;
}LinkStack;

//初始化函數
LinkStack* Init_LinkStack();

//入棧
void Push_LinkStack(LinkStack* stack, LinkNode* data);

//出棧
void Pop_LinkStack(LinkStack* stack);

//返回棧頂元素
LinkNode* Top_LinkStack(LinkStack* stack);

//返回棧元素的個數
int Size_LinkStack(LinkStack* stack);

//清空棧
void Clear_LinkStack(LinkStack* stack);

//銷毀棧
void FreeSpace_LinkStack(LinkStack* stack);


#endif // LINKSTACK_H_INCLUDED
