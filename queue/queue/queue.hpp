//
//  queue.hpp
//  queue
//
//  Created by Apple  on 21/06/2017.
//  Copyright © 2017 Apple . All rights reserved.
//

#ifndef queue_hpp
#define queue_hpp

#include <stdio.h>
#include <stdlib.h>
#define maxsize 100
typedef char datatype;

typedef struct
{
    datatype data[maxsize];
    int front;
    int rear;
}SeQueue;

void InitQueue(SeQueue *&sq);
void setNull(SeQueue *sq);
int Length(SeQueue *sq);
int Enqueue(SeQueue *sq, datatype x);
int Dequeue(SeQueue *sq, datatype &x);
int GetFront(SeQueue *sq, datatype &x);
void output(SeQueue *sq);

#endif /* queue_hpp */
