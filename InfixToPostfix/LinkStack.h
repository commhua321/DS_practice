#ifndef LINKSTACK_H_INCLUDED
#define LINKSTACK_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

//�즡�̪����I
typedef struct LINKNODE{
    struct LINKNODE* next;
}LinkNode;

//�즡��
typedef struct LINKSTACK{
    LinkNode head;
    int size;
}LinkStack;

//��l�ƨ��
LinkStack* Init_LinkStack();

//�J��
void Push_LinkStack(LinkStack* stack, LinkNode* data);

//�X��
void Pop_LinkStack(LinkStack* stack);

//��^�̳�����
LinkNode* Top_LinkStack(LinkStack* stack);

//��^�̤������Ӽ�
int Size_LinkStack(LinkStack* stack);

//�M�Ŵ�
void Clear_LinkStack(LinkStack* stack);

//�P����
void FreeSpace_LinkStack(LinkStack* stack);


#endif // LINKSTACK_H_INCLUDED
