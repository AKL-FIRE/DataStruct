//
//  main.cpp
//  SequenceList
//
//  Created by Apple  on 19/06/2017.
//  Copyright © 2017 Apple . All rights reserved.
//

#include "link.h"

int main(int argc, const char * argv[]) {
    linklist* p = CreateListF();
    output(p);
    printf("\n");
    linklist *q = CreateListR();
    output(q);
    printf("\n");
    Insert(q, 'x', 4);
    output(q);
    printf("\n");
    Delete(q, 4);
    output(q);
    return 0;
}
