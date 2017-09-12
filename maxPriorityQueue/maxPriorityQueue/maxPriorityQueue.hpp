//
//  maxPriorityQueue.hpp
//  maxPriorityQueue
//
//  Created by Apple  on 04/09/2017.
//  Copyright © 2017 lcy. All rights reserved.
//

#ifndef maxPriorityQueue_hpp
#define maxPriorityQueue_hpp

#include <iostream>
#include <string>
#include <algorithm>

template <typename T>
class maxPriorityQueue
{
public:
    virtual ~maxPriorityQueue() {}
    virtual bool empty() const = 0;
    virtual int size() const = 0;
    virtual const T& top() = 0;
    virtual void pop() = 0;
    virtual void push(const T& theElement) = 0;
};


#endif /* maxPriorityQueue_hpp */
