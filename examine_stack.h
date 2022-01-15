/*
    deley to write.

    writting now.
    2022年3月27日

    为平衡二叉树而写的栈，之后再考虑扩展性。
*/

#ifndef _EXAMINE_STACK_H_
#define _EXAMINE_STACK_H_

#include <string.h>
#define NULL 0 /* 与标准一致*/

#define STACK_SIZE 1000

typedef struct my_stree{
    int data;

    struct my_stree * left;
    struct my_stree * right;
} *my_stree_p;

struct STACK {
    my_stree_p arr[STACK_SIZE];
    // my_stree_p p; /* 等于NULL 表示没有元素，如有元素始终指向最后一个元素*/
    int n; /* 元素的个数*/
}my_stack = {{NULL, }, 0}; /* 第一个元素数组全赋值为0，第二个元素表示栈元素的个数，赋值为0*/

my_stree_p get();
void push(my_stree_p pnode);

#endif // _EXAMINE_STACK_H_