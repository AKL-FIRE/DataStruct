//
//  stack.cpp
//  stack
//
//  Created by Apple  on 19/06/2017.
//  Copyright © 2017 Apple . All rights reserved.
//

#include "stack.hpp"
void InitStack(SeqStack *&S)
{
    S = (SeqStack*)malloc(sizeof(SeqStack));
    S->Top = 0;
}

void SetNull(SeqStack *S)
{
    S->Top = 0;
}

int Empty(SeqStack *S)
{
    if(S->Top <= 0)
        return 1;
    else
        return 0;
}

int Push(SeqStack* S, datatype e)
{
    if(S->Top >= maxsize - 1)
    {
        printf("stack overflow.");
        return 0;
    }else
    {
        S->data[++S->Top] = e;
        return 1;
    }
}

int Pop(SeqStack *S, datatype &e)
{
    if(Empty(S))
    {
        printf("stack belowflow.");
        return 0;
    }else
    {
        e = S->data[S->Top--];
        return 1;
    }
}

int GetTop(SeqStack *S, datatype &e)
{
    if(Empty(S))
    {
        printf("stack is empty.");
        return 0;
    }else
    {
        e = S->data[S->Top];
        return 1;
    }
}

void output(SeqStack *S)
{
    if(Empty(S))
        printf("stack is empty.");
    for(int i = 1;i <= S->Top; i++)
        printf("%5d",S->data[i]);
}
