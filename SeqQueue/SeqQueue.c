#include "SeqQueue.h"


//初始化
SeqQueue* Init_SeqQueue(){
    SeqQueue* queue = (SeqQueue*)malloc(sizeof(SeqQueue));
    for(int i = 0 ; i < MAX_SIZE; i++){
        queue -> data[i] = NULL;
    }
    queue -> size = 0;
    return queue;
}

//入隊
void Push_SeqQueue(SeqQueue* queue, void* data){

    //數組左邊當作隊頭
    if(queue == NULL){
        return;
    }
    if(data == NULL){
        return;
    }

    if(queue -> size == MAX_SIZE){
        return;
    }
    queue -> data[queue -> size] = data;
    queue -> size++;

}

//返回隊頭元素
void* Front_SeqQueue(SeqQueue* queue){
    if(queue == NULL){
        return NULL;
    }
    if(queue -> size == 0){
        return NULL;
    }
    return queue -> data[0];
}

//出隊
void Pop_SeqQueue(SeqQueue* queue){

    //需要移動元素
    if(queue == NULL){
        return;
    }
    if(queue -> size == 0){
        return;
    }

    for(int i = 0 ; i < queue -> size - 1 ; i++){
        queue -> data[i] = queue -> data[i + 1];
    }
    queue -> size--;
}


//返回隊尾的元素
void* Back_SeqQueue(SeqQueue* queue){
    if(queue == NULL){
        return NULL;
    }
    if(queue -> size == 0){
        return NULL;
    }
    return queue -> data[queue -> size - 1];
}

//返回大小
int Size_SeqQueue(SeqQueue* queue){
    if(queue == NULL){
        return -1;
    }
    return queue -> size;
}

//清空隊列
void Clear_SeqQueue(SeqQueue* queue){
    if(queue == NULL){
        return;
    }
    queue -> size = 0;
}

//銷毀
void Free_SeqQueue(SeqQueue* queue){
    if(queue == NULL){
        return;
    }
    free(queue);
}
