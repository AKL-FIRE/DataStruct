//
//  BinaryTree.hpp
//  maxHblt
//
//  Created by Apple  on 08/09/2017.
//  Copyright © 2017 lcy. All rights reserved.
//

#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include <iostream>

template <typename T>
struct binaryTreeNode
{
    T element;
    binaryTreeNode<T> *leftChild, *rightChild;
    binaryTreeNode() {leftChild = rightChild = nullptr;}
    binaryTreeNode(const T& theElement)
    {
        element = theElement;
        leftChild = rightChild = nullptr;
    }
    binaryTreeNode(const T& theElement,binaryTreeNode *theLeftChild,binaryTreeNode *theRightChild)
    {
        element = theElement;
        leftChild = theLeftChild;
        rightChild = theRightChild;
    }
};

template <typename T>
class binaryTree
{
public:
    virtual ~binaryTree() {}
    virtual bool empty() const = 0;
    virtual int size() const = 0;
    virtual void preOrder(void(*)(T *)) = 0;
    virtual void inOrder(void(*)(T *)) = 0;
    virtual void postOrder(void(*)(T *)) = 0;
    //virtual void levelOrder(void(*)(T *)) = 0;
};

#endif /* BinaryTree_hpp */
