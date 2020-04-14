#include <iostream>
#include <iomanip>
#include <chrono>

#ifndef Sort_Timer_H
#define Sort_Timer_H

class Timer
{
private:
    std::chrono::steady_clock::time_point startPoint;
    std::chrono::steady_clock::time_point endPoint;

public:
    Timer() 
    {
        this->startPoint = std::chrono::steady_clock::now();
    }

    void start()
    {
        this->startPoint = std::chrono::steady_clock::now();
    }

    void stop()
    {
        this->endPoint = std::chrono::steady_clock::now();
    }

    void printTimeConsumed(std::string tag)
    {
        printSeconds(tag);
    }

    void printSeconds(std::string tag)
    {
        std::ios::fmtflags fmtflags = std::cout.flags();

        std::chrono::steady_clock::duration duration = this->endPoint - this->startPoint;
        double consume = duration.count() * 1.0 / decltype(duration)::period::den;
        std::cout << std::setprecision(6) << tag << " time consumed: " << consume << "(seconds)" << std::endl;

        std::cout.flags(fmtflags);
    }

    void printMilliseconds(std::string tag)
    {
        std::chrono::milliseconds duration = std::chrono::duration_cast<std::chrono::milliseconds>(this->endPoint - this->startPoint);
        std::cout << tag << " time consumed: " << duration.count() << "(milliseconds)" << std::endl;
    }

    void printMicroseconds(std::string tag)
    {
        std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(this->endPoint - this->startPoint);
        std::cout << tag << " time consumed: " << duration.count() << "(microseconds)" << std::endl;
    }

    void printNanoseconds(std::string tag)
    {
        std::chrono::nanoseconds duration = std::chrono::duration_cast<std::chrono::nanoseconds>(this->endPoint - this->startPoint);
        std::cout << tag << " time consumed: " << duration.count() << "(nanoseconds)" << std::endl;
    }
};

#endif