#pragma once
#include <iostream>
#include <chrono>

enum class DAYS {
    kDay01,
};

namespace Tools
{
    using TimePoint = std::chrono::high_resolution_clock::time_point;

    class CTimer
    {
    public:
        CTimer();
        ~CTimer();

        void probeTime();
        void printElapsed() const;
    private:
        TimePoint   m_lastProbed;
    };
}