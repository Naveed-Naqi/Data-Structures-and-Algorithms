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
    Node<T>* new_node_ptr = new Node<T>(an_item);

    isEmpty() ? insertFirstItem(new_node_ptr) : insertAtEnd(new_node_ptr);
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
void List<T>::insertAtEnd(Node<T>* new_node_ptr)
{     
    new_node_ptr->setNext(nullptr);
    new_node_ptr->setPrevious(tail_ptr_);
    tail_ptr_->setNext(new_node_ptr);
    tail_ptr_ = new_node_ptr;
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

template<class T>
void List<T>::insert(const T& an_item, int position)
{
    Node<T>* new_node_ptr = new Node<T>(an_item);

    //use exception handling here to make sure the position is valid

    if(position < item_count_+1)
    {
        if(isEmpty())
        {
            insertFirstItem(new_node_ptr);
        }
        else if (position == 0)
        {
            insertAtBeginning(new_node_ptr);
        }
        else if (position == item_count_)
        {
            insertAtEnd(new_node_ptr);
        }  
        else
        {
            insert(new_node_ptr, position);
        }
    }
}

template<class T>
void List<T>::insertAtBeginning(Node<T>* new_node_ptr)
{
    head_ptr_->setPrevious(new_node_ptr);
    new_node_ptr->setNext(head_ptr_);
    head_ptr_ = new_node_ptr;
}

template<class T>
void List<T>::insert(Node<T>* new_node_ptr, const int position)
{
    Node<T>* temp_ptr = getPointerToPosition(position);
    temp_ptr->getPrevious()->setNext(new_node_ptr);
    temp_ptr->getNext()->setPrevious(new_node_ptr);
    new_node_ptr->setPrevious(temp_ptr->getPrevious());
    new_node_ptr->setNext(temp_ptr->getNext());

    temp_ptr = nullptr;
}

template<class T>
Node<T>* List<T>::getPointerToPosition(const int position) const
{
    //Throw exception first by making sure that the position is valid

    return isGreaterThanMedian(position) ? traverseFromTailToPosition(position) : traverseFromHeadToPosition(position);  
}

template<class T>
bool List<T>::isGreaterThanMedian(const int position) const
{   
    return position > item_count_/2;
}

template<class T>
Node<T>* List<T>::traverseFromTailToPosition(const int position) const
{
    Node<T>* temp_ptr = tail_ptr_;
    int curr_position = item_count_-1;

    while(curr_position != position)
    {
        temp_ptr = temp_ptr->getPrevious();
        curr_position--;
    }

    return temp_ptr; 
}

template<class T>
Node<T>* List<T>::traverseFromHeadToPosition(const int position) const
{
    Node<T>* temp_ptr = head_ptr_;
    int curr_position = 0;

    while(curr_position != position)
    {
        temp_ptr = temp_ptr->getNext();
        curr_position++;
    }

    return temp_ptr;
}



