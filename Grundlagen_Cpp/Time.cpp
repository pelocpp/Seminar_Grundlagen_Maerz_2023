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