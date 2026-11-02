#include "Dog.hpp"

Dog::Dog() : Animal()
{
    this->type = "Dog";
    this->brain = new Brain();

    std::cout << "Dog created" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
    this->type = other.type;
    this->brain = new Brain(*other.brain);

    std::cout << "Dog copied by constructor" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        this->type = other.type;
        delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    std::cout << "Dog copied by operator" << std::endl;

    return *this;
}

Dog::~Dog()
{
    delete this->brain;
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
