#ifndef TIME_H
#define TIME_H
#include <iostream>
using namespace std;


//forward declarations for overloaded stream operators
class Time;
ostream & operator << ( ostream &, const Time & );
istream & operator >> (istream & , const Time & );
class Time
{
 
private:
    int * seconds_pointer;
 
public:
    Time();
    Time(int);
    int getSeconds() const;
    double getMinutes()const;
    double getHours() const;
    double getDays() const;
    void change_seconds(int s)
    {
        *seconds_pointer = s;
    }
    bool operator < (const Time &right)
    {
        if (*seconds_pointer < *(right.seconds_pointer))
            return true;
        else
            return false;
    }
    void operator =(const Time &right)
    {
        *seconds_pointer = *(right.seconds_pointer);
    }
    ~Time();
  

    Time operator ++ (int)
	{
	     
        Time temp;
		cout << *temp.seconds_pointer <<endl;
		*(temp.seconds_pointer) = *seconds_pointer;
		cout << *temp.seconds_pointer <<endl;		
        ((*(temp.seconds_pointer)) ++);
		cout << *temp.seconds_pointer <<endl;

        return temp;
    }

 
    double operator + (const Time &right)
    {
        double seconds_in_min = 60;
        return (*seconds_pointer + *(right.seconds_pointer)) / seconds_in_min;
 
    }
 
    Time(const Time & obj)
    {
        int temp = 0;
        temp = *(obj.seconds_pointer);
        seconds_pointer = new int;
        *seconds_pointer = temp;
    //  delete obj.seconds_pointer;
        *this = obj;
    }

    friend istream & operator >>(istream &, const Time &);
    friend ostream & operator << (ostream &, const Time &);
};

ostream & operator << ( ostream & stream, const Time & obj)
{
        stream << *(obj.seconds_pointer);
        return stream;
 
}
 
istream & operator >> (istream & is, const Time & obj)
{
    is >> *(obj.seconds_pointer);
    return is;
}
 
double Time::getDays() const
{
    double seconds_in_min = 60;
    double min_in_hour = 60;
    double hour_in_day = 24;
    return ((*seconds_pointer / seconds_in_min) / min_in_hour) / hour_in_day;
}
double Time::getMinutes()const
{
    double seconds_in_min = 60;
    return *seconds_pointer / seconds_in_min;
}
int Time::getSeconds()const
{
    return *seconds_pointer;
 
}
double Time::getHours()const
{
    double seconds_in_min = 60;
    double min_in_hour = 60;
 
    return (*seconds_pointer / seconds_in_min) / min_in_hour;
}
 
Time::Time()
{
    seconds_pointer = new int;
    *seconds_pointer = 0;
}
 
Time::Time(int seconds)
{
    seconds_pointer = new int;
    *seconds_pointer = seconds;
}
Time::~Time()
{
    delete seconds_pointer;
}
 


#endif
