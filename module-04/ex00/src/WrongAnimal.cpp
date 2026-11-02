#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    this->type = "Generic WrongAnimal";

    std::cout << "WrongAnimal created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    if (this != &other)
    {
        this->type = other.type;
    }

    std::cout << "WrongAnimal copied by constructor" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    if (this != &other)
    {
        this->type = other.type;
    }

    std::cout << "WrongAnimal copied by operator" << std::endl;

    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destroyed" << std::endl;
}

// Functions to show wrong implementation of polymorphism
void WrongAnimal::makeSound() const
{
    std::cout << "Generic WrongAnimal sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return this->type;
}
