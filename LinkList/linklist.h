#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
//鏈表結點
typedef struct LINKNODE{
    void* data; //指向任何類型的數據
    struct LINKNODE* next;
}LinkNode;

//鏈表結構體
typedef struct LINKLIST{
    LinkNode* head;
    int size;
    //需要容量嗎? 沒有容量的概念
}LinkList;

//打印函數指針
typedef void(*PRINTLINKNODE)(void*);

//初始化鏈表
LinkList* Init_LinkList();
//指定位置插入
void Insert_LinkList(LinkList* list, int pos, void* data);
//刪除指定位置的值
void RemoveByPos_LinkList(LinkList* list, int pos);
//獲得鏈表的長度
int Size_LinkList(LinkList* list);
//查找
int Find_LinkList(LinkList* list, void* data);
//返回第一個結點
void* Front_LinkList(LinkList* list);
//打印鏈表結點
void Print_LinkList(LinkList* list, PRINTLINKNODE print);
//釋放鏈表內存
void FreeSpace_LinkList(LinkList* list);






#endif // LINKLIST_H_INCLUDED
