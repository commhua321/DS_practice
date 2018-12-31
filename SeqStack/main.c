#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SeqStack.h"

typedef struct PERSON{
    char name[64];
    int age;
}Person;


int main()
{

    //創建棧
    SeqStack* stack = Init_SeqStack();

    //創建數據
    Person p1 = {"aa", 10};
    Person p2 = {"bb", 20};
    Person p3 = {"cc", 54};
    Person p4 = {"dd", 42};
    Person p5 = {"ee", 11};

    //入棧
    Push_SeqStack(stack, &p1);
    Push_SeqStack(stack, &p2);
    Push_SeqStack(stack, &p3);
    Push_SeqStack(stack, &p4);
    Push_SeqStack(stack, &p5);

    //輸出
    while(Size_SeqStack(stack) > 0){

        //訪問棧頂元素
        Person* person = (Person*)Top_SeqStack(stack);
        printf("name:%s age:%d\n", person -> name, person -> age);
        //彈出棧頂元素
        Pop_SeqStack(stack);

    }

    //釋放內存
    FreeSpace_SeqStack(stack);

    return 0;
}
