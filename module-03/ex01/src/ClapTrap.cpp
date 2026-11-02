#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    this->name = "Default";
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;

    std::cout << "ClapTrap " << this->name << " created" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
    this->name = name;
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;

    std::cout << "ClapTrap " << this->name << " created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "ClapTrap " << other.name << " copied with constructor" << std::endl;

    if (this != &other)
    {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "ClapTrap " << other.name << " copied with assigment operator" << std::endl;

    if (this != &other)
    {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }

    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->name << " destroyed" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (this->hitPoints == 0)
    {
        std::cout << "ClapTrap " << this->name << " can't attack because don't have hitPoints" << std::endl;
        return;
    }
    if (this->energyPoints == 0)
    {
        std::cout << "ClapTrap " << this->name << " can't attack because don't have energyPoints" << std::endl;
        return;
    }
    this->energyPoints--;
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hitPoints == 0)
    {
        std::cout << "ClapTrap " << this->name << " is already dead" << std::endl;
        return;
    }

    if (amount >= this->hitPoints)
        this->hitPoints = 0;
    else
        this->hitPoints -= amount;

    std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage, hitPoints left: " << this->hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->hitPoints == 0)
    {
        std::cout << "ClapTrap " << this->name << " cannot be repaired because is dead" << std::endl;
        return;
    }
    if (this->energyPoints == 0)
    {
        std::cout << "ClapTrap " << this->name << " cannot be repaired because don't have energyPoints" << std::endl;
        return;
    }

    this->energyPoints--;
    this->hitPoints += amount;
    std::cout << "ClapTrap " << this->name << " repairs itself, regaining " << amount << " hit points, current hitPoints: " << this->hitPoints << std::endl;
}
