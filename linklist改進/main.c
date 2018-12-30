#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linklist.h"

typedef struct PERSON{
    LinkNode node;
    char name[64];
    int age;
}Person;

void MyPrint(LinkNode* data){
    Person* p = (Person*)data;
    printf("name:%s age:%d\n", p -> name, p -> age);
}

int MyCompare(LinkNode* node1, LinkNode* node2){
    Person* p1 = (Person*)node1;
    Person* p2 = (Person*)node2;

    if(strcmp(p1 -> name, p2 -> name) == 0 && p1 -> age == p2 -> age){
        return 0;
    }

    return -1;
}

int main()
{

    //創建鏈表
    LinkList* list = Init_LinkList();

    //創建數據
    Person p1, p2, p3, p4, p5;
    strcpy(p1.name, "aaa");
    strcpy(p2.name, "sss");
    strcpy(p3.name, "asf");
    strcpy(p4.name, "fbf");
    strcpy(p5.name, "xxx");

    p1.age = 10;
    p2.age = 42;
    p3.age = 17;
    p4.age = 52;
    p5.age = 42;

    //將節點插入到鏈表
    Insert_LinkList(list, 0, (LinkNode*)&p1);
    Insert_LinkList(list, 0, (LinkNode*)&p2);
    Insert_LinkList(list, 0, (LinkNode*)&p3);
    Insert_LinkList(list, 0, (LinkNode*)&p4);
    Insert_LinkList(list, 0, (LinkNode*)&p5);

    //打印
    Print_LinkList(list, MyPrint);

    //刪除結點
    Remove_LinkList(list, 2);

    //打印
    printf("---------------------------\n");
    Print_LinkList(list, MyPrint);

    //查找
    Person findP;
    strcpy(findP.name, "sss");
    findP.age = 42;
    int pos = Find_LinkList(list, (LinkNode*)&findP, MyCompare);
    printf("位置:%d\n", pos);
    //釋放鏈表內存
    FreeSpace_LinkList(list);

    return 0;
}
