#include <iostream>
#include <iomanip>
#include <chrono>

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

    void printTimeConsumed()
    {
        std::ios::fmtflags fmtflags = std::cout.flags();

        std::chrono::steady_clock::duration duration = this->endPoint - this->startPoint;
        double consume = duration.count() * 1.0 / decltype(duration)::period::den;
        std::cout << std::setprecision(6) << "time consumed: " << consume << "(seconds)" << std::endl;

        std::cout.flags(fmtflags);
    }

    void printSeconds()
    {
        std::chrono::seconds duration = std::chrono::duration_cast<std::chrono::seconds>(this->endPoint - this->startPoint);
        std::cout << "time consumed: " << duration.count() << "(seconds)" << std::endl;
    }

    void printMilliseconds()
    {
        std::chrono::milliseconds duration = std::chrono::duration_cast<std::chrono::milliseconds>(this->endPoint - this->startPoint);
        std::cout << "time consumed: " << duration.count() << "(milliseconds)" << std::endl;
    }

    void printMicroseconds()
    {
        std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(this->endPoint - this->startPoint);
        std::cout << "time consumed: " << duration.count() << "(microseconds)" << std::endl;
    }

    void printNanoseconds()
    {
        std::chrono::nanoseconds duration = std::chrono::duration_cast<std::chrono::nanoseconds>(this->endPoint - this->startPoint);
        std::cout << "time consumed: " << duration.count() << "(nanoseconds)" << std::endl;
    }
};