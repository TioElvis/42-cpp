#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain created" << std::endl;
}

Brain::Brain(const Brain &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
        {
            this->ideas[i] = other.ideas[i];
        }
    }

    std::cout << "Brain copied by constructor" << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
        {
            this->ideas[i] = other.ideas[i];
        }
    }

    std::cout << "Brain copied by operator" << std::endl;

    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destroyed" << std::endl;
}
