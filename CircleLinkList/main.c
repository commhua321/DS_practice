#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CircleLinkList.h"

typedef struct PERSON{
    CircleLinkNode node;
    char name[64];
    int age;
    int score;
}Person;

void MyPrint(CircleLinkNode* data){
    Person* p = (Person*)data;
    printf("Name: %s Age:%d Score%d\n", p -> name, p -> age, p -> score);
}

int MyCompare(CircleLinkNode* data1, CircleLinkNode* data2){
    Person* p1 = (Person*)data1;
    Person* p2 = (Person*)data2;

    if(strcmp(p1 -> name, p2 -> name) == 0 && p1 -> age == p2 -> age && p1 -> score == p2 -> score){
        return CIRCLELINKLIST_TRUE;
    }
    return CIRCLELINKLIST_FALSE;
}


int main()
{

    //創建循環鏈表
    CircleLinkList* clist = Init_CircleLinkList();

    //創建數據
    Person p1, p2, p3, p4, p5;
    strcpy(p1.name, "aaa");
    strcpy(p2.name, "bbb");
    strcpy(p3.name, "ccc");
    strcpy(p4.name, "dds");
    strcpy(p5.name, "wfgfw");

    p1.age = 20;
    p2.age = 40;
    p3.age = 72;
    p4.age = 82;
    p5.age = 35;

    p1.score = 50;
    p2.score = 42;
    p3.score = 77;
    p4.score = 37;
    p5.score = 55;

    //數據入鏈表
    Insert_CircleLinkList(clist, 100, (CircleLinkNode*)&p1);
    Insert_CircleLinkList(clist, 100, (CircleLinkNode*)&p2);
    Insert_CircleLinkList(clist, 100, (CircleLinkNode*)&p3);
    Insert_CircleLinkList(clist, 100, (CircleLinkNode*)&p4);
    Insert_CircleLinkList(clist, 100, (CircleLinkNode*)&p5);

    //打印
    Print_CircleLinkList(clist, MyPrint);

    Person pDel;
    strcpy(pDel.name, "ccc");
    pDel.age = 72;
    pDel.score = 77;

    //根據值刪除
    RemoveByValue_CircleLinkList(clist, (CircleLinkList*)&pDel, MyCompare);

    //打印
    printf("刪除後\n");
    Print_CircleLinkList(clist, MyPrint);

    //釋放內存
    FreeSpace_CircleLinkList(clist);

    return 0;
}
