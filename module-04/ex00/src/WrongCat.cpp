#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    this->type = "WrongCat";

    std::cout << "WrongCat created" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal()
{
    if (this != &other)
    {
        this->type = other.type;
    }

    std::cout << "WrongCat copied by constructor" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
    if (this != &other)
    {
        this->type = other.type;
    }

    std::cout << "WrongCat copied by operator" << std::endl;

    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destroyed" << std::endl;
}
