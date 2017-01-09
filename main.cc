
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
            day->initialize();
            day->run();
            day->finalize();
        }
    }
    std::cout << "Finished.";
}