#include "CircleLinkList.h"




//��l�ƨ��
CircleLinkList* Init_CircleLinkList(){

    CircleLinkList* clist = (CircleLinkList*)malloc(sizeof(CircleLinkList));
    clist -> head.next = &(clist -> head);
    clist -> size = 0;

    return clist;
}

//���J���
void Insert_CircleLinkList(CircleLinkList* clist, int pos, CircleLinkNode* data){
    if(clist == NULL){
        return;
    }
    if(data == NULL){
        return;
    }

    if(pos < 0 || pos >= clist -> size){
        pos = clist -> size;
    }

    //�ھڦ�m�d�䵲�I
    //���U���w�ܶq
    CircleLinkNode* pCurrent = &(clist -> head);
    for(int i = 0 ; i < pos ; i++){
        pCurrent = pCurrent -> next;
    }

    //�s�ƾڤJ���
    data -> next = pCurrent -> next;
    pCurrent -> next = data;

    clist -> size++;
}

//��o�Ĥ@�Ӥ���
CircleLinkNode* Front_CircleLinkList(CircleLinkList* clist){
    return clist -> head.next;
}

//�ھڦ�m�R��
void RemoveByPos_Front_CircleLinkList(CircleLinkList* clist, int pos){
    if(clist == NULL){
        return;
    }
    if(pos < 0 || pos >= clist -> size){
        return;
    }

    //�ھ�pos�䵲�I
    //���U���w�ܶq
    CircleLinkNode* pCurrent = &(clist -> head);
    for(int i = 0 ; i < pos ; i++){
        pCurrent = pCurrent -> next;
    }

    //�w�s��e���I���U�@�ӵ��I
    CircleLinkNode* pNext = pCurrent -> next;
    pCurrent -> next = pNext -> next;

    clist -> size--;
}

//�ھڭȥh�R��
//�ѥΤ�^�ը�ƾާ@
void RemoveByValue_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data, COMPARENODE compare){
    if(clist == NULL){
        return;
    }
    if(data == NULL){
        return;
    }

    //�o�ӬO�`�����
    CircleLinkNode* pPrev = &(clist -> head);
    CircleLinkNode* pCurrent = pPrev -> next;
    for(int i = 0 ; i < clist -> size ; i++){
        if(compare(pCurrent, data) == CIRCLELINKLIST_TRUE){
            pPrev -> next = pCurrent -> next;
            clist -> size--;
            break;
        }
        pPrev = pCurrent;
        pCurrent = pPrev -> next;
    }


}

//��o�������
int Size_CircleLinkList(CircleLinkList* clist){
    return clist -> size;
}

//�P�_�O�_����
int IsEmpty_CircleLinkList(CircleLinkList* clist){
    if(clist -> size == 0){
        return CIRCLELINKLIST_TRUE;
    }
    return CIRCLELINKLIST_FALSE;
}

//�d��
//�ѥΤ�^�ը�ƾާ@
int Find_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data, COMPARENODE compare){
    if(clist == NULL){
        return -1;
    }
    if(data == NULL){
        return -1;
    }

    CircleLinkNode* pCurrent = clist -> head.next;
    int flag = -1;
    for(int i = 0 ; i < clist -> size ; i++){
        if(compare(pCurrent, data) == CIRCLELINKLIST_TRUE){
            flag = i;
            break;
        }
        pCurrent = pCurrent -> next;
    }
    return flag;
}

//���L���I
void Print_CircleLinkList(CircleLinkList* clist, PRINTNODE print){
    if(clist == NULL){
        return -1;
    }

    //���U���w�ܶq
    CircleLinkNode* pCurrent = clist -> head.next;
    //���L�⦸
    for(int i = 0 ; i < clist -> size * 2; i++){
        if(pCurrent == &(clist -> head)){
            pCurrent = pCurrent -> next;
            printf("-------------------------\n");
        }
        print(pCurrent);
        pCurrent = pCurrent -> next;
    }
    printf("-------------------------\n");

}

//���񤺦s
void FreeSpace_CircleLinkList(CircleLinkList* clist){
    if(clist == NULL){
        return -1;
    }
    free(clist);
}
