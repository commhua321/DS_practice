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

    //�Ыش�
    LinkStack* stack = Init_LinkStack();

    //�Ыؼƾ�
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

    //�J��
    Push_LinkStack(stack, (LinkNode*)&p1);
    Push_LinkStack(stack, (LinkNode*)&p2);
    Push_LinkStack(stack, (LinkNode*)&p3);
    Push_LinkStack(stack, (LinkNode*)&p4);
    Push_LinkStack(stack, (LinkNode*)&p5);

    //��X
    while(Size_LinkStack(stack) > 0){

        //���X�̳�����
        Person* p = (Person*)Top_LinkStack(stack);
        printf("name:%s age:%d\n", p -> name, p -> age);
        //�u�X�̳�����
        Pop_LinkStack(stack);
    }

    //�P����
    FreeSpace_LinkStack(stack);

    return 0;
}
