#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap " << this->name << " created" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap " << this->name << " created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "ScavTrap " << this->name << " copied with constructor" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "ScavTrap " << this->name << " copied with assignment operator" << std::endl;
    if (this != &other)
        ClapTrap::operator=(other);
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->name << " destroyed" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode " << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (this->hitPoints == 0)
    {
        std::cout << "ScavTrap " << this->name << " can't attack because don't have hitPoints" << std::endl;
        return;
    }
    if (this->energyPoints == 0)
    {
        std::cout << "ScavTrap " << this->name << " can't attack because don't have energyPoints" << std::endl;
        return;
    }
    this->energyPoints--;
    std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}
