#ifndef PONK_MATH_H
#define PONK_MATH_H

#include <SFML/System/Vector2.hpp>
#include <cmath>

template<typename T>
inline constexpr T lengthSquared(sf::Vector2<T> v)
{
    return v.x*v.x + v.y*v.y;
}

template<typename T>
inline constexpr T length(sf::Vector2<T> v)
{
    return std::sqrt(lengthSquared(v));
}

template<typename T>
inline constexpr T sgn(T val)
{
    return (T(0) < val) - (val < T(0));
}

#endif //PONK_MATH_H
