#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CircleLinkList.h"

#define M 8
#define N 3

typedef struct MYNUM{
    CircleLinkNode node;
    int val;
}MyNum;

void MyPrint(CircleLinkNode* data){
    MyNum* num = (MyNum*)data;
    printf("%d ", num -> val);
}

int MyCompare(CircleLinkNode* data1, CircleLinkNode* data2){
    MyNum* num1 = (MyNum*)data1;
    MyNum* num2 = (MyNum*)data2;
    if(num1 -> val == num2 -> val){
        return CIRCLELINKLIST_TRUE;
    }
    return CIRCLELINKLIST_FALSE;
}

int main()
{
    //�Ыش`�����
    CircleLinkList* clist = Init_CircleLinkList();
    //����J�ƾ�
    MyNum num[M];
    for(int i = 0 ; i < M ; i++){
        num[i].val = i + 1;
        Insert_CircleLinkList(clist, i, (CircleLinkNode*)&num[i]);
    }

    //���L
    Print_CircleLinkList(clist, MyPrint);
    printf("\n");

    int index = 1;
    CircleLinkNode* pCurrent = clist -> head.next;
    while(Size_CircleLinkList(clist) > 1){
        if(index == N){
            MyNum* tempNum = (MyNum*)pCurrent;
            printf("%d ", tempNum -> val);

            //�w�s�ݧR�����I���U�@�ӵ��I
            CircleLinkNode* pNext = pCurrent -> next;
            //�ھڭȧR��
            RemoveByValue_CircleLinkList(clist, pCurrent, MyCompare);
            pCurrent = pNext;
            if(pCurrent == &(clist -> head)){
                pCurrent = pCurrent -> next;
            }
            index = 1;
        }
        pCurrent = pCurrent -> next;
        if(pCurrent == &(clist -> head)){
            pCurrent = pCurrent -> next;
        }
        index++;
    }

    if(Size_CircleLinkList(clist) == 1){
        MyNum* tempNum2 = (MyNum*)Front_CircleLinkList(clist);
        printf("%d ", tempNum2 -> val);
    }
    else{
        printf("�X��\n");
    }


    //��������s
    FreeSpace_CircleLinkList(clist);



    return 0;
}
