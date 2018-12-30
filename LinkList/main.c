#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkList.h"

//�۩w�q���ƾ�����
typedef struct PERSON{
    char name[64];
    int age;
    int score;
}Person;


//���L���
void MyPrint(void* data){
    Person* p = (Person*)data;
    printf("Name: %s Age: %d Score: %d\n", p -> name, p -> age, p -> score);
}

int main()
{
    //�Ы����
    LinkList* list = Init_LinkList();

    //�Ыؼƾ�
    Person p1 = {"aaa", 18, 100};
    Person p2 = {"ggg", 14, 42};
    Person p3 = {"www", 78, 77};
    Person p4 = {"asfd", 58, 41};
    Person p5 = {"ljkl", 13, 22};

    //�ƭp���J���
    Insert_LinkList(list, 0, &p1);
    Insert_LinkList(list, 0, &p2);
    Insert_LinkList(list, 0, &p3);
    Insert_LinkList(list, 0, &p4);
    Insert_LinkList(list, 0, &p5);

    //���L
    Print_LinkList(list, MyPrint);

    //�R��3
    RemoveByPos_LinkList(list, 3);

    //���L
    printf("-------------------------\n");
    Print_LinkList(list, MyPrint);

    //��^�Ĥ@�ӵ��I
    printf("-------�d�䵲�G----------\n");
    Person* ret = (Person*)Front_LinkList(list);
    printf("Name: %s Age: %d Score: %d\n", ret -> name, ret -> age, ret -> score);



    //�P�����
    FreeSpace_LinkList(list);

    return 0;
}
