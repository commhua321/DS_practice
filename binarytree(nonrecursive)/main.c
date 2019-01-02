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

//�G�e�𪺫D���k�M��
typedef struct BITREESTACKNODE{
    LinkNode node;
    BinaryNode* root;
    int flag;
}BiTreeStackNode;

//�Ыش̤������I
BiTreeStackNode* CreateBiTreeStackNode(BinaryNode* node, int flag){
    BiTreeStackNode* newnode = (BiTreeStackNode*)malloc(sizeof(BiTreeStackNode));
    newnode -> root = node;
    newnode -> flag = flag;

    return newnode;
}





//�D���k�M��
void NonRecursive(BinaryNode* root){

    //�Ыش�
    LinkStack* stack = Init_LinkStack();
    //��ڵ��I��i�̸�
    Push_LinkStack(stack, (LinkNode*)CreateBiTreeStackNode(root, MY_FALSE));

    while(Size_LinkStack(stack) > 0){

        //���u�X�̳�����
        BiTreeStackNode* node = (BiTreeStackNode*)Top_LinkStack(stack);
        Pop_LinkStack(stack);

        //�P�_�u�X�����I�O�_����
        if(node -> root == NULL){
            continue;
        }

        if(node -> flag == MY_TRUE){
            printf("%c", node -> root -> ch);
        }
        else{
            //��e���I�k���I�J��
            Push_LinkStack(stack, (LinkNode*)CreateBiTreeStackNode(node -> root -> rchild, MY_FALSE));
            //��e���I�����I�J��
            Push_LinkStack(stack, (LinkNode*)CreateBiTreeStackNode(node -> root -> lchild, MY_FALSE));
            //��e���I�J��
            node -> flag = MY_TRUE;
            Push_LinkStack(stack, (LinkNode*)node);

        }
    }


}




void CreateBinaryTree(){

    //�Ыص��I
    BinaryNode node1 = {'A', NULL, NULL};
    BinaryNode node2 = {'B', NULL, NULL};
    BinaryNode node3 = {'C', NULL, NULL};
    BinaryNode node4 = {'D', NULL, NULL};
    BinaryNode node5 = {'E', NULL, NULL};
    BinaryNode node6 = {'F', NULL, NULL};
    BinaryNode node7 = {'G', NULL, NULL};
    BinaryNode node8 = {'H', NULL, NULL};

    //�إߵ��I���Y
    node1.lchild = &node2;
    node1.rchild = &node6;
    node2.rchild = &node3;
    node3.lchild = &node4;
    node3.rchild = &node5;
    node6.rchild = &node7;
    node7.lchild = &node8;


    //�G�e��D���k���L
    NonRecursive(&node1);



}



int main()
{

    CreateBinaryTree();


    return 0;
}
