#include "examine_stack_h"

my_stree_p get()
{
    if (my_stack.n == 0){
        /* 没有元素*/
        return NULL;
    }

    return my_stack.arr[--my_stack.n];
}

void push(my_stree_p pnode)
{
    if (my_stack.n >= STACK_SIZE){
        return ;
    }
    my_stack.arr[my_stack.n++] = pnode;
}
