/*
    一些需要在多个文件中出现的声明或者定义
*/

#ifndef _COMMON_H_
#define _COMMON_H_

typedef struct my_stree{
    int data;

    struct my_stree * left;
    struct my_stree * right;
} *my_stree_p, my_tree;

#endif // _COMMON_H_