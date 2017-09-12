//
//  linkqueue.hpp
//  queue
//
//  Created by Apple  on 21/06/2017.
//  Copyright © 2017 Apple . All rights reserved.
//

#ifndef linkqueue_hpp
#define linkqueue_hpp

#include <stdio.h>
#include <stdlib.h>

typedef int datatype;
typedef struct node
{
    datatype data;
    struct node *next;
}QueueNode;
typedef struct
{
    QueueNode *front, *rear;
}LinkQueue;

void InitQueue(LinkQueue *&q);
void setNull(LinkQueue *q);
int Empty(LinkQueue *q);
void EnQueue(LinkQueue *q, datatype x);
int DeQueue(LinkQueue *q,datatype &x);
int GetFront(LinkQueue *q, datatype &x);
void output(LinkQueue *q);
#endif /* linkqueue_hpp */
