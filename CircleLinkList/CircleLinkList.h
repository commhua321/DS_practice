#ifndef CIRCLELINKLIST_H_INCLUDED
#define CIRCLELINKLIST_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

//����p���I
typedef struct CIRCLELINKNODE{
    struct CIRCLELINKNODE* next;
}CircleLinkNode;

//����c��
typedef struct CIRCLELINKLIST{
    //�o��head���Ϋ��w
    CircleLinkNode head;
    int size;
}CircleLinkList;

//�s�g�w������c��ާ@��API���

#define CIRCLELINKLIST_TRUE 1
#define CIRCLELINKLIST_FALSE 0



//����^��
typedef int(*COMPARENODE)(CircleLinkNode*, CircleLinkNode*);
//���L�^��
typedef void(*PRINTNODE)(CircleLinkNode*);

//��l�ƨ��
CircleLinkList* Init_CircleLinkList();

//���J���
void Insert_CircleLinkList(CircleLinkList* clist, int pos, CircleLinkNode* data);

//��o�Ĥ@�Ӥ���
CircleLinkNode* Front_CircleLinkList(CircleLinkList* clist);

//�ھڦ�m�R��
void RemoveByPos_Front_CircleLinkList(CircleLinkList* clist, int pos);

//�ھڭȥh�R��
//�ѥΤ�^�ը�ƾާ@
void RemoveByValue_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data, COMPARENODE compare);

//��o�������
int Size_CircleLinkList(CircleLinkList* clist);

//�P�_�O�_����
int IsEmpty_CircleLinkList(CircleLinkList* clist);

//�d��
//�ѥΤ�^�ը�ƾާ@
int Find_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data, COMPARENODE compare);

//���L���I
void Print_CircleLinkList(CircleLinkList* clist, PRINTNODE print);

//���񤺦s
void FreeSpace_CircleLinkList(CircleLinkList* clist);

#endif // CIRCLELINKLIST_H_INCLUDED
