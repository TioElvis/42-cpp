#include "./src/ClapTrap.hpp"

int main()
{
    std::cout << "--- TEST 1: Constructors and Canonical Form ---" << std::endl;
    ClapTrap a("Alpha");
    ClapTrap b("Bravo");
    ClapTrap c(a);
    ClapTrap d;
    d = b;

    std::cout << "\n--- TEST 2: Basic Attack and Repair ---" << std::endl;
    a.attack("Test");
    a.takeDamage(4);
    a.beRepaired(2);

    std::cout << "\n--- TEST 3: Depleting Energy Points (10 actions total) ---" << std::endl;
    for (int i = 0; i < 11; ++i)
    {
        std::cout << "[" << i + 1 << "] ";
        c.attack("Target Practice");
    }
    c.attack("Test");
    c.beRepaired(5);

    std::cout << "\n--- TEST 4: Lethal Damage and Zero Hit Points ---" << std::endl;
    b.takeDamage(5);
    b.takeDamage(10);
    b.takeDamage(5);
    b.attack("Test");
    b.beRepaired(5);

    std::cout << "\n--- END OF TESTS: Destructor Calls ---" << std::endl;
    return 0;
}
