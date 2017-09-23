#include <stdio.h>
#include <stdlib.h>
/*
              front           rear
             _______________________
            |      |       |       |
  dequeue-- |   3  |   2   |   1   |--- enqueue
            |______|_______|_______|
               ^                ^
               |                |
               |   _________    |
               |  |         |   |
               |__|  front  |   |
                  |_________|   |
                  |         |   |
                  |  rear   |----
                  |_________|
                    my_Queue
*/
struct quenode{
    int data;
    struct quenode* next;
};

struct my_Queue{
    struct quenode* front;
    struct quenode* rear;
};

struct quenode* newnode(int data){
    struct quenode* temp = (struct quenode*)malloc(sizeof(struct quenode));
    temp -> data = data;
    temp -> next = NULL;
    return temp;
}

void init(struct my_Queue* que){
    que -> front = NULL;
    que -> rear = NULL;

}

void enqueue(struct my_Queue* q, int data){
    struct quenode* temp = newnode(data);
    if(q -> rear == NULL){
        q -> rear = temp;
        q -> front = temp;
        return;
    }
    q -> rear -> next = temp;
    q -> rear = temp;
}

int dequeue(struct my_Queue* q){
    if(q -> front == NULL){
        return;
    }
    int n = q -> front -> data;
    struct quenode* temp = q -> front;
    q -> front = q -> front -> next;
    if(q -> front == NULL)      q -> rear =NULL;
    free(temp);
    return n;
}

void display(struct my_Queue* q){
    if(q -> front == NULL){
        printf("empty\n");
        return;
    }
    else{
        display_node(q -> front);
        printf("\n");
    }
}
void display_node(struct quenode* head){
    if(head != NULL) {
        printf("%d ", head -> data);
        display_node(head->next);
    }
}

int main()
{
    struct my_Queue* q = (struct my_Queue*)malloc(sizeof(struct my_Queue));
    init(q);


    enqueue(q, 77);
    enqueue(q, 42);
    enqueue(q, 12);
    display(q);
    enqueue(q, 50);
    display(q);
    dequeue(q);
    display(q);
    dequeue(q);
    display(q);
    dequeue(q);
    display(q);
    dequeue(q);
    display(q);




    return 0;
}
