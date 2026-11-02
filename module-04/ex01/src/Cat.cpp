#include "Cat.hpp"

Cat::Cat() : Animal()
{
    this->type = "Cat";
    this->brain = new Brain();

    std::cout << "Cat created" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
    this->type = other.type;
    this->brain = new Brain(*other.brain);

    std::cout << "Cat copied by constructor" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        this->type = other.type;
        delete this->brain;
        this->brain = new Brain(*other.brain);
    }

    std::cout << "Cat copied by operator" << std::endl;

    return *this;
}

Cat::~Cat()
{
    delete this->brain;
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
