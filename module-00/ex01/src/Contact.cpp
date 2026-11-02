#include "./Contact.hpp"

std::string Contact::getFirstName()
{
    return this->firstName;
};

std::string Contact::getLastName()
{
    return this->lastName;
};

std::string Contact::getNickName()
{
    return this->nickName;
};

long long Contact::getPhoneNumber()
{
    return this->phoneNumber;
};

std::string Contact::getDarkestSecret()
{
    return this->darkestSecret;
};

void Contact::setFirstName(std::string firstName)
{
    this->firstName = firstName;
};

void Contact::setLastName(std::string lastName)
{
    this->lastName = lastName;
};

void Contact::setNickName(std::string nickName)
{
    this->nickName = nickName;
};

void Contact::setPhoneNumber(long long phoneNumber)
{
    this->phoneNumber = phoneNumber;
};

void Contact::setDarkestSecret(std::string darkestSecret)
{
    this->darkestSecret = darkestSecret;
};