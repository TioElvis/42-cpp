#ifndef PHONE_BOOK_H
#define PHONE_BOOK_H

#include <string>
#include "./Contact.hpp"

class PhoneBook
{
private:
    Contact contacts[8];

    int countContacts;

    std::string getInputFirstName();
    std::string getInputLastName();
    std::string getInputNickName();
    long long getInputPhoneNumber();
    std::string getInputDarkestSecret();

    bool isAllDigit(std::string s);

    void displaySearchMenu();
    void displaySpaces(std::string s, int r);
    void displayContactByIndex(int index);

    std::string textFormat(std::string s);

public:
    void addContact();
    void searchContact();
};

#endif