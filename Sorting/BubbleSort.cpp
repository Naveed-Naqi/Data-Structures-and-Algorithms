#include <iostream>

void bubbleSort(int* arr, std::size_t size);
void swap(int* arr, int some_index, int other_index);
bool bubbleUpMax(int* arr, std::size_t size);
void printArray(int* arr, std::size_t size);


void bubbleSort(int* arr, std::size_t size)
{
    bool is_sorted = false;

    while(!is_sorted)
    {
        if(!bubbleUpMax(arr, size))
        {
            is_sorted = true;
        }
    }
}

void swap(int* arr, int some_index, int other_index)
{
    int temp = arr[some_index];
    arr[some_index] = arr[other_index];
    arr[other_index] = temp;
}

bool bubbleUpMax(int* arr, std::size_t size)
{
    bool is_swapped = false;

    for(int i = 0; i < size-1; i++)
    {
        if(arr[i] > arr[i+1])
        {
            swap(arr, i, i+1);
            is_swapped = true;
        }
    }
    
    printArray(arr, size);
    return is_swapped;
}

void printArray(int* arr, std::size_t size)
{
    for(int i = 0; i < size; i++)
    {
        std::cout << arr[i] << ", ";
    }

    std::cout << "\n";
}

int main()
{
    int test[6] = {2,4,1,5,3,7};

    printArray(test, 6);
    bubbleSort(test, 6);

    return 0;
}

