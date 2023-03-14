#include <iostream>
#include <memory>
#include <vector>

void std_01()
{
    std::vector<int> vec;

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
}

void std_02()
{
    std::vector<int> vec;

  //  vec.reserve(80);

    for (int i = 0; i < 100; ++i)
    {
        vec.push_back(2 * i);

        std::cout 
            << "i:" << (i+1) << ", Capacity: "
            << vec.capacity() << std::endl;
    }

    // vector ist jetzt fertig konstruiert
    vec.shrink_to_fit();

    std::cout
        << "Capacity: "
        << vec.capacity() << std::endl;
}

int main()
{
    //std::cout << "Hallo STL\n";

    std_02();

    return 1;
}
