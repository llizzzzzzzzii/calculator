//
// Created by liza on 14.02.2022.
//

#ifndef CALCULATOR_BTREE_H
#define CALCULATOR_BTREE_H

typedef struct node
{
    int val;
    struct node *left;
    struct node *right;
}NODE;

NODE* Add2Tree(NODE * root, int value);
NODE* DeleteTree(NODE * root);
void simmetric(const NODE* root);
void pre(const NODE* root);
void post(const NODE* root);
void PrintTreeOnSide(const NODE* root,int level);
NODE* DeleteFromTree(NODE* root, int value);


#endif //CALCULATOR_BTREE_H
