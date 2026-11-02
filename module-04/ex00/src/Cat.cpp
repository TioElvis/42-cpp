#include "Cat.hpp"

Cat::Cat() : Animal()
{
    this->type = "Cat";

    std::cout << "Cat created" << std::endl;
}

Cat::Cat(const Cat &other) : Animal()
{
    this->type = other.type;

    std::cout << "Cat copied by constructor" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        this->type = other.type;
    }

    std::cout << "Cat copied by operator" << std::endl;

    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destroyed" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow" << std::endl;
}

std::string Cat::getType() const
{
    return this->type;
}
