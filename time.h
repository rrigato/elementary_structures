#ifndef
#define
TIME_H
class Time
{

    private:
    int * seconds_pointer;

    public:
    Time();
    Time(int);
    ~Time();

};

Time::Time()
{
    seconds_pointer = new int;
    seconds_pointer * = 0;
}

Time::Time(int seconds)
{
    seconds_pointer = new int;
    seconds_pointer* = seconds;
}
Time::~Time()
{
    delete seconds_pointer;
}



#endif
