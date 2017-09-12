//
//  arrayList.h
//  linearList
//
//  Created by Apple  on 2017/3/7.
//  Copyright © 2017年 Apple . All rights reserved.
//

#ifndef arrayList_h
#define arrayList_h

#include "linearList.h"

template <typename T>
class arrayList : public linearList<T>
{
public:
    arrayList(int initialCapacity = 10);
    arrayList(const arrayList<T>&);
    ~arrayList() {delete [] element;}
    
    bool empty() const {return listSize == 0;}
    int size() const {return listSize;}
    T& get(int theIndex) const;
    int indexOf(const T& theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T& theElement);
    void output(std::ostream& out) const;
    friend std::ostream& operator<<(std::ostream &out, const arrayList<T> &x);
    
    int capacity() const {return arrayLength;}
private:
    void checkIndex(int theIndex) const;
    void changeLength1D(int newLength);
    
    T* element;
    int arrayLength;
    int listSize;
};


#endif /* arrayList_h */
