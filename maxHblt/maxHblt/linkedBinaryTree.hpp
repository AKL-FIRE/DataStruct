//
//  linkedBinaryTree.hpp
//  maxHblt
//
//  Created by Apple  on 08/09/2017.
//  Copyright © 2017 lcy. All rights reserved.
//

#ifndef linkedBinaryTree_hpp
#define linkedBinaryTree_hpp

#include "BinaryTree.hpp"

template <typename T>
class linkedBinaryTree : public binaryTree<binaryTreeNode<T>>
{
public:
    linkedBinaryTree() {root = nullptr; treeSize = 0;}
    ~linkedBinaryTree() {erase();}
    bool empty() const {return treeSize == 0;}
    int size() const {return treeSize;}
    void preOrder(void(*theVisit)(binaryTreeNode<T>*))
    {visit = theVisit; preOrder(root);}
    void inOrder(void(*theVisit)(binaryTreeNode<T>*))
    {visit = theVisit; inOrder(root);}
    void postOrder(void(*theVisit)(binaryTreeNode<T>*))
    {visit = theVisit; postOrder(root);}
    //void levelOrder(void(*)(binaryTreeNode<T>*));
    void preOrderOutput() {preOrder(output);std::cout << std::endl;}
    
protected:
    binaryTreeNode<T> *root;
    int treeSize;
    void erase()
    {
        postOrder(dispose);
        root = nullptr;
        treeSize = 0;
    }
    static void (*visit)(binaryTreeNode<T> *t);
    static void preOrder(binaryTreeNode<T> *t);
    static void inOrder(binaryTreeNode<T> *t);
    static void postOrder(binaryTreeNode<T> *t);
    static void dispose(binaryTreeNode<T> *t) {delete t;}
    static void output(binaryTreeNode<T> *t) {std::cout << &t->element << "  ";}
};

//template<> void (*linkedBinaryTree<std::pair<int,int> >::visit)(binaryTreeNode<std::pair<int,int> >*) = linkedBinaryTree::output;

template <typename T>
void (*linkedBinaryTree<T>::visit)(binaryTreeNode<T> *);

template <typename T>
void linkedBinaryTree<T>::preOrder(binaryTreeNode<T> *t)
{
    if(t != nullptr)
    {
        linkedBinaryTree<T>::visit(t);
        preOrder(t->leftChild);
        preOrder(t->rightChild);
    }
}

template <typename T>
void linkedBinaryTree<T>::inOrder(binaryTreeNode<T> *t)
{
    if(t != nullptr)
    {
        inOrder(t->leftChild);
        linkedBinaryTree<T>::visit(t);
        inOrder(t->rightChild);
    }
}

template <typename T>
void linkedBinaryTree<T>::postOrder(binaryTreeNode<T> *t)
{
    if(t != nullptr)
    {
        postOrder(t->leftChild);
        postOrder(t->rightChild);
        linkedBinaryTree<T>::visit(t);
    }
}
#endif /* linkedBinaryTree_hpp */
