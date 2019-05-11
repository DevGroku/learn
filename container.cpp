#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vector_int;
    vector_int.push_back(1);
    vector_int.push_back(2);
    vector_int.push_back(3);

    for (int item : vector_int) std::cout << item;

    std::vector<int> v2 { 4, 5, 6 };
    for (int item : v2) std::cout << item;

    std::vector<int> v3(4, 5);
    for (int item : v3) std::cout << item;

    return 0;
}