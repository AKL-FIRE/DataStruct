//
//  maxHblt.hpp
//  maxHblt
//
//  Created by Apple  on 08/09/2017.
//  Copyright © 2017 lcy. All rights reserved.
//

#ifndef maxHblt_hpp
#define maxHblt_hpp

#include "linkedBinaryTree.hpp"
#include <utility>
#include <queue>

class queueEmpty
{
public:
    queueEmpty() {std::cout << "The queue is empty.";}
};

template <typename T>
class maxHblt : public linkedBinaryTree<std::pair<int, T>>
{
public:
    bool empty() const {return linkedBinaryTree<std::pair<int, T>>::treeSize ? false : true;}
    int size() const {return linkedBinaryTree<std::pair<int, T>>::treeSize;}
    const T& top() {return linkedBinaryTree<std::pair<int, T>>::root->element;}
    void meld(maxHblt<T> &theHblt);
    void push(const T& theElement);
    void pop();
    void initialize(T *theElement,int theSize);
private:
    void meld(binaryTreeNode<std::pair<int, T>>* &x,binaryTreeNode<std::pair<int, T>>* &y);
};

template <typename T>
void maxHblt<T>::meld(binaryTreeNode<std::pair<int, T>>* &x,binaryTreeNode<std::pair<int, T>>* &y)
{
    if(y == nullptr)
        return;
    if(x == nullptr)
    {x = y; return;}
    
    if(x->element.second < y->element.second)
        std::swap(x, y);
    
    meld(x->rightChild,y);
    
    if(x->leftChild == nullptr)
    {
        x->leftChild = x->rightChild;
        x->rightChild = nullptr;
        x->element.first = 1;
    }else
    {
        if(x->leftChild->element.first < x->rightChild->element.first)
            std::swap(x->leftChild, x->rightChild);
        x->element.first = x->rightChild->element.first + 1;
    }
}

template<typename T>
void maxHblt<T>::meld(maxHblt<T> &theHblt)
{
    meld(linkedBinaryTree<std::pair<int, T>>::root,theHblt.linkedBinaryTree<std::pair<int, T>>::root);
    linkedBinaryTree<std::pair<int, T>>::treeSize += theHblt.linkedBinaryTree<std::pair<int, T>>::treeSize;
    theHblt.linkedBinaryTree<std::pair<int, T>>::root = nullptr;
    theHblt.linkedBinaryTree<std::pair<int, T>>::treeSize = 0;
}

template <typename T>
void maxHblt<T>::push(const T& theElement)
{
    binaryTreeNode<std::pair<int, T>> *q = new binaryTreeNode<std::pair<int, T>> (std::pair<int, T>(1,theElement));
    meld(linkedBinaryTree<std::pair<int, T>>::root,q);
    linkedBinaryTree<std::pair<int, T>>::treeSize++;
}

template <typename T>
void maxHblt<T>::pop()
{
    if(linkedBinaryTree<std::pair<int, T>>::root == nullptr)
        throw queueEmpty();
    binaryTreeNode<std::pair<int, T>> *left = linkedBinaryTree<std::pair<int, T>>::root->leftChild,
    *right = linkedBinaryTree<std::pair<int, T>>::root->rightChild;
    
    delete linkedBinaryTree<std::pair<int, T>>::root;
    linkedBinaryTree<std::pair<int, T>>::root = left;
    meld(linkedBinaryTree<std::pair<int, T>>::root,right);
    linkedBinaryTree<std::pair<int, T>>::treeSize--;
}

template <typename T>
void maxHblt<T>::initialize(T *theElements, int theSize)
{
    std::queue<binaryTreeNode<std::pair<int, T>>*> q;
    linkedBinaryTree<std::pair<int, T>>::erase();
    
    for(int i = 1; i <= theSize; i++)
        q.push(new binaryTreeNode<std::pair<int, T>>(std::pair<int, T>(1,theElements[i])));
    
    for(int i = 1; i <= theSize - 1; i++)
    {
        binaryTreeNode<std::pair<int, T>> *b = q.front();
        q.pop();
        binaryTreeNode<std::pair<int, T>> *c = q.front();
        q.pop();
        meld(b,c);
        q.push(b);
    }
    
    if(theSize > 0)
        linkedBinaryTree<std::pair<int, T>>::root = q.front();
    linkedBinaryTree<std::pair<int, T>>::treeSize = theSize;
}
#endif /* maxHblt_hpp */
