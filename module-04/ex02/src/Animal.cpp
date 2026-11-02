#include "Animal.hpp"

Animal::Animal()
{
    this->type = "Generic Animal";

    std::cout << "Animal created" << std::endl;
}

Animal::Animal(const Animal &other)
{
    if (this != &other)
    {
        this->type = other.type;
    }

    std::cout << "Animal copied by constructor" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
    if (this != &other)
    {
        this->type = other.type;
    }

    std::cout << "Animal copied by operator" << std::endl;

    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal destroyed" << std::endl;
}

// Functions to avoid compile errors
std::string Animal::getType() const
{
    return this->type;
}
