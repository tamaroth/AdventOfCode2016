#include "tools.hh"

Tools::CTimer::CTimer() : m_lastProbed(std::chrono::high_resolution_clock::now())
{

}

Tools::CTimer::~CTimer()
{
}

void Tools::CTimer::probeTime()
{
    m_lastProbed = std::chrono::high_resolution_clock::now();
}

void Tools::CTimer::printElapsed() const
{
    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::high_resolution_clock::now() - m_lastProbed);
    std::cout << time_span.count() << "s." << std::endl;
}
