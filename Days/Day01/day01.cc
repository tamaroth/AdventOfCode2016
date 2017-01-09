#include "day01.hh"

DAYS Day01::getDay() const
{
    return DAYS::kDay01;
}

// during initialize split the input string into an array.
void Day01::initialize(...)
{
    m_timer.probeTime();
    std::string input{ "R3, L5, R2, L1, L2, R5, L2, R2, L2, L2, L1, R2, L2, R4, R4, R1, L2, L3, R3, L1, R2, L2, L4, R4, R5, L3, R3, L3, L3, R4, R5, L3, R3, L5, L1, L2, R2, L1, R3, R1, L1, R187, L1, R2, R47, L5, L1, L2, R4, R3, L3, R3, R4, R1, R3, L1, L4, L1, R2, L1, R4, R5, L1, R77, L5, L4, R3, L2, R4, R5, R5, L2, L2, R2, R5, L2, R194, R5, L2, R4, L5, L4, L2, R5, L3, L2, L5, R5, R2, L3, R3, R1, L4, R2, L1, R5, L1, R5, L1, L1, R3, L1, R5, R2, R5, R5, L4, L5, L5, L5, R3, L2, L5, L4, R3, R1, R1, R4, L2, L4, R5, R5, R4, L2, L2, R5, R5, L5, L2, R4, R4, L4, R1, L3, R1, L1, L1, L1, L4, R5, R4, L4, L4, R5, R3, L2, L2, R3, R1, R4, L3, R1, L4, R3, L3, L2, R2, R2, R2, L1, L4, R3, R2, R2, L3, R2, L3, L2, R4, L2, R3, L4, R5, R4, R1, R5, R3" };
    const std::regex separator(", ");
    std::sregex_token_iterator token_iterator(input.begin(), input.end(), separator, -1), end_seq;

    while (token_iterator != end_seq)
    {
        TOKENS element{};
        auto str{ (*token_iterator).str() };

        if (str[0] == 'L')
            element.direction = DIRECTON::kLeft;
        else
            element.direction = DIRECTON::kRight;
        element.distance = std::stoi(&str[1]);
        m_tokens.push_back(element);
        token_iterator++;
    }
}

void Day01::part1() const
{
    int numL{}, numR{};
    int distance{};
    for (const auto& token : m_tokens)
    {
        int localDistance{ token.distance };

        if (token.direction == DIRECTON::kLeft)
        {
            // not very efficient, but the easiest way possible
            if (numL && numL % 2 == 0)
                localDistance = -localDistance;
            numL++;
        }
        else
        {
            if (numR && numR % 2 == 0)
                localDistance = -localDistance;
            numR++;
        }

        distance += localDistance;
    }

    std::cout << "Part 1: " << distance << " in ";
    m_timer.printElapsed();
}

void Day01::run(...)
{
    part1();
}

void Day01::finalize(...)
{
    m_timer.printElapsed();
}