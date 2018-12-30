#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

//���p���I
typedef struct LINKNODE{
    struct LINKNODE* next;
}LinkNode;

//����I
typedef struct LINKLIST{
    LinkNode head;
    int size;
}LinkList;

//�M����ƫ��w
typedef void(*PRINTNODE)(LinkNode*);
//�����ƫ��w
typedef int(*COMPARENODE)(LinkNode*, LinkNode*);

//��l�����
LinkList* Init_LinkList();
//���J
void Insert_LinkList(LinkList* list, int pos, LinkNode* data);
//�R��
void Remove_LinkList(LinkList* list, int pos);
//�d��
int Find_LinkList(LinkList* list, LinkNode* data, COMPARENODE compare);
//��^���j�p
int Size_LinkList(LinkList* list);
//���L
void Print_LinkList(LinkList* list, PRINTNODE print);
//��������s
void FreeSpace_LinkList(LinkList* list);


#endif // LINKLIST_H_INCLUDED
