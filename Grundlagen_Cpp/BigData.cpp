#include <iostream>

#include "BigData.h"

BigData::BigData(int length)
{
    // dynamic array
    m_length = length;
    m_data = new int[length];
}

BigData::~BigData()
{
    delete[] m_data;
}

BigData::BigData(const BigData& other)
{
    // allocate new left side
    m_data = new int[other.m_length];

    // umkopieren der Daten
    for (int i = 0; i < other.m_length; ++i) {
        m_data[i] = other.m_data[i];
    }

    m_length = other.m_length;
}


BigData& BigData::operator= (const BigData& other)
{
    // release left side
    delete[] m_data;

    // allocate new left side
    m_data = new int[other.m_length];

    // umkopieren der Daten
    for (int i = 0; i < other.m_length; ++i) {
        m_data[i] = other.m_data[i];
    }

    m_length = other.m_length;

    return *this;
}