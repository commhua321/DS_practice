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

    //創建隊列
    SeqQueue* queue = Init_SeqQueue();

    //創建數據
    Person p1 = {"aaa", 10};
    Person p2 = {"bbb", 20};
    Person p3 = {"ccc", 15};
    Person p4 = {"ddd", 87};
    Person p5 = {"eee", 65};

    //數據入隊列
    Push_SeqQueue(queue, &p1);
    Push_SeqQueue(queue, &p2);
    Push_SeqQueue(queue, &p3);
    Push_SeqQueue(queue, &p4);
    Push_SeqQueue(queue, &p5);

    //輸出隊尾元素
    Person* backPerson = (Person*)Back_SeqQueue(queue);
    printf("name:%s age:%d\n\n", backPerson -> name, backPerson -> age);

    //輸出
    while(Size_SeqQueue(queue) > 0){
        Person* p = (Person*)Front_SeqQueue(queue);
        printf("name:%s age:%d\n", p -> name, p -> age);
        //從隊頭彈出元素
        Pop_SeqQueue(queue);
    }



    //銷毀隊列
    Free_SeqQueue(queue);

    return 0;
}
