#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact
{
private:
    std::string firstName;
    std::string lastName;
    std::string nickName;
    long long phoneNumber;
    std::string darkestSecret;

public:
    std::string getFirstName();
    std::string getLastName();
    std::string getNickName();
    long long getPhoneNumber();
    std::string getDarkestSecret();

    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setNickName(std::string nickName);
    void setPhoneNumber(long long phoneNumber);
    void setDarkestSecret(std::string darkestSecret);
};

#endif