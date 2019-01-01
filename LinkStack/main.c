#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkStack.h"

typedef struct PERSON{
    LinkNode node;
    char name[64];
    int age;
}Person;


int main()
{

    //創建棧
    LinkStack* stack = Init_LinkStack();

    //創建數據
    Person p1, p2, p3, p4, p5;
    strcpy(p1.name, "aaa");
    strcpy(p2.name, "bbb");
    strcpy(p3.name, "ccc");
    strcpy(p4.name, "ddd");
    strcpy(p5.name, "eee");

    p1.age = 15;
    p2.age = 25;
    p3.age = 54;
    p4.age = 98;
    p5.age = 25;

    //入棧
    Push_LinkStack(stack, (LinkNode*)&p1);
    Push_LinkStack(stack, (LinkNode*)&p2);
    Push_LinkStack(stack, (LinkNode*)&p3);
    Push_LinkStack(stack, (LinkNode*)&p4);
    Push_LinkStack(stack, (LinkNode*)&p5);

    //輸出
    while(Size_LinkStack(stack) > 0){

        //取出棧頂元素
        Person* p = (Person*)Top_LinkStack(stack);
        printf("name:%s age:%d\n", p -> name, p -> age);
        //彈出棧頂元素
        Pop_LinkStack(stack);
    }

    //銷毀棧
    FreeSpace_LinkStack(stack);

    return 0;
}
