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

    isEmpty() ? insertFirstItem(new_node_ptr) : appendToEnd(new_node_ptr);
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
void List<T>::appendToEnd(Node<T>* new_node_ptr)
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

template<class T>
void List<T>::insert(const T& an_item, int position)
{

    //use exception handling here to make sure the position is valid

    if(position < item_count_+1)
    {
        Node<T>* new_node_ptr = new Node<T>(an_item);

        if(isEmpty() || position == item_count_)
        {
            append(an_item);
        }
        else if (position == 0)
        {
            insertAtHead(new_node_ptr);
        }
        else
        {
            insert(new_node_ptr, position);
        } 
    }
}

template<class T>
void List<T>::insertAtHead(Node<T>* new_node_ptr)
{
    head_ptr_->setPrevious(new_node_ptr);
    new_node_ptr->setNext(head_ptr_);
    head_ptr_ = new_node_ptr;
    item_count_++;
}
template<class T>
void List<T>::insert(Node<T>* new_node_ptr, const int position)
{
    Node<T>* temp_ptr = getPointerToPosition(position);

    temp_ptr->getPrevious()->setNext(new_node_ptr);
    new_node_ptr->setPrevious(temp_ptr->getPrevious());
    temp_ptr->setPrevious(new_node_ptr);
    new_node_ptr->setNext(temp_ptr);

    temp_ptr = nullptr;
    item_count_++;
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

template<class T>
void List<T>::remove(const int position)
{
    if(position == 0)
    {
        removeFromHead(position);
    }
    else if (position == item_count_-1)
    {
        removeFromTail(position);
    }
    else
    {
        removeFromMiddle(position);
    }
}

template<class T>
void List<T>::removeFromHead(const int position)
{
    Node<T>* temp_ptr = head_ptr_;

    head_ptr_ = head_ptr_->getNext();
    head_ptr_->setPrevious(nullptr);

    temp_ptr->setNext(nullptr);
    temp_ptr->setPrevious(nullptr);
    delete temp_ptr;
    temp_ptr = nullptr;

    item_count_--;
}

template<class T>
void List<T>::removeFromTail(const int position)
{
    Node<T>* temp_ptr = tail_ptr_;

    tail_ptr_ = tail_ptr_->getPrevious();
    tail_ptr_->setNext(nullptr);

    temp_ptr->setNext(nullptr);
    temp_ptr->setPrevious(nullptr);
    delete temp_ptr;
    temp_ptr = nullptr;

    item_count_--;
}

template<class T>
void List<T>::removeFromMiddle(const int position)
{
    Node<T>* temp_ptr = getPointerToPosition(position);

    temp_ptr->getPrevious()->setNext(temp_ptr->getNext());
    temp_ptr->getNext()->setPrevious(temp_ptr->getPrevious());

    temp_ptr->setNext(nullptr);
    temp_ptr->setPrevious(nullptr);
    delete temp_ptr;
    temp_ptr = nullptr;

    item_count_--;
}



