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

void randomChump(std::string name);

Zombie *newZombie(std::string name);

#endif