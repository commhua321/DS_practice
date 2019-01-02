#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//二叉樹結點
typedef struct BINARYNODE{
    char ch;
    struct BINARYNODE* lchild;
    struct BINARYNODE* rchild;
}BinaryNode;

void Recursion(BinaryNode* root){
    if(root == NULL){
        return;
    }
    printf("%c", root -> ch);
    Recursion(root -> lchild);
    Recursion(root -> rchild);

}

BinaryNode* CreateBinaryTree(){

    fflush(stdin);
    char ch;
    scanf("%c", &ch);

    BinaryNode* node;
    BinaryNode* lchild;
    BinaryNode* rchild;
    if(ch == '#'){
        node = NULL;
    }
    else{

        node = (BinaryNode*)malloc(sizeof(BinaryNode));
        node -> ch = ch;
        node -> lchild = CreateBinaryTree();
        node -> rchild = CreateBinaryTree();
    }

    return node;



}

int main()
{
    //創建樹
    BinaryNode* root = CreateBinaryTree();
    //打印樹
    Recursion(root);

    return 0;
}
