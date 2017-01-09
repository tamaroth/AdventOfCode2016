#include "tools.hh"

Tools::Timer::Timer() : m_lastProbed(std::chrono::high_resolution_clock::now())
{

}

Tools::Timer::~Timer()
{
}

void Tools::Timer::probeTime()
{
    m_lastProbed = std::chrono::high_resolution_clock::now();
}

void Tools::Timer::printElapsed() const
{
    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::high_resolution_clock::now() - m_lastProbed);
    std::cout << time_span.count() << "s." << std::endl;
}
