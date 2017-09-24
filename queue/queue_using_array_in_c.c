#include <stdio.h>
#include <stdlib.h>
/*
              front           rear
             _______________________
            |        |       |      |
  dequeue-- |   3    |   2   |   1  |--- enqueue
            |________|_______|______|
            |        |
            |  front |
            |________|
            |        |
            |  rear  |
            |________|
            |        |
            |  size  |
            |________|
            |        |
            |capacity|
            |________|
*/
struct my_Queue{
    int front, rear, size;
    unsigned capacity;
    int* array;
};

struct my_Queue* create_queue(unsigned capacity){
    struct my_Queue* queue = (struct my_Queue*)malloc(sizeof(struct my_Queue));
    queue -> capacity = capacity;
    queue -> front = 0;
    queue -> size = 0;
    queue -> rear = capacity - 1;  // circular array
    queue -> array = (int*)malloc(sizeof(int) * queue -> capacity);
    return queue;
}

int is_full(struct my_Queue* queue){
    return (queue -> size == queue -> capacity);
    }

int is_empty(struct my_Queue* queue){
    return (queue -> size == 0);
}

void enqueue(struct my_Queue* queue, int data){
    if(is_full(queue))      return;
    queue -> rear = (queue -> rear + 1) % (queue -> capacity);
    queue -> array[queue -> rear] = data;
    (queue -> size)++;
 //   printf("%d enqueued to queue\n", data);
}

int dequeue(struct my_Queue* queue){
    if(is_empty(queue))  return INT_MIN;
    int data = queue -> array[queue -> front];
    queue -> front = (queue -> front +1) % (queue -> capacity);
    (queue -> size)--;
    return data;
}

void display(struct my_Queue* queue){
    if(is_empty(queue)){
        printf("empty\n");
        return;
    }
    int index = (queue -> front);
    printf("queue: ");
    while(index != queue -> rear){
        printf("%d ",queue -> array[index]);
        index = (index + 1) % (queue -> capacity);
    }
    printf("%d\n",queue -> array[queue -> rear]);
}

int main()
{
    struct my_Queue* queue = create_queue(5);
    enqueue(queue,123);
    enqueue(queue,42);
    display(queue);
    enqueue(queue,121);
    enqueue(queue,27);
    enqueue(queue,99);
    display(queue);
    dequeue(queue);
    display(queue);

    return 0;
}
