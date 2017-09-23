#include <stdio.h>
#include <stdlib.h>
struct StackNode{
    int data;
    struct StackNode* next;
};

struct StackNode* newnode(int data){
    struct StackNode* stacknode = (struct StackNode*)malloc(sizeof(struct StackNode));
    stacknode -> data = data;
    stacknode -> next = NULL;
    return stacknode;
}

int isempty(struct StackNode* root){
    return !root;
}
void push(struct StackNode** root, int data){
    struct StackNode* stacknode = newnode(data);
    stacknode -> next = *root;
    *root = stacknode;
}

int pop(struct StackNode** root){
    if(isempty(root))   return INT_MIN;
    struct StackNode* temp = *root;
    *root = (*root) -> next;
    int popped = temp -> data;
    free(temp);
    return popped;
}

void display(struct StackNode* root){
    struct StackNode* current;
    current = root;
    if(current != NULL){
            printf("Stack: ");
        do{
            printf("%d ",current -> data);
            current = current -> next;
        }while(current != NULL);
        printf("\n");
    }
    else{
        printf("the stack is empty\n");
    }
}
int main()
{
    struct StackNode* root = NULL;

    push(&root, 10);
    push(&root, 55);
    push(&root, 23);
    display(root);
    pop(&root);
    display(root);
    return 0;
}
