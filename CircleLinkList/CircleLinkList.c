#include "CircleLinkList.h"




//初始化函數
CircleLinkList* Init_CircleLinkList(){

    CircleLinkList* clist = (CircleLinkList*)malloc(sizeof(CircleLinkList));
    clist -> head.next = &(clist -> head);
    clist -> size = 0;

    return clist;
}

//插入函數
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

    //根據位置查找結點
    //輔助指針變量
    CircleLinkNode* pCurrent = &(clist -> head);
    for(int i = 0 ; i < pos ; i++){
        pCurrent = pCurrent -> next;
    }

    //新數據入鏈表
    data -> next = pCurrent -> next;
    pCurrent -> next = data;

    clist -> size++;
}

//獲得第一個元素
CircleLinkNode* Front_CircleLinkList(CircleLinkList* clist){
    return clist -> head.next;
}

//根據位置刪除
void RemoveByPos_Front_CircleLinkList(CircleLinkList* clist, int pos){
    if(clist == NULL){
        return;
    }
    if(pos < 0 || pos >= clist -> size){
        return;
    }

    //根據pos找結點
    //輔助指針變量
    CircleLinkNode* pCurrent = &(clist -> head);
    for(int i = 0 ; i < pos ; i++){
        pCurrent = pCurrent -> next;
    }

    //緩存當前結點的下一個結點
    CircleLinkNode* pNext = pCurrent -> next;
    pCurrent -> next = pNext -> next;

    clist -> size--;
}

//根據值去刪除
//由用戶回調函數操作
void RemoveByValue_CircleLinkList(CircleLinkList* clist, CircleLinkNode* data, COMPARENODE compare){
    if(clist == NULL){
        return;
    }
    if(data == NULL){
        return;
    }

    //這個是循環鏈表
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

//獲得鏈表的長度
int Size_CircleLinkList(CircleLinkList* clist){
    return clist -> size;
}

//判斷是否為空
int IsEmpty_CircleLinkList(CircleLinkList* clist){
    if(clist -> size == 0){
        return CIRCLELINKLIST_TRUE;
    }
    return CIRCLELINKLIST_FALSE;
}

//查找
//由用戶回調函數操作
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

//打印結點
void Print_CircleLinkList(CircleLinkList* clist, PRINTNODE print){
    if(clist == NULL){
        return -1;
    }

    //輔助指針變量
    CircleLinkNode* pCurrent = clist -> head.next;
    //打印兩次
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

//釋放內存
void FreeSpace_CircleLinkList(CircleLinkList* clist){
    if(clist == NULL){
        return -1;
    }
    free(clist);
}
