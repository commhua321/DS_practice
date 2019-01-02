#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//�G�e���I
typedef struct BINARYNODE{
    char ch;
    struct BINARYNODE* lchild;
    struct BINARYNODE* rchild;
}BinaryNode;

//�����G�e��
BinaryNode* CopyBinaryTree(BinaryNode* root){
    if(root == NULL){
        return 0;
    }

    //�������l��
    BinaryNode* lchild = CopyBinaryTree(root -> lchild);
    //�����k�l��
    BinaryNode* rchild = CopyBinaryTree(root -> rchild);

    //�Ыص��I
    BinaryNode* newnode = (BinaryNode*)malloc(sizeof(BinaryNode));
    newnode -> ch = root -> ch;
    newnode -> lchild = lchild;
    newnode -> rchild = rchild;

    return newnode;
}

//����G�e�𤺦s
void FreeSpaceBinaryTree(BinaryNode* root){
    if(root == NULL){
        return 0;
    }

    //���񥪤l��
    FreeSpaceBinaryTree(root -> lchild);
    //����k�l��
    FreeSpaceBinaryTree(root -> rchild);

    //�����e���I
    free(root);


}




//�D�G�e�𪺰���
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

    //���l�𸭤l���I���ƥ�
    CalculateLeafNum(root -> lchild, leafNum);
    //�k�l�𸭤l���I���ƥ�
    CalculateLeafNum(root -> rchild, leafNum);



}



//���k�M��
void Recursion(BinaryNode* root){

    if(root == NULL){
        return;
    }


    //�A�M�����l��
    Recursion(root -> lchild);
    //���X�ݮڵ��I
    printf("%c", root -> ch);
    //�A�M���k�l��
    Recursion(root -> rchild);


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

    //���k�M��
    Recursion(&node1);
    printf("\n");

    int leafNum = 0;
    CalculateLeafNum(&node1, &leafNum);
    printf("���l�ƥ�%d\n", leafNum);

    int depth = CalculateTreeDepth(&node1);
    printf("����%d\n", depth);

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
