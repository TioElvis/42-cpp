#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), ScavTrap(), FragTrap()
{
    this->name = "Default";
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 30;
    std::cout << "DiamondTrap " << this->name << " created" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
    this->name = name;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 30;
    std::cout << "DiamondTrap " << this->name << " created" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
    this->name = other.name;
    std::cout << "DiamondTrap " << this->name << " copied with constructor" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    std::cout << "DiamondTrap " << this->name << " copied with assignment operator" << std::endl;

    if (this != &other)
    {
        ClapTrap::operator=(other);
        this->name = other.name;
    }
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << this->name << " destroyed" << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "I am DiamondTrap " << this->name << ", but my ClapTrap name is " << ClapTrap::name << std::endl;
}
