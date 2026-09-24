#pragma once
#include <iostream>
#include <unordered_map>
using namespace std;


inline int NaturalNumberSum(int n){
    if(n > 0)
        return NaturalNumberSum(n-1) + n;
    return 0;
}

inline int NaturalNumberSumIterative(int n){
    int sum = 0;
    for(int i = 1; i <= n; ++i){
        sum += i;
    }
    return sum;
}

inline int Factorial(int n){
    if(n == 0)
        return 1;
    return Factorial(n-1) * n;
}

inline int FactorialIterative(int n){
    int result = 1;
    for(int i = 2; i <= n; ++i){
        result *= i;
    }
    return result;
}

inline int exponent(int m, int n){
    if(n <= 0)
        return 1;
    return exponent(m, n-1) * m;
}

inline int exponentIterative(int m, int n){
    int result = 1;
    for(int i = 0; i < n; ++i){
        result *= m;
    }
    return result;
}


inline int fibonacci(int n){
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}
//key = n, value = value at fib(n)
inline unordered_map<int, long long> M; // inline (C++17) so every .cpp shares one M instead of each defining its own
inline long long fibMemoization(int n){
    if(n <= 1)
        return n;
    if(M.count(n)) return M[n];
    return M[n] = fibMemoization(n-1) + fibMemoization(n-2);
}

inline int fib(int n){
    if(n <=1 )
        return n;
    int t0 = 0;
    int t1 = 1;
    int s;
    for(int i = 1; i < n; ++i){
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}










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

inline Time Time::operator+(Time rhs) const{
    Time timeTotal;
    timeTotal.hours = hours + rhs.hours;
    timeTotal.minutes = minutes + rhs.minutes;
    return timeTotal;
}
inline bool Time::operator==(Time rhs) const {
    return (hours == rhs.hours) && (minutes == rhs.minutes);
}

//custom exeption class
class NegativeValueException{
    public:
        NegativeValueException(){}// constructor that does nothing. though it can.
}; 

// Function that throws the custom exception
inline void checkValue(int x) {
    if (x < 0) {
        throw NegativeValueException();
    }
    else {
        cout << "Value is: " << x << endl;
    }
}

