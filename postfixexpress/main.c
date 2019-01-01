#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkStack.h"

int IsNumber2(char c){
    return c >= '0' && c <= '9';
}

typedef struct MYNUM{
    LinkNode node;
    int val;
}MyNum;

int Calculate(int left, int right, char c){

    int ret = 0;
    switch(c){
    case '+':
        ret = left + right;
        break;
    case '-':
        ret = left - right;
        break;
    case '*':
        ret = left * right;
        break;
    case '/':
        ret = left / right;
        break;
    default:
        break;
    }

    return ret;
}


int main()
{

    //後綴表達式
    char* str = "831-5*+";

    char* p = str;
    //創建棧
    LinkStack* stack = Init_LinkStack();

    while(*p != '\0'){
        //如果是數字，直接入棧
        if(IsNumber2(*p)){
            MyNum* num = (MyNum*)malloc(sizeof(MyNum));
            num -> val = *p - '0';
            Push_LinkStack(stack, (LinkNode*)num);
        }
        else{

            //先從棧中彈出右操作數
            MyNum* right = (MyNum*)Top_LinkStack(stack);
            int rightNum = right -> val;
            Pop_LinkStack(stack);
            free(right);
            //取出左操作數
            MyNum* left = (MyNum*)Top_LinkStack(stack);
            int leftNum = left -> val;
            Pop_LinkStack(stack);
            free(left);

            int ret = Calculate(leftNum, rightNum, *p);
            //結果入棧
            MyNum* num = (MyNum*)malloc(sizeof(MyNum));
            num -> val = ret;
            Push_LinkStack(stack, (LinkNode*)num);
        }
        p++;
    }

    if(Size_LinkStack(stack) == 1){
        MyNum* num = (MyNum*)Top_LinkStack(stack);
        printf("運算結果式:%d\n", num -> val);
        Pop_LinkStack(stack);
        free(num);
    }

    //釋放棧
    FreeSpace_LinkStack(stack);

    return 0;
}
