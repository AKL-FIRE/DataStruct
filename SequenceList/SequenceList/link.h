//
//  link.h
//  SequenceList
//
//  Created by Apple  on 19/06/2017.
//  Copyright © 2017 Apple . All rights reserved.
//

#ifndef link_h
#define link_h
#include <stdio.h>
#include <stdlib.h>
typedef char datatype;
typedef struct node
{
    datatype data;
    struct node* next;
}linklist;

linklist* CreateListF();
linklist* CreateListR();
linklist* Get(linklist*head,int i);
linklist *Locate(linklist* head,datatype key);
void Insert(linklist* L, datatype x, int i);
void Delete(linklist* L,int i);
void output(linklist *L);

#endif /* link_h */
