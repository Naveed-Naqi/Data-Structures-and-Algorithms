#include "List.hpp"
#include <iostream>

int main()
{
    List<std::string> test;

    test.append("root");
    test.append("next");
    test.append("next");
    test.append("next");
    test.append("next");
    test.append("next");

    test.display();

    return 0;
}