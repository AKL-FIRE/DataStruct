//
//  linkqueue.cpp
//  queue
//
//  Created by Apple  on 21/06/2017.
//  Copyright © 2017 Apple . All rights reserved.
//

#include "linkqueue.hpp"
void InitQueue(LinkQueue *&q)
{
    q = (LinkQueue*)malloc(sizeof(LinkQueue));
    q->front = q->rear = (QueueNode*)malloc(sizeof(QueueNode));
    q->front->next = NULL;
}

void setNull(LinkQueue *q)
{
    q->rear = q->front;
    q->front->next = NULL;
}

int Empty(LinkQueue *q)
{
    if(q->front == q->rear)
        return 1;
    else
        return 0;
}

void EnQueue(LinkQueue *q, datatype x)
{
    q->rear->next = (QueueNode*)malloc(sizeof(QueueNode));
    q->rear = q->rear->next;
    q->rear->data = x;
    q->rear->next = NULL;
}

int DeQueue(LinkQueue *q,datatype &x)
{
    QueueNode *s;
    if(Empty(q))
    {
        printf("below flow.");
        return 0;
    }else
    {
        s = q->front->next;
        if(s->next ==NULL)
        {
            q->front->next = NULL;
            q->rear = q->front;
        }else
            q->front->next = s->next;
        x = s->data;
        free(s);
        return 1;
    }
}

int GetFront(LinkQueue *q, datatype &x)
{
    if(Empty(q))
    {
        printf("below flow.");
        return 0;
    }else
    {
        x = q->front->next->data;
        return 1;
    }
}

void output(LinkQueue *q)
{
    if(Empty(q))
    {
        printf("empty.");
        exit(-1);
    }else
    {
        QueueNode *p = q->front->next;
        while(p != NULL)
        {
            printf("%3d",p->data);
            p = p->next;
        }
    }
}
