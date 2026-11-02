#include "Dog.hpp"

Dog::Dog() : Animal()
{
    this->type = "Dog";

    std::cout << "Dog created" << std::endl;
}

Dog::Dog(const Dog &other) : Animal()
{
    this->type = other.type;

    std::cout << "Dog copied by constructor" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        this->type = other.type;
    }

    std::cout << "Dog copied by operator" << std::endl;

    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destroyed" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Bark" << std::endl;
}

std::string Dog::getType() const
{
    return this->type;
}
