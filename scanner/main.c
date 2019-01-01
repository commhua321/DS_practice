#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkStack.h"

typedef struct MYCHAR{
    LinkNode node;
    char* pAddr;
    int index;
}MyChar;

int IsLeft(char c){
    return c == '(';
}

int IsRight(char c){
    return c == ')';
}

MyChar* CreateMyChar(char* p, int index){
    MyChar* mychar = (MyChar*)malloc(sizeof(MyChar));
    mychar -> pAddr = p;
    mychar -> index = index;
    return  mychar;
}

void ShowError(char* str, int pos){
    printf("%s\n", str);
    for(int i = 0 ; i < pos ; i++){
        printf(" ");
    }
    printf("A\n");
}

int main()
{
    char* str = "1+5+7(23)+)(5/7)";

    //創建棧容器
    LinkStack* stack = Init_LinkStack();

    char* p = str;
    int index = 0;
    while(*p != '\0'){

        //如果左括號，直接入棧
        if(IsLeft(*p)){
            Push_LinkStack(stack, (LinkNode*)CreateMyChar(p, index));
        }

        //如果是右括號，從棧頂彈出元素，判斷是不是左括號
        if(IsRight(*p)){
            if(Size_LinkStack(stack) > 0){
                MyChar* mychar = (MyChar*)Top_LinkStack(stack);
                if(IsLeft(*(mychar -> pAddr))){
                    Pop_LinkStack(stack);
                    free(mychar);
                }
            }
            else{
                printf("右括號沒有匹配的左括號:\n");
                ShowError(str, index);
                break;
            }
        }
        p++;
        index++;
    }

    while(Size_LinkStack(stack) > 0){
        MyChar* mychar = (MyChar*)Top_LinkStack(stack);
        printf("左括號沒有匹配的右括號:\n");
        ShowError(str, mychar -> index);
        Pop_LinkStack(stack);
        free(mychar);
    }
    return 0;
}
