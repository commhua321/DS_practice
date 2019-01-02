#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//二叉樹結點
typedef struct BINARYNODE{
    char ch;
    struct BINARYNODE* lchild;
    struct BINARYNODE* rchild;
}BinaryNode;

//拷貝二叉樹
BinaryNode* CopyBinaryTree(BinaryNode* root){
    if(root == NULL){
        return 0;
    }

    //拷貝左子樹
    BinaryNode* lchild = CopyBinaryTree(root -> lchild);
    //拷貝右子樹
    BinaryNode* rchild = CopyBinaryTree(root -> rchild);

    //創建結點
    BinaryNode* newnode = (BinaryNode*)malloc(sizeof(BinaryNode));
    newnode -> ch = root -> ch;
    newnode -> lchild = lchild;
    newnode -> rchild = rchild;

    return newnode;
}

//釋放二叉樹內存
void FreeSpaceBinaryTree(BinaryNode* root){
    if(root == NULL){
        return 0;
    }

    //釋放左子樹
    FreeSpaceBinaryTree(root -> lchild);
    //釋放右子樹
    FreeSpaceBinaryTree(root -> rchild);

    //釋放當前結點
    free(root);


}




//求二叉樹的高度
int CalculateTreeDepth(BinaryNode* root){
    if(root == NULL){
        return 0;
    }

    int depth = 0;
    int leftDepth = CalculateTreeDepth(root -> lchild);
    int rightDepth = CalculateTreeDepth(root -> rchild);
    depth = leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;

    return depth;

}

void CalculateLeafNum(BinaryNode* root, int* leafNum){
    if(root == NULL){
        return;
    }

    if(root -> lchild == NULL && root -> rchild == NULL){
        (*leafNum)++;
    }

    //左子樹葉子結點的數目
    CalculateLeafNum(root -> lchild, leafNum);
    //右子樹葉子結點的數目
    CalculateLeafNum(root -> rchild, leafNum);



}



//遞歸遍歷
void Recursion(BinaryNode* root){

    if(root == NULL){
        return;
    }


    //再遍歷左子樹
    Recursion(root -> lchild);
    //先訪問根結點
    printf("%c", root -> ch);
    //再遍歷右子樹
    Recursion(root -> rchild);


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

    //遞歸遍歷
    Recursion(&node1);
    printf("\n");

    int leafNum = 0;
    CalculateLeafNum(&node1, &leafNum);
    printf("葉子數目%d\n", leafNum);

    int depth = CalculateTreeDepth(&node1);
    printf("高度%d\n", depth);

    BinaryNode* root = CopyBinaryTree(&node1);
    Recursion(root);
    printf("\n");
    FreeSpaceBinaryTree(root);

}



int main()
{

    CreateBinaryTree();


    return 0;
}
