#include "List.hpp"

template<class T>
List<T>::List()
{
    head_ptr_ = nullptr;
    tail_ptr_ = nullptr;
    item_count_ = 0;
}

template<class T>
void List<T>::append(const T& an_item)
{
    Node<T>* new_node_ptr = new Node<T>;
    new_node_ptr->setItem(an_item);

    isEmpty() ? insertFirstItem(new_node_ptr) : appendToTail(new_node_ptr);
}

template<class T>
void List<T>::insertFirstItem(Node<T>* new_node_ptr)
{
    new_node_ptr->setNext(nullptr);
    new_node_ptr->setPrevious(nullptr);
    head_ptr_ = new_node_ptr;
    tail_ptr_ = new_node_ptr;
    item_count_++;
}

template<class T>
void List<T>::appendToTail(Node<T>* new_node_ptr)
{     
    new_node_ptr->setNext(nullptr);
    new_node_ptr->setPrevious(tail_ptr_);
    tail_ptr_->setNext(new_node_ptr);
    tail_ptr_ = new_node_ptr;
    item_count_++;
}

template<class T>
void List<T>::display() const
{
    if(head_ptr_ != nullptr)
    {
        Node<T>* temp_ptr = head_ptr_;
        print(temp_ptr->getItem());

        while(temp_ptr->getNext() != nullptr)
        {
            temp_ptr = temp_ptr->getNext();
            print(temp_ptr->getItem());
        }
        
        temp_ptr = nullptr;
    }
}

template<class T>
bool List<T>::isEmpty() const
{
    return item_count_ == 0;
}

template<class T>
int List<T>::getNumberOfItems() const
{
    return item_count_;
}