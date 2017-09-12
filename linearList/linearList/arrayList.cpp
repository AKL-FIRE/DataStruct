//
//  arrayList.cpp
//  linearList
//
//  Created by Apple  on 2017/3/7.
//  Copyright © 2017年 Apple . All rights reserved.
//

#include "arrayList.h"

template<typename T>
arrayList<T>::arrayList(int initialCapacity)
{
    if(initialCapacity < 1)
    {
        std::ostringstream s;
        s << "Initial capacity = " << initialCapacity << "Must be > 0";
        throw illegalParameterValue(s.str());
    }
    arrayLength = initialCapacity;
    element = new T[arrayLength];
    listSize = 0;
}

template<typename T>
arrayList<T>::arrayList(const arrayList<T> &theList)
{
    arrayLength = theList.arrayLength;
    listSize = theList.listSize;
    element = new T[arrayLength];
    std::copy(theList.element, theList.element + listSize, element);
}

template<typename T>
void arrayList<T>::checkIndex(int theIndex) const
{
    if(theIndex < 0 || theIndex >= listSize)
    {
        std::ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw illegalIndex(s.str());
    }
}

template<typename T>
void arrayList<T>::changeLength1D(int newLength)
{
    if(newLength < 0)
        throw illegalParameterValue("new length must be >= 0");
    
    T* temp = new T[newLength];
    std::copy(element, element + listSize, temp);
    delete [] element;
    element = temp;
}

template<typename T>
T& arrayList<T>::get(int theIndex) const
{
    checkIndex(theIndex);
    return element[theIndex];
}

template<typename T>
int arrayList<T>::indexOf(const T &theElement) const
{
    int theIndex = (int) (std::find(element, element + listSize, theElement) - element);
    
    if(theIndex == listSize)
        return -1;
    else
        return theIndex;
}

template<typename T>
void arrayList<T>::erase(int theIndex)
{
    checkIndex(theIndex);
    
    std::copy(element + theIndex + 1, element + listSize, element + theIndex);
    
    element[--listSize].~T();
}

template<typename T>
void arrayList<T>::insert(int theIndex, const T &theElement)
{
    if(theIndex < 0 || theIndex > listSize)
    {
        std::ostringstream s;
        s << "index = " << theIndex << " size = " <<listSize;
        throw illegalIndex(s.str());
    }
    
    if(listSize == arrayLength)
    {
        changeLength1D(2 * arrayLength);
        arrayLength *= 2;
    }
    
    std::copy_backward(element + theIndex, element + listSize, element + listSize + 1);
    
    element[theIndex] = theElement;
    listSize++;
}

template<typename T>
void arrayList<T>::output(std::ostream &out) const
{
    for(int i = 0; i < listSize; i++)
        std::cout << element[i] << std::endl;
}

template<typename T>
std::ostream& operator<<(std::ostream &out, const arrayList<T> &x)
{
    x.output(out);
    return out;
}
