#ifndef PONK_MATH_H
#define PONK_MATH_H

#include <SFML/System/Vector2.hpp>
#include <cmath>

template<typename T>
T lengthSquared(sf::Vector2<T> v) {
    return v.x*v.x + v.y*v.y;
}

template<typename T>
T length(sf::Vector2<T> v) {
    return std::sqrt(lengthSquared(v));
}

#endif //PONK_MATH_H
