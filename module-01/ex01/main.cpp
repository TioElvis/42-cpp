#include "./src/Zombie.hpp"

int main()
{
    int N = 8;
    Zombie *zombies = zombieHorde(N, "Elvis");

    for (int i = 0; i < N; i++)
        zombies[i].announce();

    delete[] zombies;

    return 0;
}