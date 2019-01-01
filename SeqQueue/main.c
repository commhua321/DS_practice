#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SeqQueue.h"


typedef struct PERSON{
    char name[64];
    int age;
}Person;

int main()
{

    //�Ыض��C
    SeqQueue* queue = Init_SeqQueue();

    //�Ыؼƾ�
    Person p1 = {"aaa", 10};
    Person p2 = {"bbb", 20};
    Person p3 = {"ccc", 15};
    Person p4 = {"ddd", 87};
    Person p5 = {"eee", 65};

    //�ƾڤJ���C
    Push_SeqQueue(queue, &p1);
    Push_SeqQueue(queue, &p2);
    Push_SeqQueue(queue, &p3);
    Push_SeqQueue(queue, &p4);
    Push_SeqQueue(queue, &p5);

    //��X��������
    Person* backPerson = (Person*)Back_SeqQueue(queue);
    printf("name:%s age:%d\n\n", backPerson -> name, backPerson -> age);

    //��X
    while(Size_SeqQueue(queue) > 0){
        Person* p = (Person*)Front_SeqQueue(queue);
        printf("name:%s age:%d\n", p -> name, p -> age);
        //�q���Y�u�X����
        Pop_SeqQueue(queue);
    }



    //�P�����C
    Free_SeqQueue(queue);

    return 0;
}
