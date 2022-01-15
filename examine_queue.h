/*
    队列
*/

#ifndef _EXAMINE_QUEUE_H_
#define _EXAMINE_QUEUE_H_

#include <string.h>
#include "common.h"

#define NULL 0 /* 与标准一致*/

#define QUEUE_SIZE 1000

// typedef struct my_stree{
//     int data;

//     struct my_stree * left;
//     struct my_stree * right;
// } *my_stree_p;

struct QUEUE {
    my_stree_p arr[STACK_SIZE];
    // my_stree_p p; /* 等于NULL 表示没有元素，如有元素始终指向最后一个元素*/
    // int n; /* 元素的个数*/
    int front;
    int back;
}my_queue = {{NULL, }, 0, 0}; /* */

my_stree_p get();
void push(my_stree_p pnode);

#endif // _EXAMINE_STACK_H_