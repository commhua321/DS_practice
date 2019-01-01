#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkStack.h"

typedef struct MYCHAR{
    LinkNode node;
    char* p;
}MyChar;

//�P�_�O�_�O�Ʀr
int IsNumber(char c){
    return c >= '0' && c <= '9';
}

//�Ʀr�ާ@
void NumberOperator(char* c){
    printf("%c", *c);
}

//�P�_�O���O���A��
int IsLeft(char c){
    return c == '(';
}

//�P�_�O���O�k�A��
int IsRight(char c){
    return c == ')';
}

//�P�_�O���O�B��Ÿ�
int IsOperator(char c){
    return c == '+' || c == '-' || c == '*' || c == '/';
}

//��^�B��Ÿ��u����
int GetPriority(char c){
    if(c == '*' || c == '/'){
        return 2;
    }
    if(c == '+' || c == '-'){
        return 1;
    }
    return 0;
}

//�Ы�MyChar
MyChar* CreateMyChar(char* p){
    MyChar* mychar = (MyChar*)malloc(sizeof(MyChar));
    mychar -> p = p;
    return mychar;
}

//���A�����ާ@
void LeftOperator(LinkStack* stack, char* p){
    Push_LinkStack(stack, (LinkNode*)CreateMyChar(p));
}

//�k�A���ާ@
void RightOperator(LinkStack* stack){
    //���P�_�̤����L����
    while(Size_LinkStack(stack) > 0){
        MyChar* mychar = (MyChar*)Top_LinkStack(stack);
        //�p�G�ǰt�쥪�A��
        if(IsLeft(*(mychar -> p))){
            Pop_LinkStack(stack);
            break;
        }
        //��X
        printf("%c", *(mychar -> p));
        //�u�X
        Pop_LinkStack(stack);
        //���񤺦s
        free(mychar);
    }
}

//�B��žާ@
void OperatorOperate(LinkStack* stack, char* p){

    //�����X�̳��Ÿ�
    MyChar* mychar = (MyChar*)Top_LinkStack(stack);
    if(mychar == NULL){
        Push_LinkStack(stack, (LinkNode*)CreateMyChar(p));
        return;
    }
    //�p�G�̳��u���ŧC���e�r�Ū��u���šA�����J��
    if(GetPriority(*(mychar -> p)) < GetPriority(*p)){
        Push_LinkStack(stack, (LinkNode*)CreateMyChar(p));
        return;
    }
    //�p�G�̳��Ÿ��u���Ť��C
    else{
        while(Size_LinkStack(stack) > 0){

            MyChar* mychar = (MyChar*)Top_LinkStack(stack);

            if(GetPriority(*(mychar -> p)) < GetPriority(*p)){
                Push_LinkStack(stack, (LinkNode*)CreateMyChar(p));
                return;
            }

            //��X
            printf("%c", *(mychar -> p));
            //�u�X
            Pop_LinkStack(stack);
            //����
            free(mychar);

        }
    }
}

int main()
{
    char* str = "8+(3-2)*5";
    char* p = str;

    //�Ыش�
    LinkStack* stack = Init_LinkStack();

    while(*p != '\0'){

        //�p�G�O�Ʀr
        if(IsNumber(*p)){
            NumberOperator(p);
        }

        //�p�G���A���A�����i��
        if(IsLeft(*p)){
            LeftOperator(stack, p);
        }

        //�p�G�O�k�A��
        if(IsRight(*p)){
            RightOperator(stack);
        }

        //�p�G�O�B��Ÿ�
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
