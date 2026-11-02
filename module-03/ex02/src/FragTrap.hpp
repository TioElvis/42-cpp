#ifndef FRAG_TRAP_H
#define FRAG_TRAP_H

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(const FragTrap &other);
    FragTrap &operator=(const FragTrap &other);

    ~FragTrap();

    void highFivesGuys();
};

#endif