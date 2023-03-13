class Time
{
private:
    int m_second;
    int m_minute;
    int m_hour;

public:
    Time();
    Time(int second, int minute, int hour);

    void print();
};