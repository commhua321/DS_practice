#include "LinkList.h"


//��l�����
LinkList* Init_LinkList(){
    LinkList* list = (LinkList*)malloc(sizeof(LinkList));
    list -> size = 0;

    //�Y���I�A���O�s�ƾګH��
    list -> head = (LinkNode*)malloc(sizeof(LinkNode));
    list -> head -> data = NULL;
    list -> head -> next = NULL;

    return list;
}

//���w��m���J
void Insert_LinkList(LinkList* list, int pos, void* data){
    if(list == NULL){
        return;
    }
    if(data == NULL){
        return;
    }

    //�ͦn���B�̡Apos�V��
    if(pos < 0 || pos > list -> size){
        pos = list -> size;
    }

    //�Ыطs�����I
    LinkNode* newnode = (LinkNode*)malloc(sizeof(LinkNode));
    newnode -> data = data;
    newnode -> next = NULL;

    //�䵲�I
    //���U���w�ܶq
    LinkNode* pCurrent = list -> head;
    for(int i = 0 ; i < pos ; i++){
        pCurrent = pCurrent -> next;
    }

    //�s���I�J���
    newnode -> next = pCurrent -> next;
    pCurrent -> next = newnode;

    list -> size++;

}

//�R�����w��m����
void RemoveByPos_LinkList(LinkList* list, int pos){
    if(list == NULL){
        return;
    }

    if(pos < 0 || pos > list -> size){
        return;
    }

    //�d��R�����I���e�@�ӵ��I
    LinkNode* pCurrent = list -> head;
    for(int i = 0 ; i < pos ; i++){
        pCurrent = pCurrent -> next;
    }

    //�w�s�R�������I
    LinkNode* pDel = pCurrent -> next;
    pCurrent -> next = pDel -> next;
    //����R�����I�����s
    free(pDel);

    list -> size--;
}

//��o�������
int Size_LinkList(LinkList* list){
    return list -> size;
}

//�d��
int Find_LinkList(LinkList* list, void* data){
    if(list == NULL){
        return -1;
    }
    if(data == NULL){
        return -1;
    }

    LinkNode* pCurrent = list -> head -> next;
    int i = 0;
    while(pCurrent != NULL){
        if(pCurrent -> data == data){
            break;
        }
        i++;
        pCurrent = pCurrent -> next;
    }

    return i;
}
//��^�Ĥ@�ӵ��I
void* Front_LinkList(LinkList* list){
    return list -> head -> next -> data;
}

//���L����I
void Print_LinkList(LinkList* list, PRINTLINKNODE print){
    if(list == NULL){
        return;
    }
    //���U���w�ܶq
    LinkNode* pCurrent = list -> head -> next;
    while(pCurrent != NULL){
        print(pCurrent -> data);
        pCurrent = pCurrent -> next;
    }

}

//��������s
void FreeSpace_LinkList(LinkList* list){
    if(list == NULL){
        return;
    }

    LinkNode* pCurrent = list -> head;
    while(pCurrent != NULL){
        //�w�s�U�@�ӵ��I
        LinkNode* pNext = pCurrent -> next;
        free(pCurrent);
        pCurrent = pNext;
    }

    //��������s
    list -> size = 0;
    free(list);

}
