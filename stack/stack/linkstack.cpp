//
//  linkstack.cpp
//  stack
//
//  Created by Apple  on 20/06/2017.
//  Copyright © 2017 Apple . All rights reserved.
//

#include "linkstack.hpp"
void InitStack(LinkStack *&S)
{
    S = (LinkStack*)malloc(sizeof(LinkStack));
    S->Top = NULL;
}

void setNull(LinkStack* S)
{
    S->Top = NULL;
}

void Push(LinkStack *S, datatype e)
{
    StackNode *p = (StackNode*)malloc(sizeof(StackNode));
    p->data = e;
    p->next = S->Top;
    S->Top = p;
}

int Empty(LinkStack *S)
{
    if(S->Top == NULL)
        return 1;
    else
        return 0;
}

int Pop(LinkStack *S,datatype &e)
{
    StackNode *p = S->Top;
    if(Empty(S))
    {
        printf("below flowed.");
        return 0;
    }else
    {
        e = p->data;
        S->Top = p->next;
        free(p);
        return 1;
    }
}

void output(LinkStack* S)
{
    StackNode *p = S->Top;
    while(p != NULL)
    {
        printf("%5d",p->data);
        p = p->next;
    }
}

datatype GetTop(LinkStack *S)
{
    if(S->Top == NULL)
    {
        printf("Empty.");
        exit(-1);
    }else
    {
        return S->Top->data;
    }
}

void Conversion(int n, int base)
{
    LinkStack *S;
    InitStack(S);
    while(n != 0)
    {
        Push(S, n % base);
        n /= base;
    }
    output(S);
    printf("\n");
}

char Precede(datatype e,char ch)
{
    if((e == '*' || e == '/') && (ch == '+' || ch == '-'))
        return '>';
    else if((e == '+' || e == '-') && (ch == '*' || ch == '/'))
        return '<';
    else if(ch == '(')
        return '<';
    else if(e == '#' && ch == '#')
        return '=';
    else if(e == '#')
        return '<';
    else if((e == '+' || e == '-' || e == '*' || e == '/') && ch == ')')
        return '>';
    else if(e == '(' && ch == ')')
        return '=';
    else if(e == '(')
        return '<';
    else if((e == '+' || e == '-' || e == '*' || e == '/') && ch == '#')
        return '>';
    else
        exit(-1);
}

double Operate(double a, char op, double b)
{
    if(op == '+')
        return a + b;
    else if(op == '-')
        return a - b;
    else if(op == '*')
        return a * b;
    else
        return a / b;
}

double EvaluateExpression()
{
    //LinkStack *OPTR,*OPND;
    char ch,op;
    double a,b,x;
    //InitStack(OPTR);
    //InitStack(OPND);
    std::stack<char> OPTR;
    std::stack<double> OPND;
    //Push(OPTR, '#');
    OPTR.push('#');
    while(((ch = getchar()) != '#') || (OPTR.top()) != '#')
    {
        if(ch == '\n')
            continue;
        if(ch != '+' && ch != '-' && ch != '*' && ch != '/' && ch != '(' && ch != ')' && ch != '#')
            OPND.push(ch - 48);
        else
            port:switch (Precede(OPTR.top(), ch)) {
                case '<':
                    OPTR.push(ch);
                    break;
                case '=':
                    OPTR.pop();
                    break;
                case '>':
                    //Pop(OPTR, op);
                    //Pop(OPND, a);
                    //Pop(OPND, b);
                    //x = Operate(b, op, a);
                    //Push(OPND, x);
                    op = OPTR.top();
                    OPTR.pop();
                    a = OPND.top();
                    OPND.pop();
                    b = OPND.top();
                    OPND.pop();
                    x = Operate(b, op, a);
                    OPND.push(x);
                   // OPTR.push(ch);
                    if(ch == ')')
                        goto port;
                    break;
            }
    }
    return OPND.top();
}
