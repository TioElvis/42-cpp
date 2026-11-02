#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed
{
private:
    int value;
    static const int literal = 8;

public:
    Fixed();
    ~Fixed();

    Fixed(const int n);
    Fixed(const float n);
    Fixed(const Fixed &other);

    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;

    Fixed &operator=(const Fixed &other);
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;

    Fixed &operator++(void);
    Fixed operator++(int);
    Fixed &operator--(void);
    Fixed operator--(int);

    static Fixed &min(Fixed &a, Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);

    static const Fixed &min(const Fixed &a, const Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);

    int getRawBits(void) const;
    void setRawBits(int const raw);

    int toInt(void) const;
    float toFloat(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif