#include "./src/HumanA.hpp"
#include "./src/HumanB.hpp"
#include "./src/Weapon.hpp"

int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA elvis1("Elvis 1", club);
        elvis1.attack();
        club.setType("some other type of club");
        elvis1.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB elvis2("Elvis 2");
        elvis2.setWeapon(club);
        elvis2.attack();
        club.setType("some other type of club");
        elvis2.attack();
    }
    return 0;
}