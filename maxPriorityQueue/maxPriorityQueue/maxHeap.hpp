//
//  maxHeap.hpp
//  maxPriorityQueue
//
//  Created by Apple  on 05/09/2017.
//  Copyright © 2017 lcy. All rights reserved.
//

#ifndef maxHeap_hpp
#define maxHeap_hpp

#include "maxPriorityQueue.hpp"
template <typename T>
class maxHeap : public maxPriorityQueue<T>
{
private:
    T* heap;
    int arrayLength;
    int heapSize;
public:
    maxHeap() : arrayLength(0), heapSize(0), heap(nullptr) {}
    bool empty() const;
    int size() const;
    const T& top();
    void pop();
    void push(const T& theElement);
    void initialize(T *theHeap, int theSize);
    void travel(void (*fun)(const T &element)) const;
    void deactivateArray();
};

class queueEmpty
{
private:
    std::string exception;
public:
    queueEmpty(const char * theExpression) : exception(theExpression) {std::cout << exception << std::endl;}
};

template<typename T>
bool maxHeap<T>::empty() const
{
    return (heapSize ? false : true);
}

template<typename T>
int maxHeap<T>::size() const
{
    return heapSize;
}

template<typename T>
const T& maxHeap<T>::top()
{
    if(!empty())
        return heap[1];
    else
        throw queueEmpty("Error,the heapSize is 0.");
}

template<typename T>
void maxHeap<T>::push(const T& theElement)
{
    if(heapSize == arrayLength - 1)
    {
        T* temp = new T[2 * arrayLength];
        std::copy(heap, heap + arrayLength - 1, temp);
        delete [] heap;
        heap = temp;
        arrayLength *= 2;
    }
    int currentNode = ++heapSize;
    while(currentNode != 1 && heap[currentNode / 2] < theElement)
    {
        heap[currentNode] = heap[currentNode / 2];
        currentNode /= 2;
    }
    heap[currentNode] = theElement;
}

template<typename T>
void maxHeap<T>::pop()
{
    if(heapSize == 0)
        throw queueEmpty("Error,the heapSize is 0.");
    heap[1].~T();
    T lastElemeny = heap[heapSize--];
    int currentNode = 1, child = 2;
    while(child <= heapSize)
    {
        if(child < heapSize && heap[child] < heap[child + 1])
            child++;
        if(lastElemeny >= heap[child])
            break;
        heap[currentNode] = heap[child];
        currentNode = child;
        child *= 2;
    }
    heap[currentNode] = lastElemeny;
}

template<typename T>
void maxHeap<T>::initialize(T *theHeap, int theSize)
{
    if(!empty())
        delete [] heap;
    heap = theHeap;
    heapSize = theSize;
    for(int root = heapSize / 2; root >= 1; root--)
    {
        T rootElement = heap[root];
        int child = 2 * root;
        while(child <= heapSize)
        {
            if(child < heapSize && heap[child] < heap[child + 1])
                child++;
            if(rootElement >= heap[child])
                break;
            heap[child / 2] = heap[child];
            child *= 2;
        }
        heap[child / 2] = rootElement;
    }
}

template<typename T>
void maxHeap<T>::travel(void (*fun)(const T &element)) const
{
    for(int i = 1; i <= heapSize; i++)
        (*fun)(heap[i]);
}

template<typename T>
void maxHeap<T>::deactivateArray()
{
    heap = nullptr;
}

template<typename T>
void heapSort(T a[],int n)
{
    maxHeap<T> heap;
    heap.initialize(a,n);
    for(int i = n - 1; i >= 1; i--)
    {
        T x = heap.top();
        heap.pop();
        a[i + 1] = x;
    }
    heap.deactivateArray();
}
#endif /* maxHeap_hpp */
