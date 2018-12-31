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

    //�Ыش�
    SeqStack* stack = Init_SeqStack();

    //�Ыؼƾ�
    Person p1 = {"aa", 10};
    Person p2 = {"bb", 20};
    Person p3 = {"cc", 54};
    Person p4 = {"dd", 42};
    Person p5 = {"ee", 11};

    //�J��
    Push_SeqStack(stack, &p1);
    Push_SeqStack(stack, &p2);
    Push_SeqStack(stack, &p3);
    Push_SeqStack(stack, &p4);
    Push_SeqStack(stack, &p5);

    //��X
    while(Size_SeqStack(stack) > 0){

        //�X�ݴ̳�����
        Person* person = (Person*)Top_SeqStack(stack);
        printf("name:%s age:%d\n", person -> name, person -> age);
        //�u�X�̳�����
        Pop_SeqStack(stack);

    }

    //���񤺦s
    FreeSpace_SeqStack(stack);

    return 0;
}
