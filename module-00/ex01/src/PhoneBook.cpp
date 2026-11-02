#include <cstdlib>
#include <iostream>

#include "./PhoneBook.hpp"

std::string PhoneBook::getInputFirstName()
{
    std::string firstName;

    std::cout << "firstName: ", std::cin >> firstName;

    if (std::cin.eof())
        std::cout << "\nEOF detected. Exiting the program. Goodbye!\n", exit(0);

    return firstName;
};

std::string PhoneBook::getInputLastName()
{
    std::string lastName;

    std::cout << "lastName: ", std::cin >> lastName;

    if (std::cin.eof())
        std::cout << "\nEOF detected. Exiting the program. Goodbye!\n", exit(0);

    return lastName;
};
std::string PhoneBook::getInputNickName()
{
    std::string nickName;

    std::cout << "nickName: ", std::cin >> nickName;

    if (std::cin.eof())
        std::cout << "\nEOF detected. Exiting the program. Goodbye!\n", exit(0);

    return nickName;
};

bool PhoneBook::isAllDigit(std::string s)
{
    int len = s.length();

    for (int i = 0; i < len; i++)
        if (!std::isdigit(s[i]))
        {
            std::cout << "Only digits are allowed" << std::endl;
            return false;
        }

    return true;
}

long long PhoneBook::getInputPhoneNumber()
{
    std::string phoneNumber;

    while (true)
    {
        std::cout << "phoneNumber (10 digits): ", std::cin >> phoneNumber;

        if (std::cin.eof())
            std::cout << "\nEOF detected. Exiting the program. Goodbye!\n", exit(0);

        int len = phoneNumber.length();

        if (len != 10)
        {
            std::cout << "The phoneNumber must have 10 digits" << std::endl;
            continue;
        }

        if (this->isAllDigit(phoneNumber) == true)
            return std::strtoll(phoneNumber.c_str(), NULL, 10);
        else
            continue;
    }
};

std::string PhoneBook::getInputDarkestSecret()
{
    std::string darkestSecret;

    std::cout << "darkestSecret: ", std::cin >> darkestSecret;

    if (std::cin.eof())
        std::cout << "\nEOF detected. Exiting the program. Goodbye!\n", exit(0);

    return darkestSecret;
};

void PhoneBook::addContact()
{
    Contact contact = Contact();

    contact.setFirstName(this->getInputFirstName());
    contact.setLastName(this->getInputLastName());
    contact.setNickName(this->getInputNickName());
    contact.setPhoneNumber(this->getInputPhoneNumber());
    contact.setDarkestSecret(this->getInputDarkestSecret());

    this->contacts[this->countContacts % 8] = contact;
    this->countContacts += 1;
}

void PhoneBook::displaySpaces(std::string s, int r)
{
    int len = s.length();

    for (int i = 0; i < r - len - 1; i++)
        std::cout << " ";
}

std::string PhoneBook::textFormat(std::string s)
{
    int len = s.length();

    if (len > 10)
        return s.substr(0, 9) + ".";

    return s;
}

void PhoneBook::displaySearchMenu()
{
    std::cout << "+-------------------------------------------------------------------------+" << std::endl;
    std::cout << "| index         | firstName         | lastName         | nickName         |" << std::endl;
    std::cout << "+-------------------------------------------------------------------------+" << std::endl;

    int contacts = 0;

    if (this->countContacts >= 8)
        contacts = 8;
    else
        contacts = this->countContacts % 8;

    if (contacts == 0)
    {
        std::cout << "+-------------------------------------------------------------------------+" << std::endl;
        std::cout << "| Not contacts to show.                                                   |" << std::endl;
        std::cout << "+-------------------------------------------------------------------------+" << std::endl;
    }

    for (int i = 0; i < contacts; i++)
    {
        std::string firstName = this->textFormat(this->contacts[i].getFirstName());
        std::string lastname = this->textFormat(this->contacts[i].getLastName());
        std::string nickName = this->textFormat(this->contacts[i].getNickName());

        std::cout << "| " << i, this->displaySpaces("0", 15);
        std::cout << "| " << firstName, this->displaySpaces(firstName, 19);
        std::cout << "| " << lastname, this->displaySpaces(lastname, 18);
        std::cout << "| " << nickName, this->displaySpaces(nickName, 18);

        std::cout << "|" << std::endl;
    }

    std::cout << "+-------------------------------------------------------------------------+" << std::endl;
    std::cout << "| Search by index or write EXIT to return to main menu                    |" << std::endl;
    std::cout << "+-------------------------------------------------------------------------+" << std::endl;
}

void PhoneBook::displayContactByIndex(int index)
{
    Contact contact = this->contacts[index];

    std::cout << "firstName: " << contact.getFirstName() << std::endl;
    std::cout << "lastName: " << contact.getLastName() << std::endl;
    std::cout << "nickName: " << contact.getNickName() << std::endl;
    std::cout << "phoneNumber: " << contact.getPhoneNumber() << std::endl;
    std::cout << "darkestSecret: " << contact.getDarkestSecret() << std::endl;
}

void PhoneBook::searchContact()
{
    this->displaySearchMenu();

    while (true)
    {
        std::string command;

        std::cout << ">", std::cin >> command;

        if (std::cin.eof())
            std::cout << "\nEOF detected. Exiting the program. Goodbye!\n", exit(0);

        if (command == "EXIT")
            break;

        if (this->isAllDigit(command) == true)
        {
            long long index = std::strtoll(command.c_str(), NULL, 10);

            if (index >= 8)
            {
                std::cout << "Index must be on range of 0-7" << std::endl;
                continue;
            }

            this->displayContactByIndex(index);
        }
        else
            continue;
    }
}
