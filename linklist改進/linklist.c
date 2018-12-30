#include "linklist.h"




//��l�����
LinkList* Init_LinkList(){
    LinkList* list = (LinkList*)malloc(sizeof(LinkList));
    list -> head.next = NULL;
    list -> size = 0;
    return list;
}

//���J
void Insert_LinkList(LinkList* list, int pos, LinkNode* data){

    if(list == NULL){
        return;
    }

    if(data == NULL){
        return;
    }

    if(pos < 0 || pos > list -> size){
        pos = list -> size;
    }

    //�d�䴡�J��m
    LinkNode* pCurrent = &(list -> head);
    for(int i = 0 ; i < pos ; i++){
        pCurrent = pCurrent -> next;
    }

    //���J�s���I
    data -> next = pCurrent -> next;
    pCurrent -> next = data;

    list -> size++;
}

//�R��
void Remove_LinkList(LinkList* list, int pos){
    if(list == NULL){
        return;
    }

    if(pos < 0 || pos > list -> size){
        return;
    }

    //���U���w�ܶq
    LinkNode* pCurrent = &(list -> head);
    for(int i = 0 ; i < pos ; i++){
        pCurrent = pCurrent -> next;
    }

    //�R���`�I
    pCurrent -> next = pCurrent -> next -> next;

    list -> size--;
}

//�d��
int Find_LinkList(LinkList* list, LinkNode* data,  COMPARENODE compare){
    if(list == NULL){
        return -1;
    }

    if(data == NULL){
        return -1;
    }

    //���U���w�ܶq
    LinkNode* pCurrent = list -> head.next;
    int index = 0;
    int flag = -1;
    while(pCurrent != NULL){
        if(compare(pCurrent, data) == 0){
            flag = index;
            break;
        }
        pCurrent = pCurrent -> next;
        index++;
    }
    return flag;
}

//��^���j�p
int Size_LinkList(LinkList* list);
//���L
void Print_LinkList(LinkList* list, PRINTNODE print){
    if(list == NULL){
        return;
    }

    //���U���w
    LinkNode* pCurrent = list -> head.next;
    while(pCurrent != NULL){
        print(pCurrent);
        pCurrent = pCurrent -> next;
    }
}

//��������s
void FreeSpace_LinkList(LinkList* list){
    if(list == NULL){
        return;
    }

    free(list);
}
