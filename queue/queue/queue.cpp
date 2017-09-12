//
//  queue.cpp
//  queue
//
//  Created by Apple  on 21/06/2017.
//  Copyright © 2017 Apple . All rights reserved.
//

#include "queue.hpp"
void InitQueue(SeQueue *&sq)
{
    sq = (SeQueue*)malloc(sizeof(SeQueue));
    sq->front = sq->rear = 0;
}

void setNull(SeQueue *sq)
{
    sq->front = sq->rear = 0;
}

int Length(SeQueue *sq)
{
    return (sq->rear - sq->front + maxsize) % maxsize;
}

int Enqueue(SeQueue *sq, datatype x)
{
    if(sq->front == (sq->rear + 1) % maxsize)
    {
        printf("overflow.");
        return 0;
    }else
    {
        sq->rear = (sq->rear + 1) % maxsize;
        sq->data[sq->rear] = x;
        return 1;
    }
}

int Dequeue(SeQueue *sq, datatype &x)
{
    if(sq->rear == sq->front)
    {
        printf("below flow.");
        return 0;
    }else
    {
        sq->front = (sq->front + 1) % maxsize;
        x = sq->data[sq->front];
        return 1;
    }
}

int GetFront(SeQueue *sq, datatype &x)
{
    if(sq->rear == sq->front)
    {
        printf("below flow.");
        return 0;
    }else
    {
        x = sq->data[(sq->front + 1) % maxsize];
        return 1;
    }
}

void output(SeQueue *sq)
{
    if(sq->front == sq->rear)
    {
        printf("empty.");
        exit(-1);
    }else
    {
        int p = sq->front + 1;
        while(p % maxsize != sq->rear % maxsize + 1)
        {
            printf("%3d",sq->data[(p % maxsize)]);
            p++;
        }
    }
}
