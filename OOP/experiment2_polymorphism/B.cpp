#include <iostream>
#include <string>
using namespace std;

class Time {
private:
    int hours;   
    int minutes;  
    int seconds;  

public:
    Time(int h=0, int m=0, int s=0)
    {
        int total=h*3600+m*60+s;
        hours=total/3600;
        minutes=total%3600/60;
        seconds=total%60;
    }

    Time operator+(Time& t)
    {
        return Time(hours + t.hours, minutes + t.minutes, seconds + t.seconds);  
    }

    void disptime(string msg)
    {
        cout<<msg<<hours<<":"<<minutes<<":"<<seconds<<'\n';
    }
};

int main()
{
    cout<<"Please enter the precise chosen time (hour:min:sec): ";
    int h,m,s;
    cin>>h>>m>>s;
    while(h<0){
        cout<<"POSITIVE NUMBER OF HOURS NEEDED!";
        cin>>h;
    }
    Time t1(h,m,s), t2(1, 20, 30), t3;
    t1.disptime("t1=");
    t2.disptime("t2=");
    t3=t1+t2;
    t3.disptime("t1+t2=");   
    return 0;
}

/*
t1=2时45分50秒
t2=1时20分30秒
t1+t2=4时6分20秒
*/