#include <iostream>
#include <iomanip>

#include "Time.h"

Time::Time()
{
    m_hour = 0;
    m_minute = 0;
    m_second = 0;
}

Time::Time(int second, int minute, int hour)
{
    m_hour = hour;
    m_minute = minute;
    m_second = second;
}

void Time::print()
{
    std::cout 
        << m_hour << ":" 
        << m_minute << ":" 
        << m_second << '\n';
}

int Time::getMinute()
{
    return m_minute;
}

int Time::DifferenceInSeconds (const Time& other) const 
{
    // that's wrong
    // other.m_hour = 12;
    int tmp = other.m_hour;

    // m_hour = 12;

    // very, very simple ... and mostly WRONG
    return 3600;
}