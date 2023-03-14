#include <iostream>
#include <memory>

void test_do_Something_With_SharedPtr(std::shared_ptr<int>& p)
{
    std::cout << "Wert: " << *p 
        << ", Ref-Counter: " << p.use_count() 
        << std::endl;
}

void test_Zeiger_Shared()
{
    int* ip = new int(123);
    std::shared_ptr<int> sp(ip);

    std::cout << "Wert: " << *sp
        << ", Ref-Counter: " << sp.use_count()
        << std::endl;

    test_do_Something_With_SharedPtr(sp);

    std::cout << "Wert: " << *sp
        << ", Ref-Counter: " << sp.use_count()
        << std::endl;

    std::shared_ptr<int> sp1;
    sp1 = sp;

}   // hier werden 2 Destruktoren von std::shared_ptr<int> aufgerufen:
    // der zweite Destruktor-Aufruf ruft delete von ip auf



// =================================================

class X;
class Y;

class X
{
public:
    std::shared_ptr<Y> m_sp_Y{};
};

class Y
{
public:
    std::shared_ptr<X> m_sp_X{};
};

void test_problem_shared() {

    std::shared_ptr<X> sp_X(new X());
    std::shared_ptr<Y> sp_Y(new Y());

    std::cout << "UseCount: " << sp_X.use_count() << std::endl;
    std::cout << "UseCount: " << sp_Y.use_count() << std::endl;

    sp_X->m_sp_Y = sp_Y;
    sp_Y->m_sp_X = sp_X;

    std::cout << "UseCount: " << sp_X.use_count() << std::endl;
    std::cout << "UseCount: " << sp_Y.use_count() << std::endl;


    std::cout << "Done." << std::endl;
}


int main_shared()
{
    std::cout << "Hallo Seminar - Zeiger\n";

    test_problem_shared();

    return 1;
}
