#ifndef LIST_H_
#define LIST_H_

#include "Node.hpp"
#include <iostream>

#define print(x) std::cout << x << std::endl;

template<class T>
class List
{
public:
    List();
    List(List<T>* some_list);
    //~List();
    
    //Adds an item to the specified position
    void add(const T& an_item, int position);

    //Adds an item to the end of the list
    void append(const T& an_item);
    void remove(const T& an_item);
    void display() const;
    bool isEmpty() const;
    int getNumberOfItems() const;
    void test(Node<T>* some_node) const;

private:
    Node<T>* head_ptr_;
    Node<T>* tail_ptr_;
    int item_count_;

    //add and append helper functions
    void appendToTail(Node<T>* new_node_ptr);
    void insertFirstItem(Node<T>* new_node_ptr);
};

#include "List.cpp"
#endif