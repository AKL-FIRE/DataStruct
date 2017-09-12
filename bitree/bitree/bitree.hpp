//
//  bitree.hpp
//  bitree
//
//  Created by Apple  on 21/06/2017.
//  Copyright © 2017 Apple . All rights reserved.
//

#ifndef bitree_hpp
#define bitree_hpp

#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <stack>

typedef char datatype;
typedef struct node
{
    datatype data;
    struct node *lchild, *rchild;
}bitree;

bitree* CREATREE();
void preorder(bitree *p);
void inorder(bitree *p);
void postorder(bitree *p);
void ninorder(bitree *T);
void layer(bitree *T);
bitree* BPI(datatype preod[], datatype inod[], int i,int j,int k,int h);

#endif /* bitree_hpp */
