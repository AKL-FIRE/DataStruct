//
//  bitree.cpp
//  bitree
//
//  Created by Apple  on 21/06/2017.
//  Copyright © 2017 Apple . All rights reserved.
//

#include "bitree.hpp"

bitree* CREATREE()
{
    char ch;
    bitree *q[100];
    int front, rear;
    bitree *root, *s;
    root = NULL;
    front = 1;
    rear = 0;
    while((ch = getchar()) != '#')
    {
        s = NULL;
        if(ch != '@')
        {
            s = (bitree*)malloc(sizeof(bitree));
            s->data = ch;
            s->lchild = NULL;
            s->rchild = NULL;
        }
        rear++;
        q[rear] = s;
        if(rear == 1)
            root = s;
        else
        {
            if(s && q[front])
                if(rear % 2 == 0)
                    q[front]->lchild = s;
                else
                {
                    q[front]->rchild = s;
                }
            if(rear % 2 == 1)
                front++;
        }
    }
    return root;
}

void preorder(bitree *p)
{
    if(p != NULL)
    {
        printf("%3c",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void inorder(bitree *p)
{
    if(p != NULL)
    {
        inorder(p->lchild);
        printf("%3c",p->data);
        inorder(p->rchild);
    }
}

void postorder(bitree *p)
{
    if(p != NULL)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%3c",p->data);
    }
}

void ninorder(bitree *T)
{
    std::stack<bitree*> stk;
    bitree *p = T;
    while(p != NULL || !stk.empty())
    {
        if(p != NULL)
        {
            stk.push(p);
            p = p->lchild;
        }else
        {
            p = stk.top();
            stk.pop();
            printf("%3c",p->data);
            p = p->rchild;
        }
    }
}

void layer(bitree *T)
{
    std::queue<bitree*> que;
    bitree *p;
    if(T != NULL)
        que.push(T);
    else
    {
        printf("The tree is empty.");
        exit(-1);
    }
    while(!que.empty())
    {
        p = que.front();
        printf("%3c",p->data);
        que.pop();
        if(p->lchild != NULL)
            que.push(p->lchild);
        if(p->rchild != NULL)
            que.push(p->rchild);
    }
}

bitree* BPI(datatype preod[], datatype inod[], int i,int j,int k,int h)
{
    int m;
    bitree *p;
    p = (bitree*)malloc(sizeof(bitree));
    p->data = preod[i];
    m = k;
    while(inod[m] != preod[i])
        m++;
    if(m == k)
        p->lchild = NULL;
    else
        p->lchild = BPI(preod, inod, i+1, i+m-k, k, m-1);
    if(m == h)
        p->rchild = NULL;
    else
        p->rchild = BPI(preod, inod, i+m-k+1, j, m+1, h);
    return p;
}
