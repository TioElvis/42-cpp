#ifndef SCAV_TRAP_H
#define SCAV_TRAP_H

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
private:
public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap &other);
    ScavTrap &operator=(const ScavTrap &other);

    ~ScavTrap();

    void guardGate();
    void attack(const std::string &target);
};

#endif