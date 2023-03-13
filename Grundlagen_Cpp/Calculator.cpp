#include <iostream>

#include "BigData.h"

//class Calculator
//{
//public:
//    static int add(int x, int y) { return x + y; }
//    static int sub(int x, int y) { return x - y; }
//    static int mul(int x, int y) { return x * y; }
//    static int div(int x, int y) { return x / y; }
//};

// primary template
template <typename T>
class Calculator
{
public:
    static T add(T x, T y) {
        return x + y;
    }
    static T sub(T x, T y) { return x - y; }
    static T mul(T x, T y) { return x * y; }
    static T div(T x, T y) { return x / y; }
};

// template specialization - for T = int
template <>
class Calculator <int>
{
public:
    static int add(int x, int y) {
        return x + y;
    }
    static int sub(int x, int y) { return x - y; }
    static int mul(int x, int y) { return x * y; }
    static int div(int x, int y) {

        return (int)(((double)x / y) + 0.5);
    }
};


class DoubleCalculator
{
public:
    static double add(double x, double y) { return x + y; }
    static double sub(double x, double y) { return x - y; }
    static double mul(double x, double y) { return x * y; }
    static double div(double x, double y) { return x / y; }
};

int main()
{
    int result = Calculator<int>::div(3, 4);

    double dresult = Calculator<double>::add(3.3, 4.4);
}

