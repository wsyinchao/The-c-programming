/*
    平衡二叉树之 AVL树
    二叉树，每一个节点加一个平衡因子，维持二叉树的平衡
*/

#include <stdio.h>
#include "examine_queue.h"

// typedef struct my_stree{
//     int data;

//     struct my_stree * left;
//     struct my_stree * right;
// }*my_tree_p;

my_tree_p addTree(my_tree_p root);
void printTree(my_tree_p root);

int main(int argc, char **argv)
{

    return 0;
}

my_tree_p addTree(my_tree_p root, int data)
{
    if (root == NULL){
        root->data = data;
        root->left = NULL;
        root->right = NULL;

        return root;
    }

    if (data < root->data){
        return addTree(root->left, data);
    }
    else {
        return addTree(root->right, data);
    }
}

void printTree(my_tree_p root)
{
    /* 层级遍历*/

    /* 借助队列，层级打印*/
    push(root);

    /* 这个层级遍历还存在一个问题，顺序是对的，但是没有体现树的结构，我希望每一层打印一个回车符号*/
    /* 怎么一层打印一个回车符号呢？怎么知道一层打印完了呢？*/
    my_tree_p p_tree;
    while ((p_tree = get()) != NULL){
        printf("%d ", p_tree->data);

        if (p_tree->left != NULL){
            push(p_tree->left);
        }
        if (p_tree->right != NULL){
            push(p_tree->right);
        }
    }

    printf("\n");
}