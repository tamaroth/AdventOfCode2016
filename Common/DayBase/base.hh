#pragma once
#include "../Tools/tools.hh"

class DayBase
{
public:
    DayBase() {};
    virtual ~DayBase() = 0 {};

    virtual
    DAYS getDay() const = 0;

    virtual
    void initialize(...) = 0;

    virtual
    void run(...) = 0;

    virtual
    void finalize(...) = 0;
};