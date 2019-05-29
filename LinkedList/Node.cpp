#include "Node.hpp"

//***************************************Default Constructor**************************//
template<class T>
Node<T>::Node()
{
    next_ = nullptr;
}

//***************************************Paramaterized Constructor**************************//
template<class T>
Node<T>::Node(const T& an_item)
{
    next_ = nullptr;
    item_ = an_item;
}

//***************************************Copy Constructor**************************//

//***************************************Setters**************************//
template<class T>
void Node<T>::setItem(const T &an_item)
{
    item_ = an_item;
}

template<class T>
void Node<T>::setNext(Node<T>* some_node)
{
    next_ = some_node;
}

template<class T>
void Node<T>::setPrevious(Node<T>* some_node)
{
    previous_ = some_node;
}

//***************************************Setters**************************//
template<class T>
T Node<T>::getItem() const
{
    return item_;
}

template<class T>
Node<T>* Node<T>::getNext() const
{
    return next_;
}

template<class T>
Node<T>* Node<T>::getPrevious() const
{
    return previous_;
}

