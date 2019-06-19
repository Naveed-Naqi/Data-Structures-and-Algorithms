#include <iostream>

#define print(x) std::cout << x << std::endl

void selectionSort(int* arr, std::size_t size);
void swap(int* arr, int some_index, int other_index);
int findMinIndex(int* arr, int starting_index, std::size_t size);

void selectionSort(int* arr, std::size_t size)
{
    int curr_min_index = 0;

    for(int i = 0; i < size-1; i++)
    {
        curr_min_index = findMinIndex(arr, i, size);
        swap(arr, i, curr_min_index);
    }

}

void swap(int* arr, int some_index, int other_index)
{
    int temp = arr[some_index];
    arr[some_index] = arr[other_index];
    arr[other_index] = temp;

}

int findMinIndex(int* arr, int starting_index, std::size_t size)
{
    int curr_min_index = starting_index;

    for(int i = starting_index+1; i < size; i++)
    {
        if(arr[i] < arr[curr_min_index])
        {
            curr_min_index = i;
        }
    }

    return curr_min_index;
}

void printArray(int* arr, std::size_t size)
{
    for(int i = 0; i < size; i++)
    {
        std::cout << arr[i] << std::endl;
    }
}

bool caseInsensitiveStringComapare(std::string some_word, std::string other_word)
{
    convertToLowerCase(some_word);
    convertToLowerCase(other_word);
    return some_word == other_word;
}

void convertToLowerCase(std::string& some_word)
{
    for(int i = 0; i < some_word.length(); i++)
    {
        some_word[i] = std::tolower(some_word[i]);
    }
}


int main()
{
    int arr[10] = {2,5,7,9,1,2,3,6,4,8};

    std::size_t size = sizeof(arr)/sizeof(arr[0]);

    selectionSort(arr, size);
    printArray(arr, size);

}

