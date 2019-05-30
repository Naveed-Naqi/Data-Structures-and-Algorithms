#ifndef _LIST_H_
#define _LIST_H_

#include "Node.hpp"
#include <iostream>

#define print(x) std::cout << x << std::endl;

template<class T>
class List
{
public:
    List();
    List(List<T>* other_list);
    //~List();

    //Adds an_item to the specified position, first item is at position 0 and so on
    void insert(const T& an_item, int position);

    //Adds an item to the end of the list
    void append(const T& an_item);

    void remove(const T& an_item);

    void display() const;
    bool isEmpty() const;
    int getNumberOfItems() const;

private:
    Node<T>* head_ptr_;
    Node<T>* tail_ptr_;
    int item_count_;

    //insert and append helper functions
    void appendToEnd(Node<T>* new_node_ptr);
    void insertFirstItem(Node<T>* new_node_ptr);
    void insertAtHead(Node<T>* new_node_ptr);
    void insert(Node<T>* new_node_ptr, const int position);

    //helps optimize the insert function
    bool isGreaterThanMedian(const int position) const;
    Node<T>* getPointerToPosition(const int position) const;
    Node<T>* traverseFromTailToPosition(const int position) const;
    Node<T>* traverseFromHeadToPosition(const int position) const;
};

#include "List.cpp"
#endif