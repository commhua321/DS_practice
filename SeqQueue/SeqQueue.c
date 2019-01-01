#include "SeqQueue.h"


//��l��
SeqQueue* Init_SeqQueue(){
    SeqQueue* queue = (SeqQueue*)malloc(sizeof(SeqQueue));
    for(int i = 0 ; i < MAX_SIZE; i++){
        queue -> data[i] = NULL;
    }
    queue -> size = 0;
    return queue;
}

//�J��
void Push_SeqQueue(SeqQueue* queue, void* data){

    //�Ʋե����@���Y
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

//��^���Y����
void* Front_SeqQueue(SeqQueue* queue){
    if(queue == NULL){
        return NULL;
    }
    if(queue -> size == 0){
        return NULL;
    }
    return queue -> data[0];
}

//�X��
void Pop_SeqQueue(SeqQueue* queue){

    //�ݭn���ʤ���
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


//��^����������
void* Back_SeqQueue(SeqQueue* queue){
    if(queue == NULL){
        return NULL;
    }
    if(queue -> size == 0){
        return NULL;
    }
    return queue -> data[queue -> size - 1];
}

//��^�j�p
int Size_SeqQueue(SeqQueue* queue){
    if(queue == NULL){
        return -1;
    }
    return queue -> size;
}

//�M�Ŷ��C
void Clear_SeqQueue(SeqQueue* queue){
    if(queue == NULL){
        return;
    }
    queue -> size = 0;
}

//�P��
void Free_SeqQueue(SeqQueue* queue){
    if(queue == NULL){
        return;
    }
    free(queue);
}
