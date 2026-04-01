#pragma once
#include <iostream>
using namespace std;

class Time{
    private:
        int hours;
        int minutes;
    public:
        Time(int h = 0, int m = 0):hours(h), minutes(m){}
        void print(){cout<<hours<<" "<<minutes;}
        // overloaded operators
        Time operator+(Time rhs) const;
        bool operator==(Time rhs) const ;
} ;

Time Time::operator+(Time rhs) const{
    Time timeTotal;
    timeTotal.hours = hours + rhs.hours;
    timeTotal.minutes = minutes + rhs.minutes;
    return timeTotal;
}
bool Time::operator==(Time rhs) const {
    return (hours == rhs.hours) && (minutes == rhs.minutes);
}

//custom exeption class
class NegativeValueException{
    public:
        NegativeValueException(){}// constructor that does nothing. though it can.
}; 

// Function that throws the custom exception
void checkValue(int x) {
    if (x < 0) {
        throw NegativeValueException();
    }
    else {
        cout << "Value is: " << x << endl;
    }
}