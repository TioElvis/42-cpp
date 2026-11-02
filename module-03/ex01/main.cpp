#include "./src/ScavTrap.hpp"

int main()
{
    std::cout << "--- TEST 1: Constructors and Canonical Form ---" << std::endl;
    ScavTrap a("Serena");
    ScavTrap b("Goliath");
    ScavTrap c(a);
    ScavTrap d;
    d = b;

    std::cout << "\n--- TEST 2: Basic Attack and Repair (New Stats) ---" << std::endl;
    a.attack("Test");
    a.takeDamage(40);
    a.beRepaired(20);

    std::cout << "\n--- TEST 3: Special Ability ---" << std::endl;
    a.guardGate();
    b.guardGate();

    std::cout << "\n--- TEST 4: Lethal Damage and Zero Hit Points ---" << std::endl;
    b.takeDamage(80);
    b.takeDamage(50);
    b.takeDamage(10);
    b.attack("Test");
    b.beRepaired(10);

    std::cout << "\n--- TEST 5: Depleting Energy Points (50 actions) ---" << std::endl;
    for (int i = 0; i < 51; ++i)
    {
        std::cout << "[" << i + 1 << "] ";
        c.attack("Target Practice");
    }

    std::cout << "\n--- END OF TESTS: Destructor Calls ---" << std::endl;
    return 0;
}