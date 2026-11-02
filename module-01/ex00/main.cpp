#include "./src/Zombie.hpp"

int main()
{
    Zombie *zombieTest1 = newZombie("Elvis 1");
    Zombie *zombieTest2 = newZombie("Elvis 2");

    zombieTest1->announce();
    zombieTest2->announce();

    delete zombieTest1;
    delete zombieTest2;

    randomChump("Elvis 3");
    randomChump("Elvis 4");

    return 0;
}
