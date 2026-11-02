#include <string>
#include <cstdlib>
#include <iostream>

#include "./src/PhoneBook.hpp"

void displayMenu()
{
    std::cout << "+-------------------------------+" << std::endl;
    std::cout << "| PhoneBook                     |" << std::endl;
    std::cout << "|                               |" << std::endl;
    std::cout << "| Commands:                     |" << std::endl;
    std::cout << "|  - ADD                        |" << std::endl;
    std::cout << "|  - SEARCH                     |" << std::endl;
    std::cout << "|  - EXIT                       |" << std::endl;
    std::cout << "|                               |" << std::endl;
    std::cout << "|  Commands are case-sensitive  |" << std::endl;
    std::cout << "+-------------------------------+" << std::endl;
}

int main()
{
    std::string command;

    bool showMenu = true;

    PhoneBook phoneBook = PhoneBook();

    while (true)
    {
        if (showMenu == true)
            displayMenu(), showMenu = false;

        std::cout << ">", std::cin >> command;

        if (std::cin.eof())
            std::cout << "\nEOF detected. Exiting the program. Goodbye!\n", exit(0);

        if (command == "EXIT")
            exit(0);

        if (command == "ADD")
        {
            phoneBook.addContact(), showMenu = true;
            continue;
        }

        if (command == "SEARCH")
        {
            phoneBook.searchContact(), showMenu = true;
            continue;
        }

        if (!(command == "EXIT" && command == "ADD" && command == "SEARCH"))
            std::cout << "Invalid input." << std::endl, showMenu = false;
    }

    return 0;
}
