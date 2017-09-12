//
//  linkstack.hpp
//  stack
//
//  Created by Apple  on 20/06/2017.
//  Copyright © 2017 Apple . All rights reserved.
//

#ifndef linkstack_hpp
#define linkstack_hpp

#include <stdio.h>
#include <stdlib.h>
#include <stack>

typedef char datatype;

typedef struct node{
    datatype data;
    struct node *next;
}StackNode;

typedef struct {
    StackNode *Top;
}LinkStack;

void InitStack(LinkStack *&S);
void setNull(LinkStack* S);
void Push(LinkStack *S, datatype e);
int Empty(LinkStack *S);
int Pop(LinkStack *S,datatype &e);
datatype GetTop(LinkStack *S);
void output(LinkStack* S);
char Precede(datatype e,char ch);
double Operate(double a, char op, double b);
void Conversion(int n, int base);

double EvaluateExpression();

#endif /* linkstack_hpp */
