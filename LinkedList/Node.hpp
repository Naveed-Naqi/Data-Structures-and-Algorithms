#ifndef NODE_H_
#define NODE_H_

template<class T>
class Node
{

public:
    Node();
    
    //Parameterized Constructor
    Node(const T& an_item);
    void setItem(const T& an_item);
    void setNext(Node<T>* some_node);
    void setPrevious(Node<T>* some_node);
    T getItem() const;
    Node<T>* getNext() const;
    Node<T>* getPrevious() const;

private:
    T item_;
    Node<T>* next_;
    Node<T>* previous_;
};

#include "Node.cpp"
#endif
