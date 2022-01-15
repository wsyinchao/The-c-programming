#include "examine_queue_h"

my_stree_p get()
{
    if (my_queue.front == my_queue.back){
        /* 没有元素*/
        return NULL;
    }

    if (my_queue.front >= QUEUE_SIZE){
        my_queue.front = 0; /* 跳转到0*/
    }

    return my_queue.arr[my_queue.front++];
}

void push(my_stree_p pnode)
{
    if (my_queue.back >= QUEUE_SIZE){
        my_queue.back = 0; /* 跳转到0*/
    }

    my_queue.arr[my_queue.back++] = pnode;
}
