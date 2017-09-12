//
//  main.cpp
//  bitree
//
//  Created by Apple  on 21/06/2017.
//  Copyright © 2017 Apple . All rights reserved.
//

#include "bithrtree.hpp"
/*
int main(int argc, const char * argv[]) {
    bitree *p;
    p = CREATREE();
    inorder(p);
    printf("\n");
    ninorder(p);
    printf("\n");
    layer(p);
    printf("\n");
    
    bitree *s;
    datatype preod[9] = {'A','B','H','F','D','E','C','K','G'};
    datatype inod[9] = {'H','B','D','F','A','E','K','C','G'};
    s = BPI(preod, inod, 0, 8, 0, 8);
    preorder(s);
    printf("\n");
    inorder(s);
}
*/


int main()
{
    BiThrNode *p;
    CreatBiTree(p);
    preorder(p);
    InThreading(p);
}
