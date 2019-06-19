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
    T getItem() const;
    Node<T>* getNext() const;

private:
    T item_;
    Node<T>* next_;
};

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
	Node();
	item_ = an_item;
}

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

#endif
