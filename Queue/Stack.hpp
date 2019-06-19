#pragma once
#include "Node.hpp"

#ifndef STACK_H_
#define STACK_H_

template<class T>
class Stack
{
public:
	Stack();
	~Stack();
	void push(const T& new_entry);
	void pop();
	T top() const;
	int size() const;
	bool isEmpty() const;
private:
	Node<T>* top_;
	size_t item_count_;

	void appendToEnd(Node<T>* new_node_ptr);
	void insertFirstItem(Node<T>* new_node_ptr);

	void removeFirstItem();
	void remove();
};

template<class T>
Stack<T>::Stack() : top_(nullptr), item_count_(0) {}

template<class T>
Stack<T>::~Stack()
{
	Node<T>* temp_ptr = top_;

	while (top_->getNext() != nullptr)
	{
		top_ = top_->getNext();

		temp_ptr->setNext(nullptr);
		temp_ptr = nullptr;
		delete temp_ptr;

		temp_ptr = top_;
	}

	item_count_ = 0;
}

template<class T>
void Stack<T>::push(const T& new_entry)
{
	Node<T>* new_node_ptr = new Node<T>(new_entry);

	isEmpty() ? insertFirstItem(new_node_ptr) : appendToEnd(new_node_ptr);
}

template<class T>
void Stack<T>::appendToEnd(Node<T>* new_node_ptr)
{
	new_node_ptr->setNext(top_);
	top_ = new_node_ptr;

	new_node_ptr = nullptr;

	item_count_++;
}

template<class T>
void Stack<T>::insertFirstItem(Node<T>* new_node_ptr)
{
	top_ = new_node_ptr;

	new_node_ptr = nullptr;
	delete new_node_ptr;

	item_count_++;
}

template<class T>
inline void Stack<T>::removeFirstItem()
{
	top_ = nullptr;

	item_count_--;
}

template<class T>
inline void Stack<T>::remove()
{
	Node<T>* temp_ptr = top_;
	top_ = top_->getNext();


	temp_ptr->setNext(nullptr);
	temp_ptr = nullptr;
	delete temp_ptr;


	item_count_--;
}

template<class T>
void Stack<T>::pop()
{	
	//add exception handling for when stack is empty

	size() == 1 ? removeFirstItem() : remove();
}


template<class T>
T Stack<T>::top() const
{
	return top_->getItem();
}

template<class T>
int Stack<T>::size() const
{
	return item_count_;
}

template<class T>
bool Stack<T>::isEmpty() const
{
	return item_count_ == 0;
}

#endif
