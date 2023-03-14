#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

void std_01()
{
    std::vector<int> vec;

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    //int wert = 4;
    //vec.push_back(wert);

    //std::vector<int>::value_type wert2 = 5;
    //vec.push_back(wert2);

    // very classic
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << "i:" << i << ": "
            << vec[i] << std::endl;
    }

    // Konzept Iterators // Position
    std::vector<int>::iterator pos;
    pos = vec.begin();

    std::vector<int>::iterator end;
    end = vec.end();

    int value = *pos;
    std::cout << value << std::endl;

    ++pos;

    if (pos != end) {
        value = *pos;
        std::cout << value << std::endl;
    }
    else {
        return;
    }

    ++pos;

    if (pos != end) {
        value = *pos;
        std::cout << value << std::endl;
    }
    else {
        return;
    }

    ++pos;

    if (pos != end) {
        value = *pos;
        std::cout << value << std::endl;
    }
    else {
        return;
    }
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

void std_03()
{
    std::vector<int> vec;

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    // Python, JavaScript
    //var n;
    //n = '?';
    //let m;
    //n = 123;  // python

    auto k = 123.456;    // Type Deduction // Typ Ableitung

    // Konzept Iterators // Position
    // std::vector<int>::iterator pos;

    auto pos = vec.begin();

    int value = *pos;
    std::cout << value << std::endl;
}

void ausgabe(int value) {
    std::cout << value << std::endl;
}

auto ausgabeLambda = [](int value) {
    std::cout << value << std::endl;
};

void std_04()
{
    std::vector<int> vec;

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    // Vektor durchlaufen
    // Very, very Classic -- Gut für das Verständnis

    std::vector<int>::iterator pos = vec.begin();
    std::vector<int>::iterator end = vec.end();

    for (; pos != end; ++pos) {
        int value = *pos;
        std::cout << value << std::endl;
    }

    // Very Classic - STL stylish with STL algorithm std::for_each

    std::for_each (
        vec.begin(),
        vec.end(),
        ausgabe
    );

    // Verbeugung vor allen anderen OO Sprachen : for_each
    // Range-based for Loop

    for ( auto value : vec ) {
        std::cout << value << std::endl;
    }

    // C++ 20
    int index = 0;
    for (auto value : vec) {
        std::cout << index << ": " << value << std::endl;
        ++index;
    }
}


class MyDateStorage
{
    class MyDateStorageIterator
    {
    private:
        int m_current;

    public:
        MyDateStorageIterator() { m_current = 0; }
        MyDateStorageIterator(int wert) { m_current = wert; }

        void operator++ () { ++m_current; }

        bool operator!= (const MyDateStorageIterator& other) {
            return m_current != other.m_current;
        }

        std::string operator* () {
            return std::to_string(m_current);
        }
    };

public:

    MyDateStorageIterator begin() { 
    
        return MyDateStorageIterator();
    }
    
    MyDateStorageIterator end() {
    
        return MyDateStorageIterator(4);
    }

};

void verarbeiteStorageElement(std::string s) {
    std::cout << "std::for_each: " << s << std::endl;
}

void std_05()
{
    MyDateStorage storage;

    for (auto value : storage) {
        std::cout << value << std::endl;
    }

    std::for_each(
        storage.begin(),
        storage.end(),
        verarbeiteStorageElement
    );
}


void std_06()
{
    std::vector<int> vec;

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    // Lamda - reguläre Schreibweise - mit auto
    auto myLambda = [](int value) {
        std::cout << "Mit Lambda: " << value << std::endl;
    };

    // Lamda - exakte Schreibweise mit ex. Datentyp
    std::function<void (int)> myLambda1 = [](int value) {
        std::cout << "Mit Lambda: " << value << std::endl;
    };

    // C Funktionszeiger
    void (*myLambda2) (int value) = &ausgabe;

    // Very Classic - STL stylish with STL algorithm std::for_each
    std::for_each(
        vec.begin(),
        vec.end(),
        [] (int value) {
            std::cout << "Mit Lambda: " << value << std::endl;
        }
    );

    std::for_each(
        vec.begin(),
        vec.end(),
        ausgabe
    );
}

void std_07()
{
    std::vector<int> vec;

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    std::string prefix = "Mit Lambda: ";

    std::string* prefixHeap = new std::string("Mit Heap Lambda: ");

    // Very Classic - STL stylish with STL algorithm std::for_each
    std::for_each(
        vec.begin(),
        vec.end(),
        [=] (int value) {
            std::cout << *prefixHeap << value << std::endl;
        }
    );

    delete prefixHeap;
}


