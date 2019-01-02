#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkStack.h"

#define MY_FALSE 0
#define MY_TRUE 1

typedef struct BINARYNODE{
    char ch;
    struct BINARYNODE* lchild;
    struct BINARYNODE* rchild;
}BinaryNode;

//二叉樹的非遞歸遍歷
typedef struct BITREESTACKNODE{
    LinkNode node;
    BinaryNode* root;
    int flag;
}BiTreeStackNode;

//創建棧中的結點
BiTreeStackNode* CreateBiTreeStackNode(BinaryNode* node, int flag){
    BiTreeStackNode* newnode = (BiTreeStackNode*)malloc(sizeof(BiTreeStackNode));
    newnode -> root = node;
    newnode -> flag = flag;

    return newnode;
}





//非遞歸遍歷
void NonRecursive(BinaryNode* root){

    //創建棧
    LinkStack* stack = Init_LinkStack();
    //把根結點放進棧裡
    Push_LinkStack(stack, (LinkNode*)CreateBiTreeStackNode(root, MY_FALSE));

    while(Size_LinkStack(stack) > 0){

        //先彈出棧頂元素
        BiTreeStackNode* node = (BiTreeStackNode*)Top_LinkStack(stack);
        Pop_LinkStack(stack);

        //判斷彈出的結點是否為空
        if(node -> root == NULL){
            continue;
        }

        if(node -> flag == MY_TRUE){
            printf("%c", node -> root -> ch);
        }
        else{
            //當前結點右結點入棧
            Push_LinkStack(stack, (LinkNode*)CreateBiTreeStackNode(node -> root -> rchild, MY_FALSE));
            //當前結點左結點入棧
            Push_LinkStack(stack, (LinkNode*)CreateBiTreeStackNode(node -> root -> lchild, MY_FALSE));
            //當前結點入棧
            node -> flag = MY_TRUE;
            Push_LinkStack(stack, (LinkNode*)node);

        }
    }


}




void CreateBinaryTree(){

    //創建結點
    BinaryNode node1 = {'A', NULL, NULL};
    BinaryNode node2 = {'B', NULL, NULL};
    BinaryNode node3 = {'C', NULL, NULL};
    BinaryNode node4 = {'D', NULL, NULL};
    BinaryNode node5 = {'E', NULL, NULL};
    BinaryNode node6 = {'F', NULL, NULL};
    BinaryNode node7 = {'G', NULL, NULL};
    BinaryNode node8 = {'H', NULL, NULL};

    //建立結點關係
    node1.lchild = &node2;
    node1.rchild = &node6;
    node2.rchild = &node3;
    node3.lchild = &node4;
    node3.rchild = &node5;
    node6.rchild = &node7;
    node7.lchild = &node8;


    //二叉樹非遞歸打印
    NonRecursive(&node1);



}



int main()
{

    CreateBinaryTree();


    return 0;
}
