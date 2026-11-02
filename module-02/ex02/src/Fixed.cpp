#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->value = 0;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
    std::cout << "Int constructor called" << std::endl;
    this->value = n << this->literal;
}

Fixed::Fixed(const float n)
{
    std::cout << "Float constructor called" << std::endl;
    this->value = roundf(n * (1 << this->literal));
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

bool Fixed::operator>(const Fixed &other) const
{
    return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator<(const Fixed &other) const
{
    return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const
{
    return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const
{
    return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const
{
    return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const
{
    return this->getRawBits() != other.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->value = other.getRawBits();
    }
    return *this;
}

Fixed Fixed::operator+(const Fixed &other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++(void)
{
    this->value += 1;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    this->value += 1;
    return temp;
}

Fixed &Fixed::operator--(void)
{
    this->value -= 1;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    this->value -= 1;
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->value;
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}

int Fixed::toInt(void) const
{
    return this->value >> this->literal;
}

float Fixed::toFloat(void) const
{
    return (float)this->value / (float)(1 << this->literal);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}
