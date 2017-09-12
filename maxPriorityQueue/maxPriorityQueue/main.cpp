//
//  main.cpp
//  maxPriorityQueue
//
//  Created by Apple  on 04/09/2017.
//  Copyright © 2017 lcy. All rights reserved.
//

#include "maxHeap.hpp"

void (*pFun)(const int&);
void print(const int &a) {std::cout << a << "  ";}

int main(int argc, const char * argv[]) {
    pFun = print;
    maxHeap<int> a;
    int x[11] = {0,20,12,35,15,10,80,30,17,2,1};
    a.initialize(x, 10);
    a.travel(pFun);
    std::cout << std::endl;
    a.push(21);
    a.push(24);
    a.push(33);
    a.travel(pFun);
    std::cout << std::endl;
    a.pop();
    a.travel(pFun);
    std::cout << std::endl;
    int d[11] = {0,20,12,35,15,10,80,30,17,2,1};
    heapSort(d, 10);
    for(int i = 1 ; i < 11 ; i++)
        std::cout << d[i] << "   ";
    return 0;
}
