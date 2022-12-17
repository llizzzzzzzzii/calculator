#include "btree.h"
#include <stdlib.h>
#include <stdio.h>
NODE* Add2Tree(NODE* root, int value)
{
    if (root==NULL)
    {
        root=(NODE*) malloc(sizeof (NODE));
        root->val=value;
        root->left=root->right=NULL;
    }
    else
    {
        if (value<root->val)
        {
            root->left= Add2Tree(root->left,value);
        }
        else
//        else if (value>root->val)
        {
            root->right= Add2Tree(root->right,value);
        }
    }
    return root;
}

NODE* DeleteTree(NODE* root)
{
    if (root)
    {
        root->left= DeleteTree(root->left);
        root->right= DeleteTree(root->right);
        free(root);
    }
    return NULL;
}

void simmetric(const NODE* root)
{
    if (root)
    {
        simmetric(root->left);
        printf("%5d",root->val);
        simmetric(root->right);
    }
}

void pre(const NODE* root)
{
    if (root)
    {
        printf("%5d",root->val);
        pre(root->left);
        pre(root->right);
    }
}

void post(const NODE* root)
{
    if (root)
    {
        post(root->left);
        post(root->right);
        printf("%5d",root->val);
    }
}

void PrintTreeOnSide(const NODE* root,int level)
{
    if (root)
    {
        PrintTreeOnSide(root->right,level+1);
        for (int i=0;i<level;++i)
            printf("\t");
        printf("%3d\n",root->val);
        PrintTreeOnSide(root->left,level+1);
    }
}

void Replace(NODE** root, int* val)
{
    if ((*root)->left)
        root=&(*root)->left;
    NODE* temp=(*root)->right;
    *val=(*root)->val;
    free(*root);
    *root=temp;
}

NODE* DelNode(NODE* root)
{
    if (root->left==NULL && root->right==NULL)
    {
        free(root);
        root=NULL;
    }
    else if (root->left && !root->right)
    {
        NODE* temp=root->left;
        free(root);
        root=temp;
    }
    else if (!root->left && root->right)
    {
        NODE* temp=root->right;
        free(root);
        root=temp;
    }
    else
    {
        int val=0;
        Replace(&root->right,&val);
        root->val=val;
    }
    return root;
}

NODE* DeleteFromTree(NODE* root, int value)
{
    if (root)
    {
        if (root->val==value)
        {
            root=DelNode(root);
        }
        else if (value<root->val)
            root->left= DeleteFromTree(root->left,value);
        else
            root->right= DeleteFromTree(root->right,value);
    }
    return root;
}