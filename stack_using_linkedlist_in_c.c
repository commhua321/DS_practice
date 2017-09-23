#include <stdio.h>
#include <stdlib.h>
//version 1

struct StackNode{
    int data;
    struct StackNode* next;
};
/*
----------------------------
        head
     --------->  NULL

----------------------------
*/
void init(struct StackNode* head){
    head = NULL;
}

/*
-----------------------------|
     |                       |
     |  head                 |
     v                       |
   _____________             |
  |        |    |            |
  |    1   |    |----->  NULL|
  |________|____|            |
------------------------------
*/
struct StackNode* push(struct StackNode* head, int data){
    struct StackNode* temp = (struct StackNode*)malloc(sizeof(struct StackNode));
    if(temp == NULL)    exit(0);
    temp -> data = data;
    temp -> next = head;
    head = temp;
    return head;
}

struct StackNode* pop(struct StackNode* head, int *element){
    struct StackNode* temp = head;
    *element = head -> data;
    head = head -> next;
    free(temp);
    return head;
}
int isempty(struct StackNode* head){
    return !head;

}
int peek(struct StackNode* head){
    if(isempty(head)){
        return INT_MIN;
    }
    return head -> data;
}

void display(struct StackNode* head){
    struct StackNode* current;
    current = head;
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

int main(){
    struct StackNode* head = NULL;
    int element = 0;
    head = push(head, 30);
    head = push(head, 39);
    head = push(head, 77);
    display(head);
    head = pop(head, &element);
    display(head);
    return 0;
}
