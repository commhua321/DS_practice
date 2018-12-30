#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

//鏈表小結點
typedef struct LINKNODE{
    struct LINKNODE* next;
}LinkNode;

//鏈表結點
typedef struct LINKLIST{
    LinkNode head;
    int size;
}LinkList;

//遍歷函數指針
typedef void(*PRINTNODE)(LinkNode*);
//比較函數指針
typedef int(*COMPARENODE)(LinkNode*, LinkNode*);

//初始化鏈表
LinkList* Init_LinkList();
//插入
void Insert_LinkList(LinkList* list, int pos, LinkNode* data);
//刪除
void Remove_LinkList(LinkList* list, int pos);
//查找
int Find_LinkList(LinkList* list, LinkNode* data, COMPARENODE compare);
//返回鏈表大小
int Size_LinkList(LinkList* list);
//打印
void Print_LinkList(LinkList* list, PRINTNODE print);
//釋放鏈表內存
void FreeSpace_LinkList(LinkList* list);


#endif // LINKLIST_H_INCLUDED
