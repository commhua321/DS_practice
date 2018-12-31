#ifndef CIRCLELINKLIST_H_INCLUDED
#define CIRCLELINKLIST_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

//鏈表的小結點
typedef struct CIRCLELINKNODE{
    struct CIRCLELINKNODE* next;
}CircleLinkNode;

//鏈表結構體
typedef struct CIRCLELINKLIST{
    //這裡head不用指針
    CircleLinkNode head;
    int size;
}CircleLinkList;

//編寫針對鏈表結構體操作的API函數

#define CIRCLELINKLIST_TRUE 1
#define CIRCLELINKLIST_FALSE 0



//比較回調
typedef int(*COMPARENODE)(CircleLinkNode*, CircleLinkNode*);
//打印回調
typedef void(*PRINTNODE)(CircleLinkNode*);

//初始化函數
CircleLinkList* Init_CircleLinkList();

//插入函數
void Insert_CircleLinkList(CircleLinkList* clist, int pos, CircleLinkNode* data);

//獲得第一個元素
CircleLinkNode* Front_CircleLinkList(CircleLinkList* clist);

//根據位置刪除
void RemoveByPos_Front_CircleLinkList(CircleLinkList* clist, int pos);

//根據值去刪除
//由用戶回調函數操作
void RemoveByValue_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data, COMPARENODE compare);

//獲得鏈表的長度
int Size_CircleLinkList(CircleLinkList* clist);

//判斷是否為空
int IsEmpty_CircleLinkList(CircleLinkList* clist);

//查找
//由用戶回調函數操作
int Find_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data, COMPARENODE compare);

//打印結點
void Print_CircleLinkList(CircleLinkList* clist, PRINTNODE print);

//釋放內存
void FreeSpace_CircleLinkList(CircleLinkList* clist);

#endif // CIRCLELINKLIST_H_INCLUDED
