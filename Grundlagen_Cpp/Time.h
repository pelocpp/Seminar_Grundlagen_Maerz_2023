class Time
{
private:
    int m_second;
    int m_minute;
    int m_hour;

public:
    Time();
    Time(int second, int minute, int hour);

    // getter / setter
    int getHour() { return m_hour; }
    int getMinute();

    int DifferenceInSeconds(const Time& other) const;

    void print();
};