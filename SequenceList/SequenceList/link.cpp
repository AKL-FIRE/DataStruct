//
//  link.cpp
//  SequenceList
//
//  Created by Apple  on 19/06/2017.
//  Copyright © 2017 Apple . All rights reserved.
//

#include "link.h"

linklist* CreateListF()
{
    linklist* head, *p;
    char ch;
    head = (linklist*)malloc(sizeof(linklist));
    head->next = NULL;
    while((ch = getchar()) != '\n')
    {
        p = (linklist*) malloc(sizeof(linklist));
        p->data = ch;
        p->next = head->next;
        head->next = p;
    }
    return head;
}

linklist* CreateListR()
{
    linklist *head,*p,*r;
    char ch;
    head = (linklist*)malloc(sizeof(linklist));
    r = head;
    while((ch = getchar()) != '\n')
    {
        p = (linklist*)malloc(sizeof(linklist));
        p->data = ch;
        r->next = p;
        r = p;
    }
    r->next = NULL;
    return head;
}

linklist* Get(linklist*head,int i)
{
    linklist* p = head;
    int j = 0;
    while(p->next != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    if(j == i)
        return p;
    else
        return NULL;
}

linklist *Locate(linklist* head,datatype key)
{
    linklist * p = head;
    while(p != NULL && p->data != key)
        p = p->next;
    if(p == NULL)
        return NULL;
    else
        return p;
}

void Insert(linklist* L, datatype x, int i)
{
    linklist *p, *s;
    p = Get(L, i - 1);
    if(p == NULL)
        printf("Can not find the i - 1 node.");
    else{
        s = (linklist*)malloc(sizeof(linklist));
        s->data = x;
        s->next = p->next;
        p->next = s;
    }
}

void Delete(linklist* L,int i)
{
    linklist *p, *r;
    p = Get(L, i - 1);
    if(p != NULL && p->next != NULL)
    {
        r = p->next;
        p->next = r->next;
        free(r);
    }
    else
        printf("The number of i is not existed.");
}

void output(linklist *L)
{
    linklist *p = L->next;
    while(p != NULL)
    {
        printf("%5c",p->data);
        p = p->next;
    }
}
