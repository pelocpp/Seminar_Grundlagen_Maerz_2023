#pragma once

class BigData
{
private:

    int  m_length;
    int* m_data;

public:
    // Konstruktor
    BigData(int length);

    BigData(const BigData&);

    BigData& operator= (const BigData&);

    // Destruktor
    ~BigData();
};