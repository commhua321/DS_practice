#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkList.h"

//自定義的數據類型
typedef struct PERSON{
    char name[64];
    int age;
    int score;
}Person;


//打印函數
void MyPrint(void* data){
    Person* p = (Person*)data;
    printf("Name: %s Age: %d Score: %d\n", p -> name, p -> age, p -> score);
}

int main()
{
    //創建鏈表
    LinkList* list = Init_LinkList();

    //創建數據
    Person p1 = {"aaa", 18, 100};
    Person p2 = {"ggg", 14, 42};
    Person p3 = {"www", 78, 77};
    Person p4 = {"asfd", 58, 41};
    Person p5 = {"ljkl", 13, 22};

    //數計插入鏈表
    Insert_LinkList(list, 0, &p1);
    Insert_LinkList(list, 0, &p2);
    Insert_LinkList(list, 0, &p3);
    Insert_LinkList(list, 0, &p4);
    Insert_LinkList(list, 0, &p5);

    //打印
    Print_LinkList(list, MyPrint);

    //刪除3
    RemoveByPos_LinkList(list, 3);

    //打印
    printf("-------------------------\n");
    Print_LinkList(list, MyPrint);

    //返回第一個結點
    printf("-------查找結果----------\n");
    Person* ret = (Person*)Front_LinkList(list);
    printf("Name: %s Age: %d Score: %d\n", ret -> name, ret -> age, ret -> score);



    //銷毀鏈表
    FreeSpace_LinkList(list);

    return 0;
}
