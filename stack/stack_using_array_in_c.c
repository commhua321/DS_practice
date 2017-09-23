#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*
stack using array in c
------------------------
my_stack* creat_stack(unsigned capacity);
------------------------
two main operations
void push(my_stack* stack, int item);
int pop(my_stack* stack);
------------------------
bool isfull(my_stack* stack);
bool isempty(my_stack* stack);
void display(my_stack* stack);
-------------------------
*/

struct my_Stack{
    int top;
    unsigned capacity;
    int* array;
};
typedef struct my_Stack my_stack;

my_stack* creat_stack(unsigned capacity){
    my_stack* stack = (my_stack*)malloc(sizeof(my_stack));
    stack -> capacity = capacity;
    stack -> top = -1;
    stack -> array = (int*)malloc(sizeof(int) * (stack -> capacity));
    return stack;
}

bool isfull(my_stack* stack){
    return stack -> top == stack -> capacity - 1;
}

bool isempty(my_stack* stack){
    return stack -> top == -1;
}

void push(my_stack* stack, int item){
    if (isfull(stack))      return;
    stack -> array[++stack->top] = item;
}

int pop(my_stack* stack){
    if (isempty(stack))     return INT_MIN;
    return stack -> array[stack->top--];
}

void display(my_stack* stack){
    printf("Stack: ");
    for(int i = 0 ; i <= (stack -> top) ; i++){
        printf("%d ",stack -> array[i]);
    }
    printf("\n");
}

int main()
{
    my_stack* stack = creat_stack(100);

    push(stack, 10);
    push(stack, 20);
    push(stack, 55);
    display(stack);
    pop(stack);
    display(stack);
    pop(stack);
    display(stack);
    pop(stack);
    display(stack);

    return 0;
}
