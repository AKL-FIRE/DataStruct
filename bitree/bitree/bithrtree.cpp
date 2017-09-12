//
//  bithrtree.cpp
//  bitree
//
//  Created by Apple  on 22/06/2017.
//  Copyright © 2017 Apple . All rights reserved.
//

#include "bithrtree.hpp"
BiThrNode *pre;
void CreatBiTree(BiThrNode *&T)
{
    char c;
    scanf("%c",&c);
    if(c == ' ')
    {
        T = NULL;
    }
    else if(c == '\n')
        return;
    else
    {
        T = (BiThrNode*)malloc(sizeof(BiThrNode));
        T->data = c;
        T->ltag = Link;
        T->rtag = Link;
        
        CreatBiTree(T->lchild);
        CreatBiTree(T->rchild);
    }
}

void preorder(BiThrNode *T)
{
    if(T != NULL)
    {
        printf("%3c",T->data);
        preorder(T->lchild);
        preorder(T->rchild);
    }
}

void InThreading(BiThrNode *T)
{
    if(T != NULL)
    {
        InThreading(T->lchild);
        
        if(!T->lchild)
        {
            T->ltag = Thread;
            T->lchild = pre;
        }
        if(!T->rchild)
        {
            T->rtag = Thread;
        }
        if(pre != NULL && pre->rtag == 1)
            pre->rchild = T;
        pre = T;
        
        InThreading(T->rchild);
    }
}
