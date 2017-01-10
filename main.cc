
#include "main.hh"

DayBase *days[]
{
    &day01
};

int main()
{
    DAYS active{ DAYS::kDay01 };
    for (const auto& day : days)
    {
        if (day->getDay() == active)
        {
            Tools::CTimer timer{};
            day->initialize();
            day->run();
            day->finalize();
            std::cout << "Done in: ";
            timer.printElapsed();
        }
    }
}