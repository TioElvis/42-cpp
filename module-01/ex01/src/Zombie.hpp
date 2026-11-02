#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>

class Zombie
{
private:
    std::string name;

public:
    ~Zombie();
    std::string getName();

    void setName(std::string name);

    void announce();
};

Zombie *zombieHorde(int N, std::string name);

#endif