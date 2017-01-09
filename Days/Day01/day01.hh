#pragma once

#include "../../Common/DayBase/base.hh"
#include <string>
#include <regex>
#include <vector>

class Day01 : public DayBase
{
public:
    Day01() {};
    ~Day01() {};

    DAYS getDay() const;
    void initialize(...);
    void run(...);
    void finalize(...);
private:
    void part1() const;
    enum class DIRECTON
    {
        kLeft,
        kRight
    };

    struct TOKENS
    {
        DIRECTON    direction;
        int         distance;
    };
private:
    std::vector<TOKENS>     m_tokens;
    Tools::Timer            m_timer;
};