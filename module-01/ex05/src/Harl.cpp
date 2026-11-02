#include <iostream>
#include "./Harl.hpp"

void Harl::debug()
{
    std::cout << "[DEBUG]: I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
    std::cout << "[INFO]: I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning()
{
    std::cout << "[WARNING]: I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error()
{
    std::cout << "[ERROR]: This is unacceptable! I want to speak to the manager now." << std::endl;
}

static int indexOf(std::string *array, std::string s, int size)
{
    int i = 0;
    int index = -1;

    while (i < size)
    {
        if (array[i] == s)
            index = i;
        i++;
    }

    return index;
}

void Harl::complain(std::string level)
{
    std::string array[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    void (Harl::*f[4])(void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error};

    int i = indexOf(array, level, 4);

    if (i == -1)
        return;

    (this->*f[i])();
}