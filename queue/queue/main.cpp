//
//  main.cpp
//  queue
//
//  Created by Apple  on 21/06/2017.
//  Copyright © 2017 Apple . All rights reserved.
//

#include "linkqueue.hpp"
/*
int main(int argc, const char * argv[]) {
    
    SeQueue *p;
    InitQueue(p);
    for(int i = 0; i < 5;i++)
        Enqueue(p, i * 2);
    //printf("%5c",p->data[2 % 100]);
    datatype x;
    Dequeue(p, x);
    output(p);
}
*/

int main()
{
    LinkQueue *p;
    InitQueue(p);
    for(int i = 0; i < 5;i++)
        EnQueue(p, i + 1);
    datatype x;
    DeQueue(p, x);
    output(p);
}
