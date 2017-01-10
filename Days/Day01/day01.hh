#pragma once

#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <map>
#include "../../Common/DayBase/base.hh"

class CDay01 : public DayBase
{
public:
    CDay01() {};
    ~CDay01() {};

    DAYS getDay() const;
    void initialize(...);
    void run(...);
    void finalize(...);
private:
    void part1() const;
    void part2() const;

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