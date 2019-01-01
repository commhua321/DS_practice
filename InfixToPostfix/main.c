#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkStack.h"

typedef struct MYCHAR{
    LinkNode node;
    char* p;
}MyChar;

//判斷是否是數字
int IsNumber(char c){
    return c >= '0' && c <= '9';
}

//數字操作
void NumberOperator(char* c){
    printf("%c", *c);
}

//判斷是不是左括號
int IsLeft(char c){
    return c == '(';
}

//判斷是不是右括號
int IsRight(char c){
    return c == ')';
}

//判斷是不是運算符號
int IsOperator(char c){
    return c == '+' || c == '-' || c == '*' || c == '/';
}

//返回運算符號優先級
int GetPriority(char c){
    if(c == '*' || c == '/'){
        return 2;
    }
    if(c == '+' || c == '-'){
        return 1;
    }
    return 0;
}

//創建MyChar
MyChar* CreateMyChar(char* p){
    MyChar* mychar = (MyChar*)malloc(sizeof(MyChar));
    mychar -> p = p;
    return mychar;
}

//左括號的操作
void LeftOperator(LinkStack* stack, char* p){
    Push_LinkStack(stack, (LinkNode*)CreateMyChar(p));
}

//右括號操作
void RightOperator(LinkStack* stack){
    //先判斷棧中有無元素
    while(Size_LinkStack(stack) > 0){
        MyChar* mychar = (MyChar*)Top_LinkStack(stack);
        //如果匹配到左括號
        if(IsLeft(*(mychar -> p))){
            Pop_LinkStack(stack);
            break;
        }
        //輸出
        printf("%c", *(mychar -> p));
        //彈出
        Pop_LinkStack(stack);
        //釋放內存
        free(mychar);
    }
}

//運算符操作
void OperatorOperate(LinkStack* stack, char* p){

    //先取出棧頂符號
    MyChar* mychar = (MyChar*)Top_LinkStack(stack);
    if(mychar == NULL){
        Push_LinkStack(stack, (LinkNode*)CreateMyChar(p));
        return;
    }
    //如果棧頂優先級低於當前字符的優先級，直接入棧
    if(GetPriority(*(mychar -> p)) < GetPriority(*p)){
        Push_LinkStack(stack, (LinkNode*)CreateMyChar(p));
        return;
    }
    //如果棧頂符號優先級不低
    else{
        while(Size_LinkStack(stack) > 0){

            MyChar* mychar = (MyChar*)Top_LinkStack(stack);

            if(GetPriority(*(mychar -> p)) < GetPriority(*p)){
                Push_LinkStack(stack, (LinkNode*)CreateMyChar(p));
                return;
            }

            //輸出
            printf("%c", *(mychar -> p));
            //彈出
            Pop_LinkStack(stack);
            //釋放
            free(mychar);

        }
    }
}

int main()
{
    char* str = "8+(3-2)*5";
    char* p = str;

    //創建棧
    LinkStack* stack = Init_LinkStack();

    while(*p != '\0'){

        //如果是數字
        if(IsNumber(*p)){
            NumberOperator(p);
        }

        //如果左括號，直接進棧
        if(IsLeft(*p)){
            LeftOperator(stack, p);
        }

        //如果是右括號
        if(IsRight(*p)){
            RightOperator(stack);
        }

        //如果是運算符號
        if(IsOperator(*p)){
            OperatorOperate(stack, p);
        }
        p++;
    }

    while(Size_LinkStack(stack) > 0){
        MyChar* mychar = (MyChar*)Top_LinkStack(stack);
        printf("%c", *(mychar -> p));
        Pop_LinkStack(stack);
        free(mychar);
    }
    free(stack);


    return 0;
}
