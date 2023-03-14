#include <iostream>
#include <memory>

void test_do_Something_With_UniquePtr(std::unique_ptr<int>& p)
{
    std::cout << "Wert: " << *p << std::endl;
}

std::unique_ptr<int> test_do_Something_With_UniquePtr2(std::unique_ptr<int> p)
{
    std::cout << "Wert: " << *p << std::endl;

    return p;
}

void test_Zeiger_Unique()
{
    int* ip = new int (123);
    std::unique_ptr<int> up(ip);

    std::unique_ptr<int> up1;

    up1 = std::move(up);

    test_do_Something_With_UniquePtr(up1);

    up1 = test_do_Something_With_UniquePtr2(std::move(up1));

    std::cout << "Wert: " << *up1 << std::endl;
}    // Destruktor von up: delete ip;

int main_unique ()
{
    std::cout << "Hallo Seminar - Zeiger\n";

    test_Zeiger_Unique();

    return 1;
}