void std_08()
{
    std::vector<int> vec;

    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    int counter = 1;

    // Very Classic - STL stylish with STL algorithm std::for_each
    std::for_each(
        vec.begin(),
        vec.end(),
        [=](int value) mutable {
            std::cout << counter << ": " << value << std::endl;

            ++counter;
        }
    );

   //  counter = 99;
}

// Aufrufbares Objekt
class BinAufrufbar
{
public:
    BinAufrufbar() {
        m_prefix = "Standard Prefix";
    }
    
    BinAufrufbar(std::string prefix) {
        m_prefix = prefix;
    }

    std::string m_prefix;

    void operator() (int n) const {
        std::cout << m_prefix << ": " << n << std::endl;
    }
};

void std_09()
{
    BinAufrufbar obj;
    obj(123);
}

void std_10()
{
    std::vector<int> vec;

    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    int counter = 1;

    BinAufrufbar obj("my pref");

    // Very Classic - STL stylish with STL algorithm std::for_each
    std::for_each(
        vec.begin(),
        vec.end(),
        obj
    );
}

void std_11()
{
    std::vector<int> vec;

    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    // auto counter = 5;

    std::for_each(
        vec.begin(),
        vec.end(),
        [counter = 5] (int value) mutable {

            std::cout << counter << ": " << value << std::endl;
            ++counter;
        }
    );

    // counter = 123;
}

void std_12()
{
    std::vector<int> vec;

    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    std::for_each(
        vec.begin(),
        vec.end(),
        [](int& value) {

            std::cout  << value << std::endl;

            value = value + 1000;
        }
    );

    std::for_each(
        vec.begin(),
        vec.end(),
        [](int value) {

            std::cout << value << std::endl;
        }
    );
}

void std_13()
{
    std::vector<int> vec;

    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    std::vector<int> vecCopy (vec);
    
    for (auto& value : vecCopy) {
        std::cout << value << std::endl;
        value = value + 1000;

        // vec.erase(...);
    }

    for (auto value : vec) {
        std::cout << value << std::endl;
        value = value + 1000;
    }
}

template <typename FUNC>
void std_14(FUNC f)
{
    std::vector<int> vec;

    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    std::for_each(
        vec.begin(),
        vec.end(),
        f
    );
}

// wenn ich nicht manipulieren möchte 
// 
// auto und Ref.

// Funktion als PArameter

// ======================================================
// ======================================================
// ======================================================

auto ausgabeInt = [](int value) {
    std::cout << "int:    " << value << std::endl;
};

auto ausgabeDouble = [](double value) {
    std::cout << "double: " << value << std::endl;
};

void std_ausblick_01 ()
{
    std::vector<int> vecInts { 1, 2,3 ,4, 5};

    std::vector<double> vecDoubles{ 1.5, 2.5,3.5 ,4.5, 5.5 };

    std::for_each(
        vecInts.begin(),
        vecInts.end(),
        ausgabeInt
    );

    std::for_each(
        vecDoubles.begin(),
        vecDoubles.end(),
        ausgabeDouble
    );
}

// ======================================================


// Lambdas & Generischen Lambdas

auto ausgabeGeneric = [](const auto& value) {

    using T = decltype (value);

    using TWithoutReference = std::remove_reference<T>::type;

    using TWithoutReferenceAndConst = 
        std::remove_const<TWithoutReference>::type;

    if (std::is_same<TWithoutReferenceAndConst, int>::value == true) {
        std::cout << "int:  " << value << std::endl;
    }
    else if (std::is_same<TWithoutReferenceAndConst, double>::value == true) {
        std::cout << "double " << value << std::endl;
    }
    else {
        std::cout << "unbekannt" << std::endl;
    }
};


template <typename T>
auto ausgabeGenericTempl = [](const T& value) {

    // using T = decltype (value);

    using TWithoutReference = std::remove_reference<T>::type;

    using TWithoutReferenceAndConst =
        std::remove_const<TWithoutReference>::type;

    if (std::is_same<TWithoutReferenceAndConst, int>::value == true) {
        std::cout << "int:  " << value << std::endl;
    }
    else if (std::is_same<TWithoutReferenceAndConst, double>::value == true) {
        std::cout << "double " << value << std::endl;
    }
    else {
        std::cout << "unbekannt" << std::endl;
    }
};

void std_ausblick_02()
{
    std::vector<int> vecInts{ 1, 2,3 ,4, 5 };

    std::vector<double> vecDoubles{ 1.5, 2.5,3.5 ,4.5, 5.5 };

    std::for_each(
        vecInts.begin(),
        vecInts.end(),
        ausgabeGeneric
    );

    std::for_each(
        vecDoubles.begin(),
        vecDoubles.end(),
        ausgabeGeneric
    );
}


int main_mit_parameter()
{
    std_14<std::function<void(int)>>(ausgabe);
    return 1;
}

int main()
{
    std_ausblick_02();
    return 1;
}
