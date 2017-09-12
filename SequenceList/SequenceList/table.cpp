//
//  table.cpp
//  SequenceList
//
//  Created by Apple  on 19/06/2017.
//  Copyright © 2017 Apple . All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>

#define maxsize 1024
typedef int datatype;
typedef struct
{
    datatype data[maxsize];
    int last;
}sequenlist;

void InitList(sequenlist*&L)
{
    L = (sequenlist*) malloc(sizeof(sequenlist));
    L->last = 0;
}

sequenlist* InitList()
{
    sequenlist* L = (sequenlist*)malloc(sizeof(sequenlist));
    L->last = 0;
    return L;
}

int Insert(sequenlist*L,datatype x,int i)
{
    int j;
    if(L->last>=maxsize - 1 )
    {
        printf("Table is full.");
        return 0;
    }else if(i < 1 || i>L->last + 1)
    {
        printf("Invaild index to insert.");
        return 0;
    }else
    {
        for(j = L->last;j >= i;j--)
            L->data[j + 1] = L->data[j];
        L->data[i] = x;
        L->last++;
        return 1;
    }
}

int Delete(sequenlist*L,int i)
{
    int j;
    if(i < 1 || i > L->last)
    {
        printf("Invaild index to delete.");
        return 0;
    }else
    {
        for(j = i; j <= L->last - 1;j++)
            L->data[j] = L->data[j + 1];
        L->last--;
        return 1;
    }
}

void output(sequenlist* L)
{
    for(int i = 1; i <= L->last;i++)
        printf("%5d",L->data[i]);
}

