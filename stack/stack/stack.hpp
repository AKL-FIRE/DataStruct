//
//  stack.hpp
//  stack
//
//  Created by Apple  on 19/06/2017.
//  Copyright © 2017 Apple . All rights reserved.
//

#ifndef stack_hpp
#define stack_hpp

#include <stdio.h>
#include <stdlib.h>
#define maxsize 1024
typedef int datatype;

typedef struct
{
    datatype data[maxsize];
    int Top;
}SeqStack;

void InitStack(SeqStack *&S);
void SetNull(SeqStack *S);
int Empty(SeqStack *S);
int Push(SeqStack* S, datatype e);
int Pop(SeqStack *S, datatype &e);
int GetTop(SeqStack *S, datatype &e);
void output(SeqStack *S);


#endif /* stack_hpp */
