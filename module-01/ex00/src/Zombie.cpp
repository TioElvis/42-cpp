#include <iostream>
#include "./Zombie.hpp"

Zombie::~Zombie()
{
    std::cout << this->name << " was deleted" << std::endl;
}

std::string Zombie::getName()
{
    return this->name;
};

void Zombie::setName(std::string name)
{
    this->name = name;
};

void Zombie::announce()
{
    std::cout << this->name << ": " << "BraiiiiiiinnnzzzZ" << std::endl;
}
