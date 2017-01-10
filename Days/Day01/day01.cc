#include "Day01.hh"

DAYS CDay01::getDay() const
{
    return DAYS::kDay01;
}

// during initialize split the input string into an array.
void CDay01::initialize(...)
{
    const std::string input{ "R3, L5, R2, L1, L2, R5, L2, R2, L2, L2, L1, R2, L2, R4, R4, R1, L2, L3, R3, L1, R2, L2, L4, R4, R5, L3, R3, L3, L3, R4, R5, L3, R3, L5, L1, L2, R2, L1, R3, R1, L1, R187, L1, R2, R47, L5, L1, L2, R4, R3, L3, R3, R4, R1, R3, L1, L4, L1, R2, L1, R4, R5, L1, R77, L5, L4, R3, L2, R4, R5, R5, L2, L2, R2, R5, L2, R194, R5, L2, R4, L5, L4, L2, R5, L3, L2, L5, R5, R2, L3, R3, R1, L4, R2, L1, R5, L1, R5, L1, L1, R3, L1, R5, R2, R5, R5, L4, L5, L5, L5, R3, L2, L5, L4, R3, R1, R1, R4, L2, L4, R5, R5, R4, L2, L2, R5, R5, L5, L2, R4, R4, L4, R1, L3, R1, L1, L1, L1, L4, R5, R4, L4, L4, R5, R3, L2, L2, R3, R1, R4, L3, R1, L4, R3, L3, L2, R2, R2, R2, L1, L4, R3, R2, R2, L3, R2, L3, L2, R4, L2, R3, L4, R5, R4, R1, R5, R3" };
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

void CDay01::part1() const
{
    int direction{};
    int Px{}, Py{};
    for (const auto& token : m_tokens)
    {
        if (token.direction == DIRECTON::kLeft)
        {
            direction = (direction + 3) % 4;
        }
        else
        {
            direction = (direction + 1) % 4;
        }

        switch (direction)
        {
        case 0:
            Py += token.distance;
            break;
        case 1:
            Px += token.distance;
            break;
        case 2:
            Py -= token.distance;
            break;
        case 3:
            Px -= token.distance;
        default:
            break;
        }
    }
    std::cout << "Part 1: " << abs(-Px) + abs(-Py) << std::endl;
}

void CDay01::part2() const
{
    std::map<std::pair<int, int>, int> crossings{};
    int direction{};
    int Px{}, Py{};
    for (const auto& token : m_tokens)
    {
        if (token.direction == DIRECTON::kLeft)
        {
            direction = (direction + 3) % 4;
        }
        else
        {
            direction = (direction + 1) % 4;
        }

        switch (direction)
        {
        case 0:
        {
            for (int i{0}; i < token.distance; ++i)
            {
                if (crossings.find(std::make_pair(Px, Py + i)) != crossings.end())
                {
                    Py += i;
                    std::cout << "Part 2: " << abs(-Px) + abs(-Py) << std::endl;
                    return;
                }
                crossings[std::make_pair(Px, Py + i)] = 1;
            }
            Py += token.distance;
            break;
        }
        case 1:
        {
            for (int i{0}; i < token.distance; ++i)
            {
                if (crossings.find(std::make_pair(Px + i, Py)) != crossings.end())
                {
                    Px += i;
                    std::cout << "Part 2: " << abs(-Px) + abs(-Py) << std::endl;
                    return;
                }
                crossings[std::make_pair(Px + i, Py)] = 1;
            }
            Px += token.distance;
            break;
        }
        case 2:
        {
            for (int i{0}; i < token.distance; ++i)
            {
                if (crossings.find(std::make_pair(Px, Py - i)) != crossings.end())
                {
                    Py -= i;
                    std::cout << "Part 2: " << abs(-Px) + abs(-Py) << std::endl;
                    return;
                }
                crossings[std::make_pair(Px, Py - i)] = 1;
            }
            Py -= token.distance;
            break;
        }
        case 3:
        {
            for (int i{0}; i < token.distance; ++i)
            {
                if (crossings.find(std::make_pair(Px - i, Py)) != crossings.end())
                {
                    Py -= i;
                    std::cout << "Part 2: " << abs(-Px) + abs(-Py) << std::endl;
                    return;
                }
                crossings[std::make_pair(Px - i, Py)] = 1;
            }
            Px -= token.distance;
        }
        default:
            break;
        }
    }
}

void CDay01::run(...)
{
    part1();
    part2();
}

void CDay01::finalize(...)
{
}