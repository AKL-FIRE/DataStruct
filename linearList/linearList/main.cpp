//
//  main.cpp
//  linearList
//
//  Created by Apple  on 2017/3/7.
//  Copyright © 2017年 Apple . All rights reserved.
//

#include "arrayList.h"

int main()
{
    arrayList<int> a(10);
    for(int i = 0; i < 10; i++)
        a.insert(i, i);
    std::cout << a;
}
