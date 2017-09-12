//
//  bithrtree.hpp
//  bitree
//
//  Created by Apple  on 22/06/2017.
//  Copyright © 2017 Apple . All rights reserved.
//

#ifndef bithrtree_hpp
#define bithrtree_hpp

#include <stdio.h>
#include <stdlib.h>


typedef char element;

typedef enum {Link, Thread} PointerTag;

typedef struct BiThrNode
{
    char data;
    struct BiThrNode *lchild, *rchild;
    PointerTag ltag;
    PointerTag rtag;
}BiThrNode, *BiThrTree;



void CreatBiTree(BiThrNode *&T);
void preorder(BiThrNode *T);
void InThreading(BiThrNode *T);

#endif /* bithrtree_hpp */
