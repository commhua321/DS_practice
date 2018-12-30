#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
//����I
typedef struct LINKNODE{
    void* data; //���V�����������ƾ�
    struct LINKNODE* next;
}LinkNode;

//����c��
typedef struct LINKLIST{
    LinkNode* head;
    int size;
    //�ݭn�e�q��? �S���e�q������
}LinkList;

//���L��ƫ��w
typedef void(*PRINTLINKNODE)(void*);

//��l�����
LinkList* Init_LinkList();
//���w��m���J
void Insert_LinkList(LinkList* list, int pos, void* data);
//�R�����w��m����
void RemoveByPos_LinkList(LinkList* list, int pos);
//��o�������
int Size_LinkList(LinkList* list);
//�d��
int Find_LinkList(LinkList* list, void* data);
//��^�Ĥ@�ӵ��I
void* Front_LinkList(LinkList* list);
//���L����I
void Print_LinkList(LinkList* list, PRINTLINKNODE print);
//��������s
void FreeSpace_LinkList(LinkList* list);






#endif // LINKLIST_H_INCLUDED
