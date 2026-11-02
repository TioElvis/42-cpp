#include "./src/DiamondTrap.hpp"

int main()
{
    std::cout << "--- TEST 1: Constructors and Canonical Form ---" << std::endl;
    DiamondTrap a("Goku");
    DiamondTrap b("Vegeta");
    DiamondTrap c(a);
    DiamondTrap d;
    d = b;

    std::cout << "\n--- TEST 2: Basic Attack and Repair (Mixed Stats) ---" << std::endl;
    a.attack("Frieza");
    a.takeDamage(40);
    a.beRepaired(20);

    std::cout << "\n--- TEST 3: Special Abilities (From all parents + own) ---" << std::endl;
    a.whoAmI();
    a.guardGate();
    a.highFivesGuys();

    std::cout << "\n--- TEST 4: Lethal Damage and Zero Hit Points ---" << std::endl;
    b.takeDamage(80);
    b.takeDamage(50);
    b.takeDamage(10);
    b.attack("Cell");
    b.beRepaired(10);

    std::cout << "\n--- TEST 5: Depleting Energy Points (50 actions) ---" << std::endl;
    for (int i = 0; i < 51; ++i)
    {
        std::cout << "[" << i + 1 << "] ";
        c.attack("Picolo");
    }

    std::cout << "\n--- END OF TESTS: Destructor Calls ---" << std::endl;
    return 0;
}
