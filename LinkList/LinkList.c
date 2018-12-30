#include "LinkList.h"


//初始化鏈表
LinkList* Init_LinkList(){
    LinkList* list = (LinkList*)malloc(sizeof(LinkList));
    list -> size = 0;

    //頭結點，不保存數據信息
    list -> head = (LinkNode*)malloc(sizeof(LinkNode));
    list -> head -> data = NULL;
    list -> head -> next = NULL;

    return list;
}

//指定位置插入
void Insert_LinkList(LinkList* list, int pos, void* data){
    if(list == NULL){
        return;
    }
    if(data == NULL){
        return;
    }

    //友好的處裡，pos越界
    if(pos < 0 || pos > list -> size){
        pos = list -> size;
    }

    //創建新的結點
    LinkNode* newnode = (LinkNode*)malloc(sizeof(LinkNode));
    newnode -> data = data;
    newnode -> next = NULL;

    //找結點
    //輔助指針變量
    LinkNode* pCurrent = list -> head;
    for(int i = 0 ; i < pos ; i++){
        pCurrent = pCurrent -> next;
    }

    //新結點入鏈表
    newnode -> next = pCurrent -> next;
    pCurrent -> next = newnode;

    list -> size++;

}

//刪除指定位置的值
void RemoveByPos_LinkList(LinkList* list, int pos){
    if(list == NULL){
        return;
    }

    if(pos < 0 || pos > list -> size){
        return;
    }

    //查找刪除結點的前一個結點
    LinkNode* pCurrent = list -> head;
    for(int i = 0 ; i < pos ; i++){
        pCurrent = pCurrent -> next;
    }

    //緩存刪除的結點
    LinkNode* pDel = pCurrent -> next;
    pCurrent -> next = pDel -> next;
    //釋放刪除結點的內存
    free(pDel);

    list -> size--;
}

//獲得鏈表的長度
int Size_LinkList(LinkList* list){
    return list -> size;
}

//查找
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
//返回第一個結點
void* Front_LinkList(LinkList* list){
    return list -> head -> next -> data;
}

//打印鏈表結點
void Print_LinkList(LinkList* list, PRINTLINKNODE print){
    if(list == NULL){
        return;
    }
    //輔助指針變量
    LinkNode* pCurrent = list -> head -> next;
    while(pCurrent != NULL){
        print(pCurrent -> data);
        pCurrent = pCurrent -> next;
    }

}

//釋放鏈表內存
void FreeSpace_LinkList(LinkList* list){
    if(list == NULL){
        return;
    }

    LinkNode* pCurrent = list -> head;
    while(pCurrent != NULL){
        //緩存下一個結點
        LinkNode* pNext = pCurrent -> next;
        free(pCurrent);
        pCurrent = pNext;
    }

    //釋放鏈表內存
    list -> size = 0;
    free(list);

}
