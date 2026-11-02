#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap " << this->name << " created" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap " << this->name << " created" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "FragTrap " << this->name << " copied with constructor" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    std::cout << "FragTrap " << this->name << " copied with assignment operator" << std::endl;
    if (this != &other)
        ClapTrap::operator=(other);
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->name << " destroyed" << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << this->name << " says: Give me a high five, guys! 🖐️" << std::endl;
}
