#include "LinkStack.h"



//��l�ƨ��
LinkStack* Init_LinkStack(){
    LinkStack* stack = (LinkStack*)malloc(sizeof(LinkStack));
    stack -> head.next = NULL;
    stack -> size = 0;
    return stack;
}

//�J��
void Push_LinkStack(LinkStack* stack, LinkNode* data){
    if(stack == NULL){
        return;
    }
    if(data == NULL){
        return;
    }

    data -> next = stack -> head.next;
    stack -> head.next = data;
    stack -> size++;
}

//�X��
void Pop_LinkStack(LinkStack* stack){
    if(stack == NULL){
        return;
    }

    if(stack -> size == 0){
        return;
    }
    //�Ĥ@�Ӧ��ĵ��I
    LinkNode* pNext = stack -> head.next;
    stack -> head.next = pNext -> next;

    stack -> size--;
}

//��^�̳�����
LinkNode* Top_LinkStack(LinkStack* stack){
    if(stack == NULL){
        return NULL;
    }
    if(stack -> size == 0){
        return NULL;
    }
    return stack -> head.next;
}

//��^�̤������Ӽ�
int Size_LinkStack(LinkStack* stack){
    if(stack == NULL){
        return -1;
    }
    return stack -> size;
}

//�M�Ŵ�
void Clear_LinkStack(LinkStack* stack){
    if(stack == NULL){
        return;
    }

    stack -> head.next = NULL;
    stack -> size = 0;
}

//�P����
void FreeSpace_LinkStack(LinkStack* stack){
    if(stack == NULL){
        return;
    }
    free(stack);
}
